#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <string>

namespace Resource {

    void loadResources();

    const sf::Texture&    getTexture(const std::string& fileName);
    const sf::Font&       getFont(const std::string& fileName);

};
