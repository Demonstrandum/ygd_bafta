#include "includes.hpp"
#include "drawing.hpp"
#include <iostream>

static int show_window(void *window)
{
    std::cout << "Show being called" << std::endl;
    ((Window *)window)->show();
    return 0;
}

int main(int argc, char **argv)
{
    std::cout << "Game starting." << std::endl;
    Window *window = new Window(640, 480);

    int thread_succ;
    SDL_Thread *thread;
    thread = SDL_CreateThread(show_window, "show_window", (void *)window);
    std::cout << "Thread just started" << std::endl;
    SDL_WaitThread(thread, &thread_succ);
    std::cout << "Thread waiting" << std::endl;

    return 0;
}
