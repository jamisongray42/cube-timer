#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>

class DBHandle;
class MainPageView;
class TimesPageView;

class ViewController : public QObject
{
    Q_OBJECT

    QObject* m_rootItem;

    DBHandle* m_database;

    MainPageView* m_mainPageView;
    TimesPageView* m_timesPageView;

public:
    explicit ViewController(QObject* rootItem, QObject *parent = nullptr);
    ~ViewController();

signals:

public slots:
private slots:
    void createPage(int index);
};

#endif // VIEWCONTROLLER_H
