#include "Player.hpp"

Player::Player(std::string n, const Point &loc, float w, float h) : name(n), origin(loc), width(w), height(h) {}

Player &Player::render(SDL_Renderer *renderer)
{
    Rectangle character(this->origin, this->width, this->height);
    character.render(renderer);

    return *this;
}

void Player::gravity(float m)
{
    if (this->isfalling) {
        this->dir[1] += 0.1;
    } else {
        this->dir[1] = 0;
    }
}

void Player::move()
{
    this->origin.x += this->dir[0];
    this->origin.y += this->dir[1];
}

void Player::collide(Player *other)
{
    if ((this->origin.x + (this->height / 2) >= other->origin.x
        && this->origin.x + (this->height / 2) <= other->origin.x + other->width)
    ) {

        if ((this->origin.y + (this->height / 2) >= other->origin.y
            && this->origin.y + (this->height / 2) <= other->origin.y + other->height)
        ) {
            this->origin.x -= this->dir[0];
            this->origin.y -= this->dir[1];
            this->isfalling = false;
        }
    } else {
        this->isfalling = true;
    }
}
