TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
<<<<<<< HEAD
    circularbuffer.cpp

HEADERS += \
    circularbuffer.h
=======
    circularbuffer.cpp \
    cbiterator.cpp

HEADERS += \
    circularbuffer.h \
    cbiterator.h
>>>>>>> 0f75e1ac74252945ebc483f0af24746237f083ed
