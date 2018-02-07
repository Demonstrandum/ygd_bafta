#include <graphics/graphics.hpp>
#include "Player.hpp"
using namespace Graphics;

int main(int argc, char **argv)
{
    Game *game = new Game(640, 480, 144); // WIDTH, HEIGHT, FPS
    game->start();

    return 0;
}

std::vector<Player> players;
void Game::setup()
{
    std::vector<std::string> names = {"Tom", "Phenelope", "Sam", "Luke"};
    int x = 10;
    for (std::string &name : names) {
        players.push_back(Player(name, Point(x, 10), 30, 30));
        x += 50;
    }
}

Player wall("wall", Point(0, 480 - 10), 640, 100);

void Game::draw()
{
    background(Colour(255));
    fill(Colour(52));
    stroke(Colour(255, 0, 255));

    for (unsigned int i = 0; i < players.size(); i++) {
        players[i].gravity(players[i].mass);
        players[i].move();
        players[i].collide(&wall);
        render(&players[i]);
    }

    render(&wall);
}
