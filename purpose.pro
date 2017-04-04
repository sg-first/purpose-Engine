TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    agent.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    world.h \
    stru.h \
    head.h

QMAKE_CXXFLAGS += -std=c++11
