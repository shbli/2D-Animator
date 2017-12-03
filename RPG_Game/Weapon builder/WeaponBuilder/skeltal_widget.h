#ifndef SKELTAL_WIDGET_H
#define SKELTAL_WIDGET_H

#include <QScrollArea>
#include <QDomElement>
#include <skeltal_hbox.h>

class skeltal_widget : public QScrollArea
{
    Q_OBJECT
public:
    explicit skeltal_widget(QWidget *parent = 0);
    skeltal_hbox* rootBox;
    bool noChilds();
signals:
    
public slots:
    QDomElement getSkeltalDomElement(QDomDocument *domDocumnet);
    void loadFromQDomElement(QDomElement* jointRoot);
    bool checkAnimationValues();
};

#endif // SKELTAL_WIDGET_H
