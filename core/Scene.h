#pragma once
#include <cstdint>
#include <vector>

#include "Vector2.h"

class Scene {
   public:
    Scene(const Vector2& extents);
    std::vector<Vector2> particles;
    const Vector2& extents() const { return _extents; }
    static Scene createRandom(const Vector2& extents, size_t numParticles);

    std::vector<uint8_t> serialize() const;
    static Scene deserialize(const std::vector<uint8_t>& data);

   private:
    Vector2 _extents;
};