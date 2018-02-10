#pragma once

#include <graphics/graphics.hpp>
using namespace Graphics;

const float GRAVITY = 0.00001;

enum Side {
    TOP=1,  BOTTOM=3,
    LEFT=4, RIGHT=2
};

template<class Entity, class Self>
Side *collision(Self *self, Entity *other)
{
    Side *sides = (Side *)calloc(4, sizeof(Side));
    int index = 0;

    if (self->origin.y + self->height <= other->origin.y) {
        index += 1;
        sides[index] = BOTTOM;
    }
    if (self->origin.y >= other->origin.y + other->height) {
        index += 1;
        sides[index] = TOP;
    }
    if (self->origin.x + self->width  <= other->origin.x) {
        index += 1;
        sides[index] = RIGHT;
    }
    if (self->origin.x >= other->origin.x + other->width) {
        index += 1;
        sides[index] = LEFT;
    }

    return sides;
}

class Sprite {
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
    void reverse();

    template<class Entity>
    Side *collide(Entity *other)
    { return collision(this, other); }
};
