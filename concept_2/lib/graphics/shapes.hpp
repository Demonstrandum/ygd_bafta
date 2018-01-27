#include "drawing.hpp"

class Point {
public:
    int x, y;
    Point(int x, int y) { this->x = x; this->y = y; }
};

class Rectangle {
private:
    int width, height;
    Point origin;
    Colour colour;
public:
    Rectangle(const Point &o, int w, int h, const Colour &col);
    Rectangle &render(SDL_Renderer *renderer);
};
