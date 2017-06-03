#include "viewcontroller.h"
#include "mainpageview.h"

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(ViewControllerCat, "ViewController")

ViewController::ViewController(QObject* rootItem, QObject *parent) :
    QObject(parent),
    m_rootItem(rootItem),
    m_mainPageView(new MainPageView(rootItem, this))
{
    connect(m_mainPageView, &MainPageView::saveTime, this, [&](QVariantHash data)->void{
        (void)data; // TODO dispatch to database from here
    });
}

ViewController::~ViewController(){
    qCDebug(ViewControllerCat) << "~ViewController()";
    delete m_mainPageView;
}
