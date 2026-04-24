#include "Client.h"

namespace Core {

const Vector2 extents(500, 500);

Client::Client() : _scene(extents) {
    _scene.particles.resize(100);  // TODO!
}

void Client::update(float deltaTimeSec, const std::vector<uint8_t>& data) {
    Scene temp = Scene::deserialize(data);
    if (temp.extents() != _scene.extents()) {
        return;
    }
    if (temp.particles.size() != _scene.particles.size()) {
        return;
    }
    _scene.particles = std::move(temp.particles);
}

}  // namespace Core
