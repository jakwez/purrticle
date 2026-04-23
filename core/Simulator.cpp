#include "Simulator.h"

Simulator::Simulator(Scene* scene) {
    const auto parts = scene->particles;
    velocities.reserve(parts.size());
    std::size_t i = 0;
    for (auto part : parts) {
        velocities.emplace(velocities.begin() + i, Vector2());
    }
}