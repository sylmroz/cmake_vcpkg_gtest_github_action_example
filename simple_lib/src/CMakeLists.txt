# PROJECT_NAME = simple_lib
set(header_path ${${PROJECT_NAME}_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} "${header_path}/add.hpp" "add.cpp")

# Folder 'include' will be visible throughout whole project.
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${header_path})

# Use c++ version specified in root CMakeLists.txt
target_link_libraries(${PROJECT_NAME} PUBLIC compiler_flags)

# With library can be used an executable if needed.
add_executable(${PROJECT_NAME}-main "simple_lib_usage.cpp")
target_link_libraries(${PROJECT_NAME}-main ${PROJECT_NAME} compiler_flags)