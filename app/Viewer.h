#pragma once
#include <Scene.h>

class QGraphicsScene;
class QGraphicsItem;

class Viewer {
   public:
    Viewer(const Scene* scene);
    void update();
    QGraphicsScene* qscene() { return _qscene; }

   private:
    const Scene* scene;
    QGraphicsScene* _qscene;
    std::vector<QGraphicsItem*> qpartItems;
};