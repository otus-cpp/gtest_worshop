#include "list.hpp"

#include <gtest/gtest.h>

#include <iostream>

struct ListFixture : public testing::Test {

    const size_t elementCount = 10;
    otus::List<size_t> list;

    // Per-test-suite set-up.
    static void SetUpTestSuite() {
        std::cout << "SetUpTestSuite" << std::endl;
    }

    // Per-test-suite tear-down.
    static void TearDownTestSuite() {
        std::cout << "TearDownTestSuite" << std::endl;
    }

    // Per-test set-up
    void SetUp() override { 
        std::cout << "SetUp" << std::endl;

        // Create list with elementCount elements
        for (size_t i = 0; i < elementCount; ++i) 
            list.push_back(i);
     }

    // You can define per-test tear-down logic as usual.
    void TearDown() override {
        std::cout << "TearDown" << std::endl;

        // Nothing to do for now
    }
};


TEST_F(ListFixture, PopBackAll) {
    // Arrange
    // nothing to do here, because we have fixture

    // Act
    std::cout << "Test body" << std::endl;
    for (size_t i = 0; i < elementCount; ++i)
        list.pop_back();

    // Assert
    ASSERT_TRUE(list.empty());
    ASSERT_EQ(list.size(), 0);
    ASSERT_THROW(
        list.pop_back(),
        std::exception
    );
}

TEST_F(ListFixture, PopFrontAll) {
    // Arrange
    // nothing to do here, because we have fixture

    // Act
    std::cout << "Test body" << std::endl;
    for (size_t i = 0; i < elementCount; ++i)
        list.pop_front();

    // Assert
    ASSERT_TRUE(list.empty());
    ASSERT_EQ(list.size(), 0);
    ASSERT_THROW(
        list.pop_front(),
        std::exception
    );
}


TEST(List, Empty) {
    // Arrange
    otus::List<int> list;

    // Act (empty for this test)

    // Assert
    ASSERT_TRUE(list.empty());
}

TEST(List, NotEmpty) {
    // Arrange
    otus::List<int> list;

    // Act (empty for this test)
    list.push_back(10);

    // Assert
    ASSERT_FALSE(list.empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}