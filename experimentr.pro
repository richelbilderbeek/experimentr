TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

TARGET = ../experimentr/bin/main

HEADERS += \
    cpp/individual.h \
    cpp/simulation.h

SOURCES += \
    cpp/individual.cpp \
    cpp/main.cpp \
    cpp/simulation.cpp
