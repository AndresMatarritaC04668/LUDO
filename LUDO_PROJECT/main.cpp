#include "ControladorLudo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ControladorLudo * controlador = new ControladorLudo();

    return a.exec();
}
