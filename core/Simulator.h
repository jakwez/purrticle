#pragma once
#include "Scene.h"

namespace Core {

class Simulator {
   public:
    Simulator(Scene* scene);
    void update(float deltaTime);

   private:
    Scene* scene;
    std::vector<Vector2> velocities;  // in pixels/second
};

}  // namespace Core
