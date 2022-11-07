#include "controladorventanaprincipal.h"
#include "ventanaprincipal.h"
#include "tableroLUDO.h"
#include "ui_ventanaprincipal.h"

ControladorVentanaPrincipal::ControladorVentanaPrincipal(controlador_Ventanas * controlador)
{
  ventanaPrincipal = new VentanaPrincipal();
  this->ventanaPrincipal->setControlador(this);
  this->controlador = controlador;
}

void ControladorVentanaPrincipal::iniciar(){
    this->ventanaPrincipal->show();
}

void ControladorVentanaPrincipal::cerrarVentana(){
    this->ventanaPrincipal->close();
    //abrir menu opciones
}

void ControladorVentanaPrincipal::graficarCeldas(QLabel * label , string color , QString numero){
    if(color == "AZUL"){
     label->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
     "border: 2px solid white;"
     "background-color: rgb(0, 0, 255);"
     "color: rgb(255,255,255)");
     label->setText(numero);
    } else if(color == "ROJO"){
      label->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
      "border: 2px solid white;"
      "background-color: rgb(255, 0, 0);"
      "color: rgb(255,255,255)");
      label->setText(numero);

    } else if(color == "VERDE"){
      label->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                            "border: 2px solid white;"
                            "background-color: rgb(0, 148, 0);"
                            "color: rgb(255,255,255)");
      label->setText(numero);

    } else if(color == "AMARILLO"){
      label->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                           "border: 2px solid white;"
                           "background-color: rgb(216, 216, 0);"
                           "color: rgb(255,255,255)");
      label->setText(numero);

    } else if(color == ""){
      label->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                           "background-color: rgba(0,0,0,0%);"
                           "color: rgb(255,255,255)");
       label->setText("");


    }
}

void ControladorVentanaPrincipal::graficarTablero(TableroAbstracto * mesa){
   TableroLudo * mesaLudo = dynamic_cast< TableroLudo * >(mesa);
   string mensaje = "";
   if(mesaLudo->tablero[0][0]){
     graficarCeldas(this->ventanaPrincipal->ui->I_0,mesaLudo->tablero[0][0]->getColor(),
     QString::number(mesaLudo->tablero[0][0]->getNumeroFicha()));

   } else if(!mesaLudo->tablero[0][0]){
     graficarCeldas(this->ventanaPrincipal->ui->I_0 , "" , "");
   }

   if(mesaLudo->tablero[1][0]){
     graficarCeldas(this->ventanaPrincipal->ui->D_0,mesaLudo->tablero[1][0]->getColor(),
     QString::number(mesaLudo->tablero[1][0]->getNumeroFicha()));

   } else if(!mesaLudo->tablero[1][0]){
     graficarCeldas(this->ventanaPrincipal->ui->D_0 , "" , "");
   }

   if(mesaLudo->tablero[0][1]){
       graficarCeldas(this->ventanaPrincipal->ui->I_1,mesaLudo->tablero[0][1]->getColor(),
       QString::number(mesaLudo->tablero[0][1]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][1]){
       graficarCeldas(this->ventanaPrincipal->ui->I_1 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][1]){
       graficarCeldas(this->ventanaPrincipal->ui->D_1,mesaLudo->tablero[1][1]->getColor(),
       QString::number(mesaLudo->tablero[1][1]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][1]){
       graficarCeldas(this->ventanaPrincipal->ui->D_1, "" ,"" );
   }

   if(mesaLudo->tablero[0][2]){
       graficarCeldas(this->ventanaPrincipal->ui->I_2,mesaLudo->tablero[0][2]->getColor(),
       QString::number(mesaLudo->tablero[0][2]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][2]){
       graficarCeldas(this->ventanaPrincipal->ui->I_2 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][2]){
       graficarCeldas(this->ventanaPrincipal->ui->D_2,mesaLudo->tablero[1][2]->getColor(),
       QString::number(mesaLudo->tablero[1][2]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][2]){
       graficarCeldas(this->ventanaPrincipal->ui->D_2,  "", "");
   }

   if(mesaLudo->tablero[0][3]){
       graficarCeldas(this->ventanaPrincipal->ui->I_3,mesaLudo->tablero[0][3]->getColor(),
       QString::number(mesaLudo->tablero[0][3]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][3]){
       graficarCeldas(this->ventanaPrincipal->ui->I_3 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][3]){
       graficarCeldas(this->ventanaPrincipal->ui->D_3,mesaLudo->tablero[1][3]->getColor(),
       QString::number(mesaLudo->tablero[1][3]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][3]){
       graficarCeldas(this->ventanaPrincipal->ui->D_3,  "", "");
   }

   if(mesaLudo->tablero[0][4]){
       graficarCeldas(this->ventanaPrincipal->ui->I_4,mesaLudo->tablero[0][4]->getColor(),
       QString::number(mesaLudo->tablero[0][4]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][4]){
       graficarCeldas(this->ventanaPrincipal->ui->I_4 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][4]){
       graficarCeldas(this->ventanaPrincipal->ui->D_4,mesaLudo->tablero[1][4]->getColor(),
       QString::number(mesaLudo->tablero[1][4]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][4]){
       graficarCeldas(this->ventanaPrincipal->ui->D_4,  "", "");
   }

   if(mesaLudo->tablero[0][5]){
       graficarCeldas(this->ventanaPrincipal->ui->I_5,mesaLudo->tablero[0][5]->getColor(),
       QString::number(mesaLudo->tablero[0][5]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][5]){
       graficarCeldas(this->ventanaPrincipal->ui->I_5 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][5]){
       graficarCeldas(this->ventanaPrincipal->ui->D_5,mesaLudo->tablero[1][5]->getColor(),
       QString::number(mesaLudo->tablero[1][5]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][5]){
       graficarCeldas(this->ventanaPrincipal->ui->D_5,  "", "");
   }

   if(mesaLudo->tablero[0][6]){
       graficarCeldas(this->ventanaPrincipal->ui->I_6,mesaLudo->tablero[0][6]->getColor(),
       QString::number(mesaLudo->tablero[0][6]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][6]){
       graficarCeldas(this->ventanaPrincipal->ui->I_6 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][6]){
       graficarCeldas(this->ventanaPrincipal->ui->D_6,mesaLudo->tablero[1][6]->getColor(),
       QString::number(mesaLudo->tablero[1][6]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][6]){
       graficarCeldas(this->ventanaPrincipal->ui->D_6,  "", "");
   }

   if(mesaLudo->tablero[0][7]){
       graficarCeldas(this->ventanaPrincipal->ui->I_7,mesaLudo->tablero[0][7]->getColor(),
       QString::number(mesaLudo->tablero[0][7]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][7]){
       graficarCeldas(this->ventanaPrincipal->ui->I_7 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][7]){
       graficarCeldas(this->ventanaPrincipal->ui->D_7,mesaLudo->tablero[1][7]->getColor(),
       QString::number(mesaLudo->tablero[1][7]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][7]){
       graficarCeldas(this->ventanaPrincipal->ui->D_7,  "", "");
   }

   if(mesaLudo->tablero[0][8]){
       graficarCeldas(this->ventanaPrincipal->ui->I_8,mesaLudo->tablero[0][8]->getColor(),
       QString::number(mesaLudo->tablero[0][8]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][8]){
       graficarCeldas(this->ventanaPrincipal->ui->I_8 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][8]){
       graficarCeldas(this->ventanaPrincipal->ui->D_8,mesaLudo->tablero[1][8]->getColor(),
       QString::number(mesaLudo->tablero[1][8]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][8]){
       graficarCeldas(this->ventanaPrincipal->ui->D_8,  "", "");
   }

   if(mesaLudo->tablero[0][9]){
       graficarCeldas(this->ventanaPrincipal->ui->I_9,mesaLudo->tablero[0][9]->getColor(),
       QString::number(mesaLudo->tablero[0][9]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][9]){
       graficarCeldas(this->ventanaPrincipal->ui->I_9 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][9]){
       graficarCeldas(this->ventanaPrincipal->ui->D_9,mesaLudo->tablero[1][9]->getColor(),
       QString::number(mesaLudo->tablero[1][9]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][9]){
       graficarCeldas(this->ventanaPrincipal->ui->D_9,  "", "");
   }

   if(mesaLudo->tablero[0][10]){
       graficarCeldas(this->ventanaPrincipal->ui->I_10,mesaLudo->tablero[0][10]->getColor(),
       QString::number(mesaLudo->tablero[0][10]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][10]){
       graficarCeldas(this->ventanaPrincipal->ui->I_10 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][10]){
       graficarCeldas(this->ventanaPrincipal->ui->D_10,mesaLudo->tablero[1][10]->getColor(),
       QString::number(mesaLudo->tablero[1][10]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][10]){
       graficarCeldas(this->ventanaPrincipal->ui->D_10,  "", "");
   }

   if(mesaLudo->tablero[0][11]){
       graficarCeldas(this->ventanaPrincipal->ui->I_11,mesaLudo->tablero[0][11]->getColor(),
       QString::number(mesaLudo->tablero[0][11]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][11]){
       graficarCeldas(this->ventanaPrincipal->ui->I_11 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][11]){
       graficarCeldas(this->ventanaPrincipal->ui->D_11,mesaLudo->tablero[1][11]->getColor(),
       QString::number(mesaLudo->tablero[1][11]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][11]){
       graficarCeldas(this->ventanaPrincipal->ui->D_11,  "", "");
   }

   if(mesaLudo->tablero[0][12]){
       graficarCeldas(this->ventanaPrincipal->ui->I_12,mesaLudo->tablero[0][12]->getColor(),
       QString::number(mesaLudo->tablero[0][12]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][12]){
       graficarCeldas(this->ventanaPrincipal->ui->I_12 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][12]){
       graficarCeldas(this->ventanaPrincipal->ui->D_12,mesaLudo->tablero[1][12]->getColor(),
       QString::number(mesaLudo->tablero[1][12]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][12]){
       graficarCeldas(this->ventanaPrincipal->ui->D_12,  "", "");
   }

   if(mesaLudo->tablero[0][13]){
       graficarCeldas(this->ventanaPrincipal->ui->I_13,mesaLudo->tablero[0][13]->getColor(),
       QString::number(mesaLudo->tablero[0][13]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][13]){
       graficarCeldas(this->ventanaPrincipal->ui->I_13 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][13]){
       graficarCeldas(this->ventanaPrincipal->ui->D_13,mesaLudo->tablero[1][13]->getColor(),
       QString::number(mesaLudo->tablero[1][13]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][13]){
       graficarCeldas(this->ventanaPrincipal->ui->D_13,  "", "");
   }

   if(mesaLudo->tablero[0][14]){
       graficarCeldas(this->ventanaPrincipal->ui->I_14,mesaLudo->tablero[0][14]->getColor(),
       QString::number(mesaLudo->tablero[0][14]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][14]){
       graficarCeldas(this->ventanaPrincipal->ui->I_14 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][14]){
       graficarCeldas(this->ventanaPrincipal->ui->D_14,mesaLudo->tablero[1][14]->getColor(),
       QString::number(mesaLudo->tablero[1][14]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][14]){
       graficarCeldas(this->ventanaPrincipal->ui->D_14,  "", "");
   }

   if(mesaLudo->tablero[0][15]){
       graficarCeldas(this->ventanaPrincipal->ui->I_15,mesaLudo->tablero[0][15]->getColor(),
       QString::number(mesaLudo->tablero[0][15]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][15]){
       graficarCeldas(this->ventanaPrincipal->ui->I_15 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][15]){
       graficarCeldas(this->ventanaPrincipal->ui->D_15,mesaLudo->tablero[1][15]->getColor(),
       QString::number(mesaLudo->tablero[1][15]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][15]){
       graficarCeldas(this->ventanaPrincipal->ui->D_15,  "", "");
   }

   if(mesaLudo->tablero[0][16]){
       graficarCeldas(this->ventanaPrincipal->ui->I_16,mesaLudo->tablero[0][16]->getColor(),
       QString::number(mesaLudo->tablero[0][16]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][16]){
       graficarCeldas(this->ventanaPrincipal->ui->I_16 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][16]){
       graficarCeldas(this->ventanaPrincipal->ui->D_16,mesaLudo->tablero[1][16]->getColor(),
       QString::number(mesaLudo->tablero[1][16]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][16]){
       graficarCeldas(this->ventanaPrincipal->ui->D_16,  "", "");
   }

   if(mesaLudo->tablero[0][17]){
       graficarCeldas(this->ventanaPrincipal->ui->I_17,mesaLudo->tablero[0][17]->getColor(),
       QString::number(mesaLudo->tablero[0][17]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][17]){
       graficarCeldas(this->ventanaPrincipal->ui->I_17 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][17]){
       graficarCeldas(this->ventanaPrincipal->ui->D_17,mesaLudo->tablero[1][17]->getColor(),
       QString::number(mesaLudo->tablero[1][17]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][17]){
       graficarCeldas(this->ventanaPrincipal->ui->D_17,  "", "");
   }

   if(mesaLudo->tablero[0][18]){
       graficarCeldas(this->ventanaPrincipal->ui->I_18,mesaLudo->tablero[0][18]->getColor(),
       QString::number(mesaLudo->tablero[0][18]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][18]){
       graficarCeldas(this->ventanaPrincipal->ui->I_18 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][18]){
       graficarCeldas(this->ventanaPrincipal->ui->D_18,mesaLudo->tablero[1][18]->getColor(),
       QString::number(mesaLudo->tablero[1][18]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][18]){
       graficarCeldas(this->ventanaPrincipal->ui->D_18,  "", "");
   }

   if(mesaLudo->tablero[0][19]){
       graficarCeldas(this->ventanaPrincipal->ui->I_19,mesaLudo->tablero[0][19]->getColor(),
       QString::number(mesaLudo->tablero[0][19]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][19]){
       graficarCeldas(this->ventanaPrincipal->ui->I_19 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][19]){
       graficarCeldas(this->ventanaPrincipal->ui->D_19,mesaLudo->tablero[1][19]->getColor(),
       QString::number(mesaLudo->tablero[1][19]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][19]){
       graficarCeldas(this->ventanaPrincipal->ui->D_19,  "", "");
   }

   if(mesaLudo->tablero[0][20]){
       graficarCeldas(this->ventanaPrincipal->ui->I_20,mesaLudo->tablero[0][20]->getColor(),
       QString::number(mesaLudo->tablero[0][20]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][20]){
       graficarCeldas(this->ventanaPrincipal->ui->I_20 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][20]){
       graficarCeldas(this->ventanaPrincipal->ui->D_20,mesaLudo->tablero[1][20]->getColor(),
       QString::number(mesaLudo->tablero[1][20]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][20]){
       graficarCeldas(this->ventanaPrincipal->ui->D_20,  "", "");
   }

   if(mesaLudo->tablero[0][21]){
       graficarCeldas(this->ventanaPrincipal->ui->I_21,mesaLudo->tablero[0][21]->getColor(),
       QString::number(mesaLudo->tablero[0][21]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][21]){
       graficarCeldas(this->ventanaPrincipal->ui->I_21 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][21]){
       graficarCeldas(this->ventanaPrincipal->ui->D_21,mesaLudo->tablero[1][21]->getColor(),
       QString::number(mesaLudo->tablero[1][21]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][21]){
       graficarCeldas(this->ventanaPrincipal->ui->D_21,  "", "");
   }

   if(mesaLudo->tablero[0][22]){
       graficarCeldas(this->ventanaPrincipal->ui->I_22,mesaLudo->tablero[0][22]->getColor(),
       QString::number(mesaLudo->tablero[0][22]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][22]){
       graficarCeldas(this->ventanaPrincipal->ui->I_22 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][22]){
       graficarCeldas(this->ventanaPrincipal->ui->D_22,mesaLudo->tablero[1][22]->getColor(),
       QString::number(mesaLudo->tablero[1][22]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][22]){
       graficarCeldas(this->ventanaPrincipal->ui->D_22,  "", "");
   }

   if(mesaLudo->tablero[0][23]){
       graficarCeldas(this->ventanaPrincipal->ui->I_23,mesaLudo->tablero[0][23]->getColor(),
       QString::number(mesaLudo->tablero[0][23]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][23]){
       graficarCeldas(this->ventanaPrincipal->ui->I_23 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][23]){
       graficarCeldas(this->ventanaPrincipal->ui->D_23,mesaLudo->tablero[1][23]->getColor(),
       QString::number(mesaLudo->tablero[1][23]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][23]){
       graficarCeldas(this->ventanaPrincipal->ui->D_23,  "", "");
   }

   if(mesaLudo->tablero[0][24]){
       graficarCeldas(this->ventanaPrincipal->ui->I_24,mesaLudo->tablero[0][24]->getColor(),
       QString::number(mesaLudo->tablero[0][24]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][24]){
       graficarCeldas(this->ventanaPrincipal->ui->I_24 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][24]){
       graficarCeldas(this->ventanaPrincipal->ui->D_24,mesaLudo->tablero[1][24]->getColor(),
       QString::number(mesaLudo->tablero[1][24]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][24]){
       graficarCeldas(this->ventanaPrincipal->ui->D_24,  "", "");
   }

   if(mesaLudo->tablero[0][25]){
       graficarCeldas(this->ventanaPrincipal->ui->I_25,mesaLudo->tablero[0][25]->getColor(),
       QString::number(mesaLudo->tablero[0][25]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][25]){
       graficarCeldas(this->ventanaPrincipal->ui->I_25 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][25]){
       graficarCeldas(this->ventanaPrincipal->ui->D_25,mesaLudo->tablero[1][25]->getColor(),
       QString::number(mesaLudo->tablero[1][25]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][25]){
       graficarCeldas(this->ventanaPrincipal->ui->D_25,  "", "");
   }

   if(mesaLudo->tablero[0][26]){
       graficarCeldas(this->ventanaPrincipal->ui->I_26,mesaLudo->tablero[0][26]->getColor(),
       QString::number(mesaLudo->tablero[0][26]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][26]){
       graficarCeldas(this->ventanaPrincipal->ui->I_26 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][26]){
       graficarCeldas(this->ventanaPrincipal->ui->D_26,mesaLudo->tablero[1][26]->getColor(),
       QString::number(mesaLudo->tablero[1][26]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][26]){
       graficarCeldas(this->ventanaPrincipal->ui->D_26,  "", "");
   }

   if(mesaLudo->tablero[0][27]){
       graficarCeldas(this->ventanaPrincipal->ui->I_27,mesaLudo->tablero[0][27]->getColor(),
       QString::number(mesaLudo->tablero[0][27]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][27]){
       graficarCeldas(this->ventanaPrincipal->ui->I_27 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][27]){
       graficarCeldas(this->ventanaPrincipal->ui->D_27,mesaLudo->tablero[1][27]->getColor(),
       QString::number(mesaLudo->tablero[1][27]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][27]){
       graficarCeldas(this->ventanaPrincipal->ui->D_27,  "", "");
   }

   if(mesaLudo->tablero[0][28]){
       graficarCeldas(this->ventanaPrincipal->ui->I_28,mesaLudo->tablero[0][28]->getColor(),
       QString::number(mesaLudo->tablero[0][28]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][28]){
       graficarCeldas(this->ventanaPrincipal->ui->I_28 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][28]){
       graficarCeldas(this->ventanaPrincipal->ui->D_28,mesaLudo->tablero[1][28]->getColor(),
       QString::number(mesaLudo->tablero[1][28]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][28]){
       graficarCeldas(this->ventanaPrincipal->ui->D_28,  "", "");
   }

   if(mesaLudo->tablero[0][29]){
       graficarCeldas(this->ventanaPrincipal->ui->I_29,mesaLudo->tablero[0][29]->getColor(),
       QString::number(mesaLudo->tablero[0][29]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][29]){
       graficarCeldas(this->ventanaPrincipal->ui->I_29 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][29]){
       graficarCeldas(this->ventanaPrincipal->ui->D_29,mesaLudo->tablero[1][29]->getColor(),
       QString::number(mesaLudo->tablero[1][29]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][29]){
       graficarCeldas(this->ventanaPrincipal->ui->D_29,  "", "");
   }

   if(mesaLudo->tablero[0][30]){
       graficarCeldas(this->ventanaPrincipal->ui->I_30,mesaLudo->tablero[0][30]->getColor(),
       QString::number(mesaLudo->tablero[0][30]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][30]){
       graficarCeldas(this->ventanaPrincipal->ui->I_30 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][30]){
       graficarCeldas(this->ventanaPrincipal->ui->D_30,mesaLudo->tablero[1][30]->getColor(),
       QString::number(mesaLudo->tablero[1][30]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][30]){
       graficarCeldas(this->ventanaPrincipal->ui->D_30,  "", "");
   }

   if(mesaLudo->tablero[0][31]){
       graficarCeldas(this->ventanaPrincipal->ui->I_31,mesaLudo->tablero[0][31]->getColor(),
       QString::number(mesaLudo->tablero[0][31]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][31]){
       graficarCeldas(this->ventanaPrincipal->ui->I_31 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][31]){
       graficarCeldas(this->ventanaPrincipal->ui->D_31,mesaLudo->tablero[1][31]->getColor(),
       QString::number(mesaLudo->tablero[1][31]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][31]){
       graficarCeldas(this->ventanaPrincipal->ui->D_31,  "", "");
   }

   if(mesaLudo->tablero[0][32]){
       graficarCeldas(this->ventanaPrincipal->ui->I_32,mesaLudo->tablero[0][32]->getColor(),
       QString::number(mesaLudo->tablero[0][32]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][32]){
       graficarCeldas(this->ventanaPrincipal->ui->I_32 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][32]){
       graficarCeldas(this->ventanaPrincipal->ui->D_32,mesaLudo->tablero[1][32]->getColor(),
       QString::number(mesaLudo->tablero[1][32]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][32]){
       graficarCeldas(this->ventanaPrincipal->ui->D_32,  "", "");
   }

   if(mesaLudo->tablero[0][33]){
       graficarCeldas(this->ventanaPrincipal->ui->I_33,mesaLudo->tablero[0][33]->getColor(),
       QString::number(mesaLudo->tablero[0][33]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][33]){
       graficarCeldas(this->ventanaPrincipal->ui->I_33 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][33]){
       graficarCeldas(this->ventanaPrincipal->ui->D_33,mesaLudo->tablero[1][33]->getColor(),
       QString::number(mesaLudo->tablero[1][33]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][33]){
       graficarCeldas(this->ventanaPrincipal->ui->D_33,  "", "");
   }

   if(mesaLudo->tablero[0][34]){
       graficarCeldas(this->ventanaPrincipal->ui->I_34,mesaLudo->tablero[0][34]->getColor(),
       QString::number(mesaLudo->tablero[0][34]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][34]){
       graficarCeldas(this->ventanaPrincipal->ui->I_34 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][34]){
       graficarCeldas(this->ventanaPrincipal->ui->D_34,mesaLudo->tablero[1][34]->getColor(),
       QString::number(mesaLudo->tablero[1][34]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][34]){
       graficarCeldas(this->ventanaPrincipal->ui->D_34,  "", "");
   }

   if(mesaLudo->tablero[0][35]){
       graficarCeldas(this->ventanaPrincipal->ui->I_35,mesaLudo->tablero[0][35]->getColor(),
       QString::number(mesaLudo->tablero[0][35]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][35]){
       graficarCeldas(this->ventanaPrincipal->ui->I_35 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][35]){
       graficarCeldas(this->ventanaPrincipal->ui->D_35,mesaLudo->tablero[1][35]->getColor(),
       QString::number(mesaLudo->tablero[1][35]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][35]){
       graficarCeldas(this->ventanaPrincipal->ui->D_35,  "", "");
   }

   if(mesaLudo->tablero[0][36]){
       graficarCeldas(this->ventanaPrincipal->ui->I_36,mesaLudo->tablero[0][36]->getColor(),
       QString::number(mesaLudo->tablero[0][36]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][36]){
       graficarCeldas(this->ventanaPrincipal->ui->I_36 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][36]){
       graficarCeldas(this->ventanaPrincipal->ui->D_36,mesaLudo->tablero[1][36]->getColor(),
       QString::number(mesaLudo->tablero[1][36]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][36]){
       graficarCeldas(this->ventanaPrincipal->ui->D_36,  "", "");
   }

   if(mesaLudo->tablero[0][37]){
       graficarCeldas(this->ventanaPrincipal->ui->I_37,mesaLudo->tablero[0][37]->getColor(),
       QString::number(mesaLudo->tablero[0][37]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][37]){
       graficarCeldas(this->ventanaPrincipal->ui->I_37 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][37]){
       graficarCeldas(this->ventanaPrincipal->ui->D_37,mesaLudo->tablero[1][37]->getColor(),
       QString::number(mesaLudo->tablero[1][37]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][37]){
       graficarCeldas(this->ventanaPrincipal->ui->D_37,  "", "");
   }

   if(mesaLudo->tablero[0][38]){
       graficarCeldas(this->ventanaPrincipal->ui->I_38,mesaLudo->tablero[0][38]->getColor(),
       QString::number(mesaLudo->tablero[0][38]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][38]){
       graficarCeldas(this->ventanaPrincipal->ui->I_38 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][38]){
       graficarCeldas(this->ventanaPrincipal->ui->D_38,mesaLudo->tablero[1][38]->getColor(),
       QString::number(mesaLudo->tablero[1][38]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][38]){
       graficarCeldas(this->ventanaPrincipal->ui->D_38,  "", "");
   }

   if(mesaLudo->tablero[0][39]){
       graficarCeldas(this->ventanaPrincipal->ui->I_39,mesaLudo->tablero[0][39]->getColor(),
       QString::number(mesaLudo->tablero[0][39]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][39]){
       graficarCeldas(this->ventanaPrincipal->ui->I_39 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][39]){
       graficarCeldas(this->ventanaPrincipal->ui->D_39,mesaLudo->tablero[1][39]->getColor(),
       QString::number(mesaLudo->tablero[1][39]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][39]){
       graficarCeldas(this->ventanaPrincipal->ui->D_39,  "", "");
   }

   if(mesaLudo->tablero[0][40]){
       graficarCeldas(this->ventanaPrincipal->ui->I_40,mesaLudo->tablero[0][40]->getColor(),
       QString::number(mesaLudo->tablero[0][40]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][40]){
       graficarCeldas(this->ventanaPrincipal->ui->I_40 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][40]){
       graficarCeldas(this->ventanaPrincipal->ui->D_40,mesaLudo->tablero[1][40]->getColor(),
       QString::number(mesaLudo->tablero[1][40]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][40]){
       graficarCeldas(this->ventanaPrincipal->ui->D_40,  "", "");
   }

   if(mesaLudo->tablero[0][41]){
       graficarCeldas(this->ventanaPrincipal->ui->I_41,mesaLudo->tablero[0][41]->getColor(),
       QString::number(mesaLudo->tablero[0][41]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][41]){
       graficarCeldas(this->ventanaPrincipal->ui->I_41 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][41]){
       graficarCeldas(this->ventanaPrincipal->ui->D_41,mesaLudo->tablero[1][41]->getColor(),
       QString::number(mesaLudo->tablero[1][41]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][41]){
       graficarCeldas(this->ventanaPrincipal->ui->D_41,  "", "");
   }

   if(mesaLudo->tablero[0][42]){
       graficarCeldas(this->ventanaPrincipal->ui->I_42,mesaLudo->tablero[0][42]->getColor(),
       QString::number(mesaLudo->tablero[0][42]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][42]){
       graficarCeldas(this->ventanaPrincipal->ui->I_42 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][42]){
       graficarCeldas(this->ventanaPrincipal->ui->D_42,mesaLudo->tablero[1][42]->getColor(),
       QString::number(mesaLudo->tablero[1][42]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][42]){
       graficarCeldas(this->ventanaPrincipal->ui->D_42,  "", "");
   }

   if(mesaLudo->tablero[0][43]){
       graficarCeldas(this->ventanaPrincipal->ui->I_43,mesaLudo->tablero[0][43]->getColor(),
       QString::number(mesaLudo->tablero[0][43]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][43]){
       graficarCeldas(this->ventanaPrincipal->ui->I_43 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][43]){
       graficarCeldas(this->ventanaPrincipal->ui->D_43,mesaLudo->tablero[1][43]->getColor(),
       QString::number(mesaLudo->tablero[1][43]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][43]){
       graficarCeldas(this->ventanaPrincipal->ui->D_43,  "", "");
   }

   if(mesaLudo->tablero[0][44]){
       graficarCeldas(this->ventanaPrincipal->ui->I_44,mesaLudo->tablero[0][44]->getColor(),
       QString::number(mesaLudo->tablero[0][44]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][44]){
       graficarCeldas(this->ventanaPrincipal->ui->I_44 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][44]){
       graficarCeldas(this->ventanaPrincipal->ui->D_44,mesaLudo->tablero[1][44]->getColor(),
       QString::number(mesaLudo->tablero[1][44]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][44]){
       graficarCeldas(this->ventanaPrincipal->ui->D_44,  "", "");
   }

   if(mesaLudo->tablero[0][45]){
       graficarCeldas(this->ventanaPrincipal->ui->I_45,mesaLudo->tablero[0][45]->getColor(),
       QString::number(mesaLudo->tablero[0][45]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][45]){
       graficarCeldas(this->ventanaPrincipal->ui->I_45 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][45]){
       graficarCeldas(this->ventanaPrincipal->ui->D_45,mesaLudo->tablero[1][45]->getColor(),
       QString::number(mesaLudo->tablero[1][45]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][45]){
       graficarCeldas(this->ventanaPrincipal->ui->D_45,  "", "");
   }

   if(mesaLudo->tablero[0][46]){
       graficarCeldas(this->ventanaPrincipal->ui->I_46,mesaLudo->tablero[0][46]->getColor(),
       QString::number(mesaLudo->tablero[0][46]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][46]){
       graficarCeldas(this->ventanaPrincipal->ui->I_46 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][46]){
       graficarCeldas(this->ventanaPrincipal->ui->D_46,mesaLudo->tablero[1][46]->getColor(),
       QString::number(mesaLudo->tablero[1][46]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][46]){
       graficarCeldas(this->ventanaPrincipal->ui->D_46,  "", "");
   }

   if(mesaLudo->tablero[0][47]){
       graficarCeldas(this->ventanaPrincipal->ui->I_47,mesaLudo->tablero[0][47]->getColor(),
       QString::number(mesaLudo->tablero[0][47]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][47]){
       graficarCeldas(this->ventanaPrincipal->ui->I_47 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][47]){
       graficarCeldas(this->ventanaPrincipal->ui->D_47,mesaLudo->tablero[1][47]->getColor(),
       QString::number(mesaLudo->tablero[1][47]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][47]){
       graficarCeldas(this->ventanaPrincipal->ui->D_47,  "", "");
   }

   if(mesaLudo->tablero[0][48]){
       graficarCeldas(this->ventanaPrincipal->ui->I_48,mesaLudo->tablero[0][48]->getColor(),
       QString::number(mesaLudo->tablero[0][48]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][48]){
       graficarCeldas(this->ventanaPrincipal->ui->I_48 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][48]){
       graficarCeldas(this->ventanaPrincipal->ui->D_48,mesaLudo->tablero[1][48]->getColor(),
       QString::number(mesaLudo->tablero[1][48]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][48]){
       graficarCeldas(this->ventanaPrincipal->ui->D_48,  "", "");
   }

   if(mesaLudo->tablero[0][49]){
       graficarCeldas(this->ventanaPrincipal->ui->I_49,mesaLudo->tablero[0][49]->getColor(),
       QString::number(mesaLudo->tablero[0][49]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][49]){
       graficarCeldas(this->ventanaPrincipal->ui->I_49 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][49]){
       graficarCeldas(this->ventanaPrincipal->ui->D_49,mesaLudo->tablero[1][49]->getColor(),
       QString::number(mesaLudo->tablero[1][49]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][49]){
       graficarCeldas(this->ventanaPrincipal->ui->D_49,  "", "");
   }

   if(mesaLudo->tablero[0][50]){
       graficarCeldas(this->ventanaPrincipal->ui->I_50,mesaLudo->tablero[0][50]->getColor(),
       QString::number(mesaLudo->tablero[0][50]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][50]){
       graficarCeldas(this->ventanaPrincipal->ui->I_50 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][50]){
       graficarCeldas(this->ventanaPrincipal->ui->D_50,mesaLudo->tablero[1][50]->getColor(),
       QString::number(mesaLudo->tablero[1][50]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][50]){
       graficarCeldas(this->ventanaPrincipal->ui->D_50,  "", "");
   }

   if(mesaLudo->tablero[0][51]){
       graficarCeldas(this->ventanaPrincipal->ui->I_51,mesaLudo->tablero[0][51]->getColor(),
       QString::number(mesaLudo->tablero[0][51]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[0][51]){
       graficarCeldas(this->ventanaPrincipal->ui->I_51 , ""  ,"" );
   }

   if(mesaLudo->tablero[1][51]){
       graficarCeldas(this->ventanaPrincipal->ui->D_51,mesaLudo->tablero[1][51]->getColor(),
       QString::number(mesaLudo->tablero[1][51]->getNumeroFicha()));
   } else if(!mesaLudo->tablero[1][51]){
       graficarCeldas(this->ventanaPrincipal->ui->D_51,  "", "");
   }



  graficarCarcel(mesa->getjugadores());
  graficarLineaFinal(mesa);

}

void ControladorVentanaPrincipal::graficarCarcel(vector<Jugador*> jugadores){
    QString mensaje = "";
    Jugador * jugador = jugadores[1];
    std::vector<FichaAbstracta*> fichas = jugador->getFichas();

    if(fichas[0]->getEstado() == false){
       mensaje =  QString::number( fichas[0]->getNumeroFicha());

       this->ventanaPrincipal->ui->carcelAzul_1->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                               "border: 2px solid white;"
                                                               "background-color: rgb(0, 0, 255);"
                                                               "color: rgb(255,255,255)");
       this->ventanaPrincipal->ui->carcelAzul_1->setText(mensaje);

    } else {
       this->ventanaPrincipal->ui->carcelAzul_1->setText("");
       this->ventanaPrincipal->ui->carcelAzul_1->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                "border: 2px solid white;"
                                                                "background-color: rgb(255, 255, 255);"
                                                                "color: rgb(255,255,255)");
    }

    if(fichas[1]->getEstado() == false){
        mensaje = QString::number( fichas[1]->getNumeroFicha());

       this->ventanaPrincipal->ui->carcelAzul_2->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                "border: 2px solid white;"
                                                                "background-color: rgb(0, 0, 255);"
                                                                "color: rgb(255,255,255)");
        this->ventanaPrincipal->ui->carcelAzul_2->setText(mensaje);

    } else {
       this->ventanaPrincipal->ui->carcelAzul_2->setText("");
       this->ventanaPrincipal->ui->carcelAzul_2->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                 "border: 2px solid white;"
                                                                 "background-color: rgb(255, 255, 255);"
                                                                 "color: rgb(255,255,255)");
    }

    if(fichas[2]->getEstado() == false){
        mensaje = QString::number( fichas[2]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelAzul_3->setText(mensaje);
       this->ventanaPrincipal->ui->carcelAzul_3->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                 "border: 2px solid white;"
                                                                 "background-color: rgb(0, 0, 255);"
                                                                 "color: rgb(255,255,255)");
    } else {
       this->ventanaPrincipal->ui->carcelAzul_3->setText("");
       this->ventanaPrincipal->ui->carcelAzul_3->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                  "border: 2px solid white;"
                                                                  "background-color: rgb(255, 255, 255);"
                                                                  "color: rgb(255,255,255)");
    }

    if(fichas[3]->getEstado() == false){
        mensaje = QString::number( fichas[3]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelAzul_4->setText(mensaje);
       this->ventanaPrincipal->ui->carcelAzul_4->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                  "border: 2px solid white;"
                                                                  "background-color: rgb(0, 0, 255);"
                                                                  "color: rgb(255,255,255)");
    } else {
       this->ventanaPrincipal->ui->carcelAzul_4->setText("");
       this->ventanaPrincipal->ui->carcelAzul_4->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                   "border: 2px solid white;"
                                                                   "background-color: rgb(255, 255, 255);"
                                                                   "color: rgb(255,255,255)");
    }

    jugador = jugadores[0];
    fichas = jugador->getFichas();

    if(fichas[0]->getEstado() == false){
       mensaje = QString::number( fichas[0]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelRoJa_1->setText(mensaje);
       this->ventanaPrincipal->ui->carcelRoJa_1->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                  "border: 2px solid white;"
                                                                  "background-color: rgb(255, 0, 0);"
                                                                   "color: rgb(255,255,255)");

    } else {
       this->ventanaPrincipal->ui->carcelRoJa_1->setText("");
       this->ventanaPrincipal->ui->carcelRoJa_1->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                    "border: 2px solid white;"
                                                                    "background-color: rgb(255, 255, 255);"
                                                                    "color: rgb(255,255,255)");
    }

    if(fichas[1]->getEstado() == false){
        mensaje = QString::number( fichas[1]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelRoJa_2->setText(mensaje);
        this->ventanaPrincipal->ui->carcelRoJa_2->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                   "border: 2px solid white;"
                                                                   "background-color: rgb(255, 0, 0);"
                                                                    "color: rgb(255,255,255)");

    } else {
       this->ventanaPrincipal->ui->carcelRoJa_2->setText("");
       this->ventanaPrincipal->ui->carcelRoJa_2->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                     "border: 2px solid white;"
                                                                     "background-color: rgb(255, 255, 255);"
                                                                     "color: rgb(255,255,255)");
    }

    if(fichas[2]->getEstado() == false){
        mensaje = QString::number( fichas[2]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelRoJa_3->setText(mensaje);
       this->ventanaPrincipal->ui->carcelRoJa_3->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                   "border: 2px solid white;"
                                                                   "background-color: rgb(255, 0, 0);"
                                                                    "color: rgb(255,255,255)");

    } else {
       this->ventanaPrincipal->ui->carcelRoJa_3->setText("");
       this->ventanaPrincipal->ui->carcelRoJa_3->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                     "border: 2px solid white;"
                                                                     "background-color: rgb(255, 255, 255);"
                                                                     "color: rgb(255,255,255)");
    }

    if(fichas[3]->getEstado() == false){
        mensaje =   QString::number( fichas[3]->getNumeroFicha());
       this->ventanaPrincipal->ui->carcelRoJa_4->setText(mensaje);
       this->ventanaPrincipal->ui->carcelRoJa_4->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                   "border: 2px solid white;"
                                                                   "background-color: rgb(255, 0, 0);"
                                                                    "color: rgb(255,255,255)");

    } else {
       this->ventanaPrincipal->ui->carcelRoJa_4->setText("");
       this->ventanaPrincipal->ui->carcelRoJa_4->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                     "border: 2px solid white;"
                                                                     "background-color: rgb(255, 255, 255);"
                                                                     "color: rgb(255,255,255)");
    }

    if(jugadores[3]!= nullptr){
        jugador = jugadores[3];
        fichas = jugador->getFichas();

        if(fichas[0]->getEstado() == false){
           mensaje = QString::number( fichas[0]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelVerde_1->setText(mensaje);
           this->ventanaPrincipal->ui->carcelVerde_1->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                       "border: 2px solid white;"
                                                                       "background-color: rgb(0, 148, 0);"
                                                                        "color: rgb(255,255,255)");
        } else {
           this->ventanaPrincipal->ui->carcelVerde_1->setText("");
           this->ventanaPrincipal->ui->carcelVerde_1->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                          "border: 2px solid white;"
                                                                          "background-color: rgb(255, 255, 255);"
                                                                          "color: rgb(255,255,255)");
        }

        if(fichas[1]->getEstado() == false){
            mensaje = QString::number( fichas[1]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelVerde_2->setText(mensaje);
           this->ventanaPrincipal->ui->carcelVerde_2->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                        "border: 2px solid white;"
                                                                        "background-color: rgb(0, 148, 0);"
                                                                         "color: rgb(255,255,255)");
        } else {
           this->ventanaPrincipal->ui->carcelVerde_2->setText("");
           this->ventanaPrincipal->ui->carcelVerde_2->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                           "border: 2px solid white;"
                                                                           "background-color: rgb(255, 255, 255);"
                                                                           "color: rgb(255,255,255)");
        }

        if(fichas[2]->getEstado() == false){
            mensaje = QString::number( fichas[2]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelVerde_3->setText(mensaje);
           this->ventanaPrincipal->ui->carcelVerde_3->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                         "border: 2px solid white;"
                                                                         "background-color: rgb(0, 148, 0);"
                                                                          "color: rgb(255,255,255)");
        } else {
           this->ventanaPrincipal->ui->carcelVerde_3->setText("");
           this->ventanaPrincipal->ui->carcelVerde_3->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                            "border: 2px solid white;"
                                                                            "background-color: rgb(255, 255, 255);"
                                                                            "color: rgb(255,255,255)");
        }

        if(fichas[3]->getEstado() == false){
            mensaje =   QString::number( fichas[3]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelVerde_4->setText(mensaje);
           this->ventanaPrincipal->ui->carcelVerde_4->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                          "border: 2px solid white;"
                                                                          "background-color: rgb(0, 148, 0);"
                                                                           "color: rgb(255,255,255)");
        } else {
           this->ventanaPrincipal->ui->carcelVerde_4->setText("");
           this->ventanaPrincipal->ui->carcelVerde_4->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                             "border: 2px solid white;"
                                                                             "background-color: rgb(255, 255, 255);"
                                                                             "color: rgb(255,255,255)");
        }
    }

    if(jugadores[2]!= nullptr){
        jugador = jugadores[2];
        fichas = jugador->getFichas();

        if(fichas[0]->getEstado() == false){
           mensaje = QString::number( fichas[0]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelAmarillo_1->setText(mensaje);
           this->ventanaPrincipal->ui->carcelAmarillo_1->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                          "border: 2px solid white;"
                                                                          "background-color: rgb(216, 216, 0);"
                                                                           "color: rgb(255,255,255)");
        } else {
           this->ventanaPrincipal->ui->carcelAmarillo_1->setText("");
           this->ventanaPrincipal->ui->carcelAmarillo_1->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                              "border: 2px solid white;"
                                                                              "background-color: rgb(255, 255, 255);"
                                                                              "color: rgb(255,255,255)");
        }

        if(fichas[1]->getEstado() == false){
            mensaje = QString::number( fichas[1]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelAmarillo_2->setText(mensaje);
           this->ventanaPrincipal->ui->carcelAmarillo_2->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                           "border: 2px solid white;"
                                                                           "background-color: rgb(216, 216, 0);"
                                                                            "color: rgb(255,255,255)");

        } else {
           this->ventanaPrincipal->ui->carcelAmarillo_2->setText("");
           this->ventanaPrincipal->ui->carcelAmarillo_2->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                               "border: 2px solid white;"
                                                                               "background-color: rgb(255, 255, 255);"
                                                                               "color: rgb(255,255,255)");
        }

        if(fichas[2]->getEstado() == false){
            mensaje = QString::number( fichas[2]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelAmarillo_3->setText(mensaje);
           this->ventanaPrincipal->ui->carcelAmarillo_3->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                            "border: 2px solid white;"
                                                                            "background-color: rgb(216, 216, 0);"
                                                                             "color: rgb(255,255,255)");
        } else {
           this->ventanaPrincipal->ui->carcelAmarillo_3->setText("");
           this->ventanaPrincipal->ui->carcelAmarillo_3->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                                "border: 2px solid white;"
                                                                                "background-color: rgb(255, 255, 255);"
                                                                                "color: rgb(255,255,255)");
        }

        if(fichas[3]->getEstado() == false){
            mensaje =   QString::number( fichas[3]->getNumeroFicha());
           this->ventanaPrincipal->ui->carcelAmarillo_4->setText(mensaje);
           this->ventanaPrincipal->ui->carcelAmarillo_4->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                             "border: 2px solid white;"
                                                                             "background-color: rgb(216, 216, 0);"
                                                                              "color: rgb(255,255,255)");
        } else {
           this->ventanaPrincipal->ui->carcelAmarillo_4->setText("");
           this->ventanaPrincipal->ui->carcelAmarillo_4->setStyleSheet("font: 700 20pt Segoe UI;""border-radius: 20px;"
                                                                                 "border: 2px solid white;"
                                                                                 "background-color: rgb(255, 255, 255);"
                                                                                 "color: rgb(255,255,255)");

        }
    }



}

void ControladorVentanaPrincipal:: graficarLineaFinal(TableroAbstracto * mesa ){

    TableroLudo * mesaLudo = dynamic_cast< TableroLudo * >(mesa);
    Jugador * jugador = mesa->getJugadorActual();
    std::vector<FichaAbstracta*> fichas = jugador->getFichas();
    string mensaje = "";

    if(fichas[0]->getColor() == "ROJO"){
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 55 )
                mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

        }
        this->ventanaPrincipal->ui->seguraRojo_55->setText(QString::fromStdString(mensaje));

        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 56 )
                mensaje +=  std::to_string( fichas[i]->getNumeroFicha()) + "  ";

        }
        this->ventanaPrincipal->ui->seguraRojo_56->setText(QString::fromStdString(mensaje));


        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 57 )
                mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

        }
        this->ventanaPrincipal->ui->seguraRojo_57->setText(QString::fromStdString(mensaje));


        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 58 )
                mensaje +=  std::to_string( fichas[i]->getNumeroFicha()) + "  ";

        }
        this->ventanaPrincipal->ui->seguraRojo_58->setText(QString::fromStdString(mensaje));


        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 59 )
                mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

        }
        this->ventanaPrincipal->ui->seguraRojo_59->setText(QString::fromStdString(mensaje));


        mensaje = "";
        for(int i = 0 ; i < 4 ; i++){
            if(fichas[i]->getPasosDados() == 60 )
                mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  \n";

        }
        this->ventanaPrincipal->ui->seguraRojo_60->setText(QString::fromStdString(mensaje));

    }

     mensaje == "";
     if(fichas[0]->getColor() == "AZUL"){
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 55 )
                     mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

             }
             this->ventanaPrincipal->ui->seguraAzul_55->setText(QString::fromStdString(mensaje));

             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 56 )
                     mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

             }
             this->ventanaPrincipal->ui->seguraAzul_56->setText(QString::fromStdString(mensaje));


             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 57 )
                     mensaje +=std::to_string( fichas[i]->getNumeroFicha()) + "  ";

             }
             this->ventanaPrincipal->ui->seguraAzul_57->setText(QString::fromStdString(mensaje));


             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 58 )
                     mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

             }
             this->ventanaPrincipal->ui->seguraAzul_58->setText(QString::fromStdString(mensaje));


             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 59 )
                     mensaje +=  std::to_string( fichas[i]->getNumeroFicha()) + "  ";

             }
             this->ventanaPrincipal->ui->seguraAzul_59->setText(QString::fromStdString(mensaje));


             mensaje = "";
             for(int i = 0 ; i < 4 ; i++){
                 if(fichas[i]->getPasosDados() == 60 )
                     mensaje +=  std::to_string( fichas[i]->getNumeroFicha()) + "  \n";

             }
             this->ventanaPrincipal->ui->seguraAzul_60->setText(QString::fromStdString(mensaje));

         }

          mensaje == "";
          if(fichas[0]->getColor() == "VERDE"){
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 55 )
                          mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_55->setText(QString::fromStdString(mensaje));

                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 56 )
                          mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_56->setText(QString::fromStdString(mensaje));


                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 57 )
                          mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_57->setText(QString::fromStdString(mensaje));


                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 58 )
                          mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_58->setText(QString::fromStdString(mensaje));


                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 59 )
                          mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_59->setText(QString::fromStdString(mensaje));


                  mensaje = "";
                  for(int i = 0 ; i < 4 ; i++){
                      if(fichas[i]->getPasosDados() == 60 )
                          mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  \n";

                  }
                  this->ventanaPrincipal->ui->seguraVerde_60->setText(QString::fromStdString(mensaje));

              }

          mensaje == "";
              if(fichas[0]->getColor() == "AMARILLO"){
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 55 )
                              mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_55->setText(QString::fromStdString(mensaje));

                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 56 )
                              mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_56->setText(QString::fromStdString(mensaje));


                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 57 )
                              mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_57->setText(QString::fromStdString(mensaje));


                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 58 )
                              mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_58->setText(QString::fromStdString(mensaje));


                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 59 )
                              mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  ";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_59->setText(QString::fromStdString(mensaje));


                      mensaje = "";
                      for(int i = 0 ; i < 4 ; i++){
                          if(fichas[i]->getPasosDados() == 60 )
                              mensaje += std::to_string( fichas[i]->getNumeroFicha()) + "  \n";

                      }
                      this->ventanaPrincipal->ui->seguraAmarillo_60->setText(QString::fromStdString(mensaje));

                  }




}




