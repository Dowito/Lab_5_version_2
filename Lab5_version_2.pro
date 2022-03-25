QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auxiliar.cpp \
    bloque.cpp \
    bomba.cpp \
    enemigo.cpp \
    explotion.cpp \
    main.cpp \
    mainwindow.cpp \
    objeto.cpp \
    personaje.cpp

HEADERS += \
    auxiliar.h \
    bloque.h \
    bomba.h \
    enemigo.h \
    explotion.h \
    macros.h \
    mainwindow.h \
    objeto.h \
    personaje.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Sprites.qrc
