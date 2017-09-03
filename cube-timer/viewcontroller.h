#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>

class MainPageView;
class DBHandle;

class ViewController : public QObject
{
    Q_OBJECT

    QObject* m_rootItem;
    MainPageView* m_mainPageView;

    DBHandle* m_database;

public:
    explicit ViewController(QObject* rootItem, QObject *parent = nullptr);
    ~ViewController();

signals:

public slots:
};

#endif // VIEWCONTROLLER_H
