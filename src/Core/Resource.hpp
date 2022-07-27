#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <string>

#define RESOURCE_PATH_TEXTURE "textures/"
#define RESOURCE_PATH_FONTS "fonts/"

namespace Resource {

    /**
     * @brief Loads resources textures and fonts.
     * Ideally called at the start of the program once. 
     * This function is thread-safe.
     */
    void loadResources();

    const sf::Texture&    getTexture(const std::string& fileName);
    const sf::Font&       getFont(const std::string& fileName);

};
