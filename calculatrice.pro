QMAKE_CXXFLAGS += -std=c++0x
QT += widgets

HEADERS += \
    include.h \
    pile.h \
    auxiliaire.h \
    calc.h \
    entier.h \
    litteraleCalculable.h \
    item.h \
    litteralemanager.h

SOURCES += \
    structure.cpp \
    main.cpp \
    pile.cpp \
    calc.cpp
