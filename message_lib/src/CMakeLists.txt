set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")

add_library(${PROJECT_NAME} "${header_path}/message.hpp" "message.cpp")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${header_path})

target_link_libraries(${PROJECT_NAME} PUBLIC compiler_flags)

find_package(nlohmann_json REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
