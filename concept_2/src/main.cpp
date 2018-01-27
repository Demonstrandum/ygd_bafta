#include "../lib/graphics/graphics"
#include <iostream>

void Game::setup()
{
    background(Colour(255, 100, 255));
}

void Game::draw()
{
    Colour fill(255, 255, 100);

    Rectangle rect(Point(3, 3), 50, 100, fill);
    render(&rect);
    // OR: `rect.render(this->renderer);`
}

int main(int argc, char **argv)
{
    Game *game = new Game(640, 480, 144); // WIDTH, HEIGHT, FPS
    game->start();

    return 0;
}
