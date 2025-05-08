#pragma once

#include <cstdint>
#include <misc/lv_area.h>
#include <misc/lv_color.h>
#include <sys/types.h>
#include <vector>

namespace GooDisplay
{
    constexpr uint16_t DISPLAY_WIDTH = 264;
    constexpr uint16_t DISPLAY_HEIGHT = 176;

    enum class Color
    {
        BLACK,
        WHITE,
    };

    struct PartialFramebuffer
    {
        std::vector<std::byte> buffer;
        uint16_t x, y, width, height;
    };

    void fill(Color color);
    void clear_screen(Color color);

    void begin_partial_draw();

    std::vector<std::byte> transform_buffer(uint8_t* buffer, uint16_t width, uint16_t height);

    void partial_draw(const PartialFramebuffer& partial_framebuffer);

    void partial_update();

    void draw_pixel(unsigned int x, unsigned int y, Color color);

    void EPD_Dis_Part(unsigned int x_start, unsigned int y_start, unsigned int PART_COLUMN,
                      unsigned int PART_LINE);
}
