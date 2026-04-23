#include "Simulator.h"

Simulator::Simulator(Scene* scene) : scene(scene) {
    const auto parts = scene->particles;
    velocities.reserve(parts.size());
    std::size_t i = 0;
    float max = 100;
    for (auto part : parts) {
        velocities.emplace(velocities.begin() + i, (Vector2().randomize() * max) + (-max / 2.f));
        i++;
    }
}

void Simulator::update(float deltaTimeSec) {
    const auto& e = scene->extents();
    auto& parts = scene->particles;
    std::size_t i = 0;
    Vector2 deltaPos;
    for (auto& part : parts) {
        deltaPos = velocities[i];
        deltaPos = deltaPos * deltaTimeSec;
        part.add(deltaPos);
        if (part.x < 0.f) {
            part.x *= -1.f;
            velocities[i].x *= -1.f;
        } else if (part.x > e.x) {
            part.x = e.x - (part.x - e.x);
            velocities[i].x *= -1.f;
        }

        if (part.y < 0.f) {
            part.y *= -1.f;
            velocities[i].y *= -1.f;
        } else if (part.y > e.y) {
            part.y = e.y - (part.y - e.y);
            velocities[i].y *= -1.f;
        }
        i++;
    }
}
