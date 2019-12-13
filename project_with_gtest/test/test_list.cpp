#include "list.hpp"

#include <gtest/gtest.h>

TEST(List, Empty) {
    // Arrange
    otus::List<int> list;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(list.size(), 0);
    ASSERT_TRUE(list.empty());
}

TEST(List, PushBack) {
    // Arrange
    const size_t count = 10;
    otus::List<size_t> list;

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Assert
    ASSERT_EQ(list.size(), count);
    ASSERT_FALSE(list.empty());
}

TEST(Lst, PopBack) {
    // Arrange 
    const size_t count = 10;
    otus::List<size_t> list;

    for (size_t i = 0; i < count; ++i) {
        list.push_back(i);
    }

    // Act
    for (size_t i = 0; i < count; ++i) {
        list.pop_back();
    }

    // Assert
    ASSERT_EQ(list.size(), 0);
    ASSERT_TRUE(list.empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}