#include "viewcontroller.h"
#include "dbhandle.h"
#include "viewbase.h"
#include "mainpageview.h"
#include "timespageview.h"
#include "defines.h"

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(ViewControllerCat, "ViewController")

ViewController::ViewController(QObject* rootItem, QObject *parent)
    : QObject(parent)
    , m_rootItem(rootItem)
    , m_database(new DBHandle(this))
    , m_mainPageView(new MainPageView(rootItem, this))
    , m_timesPageView(new TimesPageView(rootItem, this))
{
    connect(m_rootItem, SIGNAL(switchedToPage(int)), this, SLOT(createPage(int)));

    connect(m_mainPageView, &MainPageView::saveTime, this, [&](QVariantHash data)->void{
        QString currentEvent("3x3");
        m_database->addRun(data[LOGTIME_RUNTIME_T].toTime(), data[LOGTIME_DATETIME_DT].toDateTime(), currentEvent, "Notes about this run");
    });

    m_database->initDB("QSQLITE", "data");
}

ViewController::~ViewController(){
    qCDebug(ViewControllerCat) << "~ViewController()";
    delete m_mainPageView;
    delete m_database;
}

void ViewController::createPage(int index){
    switch (index) {
    case -1:  break;
    case 0: m_mainPageView->lookForChild(m_rootItem, "MainPage"); break;
    case 1: m_timesPageView->lookForChild(m_rootItem, "ViewTimesPage"); break;
    default: break;
    }
}
