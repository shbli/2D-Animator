#include "skeltal_widget.h"

skeltal_widget::skeltal_widget(QWidget *parent) {
    //adding at least one skeltal box so that the user can add and remove elements as much as they want
    QWidget *widgetmain = new QWidget;
    rootBox = new skeltal_hbox(0,widgetmain);
    widgetmain->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    rootBox->setStretchFactor(widgetmain,1000);
    rootBox->setSizeConstraint(QLayout::SetMinAndMaxSize);
    widgetmain->setLayout(rootBox);
    setWidget(widgetmain);
//    widgetmain->show();
//    widgetmain->show();
//    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

bool skeltal_widget::noChilds() {
    return rootBox->doesntContainChilds();
}

QDomElement skeltal_widget::getSkeltalDomElement(QDomDocument *domDocumnet) {
    return rootBox->partDomElement(domDocumnet);
}

void skeltal_widget::loadFromQDomElement(QDomElement *jointRoot) {
    rootBox->loadFromQDomElement(jointRoot);
}

bool skeltal_widget::checkAnimationValues() {
    return rootBox->checkAnimationValues();
}
