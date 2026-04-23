#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QObject>
#include <QTimer>
#include <iostream>

#include "Scene.h"
#include "Simulator.h"
#include "Viewer.h"

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Vector2 extents(500, 500);
    Scene scene = Scene::createRandom(extents, 100);

    Viewer viewer(&scene);

    QGraphicsView* qview = new QGraphicsView(viewer.qscene());
    qview->setRenderHint(QPainter::Antialiasing);  // Makes things look smooth
    qview->setWindowTitle("Qt Graphics View Canvas");
    int m = 20;
    qview->resize(extents.x + m, extents.y + m);
    qview->show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        // std::cout << "." << std::endl;
        scene.particles[0].x += 1;
        viewer.update();
    });
    timer.setInterval(100);
    timer.start();

    return qapp.exec();
}
