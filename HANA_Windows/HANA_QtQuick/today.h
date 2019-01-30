#ifndef TODAY_H
#define TODAY_H

#include <QtNetwork>

class Today : public QObject
{
    Q_OBJECT
public:
    Today();
    QString getData(QString j);
private:
    QNetworkAccessManager *manager;
    QEventLoop connection_loop;
};

void LogToFile(QtMsgType type, const QString &msg);

#endif // TODAY_H
