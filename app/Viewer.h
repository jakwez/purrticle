#pragma once
#include <Scene.h>

class QGraphicsScene;
class QGraphicsItem;

class Viewer {
   public:
    Viewer(const Core::Scene* scene);
    void update();
    QGraphicsScene* qscene() { return _qscene; }

   private:
    const Core::Scene* scene;
    QGraphicsScene* _qscene;
    std::vector<QGraphicsItem*> qpartItems;
};
