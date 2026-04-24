#include "Client.h"

namespace Core {

const Vector2 extents(500, 500);

Client::Client() : scene(extents) {}

void Client::update(float deltaTimeSec, const std::vector<uint8_t>& data) {
    Scene temp = Scene::deserialize(data);
    if (temp.extents() != scene.extents()) {
        return;
    }
    if (temp.particles.size() != scene.particles.size()) {
        return;
    }
    scene.particles = std::move(temp.particles);
}

}
