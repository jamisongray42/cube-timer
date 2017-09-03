#ifndef TIMESPAGEVIEW_H
#define TIMESPAGEVIEW_H

#include <QObject>
#include <QTime>

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
    void populateTimes(QList<QPair<int/*id*/, QTime/*runTime*/>> records);
};

#endif // TIMESPAGEVIEW_H
