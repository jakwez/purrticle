#pragma once
#include <vector>

#include "Vector2.h"

class Scene {
   public:
    std::vector<Vector2> particles;
    static Scene createRandom(int numParticles, float min, float max);
};