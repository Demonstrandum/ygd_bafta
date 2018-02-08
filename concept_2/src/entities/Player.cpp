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
    if (this->falling) {
        this->dir[1] += m * 0.0001;
    } else {
        this->dir[1] = 0;
    }
}

void Player::move()
{
    this->origin.x += this->dir[0];
    this->origin.y += this->dir[1];
}
