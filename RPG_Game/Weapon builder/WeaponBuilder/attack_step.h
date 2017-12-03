#ifndef ATTACK_STEP_H
#define ATTACK_STEP_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDomDocument>

class attack_step : public QHBoxLayout
{
public:
    attack_step();
    ~attack_step();
    QString tLineEdit;
    QString xLineEdit;
    QString yLineEdit;
    QString sxLineEdit;
    QString syLineEdit;
    QString opaLineEdit;
    QString rLineEdit;
    QDomElement effectsDomElement(QDomDocument* mainDocument);
    void loadeffectsDomElement(QDomElement* effectElement);

};

#endif // ATTACK_STEP_H
