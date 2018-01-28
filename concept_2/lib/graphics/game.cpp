#include "game.hpp"

namespace Graphics {
    Game::Game(unsigned short w, unsigned short h, unsigned fps) : Window::Window(w, h, fps)
    {
        this->width  = w;
        this->height = h;
        this->frame_rate = fps;
    }

    void Game::background(Colour c)
    {
        SDL_SetRenderDrawColor(this->renderer, c.r, c.g, c.b, c.a);
        SDL_RenderClear(this->renderer);
    }

    void Game::start()
    {
        this->window = NULL;
        this->renderer = NULL;

    	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    		std::cout << "SDL could not initialize! SDL_Error: "
            << SDL_GetError() << std::endl;
    	} else {  // Just make the window
    	    //window = SDL_CreateWindow("SDL TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
            SDL_Init(SDL_INIT_VIDEO);
            SDL_CreateWindowAndRenderer(
                this->width, this->height, 0,
                &(this->window),
                &(this->renderer)
            );
            SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
            SDL_RenderClear(this->renderer);
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");


            if (window == NULL) {
    			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    		} else {
                SDL_Event event;
                Timer timer;
                bool running = true;

                this->setup();
                do {  // Game loop
                    timer.start();
                    //Events
                    while(SDL_PollEvent(&event)) {
                        if( event.type == SDL_QUIT ) running = false;
                    }

                    this->draw();
                    SDL_RenderPresent(this->renderer);

                    if ((unsigned)(timer.get_ticks()) < 1000 / this->frame_rate) {
                        SDL_Delay((1000 / this->frame_rate) - timer.get_ticks());
                    }
                } while (running);
                delete this;
            }
    	}
    }


    Game::~Game()
    {
        this->hide();
        SDL_Quit();
    }
}
