#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

class Player {
private:
    int vies;
    int gold;
    int vague;
    int score;

public:
    Player(int viesInitiales = 10, int goldInitiales = 100)
        : vies(viesInitiales), gold(goldInitiales), vague(1), score(0) {}

    int& getVies() { return vies; }
    int& getGold() { return gold; }
    int getVague() const { return vague; }
    int getScore() const { return score; }

    void perdreVie(int n = 1) {
        vies -= n;
        if (vies < 0) {
            std::cout << "looser" << std::endl;
        }
    }

    void gagnerGold(int montant) {
        gold += montant;
    }

    bool depenserGold(int montant) {
        if (gold >= montant) {
            gold -= montant;
            return true;
        }
        return false;
    }

    void prochaineVague() {
        vague++;
    }

    void ajouterScore(int points) {
        score += points;
    }

    bool estVivant() const {
        return vies > 0;
    }
};

void afficherJaugeVie(sf::RenderWindow& window, int vieActuelle, int vieMax, float x, float y) {
    const int longueurBarre = 200;
    int nbBarres = (vieActuelle * longueurBarre) / vieMax;
    int nbVides = longueurBarre - nbBarres;

    sf::RectangleShape barrePleine(sf::Vector2f(nbBarres, 20));
    barrePleine.setPosition(x, y);
    barrePleine.setFillColor(sf::Color::Green);

    sf::RectangleShape barreVide(sf::Vector2f(nbVides, 20));
    barreVide.setPosition(x + nbBarres, y);
    barreVide.setFillColor(sf::Color(100, 100, 100));

    window.draw(barrePleine);
    window.draw(barreVide);
}

bool lancerVague(sf::RenderWindow& window, int vague, int& vies, int& gold) {
    std::cout << "\n--- Vague " << vague << " ---" << std::endl;
    int ennemis = vague * 2;
    int vieEnnemis = 10 * vague;

    for (int i = 0; i < ennemis; ++i) {
        sf::RectangleShape ennemi(sf::Vector2f(20, 20));
        ennemi.setPosition(50 + i * 30, 300);
        ennemi.setFillColor(sf::Color::Red);
        window.draw(ennemi);

        if (vieEnnemis > 0) {
            vies -= 1;
            vieEnnemis -= 10;
        }
    }

    if (vieEnnemis <= 0) {
        std::cout << "ennemis mort" << std::endl;
        gold += 50;
        return true;
    }
    if (vies <= 0) {
        std::cout << "Game over" << std::endl;
        return false;
    }
    std::cout << "Vague " << vague << " Vaincue" << std::endl;
    return true;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tower Defense Test");
    Player joueur;
    sf::Clock clock;
    sf::Font font;
    if (!font.loadFromFile("../assets/arial.ttf")) {
        std::cout << "Erreur chargement police, utilisation d'une police par défaut" << std::endl;
        // SFML peut fonctionner sans police, mais le texte ne s'affichera pas
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                lancerVague(window, joueur.getVague(), joueur.getVies(), joueur.getGold());
                joueur.prochaineVague();
            }
        }

        window.clear(sf::Color::Black);

        sf::RectangleShape background(sf::Vector2f(800, 600));
        background.setFillColor(sf::Color(50, 150, 50));
        window.draw(background);

        afficherJaugeVie(window, joueur.getVies(), 10, 50, 50);

        sf::Text hudText;
        hudText.setFont(font);
        hudText.setCharacterSize(20);
        std::ostringstream oss;
        oss << "Vague: " << joueur.getVague() << "\nGold: " << joueur.getGold() << "\nScore: " << joueur.getScore();
        hudText.setString(oss.str());
        hudText.setPosition(50, 100);
        window.draw(hudText);

        window.display();

        sf::sleep(sf::milliseconds(16));
    }

    return 0;
}