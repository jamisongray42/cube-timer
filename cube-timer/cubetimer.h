#ifndef CUBETIMER_H
#define CUBETIMER_H

#include <QObject>

class ViewController;

class CubeTimer : public QObject
{
    Q_OBJECT

    QObject* m_rootItem;
    ViewController* m_viewController;

public:
    explicit CubeTimer(QObject* rootItem, QObject *parent = 0);
    ~CubeTimer();

signals:

public slots:
};

#endif // CUBETIMER_H
