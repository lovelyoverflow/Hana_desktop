#include "calliwidget.h"
#include "today.h"
#include "todaycalli.h"

#include "windesk.h"
#include <conio.h>
#include <Windows.h>
#include <chrono>
#include <gdiplus.h>

#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;

CalliWidget::CalliWidget(QObject *parent)
    : QObject(parent),
      windesk(new Windesk)
{

}

void CalliWidget::drawCalliWidget()
{
    HDC desktop = windesk->GetContext();

    ULONG_PTR gdiplusToken; // 마지막에 GdiplusShutdown에서 사용하므로 저장필수.

    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    Image* image = Image::FromFile(L"C:\\Users\\hana_calli.png");
    //Image* image = Image::FromFile(L"");
    Graphics g(desktop);
    g.DrawImage(image, 800, 400);  // x, y좌표 외에도 width ,height를 받는 등의 오버로딩된 함수가 많다.

    //delete image;
    //Gdiplus::GdiplusShutdown(gdiplusToken);
}

void CalliWidget::deleteCalliWidget()
{
    windesk->SetWallpaperW(windesk->GetWallpaperW());
}
