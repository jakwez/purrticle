#pragma once
#include "Scene.h"

class Simulator {
   public:
    Simulator(Scene* scene);
    void update(float deltaTime);

   private:
    std::vector<Vector2> velocities;
};