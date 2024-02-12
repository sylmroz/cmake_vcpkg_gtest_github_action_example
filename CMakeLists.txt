cmake_minimum_required(VERSION 3.19)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("github_action_gtest_vcpkg" VERSION 1.0.0)

# It should be declared here so that "visual studio" can display unit tests in test explorer.
enable_testing()

if(NOT DEFINED BUILD_TESTING)
  set(BUILD_TESTING ON)
endif()

# Create a dummy library that stores the c++ version used throughout project.
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)

# Include sub-projects.
add_subdirectory("simple_lib")
add_subdirectory("message_lib")
add_subdirectory("app")