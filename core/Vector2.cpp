#include "Vector2.h"

#include <random>

std::random_device rd;
// std::mt19937 gen(1850103);
std::mt19937 gen(rd());
std::uniform_real_distribution dist(0.f, 1.f);

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

Vector2& Vector2::randomize() {
    x = dist(gen);
    y = dist(gen);
    return *this;
}
