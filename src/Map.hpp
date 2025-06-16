#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

// Dimensions de la carte en tuiles
const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 15;
const float TILE_SIZE = 40.f; // Taille d'une tuile en pixels

// Types de tuiles possibles dans la matrice
enum class TileType {
    EMPTY,
    PATH,
    START_BASE,
    END_BASE
};

class Map {
public:
    Map();

    // Retourne le chemin en coordonnées pixels pour les ennemis.
    const std::vector<sf::Vector2f>& getPathWaypoints() const;

    // Dessine la carte sur la fenêtre.
    void draw(sf::RenderWindow& window);

private:
    // Initialise la matrice et le chemin.
    void createSimplePath();
    // Convertit le chemin de la matrice en coordonnées pixels.
    void generateWaypoints();

    std::vector<std::vector<TileType>> grid; // La matrice de la carte
    std::vector<sf::Vector2f> pathWaypoints;   // Le chemin converti en pixels

    // Formes pour le dessin
    sf::RectangleShape emptyTile;
    sf::RectangleShape pathTile;
    sf::RectangleShape startTile;
    sf::RectangleShape endTile;
};

#endif // MAP_HPP