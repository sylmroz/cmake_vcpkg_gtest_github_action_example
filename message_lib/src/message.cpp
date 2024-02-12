#include "message.hpp"

using namespace message_lib;

std::vector<uint8_t> message_lib::serialize(const json& messageJson) {
	return json::to_ubjson(messageJson);
}

json message_lib::deserialize(const std::vector<uint8_t>& messageRaw) {
	return json::from_ubjson(messageRaw.begin(), messageRaw.end());
}
