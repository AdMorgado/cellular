#include "gtest/gtest.h"

#include "Utils/Grid.hpp"

TEST(GridTest, ValidUse) {
    constexpr int sizeX = 10;
    constexpr int sizeY = 10;
    Grid<int> sut(sizeX, sizeY);

    // correct sizes
    ASSERT_EQ(sut.sizeX, sizeX); 
    ASSERT_EQ(sut.sizeY, sizeY); 
}
TEST(GridTest, InvalidUse) {    


}

TEST(GridTest, GettingAndSettingCells) {
    Grid<int> sut(1, 1);
    const int firstSetNum = 5;
    const int secondSetNum = 15;
    sut.set(firstSetNum, 0u, 0u);
    ASSERT_EQ(firstSetNum, sut.get(0, 0));
    sut.set(secondSetNum, sf::Vector2u(0, 0));
    ASSERT_EQ(secondSetNum, sut.get(0, 0));
}
