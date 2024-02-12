#include "add.hpp"

#include <gtest/gtest.h>

TEST(simple_lib, add_test) {
	constexpr int a = 1;
	constexpr int b = 2;
	int res = add(a, b);
	EXPECT_EQ(res, 3);
}

TEST(simple_lib, add_test_2) {
	constexpr int a = 2;
	constexpr int b = 2;
	int res = add(a, b);
	EXPECT_EQ(res, 4);
}