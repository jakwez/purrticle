#include <gtest/gtest.h>

#include "MyClass.h"

TEST(MyClassTest, DoStuffReturns42) {
    MyClass obj;
    EXPECT_EQ(obj.doStuff(), 42);
}
