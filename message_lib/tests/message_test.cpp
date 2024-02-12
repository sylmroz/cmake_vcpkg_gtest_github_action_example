#include "message.hpp"

#include <gtest/gtest.h>

using namespace message_lib;

TEST(message_lib, serialization_size) {
	json j = "{ a: 1, b: 2}";
	auto serializationResut = serialize(j);
	EXPECT_EQ(serializationResut.size(), 16);
}

TEST(message_lib, deserialization_structure) {
	json j = "{ a: 1, b: 2}";
	auto serializationResut = serialize(j);
	auto deserializeResult = deserialize(serializationResut);
	//constexpr int res = a + b;
	EXPECT_EQ(j, deserializeResult);
}