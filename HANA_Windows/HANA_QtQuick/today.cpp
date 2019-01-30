#include "today.h"
#include <QWidget>

Today::Today()
{
    manager = new QNetworkAccessManager();
}

void LogToFile(QtMsgType type, const QString &msg)
{
	QFile file("D:\\Qt Project\\HANA\\tmp\\log.txt");
	if (!file.open(QIODevice::Append | QIODevice::Text)) {
		return;
	}
	QTextStream out(&file);

	QString curtime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ");
	//context.file, context.line, context.function
	switch (type) {
	case QtDebugMsg:
		out << "[Debug]" << curtime << msg << "\n";
		break;
	case QtInfoMsg:
		out << "[Info]" << curtime << msg << "\n";
		break;
	case QtWarningMsg:
		out << "[Warning]" << curtime << msg << "\n";
		break;
	}

	file.close();
}

QString Today::getData(QString j)
{
    QNetworkRequest request;

    QWidget::connect(manager, SIGNAL(finished(QNetworkReply*)), &connection_loop, SLOT(quit()));
    request.setUrl(QUrl("http://hana.kimjisub.kr:3000/quote/today"));
    //request.setUrl(QUrl("file:///C:/test.html"));
    QNetworkReply *reply = manager->get(request);
    connection_loop.exec();

    QByteArray data = reply->readAll();;

    data.push_front('[');
    data.push_back(']');

    QJsonDocument json_doc = QJsonDocument::fromJson(data);
    QString val;

    QJsonValue var = json_doc.array().first();

    val = var.toObject().value(j).toString();
    //LogToFile(QtMsgType::QtDebugMsg, val);
	//LogToFile(QtMsgType::QtDebugMsg, QByteArray("http://hana.kimjisub.kr:3000/image/" + val.toStdWString()));
    return val;
}
