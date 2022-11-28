/**
 * @file ventanainformacion.h
 * @author Joseph Fernando Núñez Solano (C05582)
 * @brief Implementa una ventana que presenta informacion en QT.
 * @version 0.1
 * @date 2022-11-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef VENTANAINFORMACION_H
#define VENTANAINFORMACION_H

#include <QMainWindow>

namespace Ui {
class ventanaInformacion;
}

class ventanaInformacion : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new ventana Informacion object by parameters.
     * 
     * @param parent Widget padre de la ventada.
     */
    explicit ventanaInformacion(QWidget *parent = nullptr);

    /**
     * @brief Destroy the ventana Informacion object
     * 
     */
    ~ventanaInformacion();

private:
    Ui::ventanaInformacion *ui;
};

#endif // VENTANAINFORMACION_H
