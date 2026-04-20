#include <gtest/gtest.h>

#include "Vector2.h"

TEST(Vector2Test, DefaultConstructor) {
    Vector2 v1;
    EXPECT_EQ(v1.x, 0);
    EXPECT_EQ(v1.y, 0);
}

TEST(Vector2Test, ConstructorWithArgs) {
    Vector2 v1(5, 7);
    EXPECT_EQ(v1.x, 5);
    EXPECT_EQ(v1.y, 7);
}

TEST(Vector2Test, Add) {
    Vector2 v1(5, 7);
    Vector2 v2(2, 3);
    Vector2 v3(1, 1);

    v1.add(v2).add(v3);
    EXPECT_EQ(v1.x, 8);
    EXPECT_EQ(v1.y, 11);
}