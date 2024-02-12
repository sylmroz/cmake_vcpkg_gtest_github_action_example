#include "use_libs.hpp"
#include <iostream>

int main() {
	LibsUsage lu;
	std::string strJson = "{ \"one\": 1, \"two\": 2 }";
	auto serializeResult = lu.getSerializedJsonString(strJson);
	std::cout << lu.getResultOfAdditionNumbersFromDeserializedUBJson(serializeResult);
	return 0;
}