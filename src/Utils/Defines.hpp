#pragma once

#include <concepts>

#define LOOP(i, n) for(int i = 0; i < n; i++)

inline void loop(int n, std::invocable<int> auto&& f) {
    for (int i = 0; i < n; i++) 
        std::invoke(f, i);
}
