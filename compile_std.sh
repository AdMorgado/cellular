#! /usr/bin/bash

g++-11 -fmodules-ts -std=c++20 -x c++-system-header string
g++-11 -fmodules-ts -std=c++20 -x c++-system-header vector
g++-11 -fmodules-ts -std=c++20 -x c++-system-header memory
g++-11 -fmodules-ts -std=c++20 -x c++-system-header thread
g++-11 -fmodules-ts -std=c++20 -x c++-system-header iostream
g++-11 -fmodules-ts -std=c++20 -x c++-system-header functional

g++-11 -fmodules-ts -std=c++20 -x c++-system-header SFML/System.hpp
g++-11 -fmodules-ts -std=c++20 -x c++-system-header SFML/Graphics.hpp
g++-11 -fmodules-ts -std=c++20 -x c++-system-header SFML/Window.hpp