#include "viewbase.h"

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(ViewBaseCat, "ViewBase")

ViewBase::ViewBase(QObject *parent)
    : QObject(parent)
    , m_rootItem(nullptr)
{
}

void ViewBase::lookForChild(QObject *rootItem, QString childName){
    if(!isChildFound()){
        m_rootItem = rootItem->findChild<QObject*>(childName);
        if(isChildFound()){
            qCDebug(ViewBaseCat) << "found child" << m_rootItem;
            initialise();
        }
    }
}
