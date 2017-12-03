#ifndef HUMAN_CHAR_CONTROLLER_H
#define HUMAN_CHAR_CONTROLLER_H

#include "moving_character.h"
#include "under_char_elips.h"
#include "human_char_arrow.h"
#include "game_controller.h"

/*
  This class is disigned to hold human controlled characters, and take touch input as needed, perform the needed steps on that character
*/

class human_char_controller : public Layer
{
    Q_OBJECT

public:
    human_char_controller();
    //adds a character child, and returns it as a pointer
#ifdef characterbuilder
    character_base* addCharacterFromXML(QString xml_file_name,skeltal_hbox* root = 0);
#else
    character_base* addCharacterFromXML(QString xml_file_name);
#endif
    //under character, attach it to selected characters, with call attach methode
//    under_char_elips* elips;
    //used to attache to it a character, and it's end is moved depnding on user finger position
//    human_char_arrow* arrow;

public slots:
    virtual void touchBegin(QGraphicsSceneMouseEvent *event);
    virtual void touchMove(QGraphicsSceneMouseEvent *event);
    virtual void touchEnd(QGraphicsSceneMouseEvent *event);
    void enable_touch_controls();
private:
    QTime clickTimer;
    QPointF startTouchPos;
    int startCharacterSelectedIndex;
    bool arrowAttached;
    float screenScale;
};

#endif // HUMAN_CHAR_CONTROLLER_H
