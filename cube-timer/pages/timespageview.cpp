#include "timespageview.h"

#include <QTime>

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(TimesPageViewCat, "TimesPageView")

TimesPageView::TimesPageView(QObject* rootItem, QObject *parent)
    : ViewBase(parent)
{
    lookForChild(rootItem, "ViewTimesPage"); // This fails because the page isnt created until its requested
}

TimesPageView::~TimesPageView(){
    qCDebug(TimesPageViewCat) << "~TimesPageView";
}

void TimesPageView::initialise(){

    QTime time(0, 0, 0);
    QList<QPair<int, QTime>> r;
    for(size_t i=0; i<10; ++i)
        r.append(QPair<int, QTime>(i, time.addSecs(i)));
    populateTimes(r);
}

void TimesPageView::populateTimes(QList<QPair<int, QTime>> records){
    qCDebug(TimesPageViewCat) << "Populating Times" << records;
    QMetaObject::invokeMethod(m_rootItem, "clearAll");
    QPair<int, QTime> pair;
    foreach (pair, records) {
        int id(pair.first);
        QTime runTime(pair.second);
        QMetaObject::invokeMethod(m_rootItem, "addTime", Q_ARG(QVariant, id), Q_ARG(QVariant, runTime));
    }
}

