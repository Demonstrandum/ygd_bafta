#include "shapes.hpp"

namespace Graphics {
    Rectangle::Rectangle(
        const Point &o,
        float w, float h,
        const Colour &col1,
        const Colour &col2,
        int mode
    ) : origin(o), fill_colour(col1), stroke_colour(col2)
    {
        this->width  = w;
        this->height = h;
    }

    Rectangle &Rectangle::render(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer,
                               fill_colour.r, fill_colour.g,
                               fill_colour.b, fill_colour.a);

        for (int x = (int)(this->origin.x); x <= (int)(this->width + this->origin.x); x++) {
            for (int y = (int)(this->origin.y); y <= (int)(this->height + this->origin.y); y++) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
        return *this;
    }
}
