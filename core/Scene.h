#pragma once
#include <cstdint>
#include <vector>

#include "Vector2.h"

class Scene {
   public:
    std::vector<Vector2> particles;

    static Scene createRandom(size_t numParticles, float min, float max);

    std::vector<uint8_t> serialize() const;
    static Scene deserialize(const uint8_t* data, size_t size);
};