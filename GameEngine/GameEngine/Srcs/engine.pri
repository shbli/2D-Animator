QT += core gui opengl svg

SrcLoc = $$PWD

INCLUDEPATH += $$SrcLoc

#That is because android still doesn't support the QtMultiMediaKit, once available we'll gear it up by removing the !android { and removing closing cairly bracket at the end }

    QT += multimedia

!android {
macx {
    QT += multimedia
}


win {
    QT += multimedia multimediakit
}

CONFIG += mobility
MOBILITY += multimedia

SOURCES += $$SrcLoc/GEInterfaces.cpp \
    $$SrcLoc/GEAudioOut.cpp \
    $$SrcLoc/GEAudioMixer.cpp \
    $$SrcLoc/GEAudioBufferPlayInstance.cpp \
    $$SrcLoc/GEAudioBuffer.cpp
HEADERS += $$SrcLoc/GEInterfaces.h \
    $$SrcLoc/GEAudioOut.h \
    $$SrcLoc/GEAudioMixer.h \
    $$SrcLoc/GEAudioBufferPlayInstance.h \
    $$SrcLoc/GEAudioBuffer.h
}
#android {
#    INCLUDEPATH += /opt/necessitas/Android/Qt/480/armeabi-v7a/include/QtMultimediaKit
#    INCLUDEPATH += /opt/necessitas/Android/Qt/480/armeabi-v7a/include/QtMobility
#}

#after having these, create a folder resourc and add to it all the images, sounds that you want to use in your game

ios:include($$[QMAKE_MKSPECS]/common/ios/qiosapp.conf)

unix:!symbian:!maemo5:!win:!android:!macx {
    #Special case for N950 that works, all other devices will use the else case
    DEFINES+=harmattan
    dir1.files = resourc/*
    dir1.path  = /opt/$${TARGET}
    INSTALLS += dir1
} else : android {
    #Special case for android that works, all other devices will use the else case
    dir1.files = resourc/*
    dir1.path  = /assets
    INSTALLS += dir1
} else : macx {
    #Special case for mac that works, all other devices will use the else case
    dir1.files = resourc
    dir1.path = Contents/Resources
    QMAKE_BUNDLE_DATA += dir1
}
else {
    dir1.source += resourc/*
    DEPLOYMENTFOLDERS = dir1
}

#for macx static building so that app works on any device mac!!
#macx {
#    #Special case for mac that works, all other devices will use the else case
#    dir2.files = /Users/ahmedalshebli/tmp/qt-everywhere-opensource-src-4.8.0/src/gui/mac/qt_menu.nib
#    dir2.path = Contents/Resources
#    QMAKE_BUNDLE_DATA += dir2
#}

SOURCES += \
    $$SrcLoc/transitionscene.cpp \
    $$SrcLoc/textitem.cpp \
    $$SrcLoc/spriteitem.cpp \
    $$SrcLoc/sprite.cpp \
    $$SrcLoc/sequence.cpp \
    $$SrcLoc/scene.cpp \
    $$SrcLoc/node.cpp \
    $$SrcLoc/menuitemlabel.cpp \
    $$SrcLoc/menuitemimage.cpp \
    $$SrcLoc/menuitem.cpp \
    $$SrcLoc/menu.cpp \
    $$SrcLoc/layer.cpp \
    $$SrcLoc/label.cpp \
    $$SrcLoc/graphicsscene.cpp \
    $$SrcLoc/director.cpp \
    $$SrcLoc/audiomanager.cpp \
    $$SrcLoc/action.cpp \
    $$SrcLoc/svgsprite.cpp \
    $$SrcLoc/svgspriteitem.cpp \
    $$SrcLoc/elips.cpp \
    $$SrcLoc/linenode.cpp

HEADERS += \
    $$SrcLoc/transitionscene.h \
    $$SrcLoc/trace.h \
    $$SrcLoc/textitem.h \
    $$SrcLoc/spriteitem.h \
    $$SrcLoc/sprite.h \
    $$SrcLoc/sequence.h \
    $$SrcLoc/scene.h \
    $$SrcLoc/node.h \
    $$SrcLoc/myfastergraphicview.h \
    $$SrcLoc/menuitemlabel.h \
    $$SrcLoc/menuitemimage.h \
    $$SrcLoc/menuitem.h \
    $$SrcLoc/menu.h \
    $$SrcLoc/layer.h \
    $$SrcLoc/label.h \
    $$SrcLoc/graphicsscene.h \
    $$SrcLoc/game_engine.h \
    $$SrcLoc/game_config.h \
    $$SrcLoc/director.h \
    $$SrcLoc/audiomanager.h \
    $$SrcLoc/action.h \
    $$SrcLoc/svgsprite.h \
    $$SrcLoc/svgspriteitem.h \
    $$SrcLoc/elips.h \
    $$SrcLoc/linenode.h
