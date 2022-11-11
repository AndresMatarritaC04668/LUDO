#include "menuopciones.h"
#include "ui_menuopciones.h"

MenuOpciones::MenuOpciones(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuOpciones)
{
    ui->setupUi(this);
}

MenuOpciones::~MenuOpciones()
{
    delete ui;
}

void MenuOpciones::setControlador(ControladorMenuOpciones * controlador){
    this->controlador = controlador;
}

void MenuOpciones::on_botonReglas_clicked()
{
   controlador->mostrarReglas();
}


void MenuOpciones::on_botonRenaudar_clicked()
{
   this->controlador->cerrarVentana(2); // Elige la opcion de jugar
}


void MenuOpciones::on_botonJugar_clicked()
{
  this->controlador->cerrarVentana(1); // Elige la opcion de jugar
}

