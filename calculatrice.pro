QMAKE_CXXFLAGS += -std=c++0x
QT += widgets

HEADERS += \
    include.h \
    pile.h \
    calc.h \
    entier.h \
    litteraleCalculable.h \
    item.h \
    litteralemanager.h \
    calcexception.h \
    litterale.h \
    controleur.h

SOURCES += \
    main.cpp \
    pile.cpp \
    calc.cpp \
    entier.cpp \
    litterale.cpp \
    item.cpp \
    controleur.cpp

FORMS +=
