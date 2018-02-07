#include "Obstacle.hpp"

Obstacle::Obstacle(std::string n, const Point &loc, float w, float h) : Sprite(n, loc, w, h)
    , name(n), origin(loc)
    , width(w), height(h) {}

Obstacle &Obstacle::render(SDL_Renderer *renderer)
{
    Rectangle character(this->origin, this->width, this->height);
    character.render(renderer);

    return *this;
}

void Obstacle::gravity(float m)
{
    if (this->falling) {
        this->dir[1] += m * 0.0001;
    } else {
        this->dir[1] = 0;
    }
}

void Obstacle::move()
{
    this->origin.x += this->dir[0];
    this->origin.y += this->dir[1];
}
