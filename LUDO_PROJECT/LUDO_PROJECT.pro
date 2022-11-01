QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ControladorLudo.cpp \
    FichaLudo.cpp \
    JugadorLudo.cpp \
    Regla.cpp \
    TableroLudo.cpp \
    ValidadorLudo.cpp \
    controlador_ventanas.cpp \
    main.cpp \
    ventanainformacion.cpp \
    ventanaprincipal.cpp

HEADERS += \
    ControladorAbstracto.h \
    ControladorLudo.h \
    Dado.h \
    FichaAbstracta.h \
    FichaLudo.h \
    Jugador.h \
    JugadorLudo.h \
    Regla.h \
    TableroAbstracto.h \
    Validador.h \
    ValidadorLudo.h \
    controlador_ventanas.h \
    tableroLUDO.h \
    ventanainformacion.h \
    ventanaprincipal.h

FORMS += \
    ventanainformacion.ui \
    ventanaprincipal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    LUDO_PROJECT.pro.user
