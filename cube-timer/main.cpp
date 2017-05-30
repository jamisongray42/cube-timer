#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDateTime>
#include <QQuickStyle>
#include <QDebug>

#include "cubetimer.h"


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    QDateTime curTime(QDateTime::currentDateTime());
    QString timeFrmt("hh:mm:ss:zzz");
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
      case QtDebugMsg:
        fprintf(stderr, "[%s] %s.Debug: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        break;
      case QtInfoMsg:
        fprintf(stderr, "[%s] %s.Info: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        break;
      case QtWarningMsg:
        fprintf(stderr, "[%s] %s.Warning: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        break;
      case QtCriticalMsg:
        fprintf(stderr, "[%s] %s.Critical: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        break;
      case QtFatalMsg:
        fprintf(stderr, "[%s] %s.Fatal: %s\n", curTime.toString(timeFrmt).toLatin1().data(), context.category, localMsg.constData());
        abort();
      }
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
    (void) ct;

    return app.exec();
}
