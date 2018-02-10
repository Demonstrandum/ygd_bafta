#include <graphics/graphics.hpp>
#include <iostream>

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
std::vector<Obstacle> walls;
int active = 1;

void Game::setup()
{
    std::vector<std::string> names = {"Tom", "Phenelope", "Sam", "Luke"};
    int x = 10;
    for (std::string &name : names) {
        players.push_back(Player(name, Point(x, 10), 30, 30));
        x += 50;
    }

    walls.push_back(
        Obstacle(Point(0, height - 30), 100, 100)
    );
    walls.push_back(
        Obstacle(Point(100, height - 100), 100, 100)
    );
}


void Game::draw()
{
    background(Colour(255));
    fill(Colour(52));
    stroke(Colour(255, 0, 255));

    for (Player &player : players) {
        Side *collisions;
        for (Obstacle &other : walls) {
            collisions = player.collide(&other);
            player.move(collisions);
        }

        free(collisions);
        render(&player);
    }


    for (Obstacle &wall : walls) {
        render(&wall);
    }
}

void Game::key_pressed()
{
    switch (key_down) {
    case (SDLK_UP):
        break;

    case (SDLK_LEFT):
        players[active].dir[0] = -1;
        break;

    case (SDLK_RIGHT):
        players[active].dir[0] = 1;
        break;
    }
}

void Game::key_released()
{
    players[active].dir[0] = 0;
    players[active].dir[1] = 0;
}
