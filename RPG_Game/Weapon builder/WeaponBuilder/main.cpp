#include <QtGui/QApplication>
#include "svg_scene.h"
#include "game_engine.h"
#include "configrationwindow.h"

int main(int argc, char *argv[])
{


    QApplication app(argc, argv);

//    QGraphicsView v;
//    QGraphicsScene s;
//    v.setScene(&s);
////    v.setStyleSheet("background-color: rgb(40, 40, 40);");
//    s.addWidget(&w);
////    v.setWindowFlags(Qt::FramelessWindowHint);
//    v.setGeometry(1100,100,555 + 15,800);
//    v.show();

    QCoreApplication::setOrganizationName("COMPASSGAMES");
    QCoreApplication::setOrganizationDomain("compassgames.com");
    QCoreApplication::setApplicationName("WeaponBuilder");


    Director::sharedDirector();

    //this code, until the last QDir is to set the CWD, aka Current Working Directory
    QDir dir(QCoreApplication::applicationDirPath());
    if (dir.dirName().toLower() == "bin")
    {
        dir.cdUp();
    }
#ifdef WIN32
    if (dir.dirName().toLower() == "debug" || dir.dirName().toLower() == "release")
    {
        dir.cdUp();
    }
#endif
#ifdef Q_OS_MAC64
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    dir.mkdir("weapon");
    dir.cd("weapon");
#endif
#ifdef Q_OS_WIN
    dir.mkdir("character");
    dir.cd("character");
#endif
    QDir::setCurrent(dir.absolutePath());
    qDebug() << "Current working directory is " << dir.absolutePath();

    //set up audio playback
    audioManager::setUpAudioManager();

#ifdef COMPUTER
    ConfigrationWindow w;
    //this is to allow the window to not block any other window
    w.setWindowModality(Qt::NonModal);

    w.showMaximized();
#endif

    Director::sharedDirector()->startWithScene(svg_scene::scene());
    return app.exec();
}
