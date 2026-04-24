#include "Server.h"

namespace Core {

const Vector2 extents(500, 500);

Server::Server() : _scene(Scene::createRandom(extents, 100)), _simulator(&_scene) {
    //
}

std::vector<uint8_t> Server::update(float deltaTimeSec) {
    _simulator.update(deltaTimeSec);
    return _scene.serialize();
}

}  // namespace Core
