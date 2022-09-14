
template <typename T>
void Grid<T>::set(const T& item, uint32_t x, uint32_t y) {
    grid[idx(x, y)] = item;
}


template <typename T>
void Grid<T>::set(const T& item, sf::Vector2u pos) {
    set(pos.x, pos.y);
}

template <typename T>
T& Grid<T>::get(uint32_t x, uint32_t y) {
    return grid.at(idx(x,y));
}

template <typename T>
T& Grid<T>::get(sf::Vector2u pos) {
    return grid.get(pos.x, pos.y);
}

template <typename T>
const T& Grid<T>::get(uint32_t x, uint32_t y) const {
    return grid.at(idx(x,y));
}


template <typename T>
const T& Grid<T>::get(sf::Vector2u pos) const {
    return grid.get(pos.x, pos.y);
}
