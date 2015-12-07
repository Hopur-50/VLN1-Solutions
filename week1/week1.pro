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
    repositories/scientistrepository.cpp \
    services/scientistservice.cpp \
    utilities/utils.cpp \
    models/computer.cpp \
    models/relation.cpp \
    repositories/computerrepository.cpp \
    utilities/computercomparator.cpp \
    utilities/scientistcomparator.cpp \
    models/relation.cpp \
    ui/interface.cpp
HEADERS += \
    models/scientist.h \
    repositories/scientistrepository.h \
    utilities/utils.h \
    utilities/constants.h \
    services/scientistservice.h \
    utilities/scientistcomparator.h \
    models/computer.h \
    models/relation.h \
    repositories/computerrepository.h \
    ui/interface.h \
    utilities/computercomparator.h
