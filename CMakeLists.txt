cmake_minimum_required(VERSION 3.16)
project(tower-defense)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(tower-defense src/main.cpp)

target_link_libraries(tower-defense sfml-graphics sfml-window sfml-system)
