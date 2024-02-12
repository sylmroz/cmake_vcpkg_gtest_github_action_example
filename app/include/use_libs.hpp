#pragma once

#include <string>
#include <vector>

class LibsUsage {
public:
	std::vector<uint8_t> getSerializedJsonString(const std::string& strJson);
	std::string getResultOfAdditionNumbersFromDeserializedUBJson(const std::vector<uint8_t>& ubJson);
private:
};