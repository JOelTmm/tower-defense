#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    try {
        std::cout << "Test SFML - Création de la fenêtre..." << std::endl;
        
        sf::RenderWindow window(sf::VideoMode(800, 600), "Test SFML");
        if (!window.isOpen()) {
            std::cerr << "Erreur: Impossible de créer la fenêtre" << std::endl;
            return 1;
        }
        
        std::cout << "Fenêtre créée avec succès!" << std::endl;
        
        // Test de chargement de police
        sf::Font font;
        if (!font.loadFromFile("assets/arial.TTF")) {
            std::cerr << "Erreur: Impossible de charger la police" << std::endl;
            return 1;
        }
        
        std::cout << "Police chargée avec succès!" << std::endl;
        
        sf::Text text;
        text.setFont(font);
        text.setString("Test SFML");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100, 100);
        
        std::cout << "Test d'affichage..." << std::endl;
        
        // Boucle simple
        for (int i = 0; i < 60; ++i) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    break;
                }
            }
            
            window.clear(sf::Color::Black);
            window.draw(text);
            window.display();
            
            sf::sleep(sf::milliseconds(50));
        }
        
        std::cout << "Test terminé avec succès!" << std::endl;
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Exception inconnue" << std::endl;
        return 1;
    }
}
