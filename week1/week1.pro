QT += core sql
QT -= gui
QT += core sql


TARGET = week1
CONFIG += console
CONFIG -= app_bundle
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cpp \
    models/scientist.cpp \
    services/scientistservice.cpp \
    utilities/utils.cpp \
    models/computer.cpp \
    utilities/computercomparator.cpp \
    utilities/scientistcomparator.cpp \
    ui/interface.cpp \
    repositories/scientistrepository.cpp
HEADERS += \
    models/scientist.h \
    utilities/utils.h \
    utilities/constants.h \
    services/scientistservice.h \
    utilities/scientistcomparator.h \
    models/computer.h \
    ui/interface.h \
    utilities/computercomparator.h \
    repositories/scientistrepository.h
