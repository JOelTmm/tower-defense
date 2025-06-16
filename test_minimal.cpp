#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    std::cout << "Test minimal SFML..." << std::endl;
    
    // Test de création d'un contexte graphique minimal
    sf::Context context;
    std::cout << "✓ Contexte SFML créé" << std::endl;
    
    // Test de création de fenêtre avec paramètres très basiques
    std::cout << "Création fenêtre..." << std::endl;
    sf::RenderWindow window(sf::VideoMode(200, 200), "Test");
    
    std::cout << "✓ Fenêtre créée!" << std::endl;
    
    // Fermer immédiatement
    window.close();
    
    std::cout << "Test réussi!" << std::endl;
    return 0;
}
