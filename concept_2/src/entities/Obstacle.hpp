#include <graphics/graphics.hpp>
#include "Sprite.hpp"

using namespace Graphics;

class Obstacle : public Sprite {
public:
    Point origin;
    std::vector<float> dir = {0, 0};
    bool falling = true;
    float width, height;
    float mass = this->width * this->height;

    Obstacle() : Sprite() {}
    Obstacle(const Point &, float, float);
    Obstacle &render(SDL_Renderer *);

    void gravity(float);
    void move();

    template<class Entity>
    Side *collide(Entity *other)
    { return collision(this, other); }
};
