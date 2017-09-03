#include "dbhandle.h"
#include "defines.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(DBHandleCat, "DBHandle")

DBHandle::DBHandle(QObject *parent) : QObject(parent)
{
}

DBHandle::~DBHandle(){
    qCDebug(DBHandleCat) << "~DBHandle()";
}

bool DBHandle::initDB(QString type, QString dbName){
    QSqlDatabase db = QSqlDatabase::addDatabase(type);
    db.setDatabaseName(dbName);

    if(!db.open()){
        qCWarning(DBHandleCat) << "Error openeing databse" << db.lastError().text();
        return false;
    }

    QStringList tables = db.tables();
    if (tables.contains(TABLE_EVENTS, Qt::CaseInsensitive)
        && tables.contains(TABLE_RUNS, Qt::CaseInsensitive))
        return true; // Already initialized

    //Create the tables
    QSqlQuery q;
    QString errorStr("");
    if (!q.exec((QString)"create table " + TABLE_EVENTS +
                              "(id integer primary key, " +
                              TABLE_EVENTS_TITLE + " varchar, " +
                              TABLE_EVENTS_DESC + " varchar)")){
        errorStr = q.lastError().text();
        if(!errorStr.isEmpty()) return false;
    }

    if (!q.exec((QString)"create table " + TABLE_RUNS +
                              "(id integer primary key, " +
                              TABLE_RUNS_TIME + " time, " +
                              TABLE_RUNS_DATETIME + " datetime, " +
                              TABLE_RUNS_EVENT + " varchar, " +
                              TABLE_RUNS_NOTES + " varchar)")){
        errorStr = q.lastError().text();
        if(!errorStr.isEmpty()) return false;
    }

    addEvent("2x2", "2x2 desc");
    addEvent("3x3", "3x3 desc");
    addEvent("4x4", "4x4 desc");
    addEvent("5x5", "5x5 desc");
    addEvent("6x6", "6x6 desc");
    addEvent("7x7", "7x7 desc");

    return true;
}

bool DBHandle::addEvent(QString title, QString desc){
    QSqlQuery q;
    q.prepare((QString)"insert into " +
                            TABLE_EVENTS + "(" +
                            TABLE_EVENTS_TITLE + ", " +
                            TABLE_EVENTS_DESC + ") values(?, ?)");
    q.addBindValue(title);
    q.addBindValue(desc);
    return q.exec();
}

bool DBHandle::addRun(QTime runTime, QDateTime dateTime, QString event, QString notes){
    QSqlQuery q;
    q.prepare((QString)"insert into " +
                            TABLE_RUNS + "(" +
                            TABLE_RUNS_TIME + ", " +
                            TABLE_RUNS_DATETIME + ", " +
                            TABLE_RUNS_EVENT + ", " +
                            TABLE_RUNS_NOTES + ") values(?, ?, ?, ?)");
    q.addBindValue(runTime);
    q.addBindValue(dateTime);
    q.addBindValue(event);
    q.addBindValue(notes);
    return q.exec();
}

QList<QHash<QString, QVariant>> DBHandle::getRuns(){
    QList<QHash<QString, QVariant>> ret;
    QSqlQuery q("select id, " + (QString)TABLE_RUNS_TIME + ", " TABLE_RUNS_DATETIME + " from " + TABLE_RUNS);
    while(q.next()){
        QHash<QString, QVariant> hash;
        hash[LOGTIME_RUNID_I] = q.value(0).toInt();
        hash[LOGTIME_RUNTIME_T] = q.value(1).toTime();
        hash[LOGTIME_DATETIME_DT] = q.value(2).toDateTime();
        ret.append(hash);
    }

    return ret;
}
