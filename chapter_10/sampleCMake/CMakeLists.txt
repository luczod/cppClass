# cmake_minimum_required(VERSION 3.30)
# project(sampleCMake)

# # Set the compiler paths
# # cmake -DCMAKE_CXX_COMPILER="C:/MinGW/bin/g++.exe" -DCMAKE_C_COMPILER="C:/MinGW/bin/gcc.exe" -G "MinGW Makefiles" ..
# # set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
# # set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

# include(FetchContent)

# FetchContent_Declare(
#   catch2
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG v3.4.0  # Check for the latest version and update the tag
# )

# FetchContent_MakeAvailable(catch2)

# # Add your tests
# # add_executable(tests test.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
