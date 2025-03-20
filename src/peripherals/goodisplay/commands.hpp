#pragma once

namespace GooDisplay
{
    enum class Color
    {
        BLACK,
        WHITE,
    };

    void clear_screen(Color color);

    void partial_draw(
        unsigned int x_start, unsigned int y_start,
        const unsigned char* buffer, unsigned int width,
        unsigned int height);
}
