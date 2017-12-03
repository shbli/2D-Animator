#ifndef ATTACKEFFECTS_H
#define ATTACKEFFECTS_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QLineEdit>
#include <QLabel>
#include "attack_animation_part.h"
#include <QDomDocument>
#include <QListWidget>

class attack_animation_part;

class attackEffects : public QObject
{
    Q_OBJECT
public:
    attackEffects(QString name);
    ~attackEffects();
    QString effectName;
    QPushButton* add;
    QLineEdit* soundFile;
    QList <attack_animation_part*> *attackParts;
    void removeChild(attack_animation_part* toBeRemoved);
    int size();
    QListWidget* listWidget;

public slots:
    void on_add_button();
    QDomElement effectsDomElement(QDomDocument* mainDocument);
    void loadeffectsDomElement(QDomElement* effectElement);
};

#endif // ATTACKEFFECTS_H
