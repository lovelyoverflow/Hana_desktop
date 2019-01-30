#include "todaycalli.h"
#include "today.h"

#include <QDebug>
#include <QImage>
#include <QPixmap>

TodayCalli::TodayCalli(QObject *parent)
    : QObject(parent),
      today(new Today)
{
    QImage image;

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QEventLoop connection_loop;

    connect(manager, SIGNAL(finished(QNetworkReply*)), &connection_loop, SLOT(quit()));
    QNetworkRequest request;

    QString img = today->getData("img");
    QString imgURL = QString("http://hana.kimjisub.kr:3000/image/" + img);

    request.setUrl(QUrl(imgURL));
    QNetworkReply *reply = manager->get(request);
    connection_loop.exec();
    QByteArray data = reply->readAll();
    image.loadFromData(data);

    image.save("C:\\Users\\hana_calli.png");

    QPixmap buffer;
    buffer = QPixmap::fromImage(image);
}

QString TodayCalli::getTodayKor()
{
    QString kor = today->getData("korean");
    return kor;
}

QString TodayCalli::getTodayEng()
{
    QString eng = today->getData("english");
    return eng;
}

QString TodayCalli::getTodayPro()
{
    QString pro = today->getData("pronunciation");
    return pro;
}

QString TodayCalli::getTodayPub()
{
    QString pub = today->getData("publish_date");
    return pub;
}
