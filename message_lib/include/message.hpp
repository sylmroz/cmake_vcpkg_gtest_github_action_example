#pragma once

#include <nlohmann/json.hpp>
#include <vector>

namespace message_lib {
	using json = nlohmann::json;
	std::vector<uint8_t> serialize(const json& message_json);
	json deserialize(const std::vector<uint8_t>& message_raw);
}