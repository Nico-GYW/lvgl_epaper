#pragma once
#include <cstdint>

namespace GooDisplay
{
    constexpr uint16_t DISPLAY_WIDTH = 264;
    constexpr uint16_t DISPLAY_HEIGHT = 176;

    enum class Color
    {
        BLACK,
        WHITE,
    };

    void fill(Color color);
    void clear_screen(Color color);

    void partial_draw(
        unsigned int x_start, unsigned int y_start,
        unsigned int width,
        unsigned int height);

    void draw_pixel(unsigned int x, unsigned int y, Color color);
}
