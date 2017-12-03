SrcLoc = $$PWD

INCLUDEPATH += $$SrcLoc


SOURCES += \
    $$SrcLoc/map.cpp \
    $$SrcLoc/home.cpp \
    $$SrcLoc/shop_weapon.cpp \
    $$SrcLoc/shop_item.cpp \
    $$SrcLoc/quest_logic.cpp \
    $$SrcLoc/win_message.cpp \
    $$SrcLoc/shop.cpp

HEADERS += \
    $$SrcLoc/map.h \
    $$SrcLoc/home.h \
    $$SrcLoc/shop_weapon.h \
    $$SrcLoc/shop_item.h \
    $$SrcLoc/quest_logic.h \
    $$SrcLoc/win_message.h \
    $$SrcLoc/shop.h
