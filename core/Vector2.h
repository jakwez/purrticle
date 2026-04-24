#pragma once

namespace Core {

class Vector2 {
   public:
    float x{0};
    float y{0};

    Vector2() = default;
    Vector2(const Vector2& other) = default;
    Vector2(float x, float y);
    Vector2& add(const Vector2& v2);

    Vector2& operator+(float scalar);
    Vector2& operator*(float scalar);
    bool operator==(const Vector2& other) const;

    /// @brief randomize x and y to the [0..1] range
    Vector2& randomize();
};

}
