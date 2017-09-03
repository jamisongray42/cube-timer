#ifndef DBHANDLE_H
#define DBHANDLE_H

#include <QObject>
#include <QDateTime>
#include <QTime>

class DBHandle : public QObject
{
    Q_OBJECT
public:
    explicit DBHandle(QObject *parent = nullptr);
    ~DBHandle();

    bool initDB(QString type, QString dbName);
signals:

public slots:
    bool addEvent(QString title, QString desc);
    bool addRun(QTime runTime, QDateTime dateTime, QString event, QString notes);
};

#endif // DBHANDLE_H
