#include <QApplication>
#include <QElapsedTimer>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <algorithm>
#include <string>

#include "Client.h"
#include "Scene.h"
#include "Server.h"
#include "Simulator.h"
#include "Viewer.h"

using namespace Core;

static bool hasArg(int argc, char* argv[], const std::string& flag) {
    return std::any_of(argv + 1, argv + argc,
                       [&](const char* arg) { return arg == flag; });
}

int main(int argc, char* argv[]) {
    QApplication qapp(argc, argv);

    Vector2 extents(500, 500);
    Scene scene = Scene::createRandom(extents, 100);

    Simulator simulator(&scene);

    Viewer viewer(&scene);
    QGraphicsView* qview = new QGraphicsView(viewer.qscene());
    qview->setRenderHint(QPainter::Antialiasing);
    qview->setWindowTitle("Purrticle");
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
