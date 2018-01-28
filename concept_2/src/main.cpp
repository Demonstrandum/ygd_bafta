#include <graphics/graphics.hpp>
#include <iostream>

using namespace Graphics;

int main(int argc, char **argv)
{
    Game *game = new Game(640, 480, 144); // WIDTH, HEIGHT, FPS
    game->start();

    return 0;
}

Point coord;
std::vector<Point> points;

float spin = 0;

void Game::setup()
{
    coord = Point(width/2 - 25, height/2 - 25);
}

void Game::draw()
{
    background(Colour(255, 100, 255));

    Colour yellow(255, 255, 20);
    fill(yellow);
    stroke(Colour(255, 255, 255));

    for (float angle = 0; angle < TAU; angle += 0.01) {
        coord.y = 200 * sin(angle + spin) + height/2 - 0.5;
        coord.x = width/TAU * angle; // Full wavelength

        Rectangle rect(coord, 1, 1);
        render(&rect);
    }

    spin += 0.01;
    if (spin >= TAU) spin = 0;

    // OR: `rect.render(this->renderer);`

    std::cout << "\r(" << coord.x << ", " << coord.y << ")";
}
