#include <graphics/graphics.hpp>
#include "Sprite.hpp"

using namespace Graphics;

class Player : public Sprite {
private:
    bool falling = true;

public:
    Point origin;
    int maxjumps = 2;
    int jumps = this->maxjumps;
    std::vector<float> dir = {0, 0};
    std::vector<int> inputdir = {0, 0};
    float width, height;
    float mass = this->width * this->height;
    std::string name;

    Player() : Sprite() {}
    Player(std::string, const Point &, float, float);
    Player &render(SDL_Renderer *);

    void gravity(float);
    void move();
    void input(float);

    template<class Entity>
    void collide(Entity *other)
    {
        if ((this->origin.x >= other->origin.x
            && this->origin.x <= other->origin.x + other->width)
            || (this->origin.x + this->width >= other->origin.x
            && this->origin.x + this->width <= other->origin.x + other->width)
        ) {
            if ((this->origin.y >= other->origin.y
                && this->origin.y <= other->origin.y + other->height)
                || (this->origin.y + this->height >= other->origin.y
                && this->origin.y + this->height<= other->origin.y + other->height)
            ) {
                this->origin.x -= this->dir[0];
                this->origin.y -= this->dir[1] + 1;

                this->origin.x -= this->inputdir[0];
                this->origin.y -= this->inputdir[1];

                this->dir[1] = -this->dir[1] / 2;
                this->jumps = this->maxjumps;
            }
        }
    }
};
