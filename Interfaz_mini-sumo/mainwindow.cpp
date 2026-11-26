#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Telemetría Minisumo - UDP");
    resize(450, 380);

    // 1. Cargar las 3 imágenes (ajusta las rutas o usa recursos Qt :/imagenes/...)
    imgBuscando = QPixmap(":/buscando.png");
    imgAtacando = QPixmap(":/atacando.png");
    imgBorde    = QPixmap(":/borde.png");

    // 2. Crear interfaz gráfica
    QWidget *central = new QWidget(this);
    QVBoxLayout *layoutPrincipal = new QVBoxLayout(central);

    // --- Sección de Sensores ---
    QGroupBox *grupoSensores = new QGroupBox("Lectura de Sensores", this);
    QVBoxLayout *layoutSensores = new QVBoxLayout(grupoSensores);

    // Sensor CNY70 (Analógico 0 - 1023 en ESP8266)
    lblCnyValor = new QLabel("CNY Suelo (Analógico): 0", this);
    lblCnyValor->setStyleSheet("font-size: 16px; font-weight: bold;");
    barCny = new QProgressBar(this);
    barCny->setRange(0, 1023);
    barCny->setValue(0);

    // Sensor Ultrasónico (cm)
    lblDistanciaValor = new QLabel("Distancia Ultrasónico: -- cm", this);
    lblDistanciaValor->setStyleSheet("font-size: 16px; font-weight: bold; margin-top: 10px;");

    layoutSensores->addWidget(lblCnyValor);
    layoutSensores->addWidget(barCny);
    layoutSensores->addWidget(lblDistanciaValor);

    // --- Sección de Estado e Imagen ---
    QGroupBox *grupoEstado = new QGroupBox("Estado del Minisumo", this);
    QVBoxLayout *layoutEstado = new QVBoxLayout(grupoEstado);

    lblEstadoTexto = new QLabel("SIN SEÑAL - ESPERANDO...", this);
    lblEstadoTexto->setAlignment(Qt::AlignCenter);
    lblEstadoTexto->setStyleSheet("font-size: 18px; font-weight: bold; padding: 6px; background-color: #424242; color: white; border-radius: 5px;");

    lblImagenEstado = new QLabel(this);
    lblImagenEstado->setFixedSize(180, 180);
    lblImagenEstado->setAlignment(Qt::AlignCenter);
    lblImagenEstado->setStyleSheet("border: 2px solid #888; border-radius: 8px; background-color: #222; color: #aaa;");


    layoutEstado->addWidget(lblEstadoTexto);
    layoutEstado->addWidget(lblImagenEstado, 0, Qt::AlignCenter);

    layoutPrincipal->addWidget(grupoSensores);
    layoutPrincipal->addWidget(grupoEstado);
    setCentralWidget(central);

    // 3. Configurar temporizadores para rotación sin señal
    timerDemo = new QTimer(this);
    connect(timerDemo, &QTimer::timeout, this, &MainWindow::rotarImagenSinSenal);

    timerTimeout = new QTimer(this);
    timerTimeout->setSingleShot(true); // Se dispara una sola vez si pasa el tiempo sin datos
    connect(timerTimeout, &QTimer::timeout, this, &MainWindow::activarModoSinSenal);

    // 4. Configurar Socket UDP en puerto 4210
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4, 4210);
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::leerTelemetriaUDP);

    // 5. Iniciar en modo "Sin señal" rotando imágenes cada 1.5 segundos
    activarModoSinSenal();
}

MainWindow::~MainWindow() {}
void MainWindow::activarModoSinSenal() {
    lblCnyValor->setText("CNY Suelo (Analógico): --");
    barCny->setValue(0);
    lblDistanciaValor->setText("Distancia Ultrasónico: -- cm");

    estadoDemoActual = 0;
    actualizarEstadoVisual(estadoDemoActual, true);
    timerDemo->start(1500); // Cambia de imagen cada 1500 ms (1.5 s)
}

void MainWindow::rotarImagenSinSenal() {
    estadoDemoActual = (estadoDemoActual + 1) % 3; // Cicla 0 -> 1 -> 2 -> 0
    actualizarEstadoVisual(estadoDemoActual, true);
}

void MainWindow::leerTelemetriaUDP() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(buffer.data(), buffer.size());

        QString mensaje = QString::fromUtf8(buffer).trimmed();
        QStringList datos = mensaje.split(",");

        if (datos.size() == 3) {
            if (timerDemo->isActive()) {
                timerDemo->stop();
            }
            timerTimeout->start(2000);

            int cny = datos[0].toInt();
            float distancia = datos[1].toFloat();
            int estado = datos[2].toInt();

            lblCnyValor->setText(QString("CNY Suelo (Analógico): %1").arg(cny));
            barCny->setValue(qBound(0, cny, 1023));
            lblDistanciaValor->setText(QString("Distancia Ultrasónico: %1 cm").arg(distancia, 0, 'f', 1));

            actualizarEstadoVisual(estado, false);
        }
    }
}

void MainWindow::actualizarEstadoVisual(int estado, bool sinSenal) {
    QPixmap imagenActual;

    switch (estado) {
    case 0:
        imagenActual = imgBuscando;
        if (!sinSenal) {
            lblEstadoTexto->setText("ESTADO 0: BUSCANDO RIVAL");
            lblEstadoTexto->setStyleSheet("font-size: 18px; font-weight: bold; padding: 6px; background-color: #1976D2; color: white; border-radius: 5px;");
        }
        break;

    case 1:
        imagenActual = imgAtacando;
        if (!sinSenal) {
            lblEstadoTexto->setText("ESTADO 1: ¡ATACANDO!");
            lblEstadoTexto->setStyleSheet("font-size: 18px; font-weight: bold; padding: 6px; background-color: #D32F2F; color: white; border-radius: 5px;");
        }
        break;

    case 2:
        imagenActual = imgBorde;
        if (!sinSenal) {
            lblEstadoTexto->setText("ESTADO 2: BORDE DEL DOHYO");
            lblEstadoTexto->setStyleSheet("font-size: 18px; font-weight: bold; padding: 6px; background-color: #F57C00; color: white; border-radius: 5px;");
        }
        break;

    default:
        if (!sinSenal) {
            lblEstadoTexto->setText("ESTADO DESCONOCIDO");
        }
        break;
    }

    if (sinSenal) {
        lblEstadoTexto->setText("SIN SEÑAL - ESPERANDO ESP8266...");
        lblEstadoTexto->setStyleSheet("font-size: 18px; font-weight: bold; padding: 6px; background-color: #424242; color: #FFCC00; border-radius: 5px;");
    }

    if (!imagenActual.isNull()) {
        lblImagenEstado->setPixmap(imagenActual.scaled(lblImagenEstado->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        lblImagenEstado->setText(QString("Imagen Estado %1\n(No cargada)").arg(estado));
    }
}