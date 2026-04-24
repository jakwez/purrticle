#include "Server.h"

namespace Core {

const Vector2 extents(500, 500);

Server::Server() : scene(Scene::createRandom(extents, 100)), simulator(&scene) {}

std::vector<uint8_t> Server::update(float deltaTimeSec) {
    simulator.update(deltaTimeSec);
    return scene.serialize();
}

}
