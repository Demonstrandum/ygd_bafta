#include <graphics/graphics.hpp>

using namespace Graphics;

int main(int argc, char **argv)
{
    Game *game = new Game(640, 480, 144); // WIDTH, HEIGHT, FPS
    game->start();

    return 0;
}

void Game::setup()
{

}


void Game::draw()
{
    background(Colour(100));
    fill(Colour(255));
    stroke(Colour(0));
}

void Game::key_pressed()
{
    switch (key_down) {
    case (SDLK_UP):
        break;

    case (SDLK_LEFT):
        break;

    case (SDLK_RIGHT):
        break;
    }
}
void Game::key_released()
{
    
}
