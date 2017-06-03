#ifndef MAINPAGEVIEW_H
#define MAINPAGEVIEW_H

#include <QObject>
#include <QVariantHash>

class MainPageView : public QObject
{
    Q_OBJECT

    QObject* m_rootItem;
public:
    explicit MainPageView(QObject* rootItem, QObject *parent = nullptr);
    ~MainPageView();

signals:
    void saveTime(QVariantHash);

public slots:
private slots:
    void logTime(int minutes, int seconds, int miliseconds);
};

#endif // MAINPAGEVIEW_H
