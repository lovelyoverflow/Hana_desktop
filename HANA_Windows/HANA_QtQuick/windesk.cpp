#include "windesk.h"
#include <ShlObj.h>
#include <QDebug>

Windesk::Windesk()
{ }

HWND Windesk::workerW = nullptr;

HDC Windesk::GetContext()
{
    // Based on the discovery of Mr. Gerald Degeneve
    // https://www.codeproject.com/articles/856020/draw-behind-desktop-icons-in-windows
    HWND progman = FindWindowA("Progman", nullptr);
    SendMessageTimeoutA(progman, 0x052C, 0, 0, SMTO_NORMAL, 1000, nullptr);
    EnumWindows([](HWND hwnd, LPARAM lparam) -> BOOL
    {
        HWND p = FindWindowExA(hwnd, 0, "SHELLDLL_DefView", nullptr);
        if (p != 0)
        {
            workerW = FindWindowExA(0, hwnd, "WorkerW", nullptr);
        }

        return true;
    }, 0);

    return GetDCEx(workerW, 0, DCX_LOCKWINDOWUPDATE | DCX_CLIPCHILDREN);
}

std::wstring Windesk::GetWallpaperW()
{
    // Search for the current wallpaper
    std::wstring path(MAX_PATH, '\0');
    SystemParametersInfoW(SPI_GETDESKWALLPAPER, path.size(), &path[0], 0);
    path.resize(wcslen(&path[0]));

    // Check if the file exists
    DWORD attr = GetFileAttributesW(path.c_str());
    if (attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY))
    {
        return path;
    }

    // Check for TranscodedWallpaper
    path.clear();
    path.resize(MAX_PATH, '\0');
    SHGetFolderPathW(0, CSIDL_APPDATA, 0, 0, &path[0]);
    path.resize(wcslen(&path[0]));
    path += L"\\Microsoft\\Windows\\Themes\\TranscodedWallpaper";
    attr = GetFileAttributesW(path.c_str());
    if (attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY))
    {
        return path;
    }

    // The user has no wallpaper
    return L"";
}

void Windesk::SetWallpaperW(const std::wstring& path)
{
    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void*)&path[0], SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
}
