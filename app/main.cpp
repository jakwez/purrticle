#include <QApplication>
#include <QElapsedTimer>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QObject>
#include <QTimer>
#include <iostream>

#include "Client.h"
#include "Scene.h"
#include "Server.h"
#include "Simulator.h"
#include "Viewer.h"

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Server server(12345);

    QUrl url("ws://localhost:12345");
    Client client(url);

    Vector2 extents(500, 500);
    Scene scene = Scene::createRandom(extents, 100);

    Simulator simulator(&scene);

    Viewer viewer(&scene);
    QGraphicsView* qview = new QGraphicsView(viewer.qscene());
    qview->setRenderHint(QPainter::Antialiasing);  // Makes things look smooth
    qview->setWindowTitle("Qt Graphics View Canvas");
    int m = 20;
    qview->resize(extents.x + m, extents.y + m);
    qview->show();

    QElapsedTimer elapsedTimer;
    elapsedTimer.start();
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        qint64 deltaTimeMs = elapsedTimer.restart();
        float deltaTimeSec = static_cast<float>(deltaTimeMs) / 1000.f;
        simulator.update(deltaTimeSec);
        viewer.update();

        auto data = scene.serialize();
    });
    timer.setInterval(10);
    timer.start();

    return qapp.exec();
}
