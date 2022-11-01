#include "controlador_ventanas.h"
#include "ui_ventanaprincipal.h"
#include <qstring.h>
#include <QPushButton>
#include <qmessagebox.h>
#include "qinputdialog.h"
#include "tableroLUDO.h"
#include <iostream>
#include "FichaAbstracta.h"

controlador_Ventanas::controlador_Ventanas()
{
    this->ventanaPrincipal = new  VentanaPrincipal();
    this->input = new ventanaInformacion();
}

void controlador_Ventanas::iniciar(){
    ventanaPrincipal->show();


}

void controlador_Ventanas::graficarTablero(TableroAbstracto * mesa){
   TableroLudo * mesaLudo = dynamic_cast< TableroLudo * >(mesa);
   string mensaje = "";
   if(mesaLudo->tablero[0][0]){
     mensaje = mesaLudo->tablero[0][0]->getColor() + std::to_string(mesaLudo->tablero[0][0]->getNumeroFicha()) + "\n";
   }
   if(mesaLudo->tablero[1][0]){
     mensaje += mesaLudo->tablero[1][0]->getColor() + std::to_string(mesaLudo->tablero[1][0]->getNumeroFicha()) + "\n";
   }
   this->ventanaPrincipal->ui->celda_0->setText(QString::fromStdString(mensaje));

   mensaje = "";
    if(mesaLudo->tablero[0][1]){
     mensaje = mesaLudo->tablero[0][1]->getColor() + std::to_string(mesaLudo->tablero[0][1]->getNumeroFicha()) + "\n";
   }
   if(mesaLudo->tablero[1][1]){
     mensaje += mesaLudo->tablero[1][1]->getColor() + std::to_string(mesaLudo->tablero[1][1]->getNumeroFicha()) + "\n";
   }
   this->ventanaPrincipal->ui->celda_1->setText(QString::fromStdString(mensaje));

   mensaje = "" ;
   if(mesaLudo->tablero[0][2]){
   mensaje = mesaLudo->tablero[0][2]->getColor() + std::to_string(mesaLudo->tablero[0][2]->getNumeroFicha()) + " \n";
 }
   if(mesaLudo->tablero[1][2]){
  mensaje += mesaLudo->tablero[1][2]->getColor() + std::to_string(mesaLudo->tablero[1][2]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_2->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][3]){
   mensaje = mesaLudo->tablero[0][3]->getColor() + std::to_string(mesaLudo->tablero[0][3]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][3]){
  mensaje += mesaLudo->tablero[1][3]->getColor() + std::to_string(mesaLudo->tablero[1][3]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_3->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][4]){
   mensaje = mesaLudo->tablero[0][4]->getColor() + std::to_string(mesaLudo->tablero[0][4]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][4]){
  mensaje += mesaLudo->tablero[1][4]->getColor() + std::to_string(mesaLudo->tablero[1][4]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_4->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][5]){
   mensaje = mesaLudo->tablero[0][5]->getColor() + std::to_string(mesaLudo->tablero[0][5]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][5]){
  mensaje += mesaLudo->tablero[1][5]->getColor() + std::to_string(mesaLudo->tablero[1][5]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_5->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][6]){
   mensaje = mesaLudo->tablero[0][6]->getColor() + std::to_string(mesaLudo->tablero[0][6]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][6]){
  mensaje += mesaLudo->tablero[1][6]->getColor() + std::to_string(mesaLudo->tablero[1][6]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_6->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][7]){
   mensaje = mesaLudo->tablero[0][7]->getColor() + std::to_string(mesaLudo->tablero[0][7]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][7]){
  mensaje += mesaLudo->tablero[1][7]->getColor() + std::to_string(mesaLudo->tablero[1][7]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_7->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][8]){
   mensaje = mesaLudo->tablero[0][8]->getColor() + std::to_string(mesaLudo->tablero[0][8]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][8]){
  mensaje += mesaLudo->tablero[1][8]->getColor() + std::to_string(mesaLudo->tablero[1][8]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_8->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][9]){
   mensaje = mesaLudo->tablero[0][9]->getColor() + std::to_string(mesaLudo->tablero[0][9]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][9]){
  mensaje += mesaLudo->tablero[1][9]->getColor() + std::to_string(mesaLudo->tablero[1][9]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_9->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][10]){
   mensaje = mesaLudo->tablero[0][10]->getColor() + std::to_string(mesaLudo->tablero[0][10]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][10]){
  mensaje += mesaLudo->tablero[1][10]->getColor() + std::to_string(mesaLudo->tablero[1][10]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_10->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][11]){
   mensaje = mesaLudo->tablero[0][11]->getColor() + std::to_string(mesaLudo->tablero[0][11]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][11]){
  mensaje += mesaLudo->tablero[1][11]->getColor() + std::to_string(mesaLudo->tablero[1][11]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_11->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][12]){
   mensaje = mesaLudo->tablero[0][12]->getColor() + std::to_string(mesaLudo->tablero[0][12]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][12]){
  mensaje += mesaLudo->tablero[1][12]->getColor() + std::to_string(mesaLudo->tablero[1][12]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_12->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][13]){
   mensaje = mesaLudo->tablero[0][13]->getColor() + std::to_string(mesaLudo->tablero[0][13]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][13]){
  mensaje += mesaLudo->tablero[1][13]->getColor() + std::to_string(mesaLudo->tablero[1][13]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_13->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][14]){
   mensaje = mesaLudo->tablero[0][14]->getColor() + std::to_string(mesaLudo->tablero[0][14]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][14]){
  mensaje += mesaLudo->tablero[1][14]->getColor() + std::to_string(mesaLudo->tablero[1][14]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_14->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][15]){
   mensaje = mesaLudo->tablero[0][15]->getColor() + std::to_string(mesaLudo->tablero[0][15]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][15]){
  mensaje += mesaLudo->tablero[1][15]->getColor() + std::to_string(mesaLudo->tablero[1][15]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_15->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][16]){
   mensaje = mesaLudo->tablero[0][16]->getColor() + std::to_string(mesaLudo->tablero[0][16]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][16]){
  mensaje += mesaLudo->tablero[1][16]->getColor() + std::to_string(mesaLudo->tablero[1][16]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_16->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][17]){
   mensaje = mesaLudo->tablero[0][17]->getColor() + std::to_string(mesaLudo->tablero[0][17]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][17]){
  mensaje += mesaLudo->tablero[1][17]->getColor() + std::to_string(mesaLudo->tablero[1][17]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_17->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][18]){
   mensaje = mesaLudo->tablero[0][18]->getColor() + std::to_string(mesaLudo->tablero[0][18]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][18]){
  mensaje += mesaLudo->tablero[1][18]->getColor() + std::to_string(mesaLudo->tablero[1][18]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_18->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][19]){
   mensaje = mesaLudo->tablero[0][19]->getColor() + std::to_string(mesaLudo->tablero[0][19]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][19]){
  mensaje += mesaLudo->tablero[1][19]->getColor() + std::to_string(mesaLudo->tablero[1][19]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_19->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][20]){
   mensaje = mesaLudo->tablero[0][20]->getColor() + std::to_string(mesaLudo->tablero[0][20]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][20]){
  mensaje += mesaLudo->tablero[1][20]->getColor() + std::to_string(mesaLudo->tablero[1][20]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_20->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][21]){
   mensaje = mesaLudo->tablero[0][21]->getColor() + std::to_string(mesaLudo->tablero[0][21]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][21]){
  mensaje += mesaLudo->tablero[1][21]->getColor() + std::to_string(mesaLudo->tablero[1][21]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_21->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][22]){
   mensaje = mesaLudo->tablero[0][22]->getColor() + std::to_string(mesaLudo->tablero[0][22]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][22]){
  mensaje += mesaLudo->tablero[1][22]->getColor() + std::to_string(mesaLudo->tablero[1][22]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_22->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][23]){
   mensaje = mesaLudo->tablero[0][23]->getColor() + std::to_string(mesaLudo->tablero[0][23]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][23]){
  mensaje += mesaLudo->tablero[1][23]->getColor() + std::to_string(mesaLudo->tablero[1][23]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_23->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][24]){
   mensaje = mesaLudo->tablero[0][24]->getColor() + std::to_string(mesaLudo->tablero[0][24]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][24]){
  mensaje += mesaLudo->tablero[1][24]->getColor() + std::to_string(mesaLudo->tablero[1][24]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_24->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][25]){
   mensaje = mesaLudo->tablero[0][25]->getColor() + std::to_string(mesaLudo->tablero[0][25]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][25]){
  mensaje += mesaLudo->tablero[1][25]->getColor() + std::to_string(mesaLudo->tablero[1][25]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_25->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][26]){
   mensaje = mesaLudo->tablero[0][26]->getColor() + std::to_string(mesaLudo->tablero[0][26]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][26]){
  mensaje += mesaLudo->tablero[1][26]->getColor() + std::to_string(mesaLudo->tablero[1][26]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_26->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][27]){
   mensaje = mesaLudo->tablero[0][27]->getColor() + std::to_string(mesaLudo->tablero[0][27]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][27]){
  mensaje += mesaLudo->tablero[1][27]->getColor() + std::to_string(mesaLudo->tablero[1][27]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_27->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][28]){
   mensaje = mesaLudo->tablero[0][28]->getColor() + std::to_string(mesaLudo->tablero[0][28]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][28]){
  mensaje += mesaLudo->tablero[1][28]->getColor() + std::to_string(mesaLudo->tablero[1][28]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_28->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][29]){
   mensaje = mesaLudo->tablero[0][29]->getColor() + std::to_string(mesaLudo->tablero[0][29]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][29]){
  mensaje += mesaLudo->tablero[1][29]->getColor() + std::to_string(mesaLudo->tablero[1][29]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_29->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][30]){
   mensaje = mesaLudo->tablero[0][30]->getColor() + std::to_string(mesaLudo->tablero[0][30]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][30]){
  mensaje += mesaLudo->tablero[1][30]->getColor() + std::to_string(mesaLudo->tablero[1][30]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_30->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][31]){
   mensaje = mesaLudo->tablero[0][31]->getColor() + std::to_string(mesaLudo->tablero[0][31]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][31]){
  mensaje += mesaLudo->tablero[1][31]->getColor() + std::to_string(mesaLudo->tablero[1][31]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_31->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][32]){
   mensaje = mesaLudo->tablero[0][32]->getColor() + std::to_string(mesaLudo->tablero[0][32]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][32]){
  mensaje += mesaLudo->tablero[1][32]->getColor() + std::to_string(mesaLudo->tablero[1][32]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_32->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][33]){
   mensaje = mesaLudo->tablero[0][33]->getColor() + std::to_string(mesaLudo->tablero[0][33]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][33]){
  mensaje += mesaLudo->tablero[1][33]->getColor() + std::to_string(mesaLudo->tablero[1][33]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_33->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][34]){
   mensaje = mesaLudo->tablero[0][34]->getColor() + std::to_string(mesaLudo->tablero[0][34]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][34]){
  mensaje += mesaLudo->tablero[1][34]->getColor() + std::to_string(mesaLudo->tablero[1][34]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_34->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][35]){
   mensaje = mesaLudo->tablero[0][35]->getColor() + std::to_string(mesaLudo->tablero[0][35]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][35]){
  mensaje += mesaLudo->tablero[1][35]->getColor() + std::to_string(mesaLudo->tablero[1][35]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_35->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][36]){
   mensaje = mesaLudo->tablero[0][36]->getColor() + std::to_string(mesaLudo->tablero[0][36]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][36]){
  mensaje += mesaLudo->tablero[1][36]->getColor() + std::to_string(mesaLudo->tablero[1][36]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_36->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][37]){
   mensaje = mesaLudo->tablero[0][37]->getColor() + std::to_string(mesaLudo->tablero[0][37]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][37]){
  mensaje += mesaLudo->tablero[1][37]->getColor() + std::to_string(mesaLudo->tablero[1][37]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_37->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][38]){
   mensaje = mesaLudo->tablero[0][38]->getColor() + std::to_string(mesaLudo->tablero[0][38]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][38]){
  mensaje += mesaLudo->tablero[1][38]->getColor() + std::to_string(mesaLudo->tablero[1][38]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_38->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][39]){
   mensaje = mesaLudo->tablero[0][39]->getColor() + std::to_string(mesaLudo->tablero[0][39]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][39]){
  mensaje += mesaLudo->tablero[1][39]->getColor() + std::to_string(mesaLudo->tablero[1][39]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_39->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][40]){
   mensaje = mesaLudo->tablero[0][40]->getColor() + std::to_string(mesaLudo->tablero[0][40]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][40]){
  mensaje += mesaLudo->tablero[1][40]->getColor() + std::to_string(mesaLudo->tablero[1][40]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_40->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][41]){
   mensaje = mesaLudo->tablero[0][41]->getColor() + std::to_string(mesaLudo->tablero[0][41]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][41]){
  mensaje += mesaLudo->tablero[1][41]->getColor() + std::to_string(mesaLudo->tablero[1][41]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_41->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][42]){
   mensaje = mesaLudo->tablero[0][42]->getColor() + std::to_string(mesaLudo->tablero[0][42]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][42]){
  mensaje += mesaLudo->tablero[1][42]->getColor() + std::to_string(mesaLudo->tablero[1][42]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_42->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][43]){
   mensaje = mesaLudo->tablero[0][43]->getColor() + std::to_string(mesaLudo->tablero[0][43]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][43]){
  mensaje += mesaLudo->tablero[1][43]->getColor() + std::to_string(mesaLudo->tablero[1][43]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_43->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][44]){
   mensaje = mesaLudo->tablero[0][44]->getColor() + std::to_string(mesaLudo->tablero[0][44]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][44]){
  mensaje += mesaLudo->tablero[1][44]->getColor() + std::to_string(mesaLudo->tablero[1][44]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_44->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][45]){
   mensaje = mesaLudo->tablero[0][45]->getColor() + std::to_string(mesaLudo->tablero[0][45]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][45]){
  mensaje += mesaLudo->tablero[1][45]->getColor() + std::to_string(mesaLudo->tablero[1][45]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_45->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][46]){
   mensaje = mesaLudo->tablero[0][46]->getColor() + std::to_string(mesaLudo->tablero[0][46]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][46]){
  mensaje += mesaLudo->tablero[1][46]->getColor() + std::to_string(mesaLudo->tablero[1][46]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_46->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][47]){
   mensaje = mesaLudo->tablero[0][47]->getColor() + std::to_string(mesaLudo->tablero[0][47]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][47]){
  mensaje += mesaLudo->tablero[1][47]->getColor() + std::to_string(mesaLudo->tablero[1][47]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_47->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][48]){
   mensaje = mesaLudo->tablero[0][48]->getColor() + std::to_string(mesaLudo->tablero[0][48]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][48]){
  mensaje += mesaLudo->tablero[1][48]->getColor() + std::to_string(mesaLudo->tablero[1][48]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_48->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][49]){
   mensaje = mesaLudo->tablero[0][49]->getColor() + std::to_string(mesaLudo->tablero[0][49]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][49]){
  mensaje += mesaLudo->tablero[1][49]->getColor() + std::to_string(mesaLudo->tablero[1][49]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_49->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][50]){
   mensaje = mesaLudo->tablero[0][50]->getColor() + std::to_string(mesaLudo->tablero[0][50]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][50]){
  mensaje += mesaLudo->tablero[1][50]->getColor() + std::to_string(mesaLudo->tablero[1][50]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_50->setText(QString::fromStdString(mensaje));
   mensaje =  "";
   if(mesaLudo->tablero[0][51]){
   mensaje = mesaLudo->tablero[0][51]->getColor() + std::to_string(mesaLudo->tablero[0][51]->getNumeroFicha()) + "\n";
 }
   if(mesaLudo->tablero[1][51]){
  mensaje += mesaLudo->tablero[1][51]->getColor() + std::to_string(mesaLudo->tablero[1][51]->getNumeroFicha()) + "\n";
 }
 this->ventanaPrincipal->ui->celda_51->setText(QString::fromStdString(mensaje));

  graficarLineaFinal(mesa);

}

void controlador_Ventanas::mensajeGrafico(string mensaje){
    QMessageBox::information(input,"Informacion", QString::fromStdString(mensaje));


 }

void controlador_Ventanas::graficarCarcel(vector<Jugador*> jugadores){
    QString mensaje = "";
    Jugador * jugador = jugadores[1];
    std::vector<FichaAbstracta*> fichas = jugador->getFichas();

    if(fichas[0]->getEstado() == false){
       mensaje = QString::fromStdString(fichas[0]->getColor()) + QString::number( fichas[0]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelAzul_1->setText(mensaje);
    } else {
       this->ventanaPrincipal->ui->carcelAzul_1->setText("");
    }

    if(fichas[1]->getEstado() == false){
       mensaje = QString::fromStdString(fichas[1]->getColor()) + QString::number( fichas[1]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelAzul_2->setText(mensaje);
    } else {
       this->ventanaPrincipal->ui->carcelAzul_2->setText("");
    }

    if(fichas[2]->getEstado() == false){
       mensaje = QString::fromStdString(fichas[2]->getColor()) + QString::number( fichas[2]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelAzul_3->setText(mensaje);
    } else {
       this->ventanaPrincipal->ui->carcelAzul_3->setText("");
    }

    if(fichas[3]->getEstado() == false){
       mensaje = QString::fromStdString(fichas[3]->getColor()) + QString::number( fichas[3]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelAzul_4->setText(mensaje);
    } else {
       this->ventanaPrincipal->ui->carcelAzul_4->setText("");
    }

    jugador = jugadores[0];
    fichas = jugador->getFichas();

    if(fichas[0]->getEstado() == false){
       mensaje = QString::fromStdString(fichas[0]->getColor()) + QString::number( fichas[0]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelRoJa_1->setText(mensaje);
    } else {
       this->ventanaPrincipal->ui->carcelRoJa_1->setText("");
    }

    if(fichas[1]->getEstado() == false){
       mensaje = QString::fromStdString(fichas[1]->getColor()) + QString::number( fichas[1]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelRoJa_2->setText(mensaje);
    } else {
       this->ventanaPrincipal->ui->carcelRoJa_2->setText("");
    }

    if(fichas[2]->getEstado() == false){
       mensaje = QString::fromStdString(fichas[2]->getColor()) + QString::number( fichas[2]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelRoJa_3->setText(mensaje);
    } else {
       this->ventanaPrincipal->ui->carcelRoJa_3->setText("");
    }

    if(fichas[3]->getEstado() == false){
       mensaje = QString::fromStdString(fichas[3]->getColor()) + QString::number( fichas[3]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelRoJa_4->setText(mensaje);
    } else {
       this->ventanaPrincipal->ui->carcelRoJa_4->setText("");
    }

    if(jugadores[3]!= nullptr){
        jugador = jugadores[3];
        fichas = jugador->getFichas();

        if(fichas[0]->getEstado() == false){
           mensaje = QString::fromStdString(fichas[0]->getColor()) + QString::number( fichas[0]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelVerde_1->setText(mensaje);
        } else {
           this->ventanaPrincipal->ui->carcelVerde_1->setText("");
        }

        if(fichas[1]->getEstado() == false){
           mensaje = QString::fromStdString(fichas[1]->getColor()) + QString::number( fichas[1]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelVerde_2->setText(mensaje);
        } else {
           this->ventanaPrincipal->ui->carcelVerde_2->setText("");
        }

        if(fichas[2]->getEstado() == false){
           mensaje = QString::fromStdString(fichas[2]->getColor()) + QString::number( fichas[2]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelVerde_3->setText(mensaje);
        } else {
           this->ventanaPrincipal->ui->carcelVerde_3->setText("");
        }

        if(fichas[3]->getEstado() == false){
           mensaje = QString::fromStdString(fichas[3]->getColor()) + QString::number( fichas[3]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelVerde_4->setText(mensaje);
        } else {
           this->ventanaPrincipal->ui->carcelVerde_4->setText("");
        }
    }

    if(jugadores[2]!= nullptr){
        jugador = jugadores[2];
        fichas = jugador->getFichas();

        if(fichas[0]->getEstado() == false){
           mensaje = QString::fromStdString(fichas[0]->getColor()) + QString::number( fichas[0]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelAmarillo_1->setText(mensaje);
        } else {
           this->ventanaPrincipal->ui->carcelAmarillo_1->setText("");
        }

        if(fichas[1]->getEstado() == false){
           mensaje = QString::fromStdString(fichas[1]->getColor()) + QString::number( fichas[1]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelAmarillo_2->setText(mensaje);
        } else {
           this->ventanaPrincipal->ui->carcelAmarillo_2->setText("");
        }

        if(fichas[2]->getEstado() == false){
           mensaje = QString::fromStdString(fichas[2]->getColor()) + QString::number( fichas[2]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelAmarillo_3->setText(mensaje);
        } else {
           this->ventanaPrincipal->ui->carcelAmarillo_3->setText("");
        }

        if(fichas[3]->getEstado() == false){
           mensaje = QString::fromStdString(fichas[3]->getColor()) + QString::number( fichas[3]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelAmarillo_4->setText(mensaje);
        } else {
           this->ventanaPrincipal->ui->carcelAmarillo_4->setText("");
        }
    }



}

void controlador_Ventanas:: graficarLineaFinal(TableroAbstracto * mesa ){

    TableroLudo * mesaLudo = dynamic_cast< TableroLudo * >(mesa);
    Jugador * jugador = mesa->getJugadorActual();
    std::vector<FichaAbstracta*> fichas = jugador->getFichas();
    string mensaje = "";

    if(fichas[0]->getColor() == "ROJO"){
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 55 )
                mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

        }
        this->ventanaPrincipal->ui->seguraRojo_55->setText(QString::fromStdString(mensaje));

        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 56 )
                mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

        }
        this->ventanaPrincipal->ui->seguraRojo_56->setText(QString::fromStdString(mensaje));


        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 57 )
                mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

        }
        this->ventanaPrincipal->ui->seguraRojo_57->setText(QString::fromStdString(mensaje));


        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 58 )
                mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

        }
        this->ventanaPrincipal->ui->seguraRojo_58->setText(QString::fromStdString(mensaje));


        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 59 )
                mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

        }
        this->ventanaPrincipal->ui->seguraRojo_59->setText(QString::fromStdString(mensaje));


        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 60 )
                mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

        }
        this->ventanaPrincipal->ui->seguraRojo_60->setText(QString::fromStdString(mensaje));

    }

     mensaje == "";
     if(fichas[0]->getColor() == "AZUL"){
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 55 )
                     mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

             }
             this->ventanaPrincipal->ui->seguraAzul_55->setText(QString::fromStdString(mensaje));

             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 56 )
                     mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

             }
             this->ventanaPrincipal->ui->seguraAzul_56->setText(QString::fromStdString(mensaje));


             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 57 )
                     mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

             }
             this->ventanaPrincipal->ui->seguraAzul_57->setText(QString::fromStdString(mensaje));


             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 58 )
                     mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

             }
             this->ventanaPrincipal->ui->seguraAzul_58->setText(QString::fromStdString(mensaje));


             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 59 )
                     mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

             }
             this->ventanaPrincipal->ui->seguraAzul_59->setText(QString::fromStdString(mensaje));


             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 60 )
                     mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

             }
             this->ventanaPrincipal->ui->seguraAzul_60->setText(QString::fromStdString(mensaje));

         }

          mensaje == "";
          if(fichas[0]->getColor() == "VERDE"){
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 55 )
                          mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_55->setText(QString::fromStdString(mensaje));

                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 56 )
                          mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_56->setText(QString::fromStdString(mensaje));


                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 57 )
                          mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_57->setText(QString::fromStdString(mensaje));


                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 58 )
                          mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_58->setText(QString::fromStdString(mensaje));


                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 59 )
                          mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_59->setText(QString::fromStdString(mensaje));


                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 60 )
                          mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_60->setText(QString::fromStdString(mensaje));

              }

          mensaje == "";
              if(fichas[0]->getColor() == "AMARILLO"){
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 55 )
                              mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_55->setText(QString::fromStdString(mensaje));

                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 56 )
                              mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_56->setText(QString::fromStdString(mensaje));


                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 57 )
                              mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_57->setText(QString::fromStdString(mensaje));


                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 58 )
                              mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_58->setText(QString::fromStdString(mensaje));


                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 59 )
                              mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_59->setText(QString::fromStdString(mensaje));


                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 60 )
                              mensaje += fichas[i]->getColor() + std::to_string( fichas[i]->getNumeroFicha()) + "\n";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_60->setText(QString::fromStdString(mensaje));

                  }




}



int  controlador_Ventanas::elegirFicha(string mensaje){
  mensaje +=  "\nQue numero de ficha desea elegir: 1,2,3 o 4";
  mensaje += "\n Digita el numero de ficha";
  int opcion = 1;
  opcion = QInputDialog::getInt(this->input,"Elegir ficha",QString::fromStdString(mensaje));

   return opcion;
}
