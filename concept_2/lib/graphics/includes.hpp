#ifdef __linux__
  #include <SDL2/SDL.h>
#elif __APPLE__
  std::cout << "Linux is better..." << std::endl;
  #include <SDL2/SDL.h>
#elif _WIN32
  #include <SDL.h>
#else
  #error "I don't know what OS this is."
#endif

#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>
