include(../RibiLibraries/Rinside.pri)
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11
SOURCES += \
    src/main.cpp \
    src/individual.cpp \
    src/simulation.cpp
    #src/*.cpp

INCLUDEPATH += include
HEADERS += \
    include/*.h
