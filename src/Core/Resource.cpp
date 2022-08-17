#include "Core/Resource.hpp"

#include <mutex>
#include <string>
#include <iostream>
#include <filesystem>
#include <unordered_map>


namespace Resource {

    std::mutex guard;

    //shared mutable state protected by [guard]
    std::unordered_map<std::string, const sf::Texture> textures;
    std::unordered_map<std::string, const sf::Font> fonts;

    namespace fs = std::filesystem;

    void loadTextures() {
        std::lock_guard<std::mutex> lock(guard);

        if(!fs::exists(fs::path(RESOURCE_PATH_TEXTURE))) {
            std::cout << RESOURCE_PATH_TEXTURE << " folder does not exist, no loading textures!" << std::endl;
            return;
        }
        for(const auto& entry : fs::recursive_directory_iterator(RESOURCE_PATH_TEXTURE)) { 
            const fs::path path = entry.path();          
            
            if(!entry.is_regular_file())    continue;
            if(path.extension() != ".png")  continue;
            
            std::cout << path << std::endl;

            sf::Texture tex;
            if(tex.loadFromFile(path)) {
                textures.insert({path, tex});
            }
        }
    }

    void loadFonts() {
        std::lock_guard<std::mutex> lock(guard);

        if(!fs::exists(fs::path(RESOURCE_PATH_FONTS))) {
            std::cout << RESOURCE_PATH_FONTS << " folder does not exist, no loading fonts!" << std::endl;
            return;
        }

        for(const auto& entry : fs::recursive_directory_iterator(RESOURCE_PATH_FONTS)) { 
            const fs::path path = entry.path();          
            
            if(!entry.is_regular_file())    continue;
            if(path.extension() != ".ttf")  continue;
            
            std::cout << path << std::endl;

            sf::Font font;
            if(font.loadFromFile(path)) {
                fonts.insert({path, font});
            }
        }
    }

    void loadResources() {
        loadTextures();
        loadFonts();
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
