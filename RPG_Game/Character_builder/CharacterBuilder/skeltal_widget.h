#ifndef SKELTAL_WIDGET_H
#define SKELTAL_WIDGET_H

#include <QScrollArea>
#include <QDomElement>
#include <skeltal_hbox.h>
#include <QTreeWidget>

class skeltal_widget : public QObject
{
    Q_OBJECT
public:
    explicit skeltal_widget(ConfigrationWindow* window, QWidget *parent = 0);
    skeltal_hbox* rootBox;
    bool noChilds();
    QTreeWidget *widgetmain;
signals:
    
public slots:
    QDomElement getSkeltalDomElement(QDomDocument *domDocumnet);
    void loadFromQDomElement(QDomElement* jointRoot);
    bool checkAnimationValues();
};

#endif // SKELTAL_WIDGET_H
