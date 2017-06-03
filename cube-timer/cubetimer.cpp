#include "cubetimer.h"
#include "viewcontroller.h"
#include "mainpageview.h"

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(CubeTimerCat, "CubeTimer")

CubeTimer::CubeTimer(QObject* rootItem, QObject *parent) :
    QObject(parent),
    m_rootItem(rootItem),
    m_viewController(new ViewController(rootItem, this))
{
}

CubeTimer::~CubeTimer(){
    qCDebug(CubeTimerCat) << "~CubeTimer()";
    delete m_viewController;
}
