TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lazyChunk.cpp \
    event.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    head.h \
    event.h \
    agent.h \
    publicState.h \
    lazyChunk.h

QMAKE_CXXFLAGS += -std=c++11
