set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} "main.cpp" "use_libs.cpp")

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${header_path})

find_package(nlohmann_json REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC simple_lib message_lib compiler_flags nlohmann_json::nlohmann_json)