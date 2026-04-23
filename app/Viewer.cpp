#include "Viewer.h"

#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>

Viewer::Viewer(const Scene* scene) : scene(scene), _qscene(new QGraphicsScene()) {
    const auto& extents = scene->extents();
    _qscene->setSceneRect(0, 0, extents.x, extents.y);  // Define the boundaries

    QGraphicsRectItem* rect = _qscene->addRect(0, 0, extents.x, extents.y);
    rect->setBrush(Qt::GlobalColor::lightGray);

    const auto parts = scene->particles;
    qpartItems.resize(parts.size());
    for (std::size_t i = 0; i < parts.size(); ++i) {
        const auto& part = parts[i];
        QGraphicsEllipseItem* item = _qscene->addEllipse(part.x, part.y, 3, 3);
        item->setBrush(Qt::GlobalColor::magenta);
        qpartItems[i] = item;
    }

    // QGraphicsRectItem* rect = qscene->addRect(50, 50, 100, 60);
    // rect->setBrush(Qt::GlobalColor::cyan);
    // rect->setFlag(QGraphicsItem::ItemIsMovable);  // Magic! Now you can drag it.

    // QGraphicsEllipseItem* circle = qscene->addEllipse(200, 150, 80, 80);
    // circle->setBrush(Qt::GlobalColor::magenta);
}

void Viewer::update() {
    const auto parts = scene->particles;
    for (std::size_t i = 0; i < parts.size(); i++) {
        const auto part = parts[i];
        const auto partItem = qpartItems[i];
        partItem->setPos(part.x, part.y);
    }
}