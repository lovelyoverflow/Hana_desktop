#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include "calliwidget.h"
#include "todaycalli.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    //app.setWindowIcon(QIcon(":/icons/hana.ico"));

    CalliWidget calliWidget;
    TodayCalli todayCalli;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("CalliWidget", &calliWidget);
    engine.rootContext()->setContextProperty("TodayCalli", &todayCalli);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
