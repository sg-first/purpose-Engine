TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lazyChunk.cpp \
    event.cpp \
    agent.cpp \
    engine.cpp \
    initmap.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    head.h \
    event.h \
    agent.h \
    lazyChunk.h \
    engine.h \
    initmap.h

QMAKE_CXXFLAGS += -std=c++11
