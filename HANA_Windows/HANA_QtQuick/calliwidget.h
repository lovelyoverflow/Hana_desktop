#ifndef CALLIWIDGET_H
#define CALLIWIDGET_H

#include <QObject>

class Windesk;
class CalliWidget : public QObject
{
    Q_OBJECT
public:
    explicit CalliWidget(QObject *parent = nullptr);

    Q_INVOKABLE void drawCalliWidget();
    Q_INVOKABLE void deleteCalliWidget();

signals:

public slots:

private:
    Windesk *windesk;
};

#endif // CALLIWIDGET_H
