#include <graphics/graphics.hpp>
#include "Sprite.hpp"

using namespace Graphics;

class Obstacle : public Sprite {
private:
    std::string name;
    bool falling = true;

public:
    Point origin;
    std::vector<float> dir = {0, 0};
    float width, height;
    float mass = this->width * this->height;

    Obstacle() : Sprite() {}
    Obstacle(std::string, const Point &, float, float);
    Obstacle &render(SDL_Renderer *);

    void gravity(float);
    void move();
};
