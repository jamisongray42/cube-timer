#include "mainpageview.h"
#include "defines.h"

#include <QDateTime>

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(MainPageViewCat, "MainPageView")

MainPageView::MainPageView(QObject* rootItem, QObject *parent)
    : ViewBase(parent)
{
    lookForChild(rootItem, "MainPage");
}

MainPageView::~MainPageView(){
    qCDebug(MainPageViewCat) << "~MainPageView()";
}

void MainPageView::initialise(){
    connect(m_rootItem, SIGNAL(logTime(int,int,int)), this, SLOT(logTime(int,int,int)));
}

void MainPageView::logTime(int minutes, int seconds, int miliseconds){
    QVariantHash data;
    data[LOGTIME_RUNTIME_T] = QTime(0, minutes, seconds, miliseconds);
    data[LOGTIME_DATETIME_DT] = QDateTime::currentDateTime();
    emit saveTime(data);
    qCDebug(MainPageViewCat) << "LoggingTime" << data;
}
