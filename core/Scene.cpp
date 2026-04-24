#include "Scene.h"

#include <random>

#include "scene_generated.h"

Scene::Scene(const Vector2& extents) : _extents(extents) {
    //
}

Scene Scene::createRandom(const Vector2& extents, size_t numParticles) {
    std::random_device rd;
    // std::mt19937 gen(1850103);
    std::mt19937 gen(rd());
    std::uniform_real_distribution distX(0.f, extents.x);
    std::uniform_real_distribution distY(0.f, extents.y);
    Scene scene(extents);
    scene.particles.reserve(numParticles);
    for (size_t i = 0; i < numParticles; i++) {
        float x = distX(gen);
        float y = distY(gen);
        scene.particles.emplace_back(x, y);
    }

    auto data = scene.serialize();
    Scene scene2 = deserialize(data);

    return scene2;
}

std::vector<uint8_t> Scene::serialize() const {
    flatbuffers::FlatBufferBuilder builder;
    std::vector<purrticle::Vector2> vecs;
    vecs.reserve(particles.size());
    for (const auto& p : particles) {
        vecs.emplace_back(p.x, p.y);
    }
    const auto& e = extents();
    purrticle::Vector2 fb_extents(e.x, e.y);
    auto fb_particles = builder.CreateVectorOfStructs(vecs);
    builder.Finish(purrticle::CreateScene(builder, &fb_extents, fb_particles));
    auto* buf = builder.GetBufferPointer();
    return {buf, buf + builder.GetSize()};
}

Scene Scene::deserialize(const std::vector<uint8_t>& data) {
    flatbuffers::Verifier verifier(data.data(), data.size());
    verifier.VerifyBuffer<purrticle::Scene>();
    const auto* fb_scene = purrticle::GetScene(data.data());
    const auto fb_extents = fb_scene->extents();
    auto e = Vector2(fb_extents->x(), fb_extents->y());
    Scene scene(e);
    if (fb_scene->particles()) {
        scene.particles.reserve(fb_scene->particles()->size());
        for (const auto* p : *fb_scene->particles()) {
            scene.particles.emplace_back(p->x(), p->y());
        }
    }
    return scene;
}
