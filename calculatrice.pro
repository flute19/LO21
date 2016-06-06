QMAKE_CXXFLAGS += -std=c++0x
QT += widgets

HEADERS += \
    include.h \
    structure.h \
    pile.h \
    auxiliaire.h \
    calc.h \
    entier.h \
    litteraleCalculable.h \
    item.h \
    litterale.h

SOURCES += \
    structure.cpp \
    main.cpp \
    pile.cpp \
    calc.cpp
