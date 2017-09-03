#ifndef MAINPAGEVIEW_H
#define MAINPAGEVIEW_H

#include <QObject>
#include <QVariantHash>

#include "viewbase.h"

class MainPageView : public ViewBase
{
    Q_OBJECT

public:
    explicit MainPageView(QObject* rootItem, QObject *parent = nullptr);
    ~MainPageView();

    void initialise();

signals:
    void saveTime(QVariantHash);

public slots:
private slots:
    void logTime(int minutes, int seconds, int miliseconds);
};

#endif // MAINPAGEVIEW_H
