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

    void Game::on_resize(SDL_Event event)
    {
        /*SDL_Log("Window %d resized to %dx%d",
                event.window.windowID, event.window.data1,
                event.window.data2);*/
        width  = event.window.data1;
        height = event.window.data2;
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
                Timer timer;
                bool running = true;

                this->setup();
                do {  // Game loop
                    timer.start();
                    //Events
                    while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) running = false;
                        if (event.type == SDL_WINDOWEVENT) {
                            switch (event.window.event) {
                            case SDL_WINDOWEVENT_RESIZED:
                                this->on_resize(event);
                                break;
                            case SDL_WINDOWEVENT_SIZE_CHANGED:
                                this->on_resize(event);
                                break;
                            default:
                                /*SDL_Log("Window %d got unknown event %d",
                                        event.window.windowID, event.window.event);*/
                                break;
                            }
                        }
                        if (event.type == SDL_KEYDOWN) {
                            this->key_down = event.key.keysym.sym;
                            this->key_pressed();
                        }
                        if (event.type == SDL_KEYUP) {
                            this->key_up = event.key.keysym.sym;
                            this->key_released();
                        }
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
