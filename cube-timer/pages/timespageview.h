#ifndef TIMESPAGEVIEW_H
#define TIMESPAGEVIEW_H

#include <QObject>
#include <QVariant>

#include "viewbase.h"

class TimesPageView : public ViewBase
{
    Q_OBJECT

public:
    explicit TimesPageView(QObject* rootItem, QObject *parent = nullptr);
    ~TimesPageView();

    void initialise();

signals:
public slots:
    void populateTimes(QList<QHash<QString, QVariant>> records);
};

#endif // TIMESPAGEVIEW_H
