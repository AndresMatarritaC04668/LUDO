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
    explicit ventanaInformacion(QWidget *parent = nullptr);
    ~ventanaInformacion();

private:
    Ui::ventanaInformacion *ui;
};

#endif // VENTANAINFORMACION_H
