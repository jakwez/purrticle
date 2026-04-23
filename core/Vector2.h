#pragma once

class Vector2 {
   public:
    float x{0};
    float y{0};

    Vector2() = default;

    Vector2(float x, float y);
    Vector2& add(const Vector2& v2);

    /// @brief randomize x and y to the [0..1] range
    Vector2& randomize();

    Vector2& operator*(float scalar);
};