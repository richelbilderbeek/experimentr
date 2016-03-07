TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

include(../RibiLibraries/Rinside.pri)

TARGET = ../experimentr/bin/main

HEADERS += \
    src/individual.h \
    src/simulation.h

SOURCES += \
    src/individual.cpp \
    src/main.cpp \
    src/simulation.cpp
