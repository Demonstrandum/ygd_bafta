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

Point coord(100, 100);
float spin = 0;

void Game::draw()
{
    background(Colour(52));

    Colour yellow(255, 255, 20);
    fill(yellow);
    stroke(Colour(255, 255, 255));

    for (float angle = 0; angle < TAU; angle += 0.01) {
        coord.y = 200 * tan(angle + spin) + height/2 - 0.5;
        coord.x = width/TAU * angle; // Full wavelength

        Rectangle rect(coord, 1, 1);
        render(&rect);
    }

    spin += 0.03;
    if (spin >= TAU) spin = 0;
}
