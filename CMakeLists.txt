cmake_minimum_required(VERSION 3.16)
project(tower-defense)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Indiquer où sont les headers
include_directories(include)

# Ajouter tous les fichiers sources du dossier src
file(GLOB SOURCES "src/*.cpp")

# Trouver SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(tower-defense ${SOURCES})

target_link_libraries(tower-defense sfml-graphics sfml-window sfml-system)
