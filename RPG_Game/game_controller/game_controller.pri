SrcLoc = $$PWD

INCLUDEPATH += $$SrcLoc

SOURCES += \
    $$SrcLoc/game_controller.cpp \
    $$SrcLoc/shared_storage.cpp \
    $$SrcLoc/human_char_controller.cpp \
    $$SrcLoc/under_char_elips.cpp \
    $$SrcLoc/human_char_arrow.cpp \
    $$SrcLoc/enemy_char_controller.cpp

HEADERS += \
    $$SrcLoc/game_controller.h  \
    $$SrcLoc/shared_storage.h  \
    $$SrcLoc/human_char_controller.h \
    $$SrcLoc/under_char_elips.h \
    $$SrcLoc/human_char_arrow.h \
    $$SrcLoc/enemy_char_controller.h
