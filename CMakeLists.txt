cmake_minimum_required(VERSION 3.10)
project(TowerDefense LANGUAGES CXX)

# Configuration du standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recherche de SFML
find_package(SFML 2.6.1 COMPONENTS graphics window system audio REQUIRED)

# Fichiers sources du projet
set(SOURCE_FILES
    src/main.cpp
    src/GameManager.cpp
    src/GameView.cpp
    src/Tower.cpp
    src/Enemy.cpp
    src/Map.cpp
    src/StartState.cpp
    src/MainMenuState.cpp
    src/PauseState.cpp
    src/SettingsState.cpp
    src/TowerMenuState.cpp
    src/ButtonFactory.cpp
    src/ButtonText.cpp
    src/ButtonImage.cpp
    src/ResourceManager.cpp
)

# Création de l'exécutable
add_executable(tower-defense ${SOURCE_FILES})

# Lien avec les bibliothèques SFML
target_link_libraries(tower-defense
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

# Inclusion des headers
target_include_directories(tower-defense PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Copie automatique du dossier assets dans le dossier de build
file(COPY src/assets DESTINATION ${CMAKE_BINARY_DIR})
