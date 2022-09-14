#pragma once

#include <array>
#include <stdint.h>

#include "SFML/System/Vector2.hpp"

template<typename T>
class Grid {
public:

    Grid(uint32_t sizeX, uint32_t sizeY) :
        sizeX(sizeX),
        sizeY(sizeY),
        grid(sizeX * sizeY)
    {

    }

    constexpr inline uint32_t idx(uint32_t x, uint32_t y) {
        return y * sizeX + x;
        std::vector<int> vec;
    }

    void set(const T& item, uint32_t x, uint32_t y);
    void set(const T& item, sf::Vector2u pos);

    T& get(uint32_t x, uint32_t y);
    T& get(sf::Vector2u pos);

    const T& get(uint32_t x, uint32_t y) const;
    const T& get(sf::Vector2u pos) const;


    const int sizeX;
    const int sizeY;

private:
    std::vector<T> grid;
};

#include "Utils/Grid.inl"
