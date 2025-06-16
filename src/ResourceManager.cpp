#include "ResourceManager.hpp"
#include <iostream>

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager& ResourceManager::getInstance() {
    if (!instance) {
        instance = new ResourceManager();
    }
    return *instance;
}

sf::Font& ResourceManager::getFont(const std::string& fontPath) {
    auto it = fonts.find(fontPath);
    if (it == fonts.end()) {
        loadFont(fontPath);
    }
    return *fonts[fontPath];
}

sf::Texture& ResourceManager::getTexture(const std::string& texturePath) {
    auto it = textures.find(texturePath);
    if (it == textures.end()) {
        loadTexture(texturePath);
    }
    return *textures[texturePath];
}

sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& soundPath) {
    auto it = soundBuffers.find(soundPath);
    if (it == soundBuffers.end()) {
        loadSoundBuffer(soundPath);
    }
    return *soundBuffers[soundPath];
}

bool ResourceManager::loadFont(const std::string& fontPath, const std::string& key) {
    std::string fontKey = key.empty() ? fontPath : key;
    auto font = std::make_unique<sf::Font>();
    
    if (font->loadFromFile(fontPath)) {
        fonts[fontKey] = std::move(font);
        return true;
    } else {
        std::cerr << "Erreur lors du chargement de la police: " << fontPath << std::endl;
        return false;
    }
}

bool ResourceManager::loadTexture(const std::string& texturePath, const std::string& key) {
    std::string textureKey = key.empty() ? texturePath : key;
    auto texture = std::make_unique<sf::Texture>();
    
    if (texture->loadFromFile(texturePath)) {
        textures[textureKey] = std::move(texture);
        return true;
    } else {
        std::cerr << "Erreur lors du chargement de la texture: " << texturePath << std::endl;
        return false;
    }
}

bool ResourceManager::loadSoundBuffer(const std::string& soundPath, const std::string& key) {
    std::string soundKey = key.empty() ? soundPath : key;
    auto soundBuffer = std::make_unique<sf::SoundBuffer>();
    
    if (soundBuffer->loadFromFile(soundPath)) {
        soundBuffers[soundKey] = std::move(soundBuffer);
        return true;
    } else {
        std::cerr << "Erreur lors du chargement du son: " << soundPath << std::endl;
        return false;
    }
}
