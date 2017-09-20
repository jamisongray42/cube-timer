#include "timespageview.h"
#include "defines.h"

#include <QTime>

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(TimesPageViewCat, "TimesPageView")

TimesPageView::TimesPageView(QObject* rootItem, QObject *parent)
    : ViewBase(parent)
{
    lookForChild(rootItem, "ViewTimesPage");
}

TimesPageView::~TimesPageView(){
    qCDebug(TimesPageViewCat) << "~TimesPageView";
}

void TimesPageView::initialise(){
    return;
    QTime time(0, 0, 0);
    QList<QHash<QString, QVariant>> r;
    for(int i=0; i<100; ++i){
        QHash<QString, QVariant> record;
        record[LOGTIME_RUNID_I] = i;
        record[LOGTIME_RUNTIME_T] = time.addSecs(i).addMSecs((1.0*qrand()/RAND_MAX) * 1000);
        record[LOGTIME_DATETIME_DT] = QDateTime::currentDateTime();
        r.append(record);
    }
    populateTimes(r);
}

void TimesPageView::populateTimes(QList<QHash<QString, QVariant>> records){
    QMetaObject::invokeMethod(m_rootItem, "clearAll");
    QHash<QString, QVariant> r;
    foreach (r, records) {
        QMetaObject::invokeMethod(m_rootItem, "addTime",
                                  Q_ARG(QVariant, r[LOGTIME_RUNID_I]),
                                  Q_ARG(QVariant, r[LOGTIME_RUNTIME_T].toTime().toString(Qt::ISODateWithMs)),
                                  Q_ARG(QVariant, r[LOGTIME_DATETIME_DT].toDateTime().toString(Qt::ISODate)));
    }
}

