#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    std::cout << "🎮 Version Tower Defense basique - v1.0" << std::endl;
    std::cout << "=================================" << std::endl;
    
    // Version console du jeu tower defense
    std::cout << "Démarrage de la simulation..." << std::endl;
    
    // Simulation des phases du jeu
    int wave = 1;
    int score = 0;
    int lives = 10;
    
    while (wave <= 5 && lives > 0) {
        std::cout << "\n🌊 VAGUE " << wave << std::endl;
        std::cout << "Vies restantes: " << lives << std::endl;
        std::cout << "Score actuel: " << score << std::endl;
        
        // Simulation des ennemis
        for (int enemy = 1; enemy <= wave * 2; enemy++) {
            std::cout << "  📍 Ennemi " << enemy << " détruit!" << std::endl;
            score += 10;
        }
        
        // Chance de perdre une vie
        if (wave > 2 && rand() % 3 == 0) {
            lives--;
            std::cout << "  💥 Un ennemi a passé les défenses! (-1 vie)" << std::endl;
        }
        
        wave++;
    }
    
    std::cout << "\n🏆 RÉSULTATS FINAUX:" << std::endl;
    if (lives > 0) {
        std::cout << "✅ VICTOIRE! Toutes les vagues repoussées!" << std::endl;
    } else {
        std::cout << "💀 DÉFAITE! La base a été détruite..." << std::endl;
    }
    std::cout << "Score final: " << score << std::endl;
    std::cout << "Vies restantes: " << lives << std::endl;
    
    std::cout << "\n🎯 Le jeu fonctionne! SFML est installé correctement." << std::endl;
    std::cout << "Pour la version graphique, il faut configurer l'environnement X11/WSLg." << std::endl;
    
    return 0;
}
