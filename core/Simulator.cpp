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
    auto& parts = scene->particles;
    std::size_t i = 0;
    Vector2 deltaPos;
    for (auto& part : parts) {
        deltaPos = velocities[i];
        deltaPos = deltaPos * deltaTimeSec;
        part.add(deltaPos);
        i++;
    }
}
