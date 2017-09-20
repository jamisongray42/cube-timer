#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDateTime>
#include <QQuickStyle>
#include <QDebug>

#include "cubetimer.h"


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    //TODO IGnore these messages for now so they dont pollute the log
    // Will deal with them eventually
    if(msg.contains("doing manual update") ||
       msg.contains("TouchPointPressed without previous release event"))
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

    int rc(0);
    {
        qWarning() << "Starting Cube Timer";

        QQmlApplicationEngine engine;
        engine.load(QUrl(QLatin1String("qrc:/main.qml")));

        CubeTimer ct(engine.rootObjects().first());
        (void) ct; // Supress unused warning
        rc = app.exec();
    }

    qWarning() << "Cube Timer Exiting with code" << rc;
    return rc;
}
