#ifndef VIEWBASE_H
#define VIEWBASE_H

#include <QObject>

class ViewBase : public QObject
{
    Q_OBJECT
public:
    QObject* m_rootItem;

    explicit ViewBase(QObject *parent = nullptr);

    bool isChildFound(){ return m_rootItem;}
    void lookForChild(QObject* rootItem, QString childName);

    virtual void initialise() = 0;
signals:

public slots:
};

#endif // VIEWBASE_H
