#include "Sprite.hpp"

Sprite::Sprite(const Point &loc, float w, float h) : origin(loc), width(w), height(h) {}

Sprite &Sprite::render(SDL_Renderer *renderer)
{
    Rectangle character(this->origin, this->width, this->height);
    character.render(renderer);

    return *this;
}

void Sprite::gravity(float m)
{
    this->dir[1] += 0.1;
}

void Sprite::move()
{
    this->origin.x += this->dir[0];
    this->origin.y += this->dir[1];
}

void Sprite::reverse()
{
    this->origin.x -= this->dir[0];
    this->origin.y -= this->dir[1];
}
