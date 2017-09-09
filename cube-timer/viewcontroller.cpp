#include "viewcontroller.h"
#include "dbhandle.h"
#include "viewbase.h"
#include "mainpageview.h"
#include "timespageview.h"
#include "defines.h"
#include "serv/requestmapper.h"

#include "httplistener.h"
using namespace stefanfrings;

#include <QNetworkInterface>

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(ViewControllerCat, "ViewController")

ViewController::ViewController(QObject* rootItem, QObject *parent)
    : QObject(parent)
    , m_rootItem(rootItem)
    , m_database(new DBHandle(this))
    , m_mainPageView(new MainPageView(rootItem, this))
    , m_timesPageView(new TimesPageView(rootItem, this))
    , m_listenerSettings(new QSettings(this))
    , m_httpListener(nullptr)
{
    connect(m_mainPageView, &MainPageView::saveTime, this, [&](QVariantHash data)->void{
        QString currentEvent("3x3");
        m_database->addRun(data[LOGTIME_RUNTIME_T].toTime(), data[LOGTIME_DATETIME_DT].toDateTime(), currentEvent, "Notes about this run");
        updateTimesPage();
    });

    m_database->initDB("QSQLITE", "data");
    updateTimesPage();

    setupServer();
}

ViewController::~ViewController(){
    qCDebug(ViewControllerCat) << "~ViewController()";
    delete m_mainPageView;
    delete m_database;
}

void ViewController::updateTimesPage(){
    m_timesPageView->populateTimes(m_database->getRuns());
}

void ViewController::setupServer(){
    m_listenerSettings->beginGroup("listenerGroup");
    m_listenerSettings->setValue("port", VC_LISTEN_PORT);
    m_listenerSettings->setValue("minThreads", 1);
    m_listenerSettings->setValue("maxThreads", 10);
    m_listenerSettings->setValue("cleanupInterval", 1000);
    m_listenerSettings->setValue("readTimeout", 60000);
    m_listenerSettings->setValue("maxRequestSize", 16000);
    m_listenerSettings->setValue("maxMultiPortSize", 1000000);
    m_httpListener = new HttpListener(m_listenerSettings, new RequestMapper(this), this);

    QString lanAddr("Not Found");
    foreach(QHostAddress address, QNetworkInterface::allAddresses()){
        if(address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)){
            lanAddr = address.toString() + ":" + QString::number(VC_LISTEN_PORT);
            qCDebug(ViewControllerCat) << "LAN addr" << lanAddr;
        }
    }
    m_mainPageView->setLANAddr(lanAddr);
}

