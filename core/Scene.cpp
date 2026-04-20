
#include "Scene.h"

#include <random>

Scene Scene::createRandom(int numParticles, float mim, float max) {
    std::mt19937 gen(1850103);
    std::uniform_real_distribution dist(mim, max);
    Scene scene;
    for (int i = 0; i < numParticles; i++) {
        float x = dist(gen);
        float y = dist(gen);
        scene.particles.emplace_back(x, y);
    }
    return scene;
}
