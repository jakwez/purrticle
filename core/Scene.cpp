#include "Scene.h"

#include <random>

#include "scene_generated.h"

Scene Scene::createRandom(size_t numParticles, float mim, float max) {
    std::random_device rd;
    // std::mt19937 gen(1850103);
    std::mt19937 gen(rd());
    std::uniform_real_distribution dist(mim, max);
    Scene scene;
    scene.particles.reserve(numParticles);
    for (size_t i = 0; i < numParticles; i++) {
        float x = dist(gen);
        float y = dist(gen);
        scene.particles.emplace_back(x, y);
    }

    auto data = scene.serialize();
    Scene scene2 = deserialize(data.data(), data.size());

    return scene2;
}

std::vector<uint8_t> Scene::serialize() const {
    flatbuffers::FlatBufferBuilder builder;
    std::vector<purrticle::Vector2> vecs;
    vecs.reserve(particles.size());
    for (const auto& p : particles) {
        vecs.emplace_back(p.x, p.y);
    }
    auto fb_particles = builder.CreateVectorOfStructs(vecs);
    builder.Finish(purrticle::CreateScene(builder, fb_particles));
    auto* buf = builder.GetBufferPointer();
    return {buf, buf + builder.GetSize()};
}

Scene Scene::deserialize(const uint8_t* data, size_t size) {
    flatbuffers::Verifier verifier(data, size);
    verifier.VerifyBuffer<purrticle::Scene>();
    const auto* fb_scene = purrticle::GetScene(data);
    Scene scene;
    if (fb_scene->particles()) {
        scene.particles.reserve(fb_scene->particles()->size());
        for (const auto* p : *fb_scene->particles()) {
            scene.particles.emplace_back(p->x(), p->y());
        }
    }
    return scene;
}
