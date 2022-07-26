#include "Core/Resource.hpp"

#include <mutex>
#include <string>
#include <filesystem>
#include <unordered_map>


namespace Resource {

    std::mutex guard;

    //shared mutable state protected by [guard]
    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, sf::Font> fonts;

    void loadResources() {
        std::lock_guard<std::mutex> lock(guard);
        
    }

    const sf::Texture& getTexture(const std::string& fileName) {
        std::lock_guard<std::mutex> lock(guard);

        if(!textures.contains(fileName)) 
            throw std::runtime_error("Texture with filename " + fileName + " does not exist!");

        return textures[fileName];
    }

    const sf::Font& getFont(const std::string& fileName) {
        std::lock_guard<std::mutex> lock(guard);
        
        if(!fonts.contains(fileName))
            throw std::runtime_error("Font with filename " + fileName + " does not exist!");

        return fonts[fileName];
    }
}
