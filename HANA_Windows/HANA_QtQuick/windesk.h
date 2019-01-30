#ifndef WINDESK_H
#define WINDESK_H

#include <Windows.h>
#include <string>

class Windesk
{
public:
    Windesk();
    HDC GetContext();

    std::string GetWallpaperA();
    void SetWallpaperA(const std::string& path);

    std::wstring GetWallpaperW();
    void SetWallpaperW(const std::wstring& path);
private:
    static HWND workerW;
};

#endif // WINDESK_H
