# PROJECT_NAME = simple_lib
set(lib_test ${PROJECT_NAME}-tests)

find_package(GTest CONFIG REQUIRED)

add_executable(${lib_test} "message_test.cpp")

target_link_libraries(${lib_test} PUBLIC GTest::gtest_main GTest::gtest ${PROJECT_NAME} compiler_flags)

# GooglTest must be included to use gtest_discover_tests function for automatic test discovery
# so test do not need to be added manualy.
include(GoogleTest)
gtest_discover_tests(${lib_test})