TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    fraction.cpp \
    fraction-friends.cpp \
    mixednumber.cpp \
    mixednumber-friends.cpp \
    parser.cpp \
    calculate.cpp \
    interface.cpp

HEADERS += \
    fraction.h \
    mixednumber.h \
    parser.h \
    calculate.h \
    myexception.h \
    interface.h
