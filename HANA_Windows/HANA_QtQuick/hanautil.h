#ifndef HANAUTIL_H
#define HANAUTIL_H

#include <QObject>

class HanaUtil : public QObject
{
    Q_OBJECT
public:
    explicit HanaUtil(QObject *parent = nullptr);
    Q_INVOKABLE void regStart();

signals:

public slots:
};

#endif // HANAUTIL_H
