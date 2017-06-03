#include "viewcontroller.h"

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(ViewControllerCat, "ViewController")

ViewController::ViewController(QObject* rootItem, QObject *parent) :
    QObject(parent),
    m_rootItem(rootItem)
{
}

ViewController::~ViewController(){
    qCDebug(ViewControllerCat) << "~ViewController()";
}
