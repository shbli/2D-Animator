#ifndef DIRECTOR_H
#define DIRECTOR_H

// this is a singletone class, the director is one and can change the scenes as you wish to
//class Scene;

#include <QTimer>
#include <QTime>
#include <QApplication>
#include <QDesktopWidget>
#include "game_config.h"
#include <QDebug>
#include "graphicsscene.h"
#include <QtOpenGL>
#include "textitem.h"
#include "myfastergraphicview.h"

class transitionScene;
class Scene;

class Director : public QObject
{
    Q_OBJECT

private:

    Director();	// hide constructor
    ~Director();	// hide destructor
    Director(const Director &); // hide copy constructor
    Director& operator=(const Director &); // hide assign op
    static Scene *currentscene;
    static Director *director;
    static QMutex mutex;
    static QRect desk;
    static QMainWindow *mainViewWindow;
    QGraphicsTextItem *frameRateText;
    QTime delta;
    QTimer frameSchedular;
    static MyFasterGraphicView *GraphicView;
    bool isRuning;
    graphicsScene *scene;
    QGLWidget* openGLwidget;
    int updateLessTimes;
public:
    void setupDirector();
    QGraphicsView* sharedGraphicView();
    graphicsScene* sharedGraphicScene();
    static Director* sharedDirector();
    QRect winSizeInPixels();
    void startWithScene(Scene *scene);
    void replaceScene(Scene *scene);
    void replaceScene(transitionScene *traSce);
    void pauseView();
    void continueView();

    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };
    void setOrientation(ScreenOrientation orientation);
    static QPointF convertTouchPoint(QPointF oldPoint);

public slots:
    void refreshAndroidScreen();
    void updatedEveryFrameRate();
    void updatedEveryFrameRateOpenGL();
    void transitionDone(Scene* scene);
signals:
    void update(double deltams);
protected:

};

#endif // SHAREDDIRECTOR_H
