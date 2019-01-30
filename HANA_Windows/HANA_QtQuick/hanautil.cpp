#include "hanautil.h"
#include <QSettings>
#include <QCoreApplication>

HanaUtil::HanaUtil(QObject *parent) : QObject(parent)
{

}

void HanaUtil::regStart()
{
    QSettings Settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",
                       QSettings::NativeFormat);

    QString Path=QString("\"%1\"").arg(QCoreApplication::applicationFilePath().replace('/','\\'));
    Settings.setValue("HANA",Path); //�ڵ����� ����
    //Settings.remove("HANA"); //�ڵ����� ����
}
