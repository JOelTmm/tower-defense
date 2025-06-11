cmake_minimum_required(VERSION 3.16)
project(TowerDefenseStatePattern)

set(CMAKE_CXX_STANDARD 17)

# SFML: cherchez le package installé
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Ajouter les fichiers du projet
add_executable(${PROJECT_NAME}
    main.cpp
    Button.hpp
    Game.hpp
    GameState.hpp
    MainMenuState.hpp
    SettingsState.hpp
    MainMenuState.cpp
    SettingsState.cpp
)

# Lier SFML
target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
)

# Pour l'exécution depuis l'IDE (copie des ressources)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
