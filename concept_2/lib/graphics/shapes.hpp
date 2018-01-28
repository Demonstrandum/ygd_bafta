#include "drawing.hpp"

namespace Graphics {
    class Point {
    public:
        float x, y;
        Point(float x = 0, float y = 0) { this->x = x; this->y = y; }
    };

    class Rectangle {
    private:
        float width, height;
        Point origin;
        Colour   fill_colour;
        Colour stroke_colour;
    public:
        Rectangle(
            const Point &o,
            float w, float h,
            const Colour &col1 = filler,
            const Colour &col2 = stroker,
            int mode = Mode::FILL | Mode::STROKE
        );
        Rectangle &render(SDL_Renderer *renderer);
    };
}
