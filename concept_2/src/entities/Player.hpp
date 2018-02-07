#include <graphics/graphics.hpp>
#include "Sprite.hpp"

using namespace Graphics;

class Player : public Sprite {
private:
    std::string name;
    bool falling = true;

public:
    Point origin;
    std::vector<float> dir = {0, 0};
    float width, height;
    float mass = this->width * this->height;

    Player() : Sprite() {}
    Player(std::string, const Point &, float, float);
    Player &render(SDL_Renderer *);

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
