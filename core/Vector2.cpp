#include "Vector2.h"

#include <random>

namespace Core {

static std::mt19937 gen(std::random_device{}());
static std::uniform_real_distribution dist(0.f, 1.f);

Vector2::Vector2(float x, float y) : x{x}, y{y} {}

Vector2& Vector2::add(const Vector2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vector2& Vector2::operator+(float scalar) {
    x += scalar;
    y += scalar;
    return *this;
}

Vector2& Vector2::operator*(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

bool Vector2::operator==(const Vector2& other) const {
    return x == other.x && y == other.y;
}

Vector2& Vector2::randomize() {
    x = dist(gen);
    y = dist(gen);
    return *this;
}

}
