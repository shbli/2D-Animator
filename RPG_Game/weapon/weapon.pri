SrcLoc = $$PWD

INCLUDEPATH += $$SrcLoc

SOURCES += \
    $$SrcLoc/weapon.cpp \
    $$SrcLoc/weapon_effect.cpp \
    ../../weapon/s_attk_obj.cpp

HEADERS += \
    $$SrcLoc/weapon.h \
    $$SrcLoc/weapon_effect.h \
    ../../weapon/s_attk_obj.h
