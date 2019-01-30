#ifndef TODAYCALLI_H
#define TODAYCALLI_H

#include <QObject>

class Today;

class TodayCalli : public QObject
{
    Q_OBJECT
public:
    explicit TodayCalli(QObject *parent = nullptr);

    Q_INVOKABLE QString getTodayKor();
    Q_INVOKABLE QString getTodayEng();
    Q_INVOKABLE QString getTodayPro();
    Q_INVOKABLE QString getTodayPub();

signals:

public slots:

private:
    Today *today;
};

#endif // TODAYCALLI_H
