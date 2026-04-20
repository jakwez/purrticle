#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    // 1. Create the Scene (The "Canvas" logic)
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 400, 400);  // Define the boundaries

    // 2. Create and add items
    // You don't need a painter here; you just define properties.
    QGraphicsRectItem* rect = scene->addRect(50, 50, 100, 60);
    rect->setBrush(Qt::GlobalColor::cyan);
    rect->setFlag(QGraphicsItem::ItemIsMovable);  // Magic! Now you can drag it.

    QGraphicsEllipseItem* circle = scene->addEllipse(200, 150, 80, 80);
    circle->setBrush(Qt::GlobalColor::magenta);

    // 3. Create the View (The "Widget")
    QGraphicsView* view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);  // Makes things look smooth
    view->setWindowTitle("Qt Graphics View Canvas");
    view->resize(450, 450);
    view->show();

    return a.exec();
}
