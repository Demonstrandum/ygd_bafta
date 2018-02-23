#include <graphics/graphics.hpp>
#include <iostream>
#include <climits>
#include <ctime>

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
    std::vector<std::string> names = {"Tom", "Phenelope"};//, "Sam", "Luke"};
    int x = 10;
    for (std::string &name : names) {
        players.push_back(Player(name, Point(x, 300), 30, 30));
        x += 50;
    }

    walls.push_back(
        Obstacle(Point(101, 100), 100, 8)
    );
    walls.push_back(
        Obstacle(Point(0, height - 30), 100, 100)
    );
    walls.push_back(
        Obstacle(Point(100, height - 100), 100, 100)
    );
    walls.push_back(
        Obstacle(Point(0, height - 100), 8, 300)
    );
}

unsigned int frames = 0;
auto begin = std::time(0);
short bounce = 1;
void Game::draw()
{
    if (frames == UINT_MAX) {
        frames = 0;
        begin = std::time(0);
    }
    frames++;
    auto now = std::time(0);
    std::cout << "FPS: " << (double)frames / (now - begin) << std::endl;

    background(Colour(255));
    fill(Colour(52));
    stroke(Colour(255, 0, 255));

    if (walls[0].origin.x + walls[0].width >= width || walls[0].origin.x <= 100)
        bounce *= -1;
    walls[0].origin.x += bounce;
    for (Player &player : players) {
        for (Obstacle &other : walls) {
            Side *collisions = NULL;
            collisions = player.collide(&other);
            player.move(collisions);
            free(collisions);
        }

        // for (Player &other : players) {
        //     if (player.name != other.name) {
        //         Side *collisions = NULL;
        //         collisions = player.collide(&other);
        //         player.move(collisions);
        //     }
        // }
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
    //players[active].dir[1] = 0;
}
