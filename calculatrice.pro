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
    controleur.h \
    rationnel.h \
    reel.h \
    expression.h \
    complexe.h \
    programme.h \
    atome.h \
    atomemanager.h

SOURCES += \
    main.cpp \
    pile.cpp \
    calc.cpp \
    entier.cpp \
    litterale.cpp \
    item.cpp \
    controleur.cpp \
    litteralemanager.cpp \
    rationnel.cpp \
    reel.cpp \
    expression.cpp \
    complexe.cpp \
    programme.cpp \
    atome.cpp

FORMS +=
