#include "ventanainformacion.h"
#include "ui_ventanainformacion.h"

ventanaInformacion::ventanaInformacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanaInformacion)
{
    ui->setupUi(this);
}

ventanaInformacion::~ventanaInformacion()
{
    delete ui;
}
