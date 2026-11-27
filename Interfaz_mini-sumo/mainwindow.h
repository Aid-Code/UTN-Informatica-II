#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QLabel>
#include <QProgressBar>
#include <QPixmap>
#include <QTimer>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void leerTelemetriaUDP();
    void rotarImagenSinSenal();
    void activarModoSinSenal();

private:
    void actualizarEstadoVisual(int estado, bool sinSenal = false);

    QUdpSocket *udpSocket;
    QTimer *timerDemo;
    QTimer *timerTimeout;
    int estadoDemoActual = 0;

    // Elementos de la interfaz
    QLabel *lblQtrValor;
    QProgressBar *barQtr;
    QLabel *lblDistanciaValor;
    QLabel *lblEstadoTexto;
    QLabel *lblImagenEstado;

    // Imágenes para los 3 estados
    QPixmap imgBuscando;
    QPixmap imgAtacando;
    QPixmap imgBorde;
};

#endif // MAINWINDOW_H