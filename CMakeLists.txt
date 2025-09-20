cmake_minimum_required(VERSION 4.0)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1 main.cpp
        Vecteur.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.x
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(tests)