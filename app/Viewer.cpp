#include "Viewer.h"

#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>

using namespace Core;

Viewer::Viewer(const Scene* scene) : scene(scene), _qscene(new QGraphicsScene()) {
    const auto& extents = scene->extents();
    _qscene->setSceneRect(0, 0, extents.x, extents.y);

    QGraphicsRectItem* rect = _qscene->addRect(0, 0, extents.x, extents.y);
    rect->setBrush(Qt::GlobalColor::lightGray);

    float hs = 2;

    const auto parts = scene->particles;
    qpartItems.resize(parts.size());
    for (std::size_t i = 0; i < parts.size(); ++i) {
        const auto& part = parts[i];
        QGraphicsEllipseItem* qpartItem = _qscene->addEllipse(-hs, -hs, hs * 2, hs * 2);
        qpartItem->setPos(part.x, part.y);
        qpartItem->setBrush(Qt::GlobalColor::magenta);
        qpartItems[i] = qpartItem;
    }
}

void Viewer::update() {
    const auto parts = scene->particles;
    for (std::size_t i = 0; i < parts.size(); i++) {
        const auto part = parts[i];
        qpartItems[i]->setPos(part.x, part.y);
    }
}
