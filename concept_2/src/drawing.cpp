#include "drawing.hpp"
#include "timer.hpp"
#include <iostream>

Window::Window(unsigned short w, unsigned short h, unsigned fps)
{
    this->width  = w;
    this->height = h;
    this->frame_rate = fps;
}

void Window::show()
{
    this->window = NULL;
	this->base_surface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	} else {  // Just make the window
		window = SDL_CreateWindow("SDL TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		} else {
            SDL_Event event;
            Timer timer;
            bool running = true;
            do {
                timer.start();
                //Events
                while(SDL_PollEvent(&event)) {
                    if( event.type == SDL_QUIT ) running = false;
                }
    			this->base_surface = SDL_GetWindowSurface(window);

                // White bg
    			SDL_FillRect( this->base_surface, NULL, SDL_MapRGB(this->base_surface->format, 0xFF, 0xFF, 0xFF));
                // Draw Image
                SDL_Surface *picc = SDL_LoadBMP("src/assets/kitten.bmp");
                if (picc == NULL) std::cout << "Couldn't load kittycat. " << SDL_GetError() << std::endl;
                SDL_BlitSurface(picc, NULL, this->surface_ptr(), NULL);

    			SDL_UpdateWindowSurface(window);
                // regulate fps
                if( timer.get_ticks() < 1000 / this->frame_rate) {
                    SDL_Delay((1000 / this->frame_rate) - timer.get_ticks());
                }
            } while (running);
            delete this;
        }
	}
}

SDL_Window *Window::window_ptr() { return &*(this->window); }
SDL_Surface *Window::surface_ptr() { return &*(this->base_surface); }

Window::~Window()
{
    this->hide();
    SDL_Quit();
}

void Window::hide()
{
    SDL_DestroyWindow(this->window);
}
