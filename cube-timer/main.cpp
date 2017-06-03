#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDateTime>
#include <QQuickStyle>
#include <QDebug>

#include "cubetimer.h"


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    if(msg.contains("doing manual update"))
        return;
    QDateTime curTime(QDateTime::currentDateTime());
    QString timeFrmt("hh:mm:ss:zzz");
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
      case QtDebugMsg:
        fprintf(stdout, "[%s] %s.Debug: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        break;
      case QtInfoMsg:
        fprintf(stdout, "[%s] %s.Info: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        break;
      case QtWarningMsg:
        fprintf(stdout, "[%s] %s.Warning: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        break;
      case QtCriticalMsg:
        fprintf(stdout, "[%s] %s.Critical: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        break;
      case QtFatalMsg:
        fprintf(stdout, "[%s] %s.Fatal: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        abort();
      }
    QTextStream s(stdout);
    flush(s);
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qInstallMessageHandler(myMessageOutput);
    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    qDebug() << "Starting Cube Timer";

    CubeTimer ct(engine.rootObjects().first());
    (void) ct; // Supress unused warning

    return app.exec();
}
