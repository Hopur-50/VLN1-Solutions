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
    ui/interface.cpp \
    repositories/scientistrepository.cpp \
    repositories/computerrepository.cpp \
    services/computerservice.cpp
HEADERS += \
    models/scientist.h \
    utilities/utils.h \
    utilities/constants.h \
    services/scientistservice.h \
    models/computer.h \
    ui/interface.h \
    repositories/scientistrepository.h \
    repositories/computerrepository.h \
    services/computerservice.h
