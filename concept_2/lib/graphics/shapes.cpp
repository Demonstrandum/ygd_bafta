#include "shapes.hpp"

// Point::Point(unsigned x, unsigned y) { this->x = x; this->y = y; }

Rectangle::Rectangle(const Point &o, int w, int h, const Colour &col) : origin(o), colour(col)
{
    this->width  = w;
    this->height = h;
}

void Rectangle::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);

    for (int x = this->origin.x; x <= this->width; x++) {
        for (int y = this->height; y >= this->origin.y; y--) {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}
