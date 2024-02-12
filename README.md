![example workflow](https://github.com/sylmroz/cmake_vcpkg_gtest_github_action_example/actions/workflows/build.yaml/badge.svg)
# General

This is an example of how to use combined following technologies:
- **CMake** with CMake presets (minimum version 3.19).
- **vcpkg**, which is used as submodule in this repository.
- **Google Test (gtest)**: integrated with cmake.
- **Ninja** as the CMake generator.
- **Github Actions** for building project and running unit tests accross three different operating systems.

All these components are consolidated in one repository as a template, which can be easily modified and adapted for different projects.

There is the various links on the web integrating separate modules however this one
all-in-one example that simplify your workflow. :rocket:

## Build locally and run unit tests
1. **Clone the repository** using the following command command:
```git clone --recurse-submodules https://github.com/sylmroz/cmake_vcpkg_gtest_github_action_example.git```

2. **Bootstrap vcpkg** by navigating to the repository directory:
```
cd github_action_gtest_vcpkg
./external/vcpkg/bootstrap-vcpkg.sh # for non-Windows system

./external/vcpkg/bootstrap-vcpkg.bat # for Windows
```

3. The entire configuration is defined in `CMakePresets.json` file including toolchainFile pointed to vcpkg.
The initial file was generated using VisualStudio 2022 and next manually modified to meet the project requirements.

4. To build this example, execute the following command in the repository directory:
```cmake --preset <presetName>
cmake --build --<presetName>
```

5. The output binary will be located in the path defined in the `CMakePresets.json` file. In this example it is 
`${sourceDir}/out/build/${presetName}` where source dir a project root directory

6. To run unit test just write in root directory. The `CMakePresets.json` has configured location and all tests can be run using one commad. 
```ctest --preset <presetName>```

Choose appropiat `presetName` based on the platform where the code is being build and run.
Available prestes include:
- x64-debug
- x64-release
- x84-debug
- x84-release
- linux-debug
- linux-release
- macos-debug
- macos-release

## Action result
The github action workflow is located in file `.github/workflows/build.yaml` and is configured to run build process and unit tests on three different systems:
- windows-latest
- ubuntu-latest
- macos-latest

The result of running actoins looks like this:

![github action result](https://github.com/sylmroz/cmake_vcpkg_gtest_github_action_example/blob/main/doc/github_action_result.jpg?raw=true)

## VisualStudio Test Explorer integration
To ensure that your tests appear in the Test Explorer in Visual Studio, after running `cmake` command, use `Build/Build All`.
In the Test Explorer view you should see unit tests in tree view.

![github action result](https://github.com/sylmroz/cmake_vcpkg_gtest_github_action_example/blob/main/doc/test_explorer_result.jpg?raw=true)

## File structure
The example uses a flollowing folder structure

```
root\
  CMakeLists.txt
  folder1/
    CMakeLists.txt
    include/
      *.hpp files
    src/
      CMakeLists.txt
      *.cpp files
    tests/
      CMakeLists.txt
      *_test.cpp files
  folder2/
    CMakeLists.txt
    include/
      *.hpp files
    src/
      CMakeLists.txt
      *.cpp files
    tests/
      CMakeLists.txt
      *_test.cpp files
...
  folderN/
    CMakeLists.txt
    include/
      *.hpp files
    src/
      CMakeLists.txt
      *.cpp files
    tests/
      CMakeLists.txt
      *_test.cpp files
  external/
    store vcpkg repository
    store submodules which cannot be uses using vcpkg
```

In this example, the [nlohmann-json](https://github.com/nlohmann/json) is used as a demonstration of integrating external package in a project.
