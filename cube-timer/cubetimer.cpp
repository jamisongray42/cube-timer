#include "cubetimer.h"

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(CubeTimerCat, "CubeTimer")

CubeTimer::CubeTimer(QObject* rootItem, QObject *parent) :
    QObject(parent),
    m_rootItem(rootItem)
{
}

CubeTimer::~CubeTimer(){
    qCDebug(CubeTimerCat) << "~CubeTimer()";
}
