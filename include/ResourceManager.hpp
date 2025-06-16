#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <map>
#include <string>

class ResourceManager {
private:
    static ResourceManager* instance;
    std::map<std::string, std::unique_ptr<sf::Font>> fonts;
    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
    std::map<std::string, std::unique_ptr<sf::SoundBuffer>> soundBuffers;

    ResourceManager() = default;

public:
    static ResourceManager& getInstance();
    
    sf::Font& getFont(const std::string& fontPath);
    sf::Texture& getTexture(const std::string& texturePath);
    sf::SoundBuffer& getSoundBuffer(const std::string& soundPath);
    
    bool loadFont(const std::string& fontPath, const std::string& key = "");
    bool loadTexture(const std::string& texturePath, const std::string& key = "");
    bool loadSoundBuffer(const std::string& soundPath, const std::string& key = "");
};

#endif
