#include "Player.hpp"

Player::Player(std::string n, const Point &loc, float w, float h) : Sprite(loc, w, h)
    , name(n), origin(loc)
    , width(w), height(h) {}

Player &Player::render(SDL_Renderer *renderer)
{
    Rectangle character(this->origin, this->width, this->height);
    character.render(renderer);

    return *this;
}

void Player::gravity(float m)
{
    this->dir[1] += m * GRAVITY;
}

void Player::move(Side *collisions)
{
    this->gravity(this->mass);

    if (includes(collisions, TOP) || includes(collisions, BOTTOM)) {
        this->dir[1] = 0;
        this->origin.y -= this->dir[1] + GRAVITY * this->mass;
    } else {
        this->origin.y += this->dir[1];
    }

    if (includes(collisions, RIGHT)) {
        this->origin.x -= this->dir[0];
        std::cout << "goat farmer";
    }
    else { // HOW DO I STOP HIM FROM GOING THROUGH SIDE WALL!
        this->origin.x += this->dir[0];
    }

}

void Player::reverse()
{
    this->origin.y -= this->dir[1] + GRAVITY * this->mass;
}
