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
<<<<<<< HEAD \
    models/relation.cpp \
    repositories/computerrepository.cpp \
    ui/interface.cpp \
    utilities/computercomparator.cpp \
    utilities/scientistcomparator.cpp
    utilities/scientistcomparator.cpp \
    models/relation.cpp \
    ui/interface.cpp
=======
    utilities/scientistcomparator.cpp
    models/relation.cpp
>>>>>>> dc00e4ab57a628b105aca69fd545fc8a21f5c6d4

HEADERS += \
    models/scientist.h \
    repositories/scientistrepository.h \
    utilities/utils.h \
    utilities/constants.h \
    services/scientistservice.h \
    utilities/scientistcomparator.h \
<<<<<<< HEAD \
    models/computer.h \
    models/relation.h \
    repositories/computerrepository.h \
    ui/interface.h \
    utilities/computercomparator.h
    models/computer.h \
    ui/interface.h
=======
    models/computer.h
>>>>>>> dc00e4ab57a628b105aca69fd545fc8a21f5c6d4
    models/relation.h

