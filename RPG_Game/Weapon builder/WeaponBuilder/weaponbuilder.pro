#-------------------------------------------------
#
# Project created by QtCreator 2012-02-11T13:34:06
#
#-------------------------------------------------

include(E:/XP_Shared/QtApps/GameEngine/GameEngine/Srcs/engine.pri)
include(E:/XP_Shared/QtApps/RPG_Game/weapon/weapon.pri)
include(E:\XP_Shared\QtApps\RPG_Game\game_controller\game_controller.pri)
include(E:\XP_Shared\QtApps\RPG_Game\skeltal\skeltal.pri)
include(E:\XP_Shared\QtApps\RPG_Game\character\character.pri)
include(E:\XP_Shared\QtApps\RPG_Game\health_bar\health_bar.pri)
include(E:\XP_Shared\QtApps\RPG_Game\map\map.pri)

#include(/Users/ahmedalshebli/XP_Shared/QtApps/GameEngine/GameEngine/Srcs/engine.pri)
#include(/Users/ahmedalshebli/XP_Shared/QtApps/RPG_Game/weapon/weapon.pri)

QT += xml

TARGET = weaponbuilder
#TEMPLATE = app


SOURCES += main.cpp \
        configrationwindow.cpp \
    svg_scene.cpp \
    png_scene.cpp \
    attackeffects.cpp \
    attack_animation_part.cpp \
    attack_step.cpp

HEADERS  += configrationwindow.h \
    global_keys.h \
    svg_scene.h \
    png_scene.h \
    attackeffects.h \
    attack_animation_part.h \
    attack_step.h

FORMS    += configrationwindow.ui

symbian {
    TARGET.UID3 = 0xe99e5f5a
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    android/AndroidManifest.xml \
    android/res/drawable/icon.png \
    android/res/drawable/logo.png \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/res/layout/splash.xml \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/src/org/kde/necessitas/origo/QtApplication.java

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()


#for macx static building so that app works on any device mac!!
macx {
    #Special case for mac that works, all other devices will use the else case
    dir2.files = /Users/ahmedalshebli/tmp/qt-everywhere-opensource-src-4.8.0/src/gui/mac/qt_menu.nib
    dir2.path = Contents/Resources
    QMAKE_BUNDLE_DATA += dir2
}

