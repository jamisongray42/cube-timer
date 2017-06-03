#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>

class ViewController : public QObject
{
    Q_OBJECT

    QObject* m_rootItem;

public:
    explicit ViewController(QObject* rootItem, QObject *parent = nullptr);
    ~ViewController();

signals:

public slots:
};

#endif // VIEWCONTROLLER_H
