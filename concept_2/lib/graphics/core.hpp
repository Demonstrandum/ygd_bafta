#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <iostream>

template<class T>
bool includes(T *array, T item)
{
    for (unsigned i = 0; i < sizeof(array) / sizeof(T); i++) {
        if (array[i] == item)
            return true;
    }
    return false;
}

#ifdef __linux__
    #include <SDL2/SDL.h>
#elif __APPLE__
    std::cout << "Linux is better... smh" << std::endl;
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
    #ifdef _MSC_VER
        #include "stdafx.h"
    #endif
#else
    #error "I don't know what OS this is."
#endif
