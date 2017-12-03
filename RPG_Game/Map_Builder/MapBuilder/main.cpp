#include <QtGui/QApplication>
#include "global_keys.h"
#include "svg_scene.h"
#include "game_engine.h"
#include "png_scene.h"
#include "splash_screen.h"
#include "startscreen.h"
#ifndef viewerOnly
#include "configrationwindow.h"
#endif

int main(int argc, char *argv[])
{

    QApplication::setGraphicsSystem("raster");

    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("COMPASSGAMES");
    QCoreApplication::setOrganizationDomain("compassgames.net");
    QCoreApplication::setApplicationName("MapBuilder");


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
    dir.mkdir("character");
    dir.cd("character");
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
#ifndef viewerOnly
    ConfigrationWindow w;
    //this is to allow the window to not block any other window
    w.setWindowModality(Qt::NonModal);

    w.showMaximized();
#endif
#endif

#ifdef viewerOnly
    Director::sharedDirector()->startWithScene(startscreen::scene());
#else
    Director::sharedDirector()->startWithScene(svg_scene::scene());
#endif


    if (QCoreApplication::arguments().contains("-speed",Qt::CaseInsensitive)) {
        int indexOfSpeed = QCoreApplication::arguments().indexOf("-speed",0) + 1;
        if (indexOfSpeed < QCoreApplication::arguments().size()) {
            float speed = QCoreApplication::arguments().at(indexOfSpeed).toFloat();
            game_controller::sharedGameController()->playerSpeed = speed;
            game_controller::sharedGameController()->enemySpeed = speed;
            qDebug() << "Speed adjusted to " << speed;
        } else {
            qDebug() << "use -speed then a float, example '-speed 0.5'";
        }
    }

    return app.exec();
}
