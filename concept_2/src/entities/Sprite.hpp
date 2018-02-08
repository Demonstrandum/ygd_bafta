#pragma once

#include <graphics/graphics.hpp>
using namespace Graphics;

class Sprite {
private:
    bool falling = true;

public:
    Point origin;
    std::vector<float> dir = {0, 0};
    float width, height;
    float mass = this->width * this->height;

    Sprite() {}
    Sprite(const Point &, float, float);
    Sprite &render(SDL_Renderer *);

    void gravity(float);
    void move();

    template<class Entity>
    void collide(Entity *other)
    {
        if ((this->origin.x + (this->height / 2) >= other->origin.x
            && this->origin.x + (this->height / 2) <= other->origin.x + other->width)
        ) {

            if ((this->origin.y + (this->height / 2) >= other->origin.y
                && this->origin.y + (this->height / 2) <= other->origin.y + other->height)
            ) {
                this->origin.x -= this->dir[0];
                this->origin.y -= this->dir[1];
                this->falling = false;
            }
        } else {
            this->falling = true;
        }
    }
};
