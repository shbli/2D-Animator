#include "skeltal_widget.h"
#include "configrationwindow.h"

skeltal_widget::skeltal_widget(ConfigrationWindow* window, QWidget *parent) {
    //adding at least one skeltal box so that the user can add and remove elements as much as they want
    rootBox = new skeltal_hbox(0,window->jointTreeWidget());
    rootBox->configWindow = window;
    window->jointTreeWidget()->addTopLevelItem(rootBox);
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
