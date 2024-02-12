#include "use_libs.hpp"

#include "message.hpp"
#include "add.hpp"

#if _MSC_VER
#include <format>
#endif

using namespace message_lib;

std::vector<uint8_t> LibsUsage::getSerializedJsonString(const std::string& strJson) {
	json j = json::parse(strJson);
	return serialize(j);
}

std::string LibsUsage::getResultOfAdditionNumbersFromDeserializedUBJson(const std::vector<uint8_t>& ubJson) {
	auto j = deserialize(ubJson);
	int one = j["one"].template get<int>();
	int two = j["two"].template get<int>();
#if _MSC_VER
	return std::format("{} + {} = {}", one, two, add(one, two));
#else
	// 11.02.2024 - the gcc compuler on latest ubuntu doesn't support <format> library
	return std::to_string(one) + " + " + std::to_string(two) + " = " + std::to_string(add(one, two));
#endif
}