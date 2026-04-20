#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>

#include "Scene.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QGraphicsScene* qscene = new QGraphicsScene();
    qscene->setSceneRect(0, 0, 500, 500);  // Define the boundaries

    QGraphicsRectItem* rect = qscene->addRect(0, 0, 500, 500);
    rect->setBrush(Qt::GlobalColor::lightGray);

    // QGraphicsRectItem* rect = qscene->addRect(50, 50, 100, 60);
    // rect->setBrush(Qt::GlobalColor::cyan);
    // rect->setFlag(QGraphicsItem::ItemIsMovable);  // Magic! Now you can drag it.

    // QGraphicsEllipseItem* circle = qscene->addEllipse(200, 150, 80, 80);
    // circle->setBrush(Qt::GlobalColor::magenta);

    QGraphicsView* view = new QGraphicsView(qscene);
    view->setRenderHint(QPainter::Antialiasing);  // Makes things look smooth
    view->setWindowTitle("Qt Graphics View Canvas");
    view->resize(500, 500);
    view->show();

    Scene scene = Scene::createRandom(100, 0, 500);

    for (int i = 0; i < scene.particles.size(); ++i) {
        const Vector2& part = scene.particles[i];
        QGraphicsEllipseItem* circle = qscene->addEllipse(part.x, part.y, 3, 3);
        circle->setBrush(Qt::GlobalColor::magenta);
    }

    return a.exec();
}
