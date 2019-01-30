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

    ULONG_PTR gdiplusToken; // �������� GdiplusShutdown���� ����ϹǷ� �����ʼ�.

    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    Image* image = Image::FromFile(L"C:\\Users\\hana_calli.png");

    Graphics g(desktop);
    g.DrawImage(image, 800, 400);  // x, y��ǥ �ܿ��� width ,height�� �޴� ���� �����ε��� �Լ��� ����.

    //delete image;
    //Gdiplus::GdiplusShutdown(gdiplusToken);
}

void CalliWidget::deleteCalliWidget()
{
    windesk->SetWallpaperW(windesk->GetWallpaperW());
}
