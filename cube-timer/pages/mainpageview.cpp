#include "mainpageview.h"
#include "defines.h"

#include <QDateTime>

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(MainPageViewCat, "MainPageView")

MainPageView::MainPageView(QObject* rootItem, QObject *parent) :
    QObject(parent),
    m_rootItem(rootItem->findChild<QObject*>("MainPage"))
{
    connect(m_rootItem, SIGNAL(logTime(int,int,int)), this, SLOT(logTime(int,int,int)));
}

MainPageView::~MainPageView(){
    qCDebug(MainPageViewCat) << "~MainPageView()";
}

void MainPageView::logTime(int minutes, int seconds, int miliseconds){
    QVariantHash data;
    data[LOGTIME_MINUTES_I] = minutes;
    data[LOGTIME_SECONDS_I] = seconds;
    data[LOGTIME_MILISECONDS_I] = miliseconds;
    data[LOGTIME_DATETIME_DT] = QDateTime::currentDateTime();
    emit saveTime(data);
    qCDebug(MainPageViewCat) << "LoggingTime" << data;
}
