#include "Vector2.h"

Vector2::Vector2(float x, float y) : x{x}, y{y} {}

Vector2& Vector2::add(const Vector2& v) {
    x += v.x;
    y += v.y;
    return *this;
}