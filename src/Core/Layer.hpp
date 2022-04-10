#pragma once

#include <iostream>

class Layer
{
public:

    virtual void update() { std::cout << "Hello world!\n"; }
};
