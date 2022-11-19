QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += $$PWD

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ConstructorSerializadorJSON.cpp \
    ControladorLudo.cpp \
    Controlador_Memento.cpp \
    DeserializadorJSON.cpp \
    FichaLudo.cpp \
    Hilera.cpp \
    JugadorLudo.cpp \
    Objeto.cpp \
    Regla.cpp \
    TableroLudo.cpp \
    ValidadorLudo.cpp \
    controlador_ventanas.cpp \
    controladormenuopciones.cpp \
    controladorventanaprincipal.cpp \
    main.cpp \
    menuopciones.cpp \
    ventanainformacion.cpp \
    ventanaprincipal.cpp

HEADERS += \
    ConstructorSerializadorAbstracto.h \
    ConstructorSerializadorJSON.h \
    ControladorAbstracto.h \
    ControladorLudo.h \
    Controlador_Memento.h \
    Dado.h \
    DeserializadorAbstracto.h \
    DeserializadorJSON.h \
    FichaAbstracta.h \
    FichaLudo.h \
    Hilera.h \
    Jugador.h \
    JugadorLudo.h \
    Objeto.h \
    ObtAsg.h \
    Regla.h \
    TableroAbstracto.h \
    Validador.h \
    ValidadorLudo.h \
    Valor.h \
    controlador_ventanas.h \
    controladormenuopciones.h \
    controladorventanaprincipal.h \
    menuopciones.h \
    tableroLUDO.h \
    tipo.h \
    ventanainformacion.h \
    ventanaprincipal.h

FORMS += \
    menuopciones.ui \
    ventanainformacion.ui \
    ventanaprincipal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    HD-wallpaper-love-ludo-game-naseeb.jpg \
    LUDO_PROJECT.pro.user
