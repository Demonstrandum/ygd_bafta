#include <graphics/graphics.hpp>
#include "entities/Player.hpp"
#include "entities/Obstacle.hpp"

using namespace Graphics;

int main(int argc, char **argv)
{
    Game *game = new Game(640, 480, 144); // WIDTH, HEIGHT, FPS
    game->start();

    return 0;
}

std::vector<Player> players;
Obstacle wall;

void Game::setup()
{
    std::vector<std::string> names = {"Tom", "Phenelope", "Sam", "Luke"};
    int x = 10;
    for (std::string &name : names) {
        players.push_back(Player(name, Point(x, 10), 30, 30));
        x += 50;
    }

    wall = Obstacle(Point(0, height - 30), width, 100);
}


void Game::draw()
{
    background(Colour(255));
    fill(Colour(52));
    stroke(Colour(255, 0, 255));

    unsigned mass_jump = 0;
    for (Player &player : players) {
        player.gravity(player.mass + mass_jump);
        mass_jump += 300;
        player.move();
        player.collide(&wall);

        render(&player);
    }

    render(&wall);
}
