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
        this->draw_mode = mode;
    }

    void Rectangle::draw_fill(SDL_Renderer *renderer)
    {
        SDL_SetRenderDrawColor(renderer,
                               fill_colour.r, fill_colour.g,
                               fill_colour.b, fill_colour.a);
        for (int x = (int)(this->origin.x); x <= (int)(this->width + this->origin.x); x++)
            for (int y = (int)(this->origin.y); y <= (int)(this->height + this->origin.y); y++)
                SDL_RenderDrawPoint(renderer, x, y);
    }

    void Rectangle::draw_stroke(SDL_Renderer *renderer)
    {
        SDL_SetRenderDrawColor(renderer,
                               stroke_colour.r, stroke_colour.g,
                               stroke_colour.b, stroke_colour.a);
        SDL_RenderDrawLine(renderer, this->origin.x, this->origin.y,
        this->origin.x + this->width, this->origin.y);
        SDL_RenderDrawLine(renderer, this->origin.x, this->origin.y,
        this->origin.x, this->origin.y + this->height);
        SDL_RenderDrawLine(renderer, this->origin.x, this->origin.y + this->height,
        this->origin.x + this->width, this->origin.y + this->height);
        SDL_RenderDrawLine(renderer, this->origin.x + this->width, this->origin.y,
        this->origin.x + this->width, this->origin.y + this->height);
    }

    Rectangle &Rectangle::render(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer,
                               fill_colour.r, fill_colour.g,
                               fill_colour.b, fill_colour.a);

        switch (this->draw_mode) {
        case (Mode::FILL):
            this->draw_fill(renderer);
            break;
        case (Mode::STROKE):
            this->draw_stroke(renderer);
            break;
        case (Mode::FILL | Mode::STROKE):
            this->draw_fill(renderer);
            this->draw_stroke(renderer);
            break;
        }
        return *this;
    }
}
