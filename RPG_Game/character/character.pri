SrcLoc = $$PWD

INCLUDEPATH += $$SrcLoc


SOURCES += \
    $$SrcLoc/character_base.cpp \
    $$SrcLoc/moving_character.cpp \
    $$SrcLoc/die_effect.cpp

HEADERS += \
    $$SrcLoc/character_base.h \
    $$SrcLoc/moving_character.h \
    $$SrcLoc/die_effect.h
