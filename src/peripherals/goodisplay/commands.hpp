#pragma once
#include <cstdint>
#include <misc/lv_area.h>
#include <misc/lv_color.h>

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
        lv_color_t* color_p,
        const lv_area_t* area);

    void partial_update();

    void draw_pixel(unsigned int x, unsigned int y, Color color);

    void EPD_Dis_Part(unsigned int x_start, unsigned int y_start, unsigned int PART_COLUMN,
                             unsigned int PART_LINE);

    void EPD_Dis_Part_myself11(unsigned int x_startA,unsigned int y_startA,const unsigned char * datasA,
                     unsigned int x_startB,unsigned int y_startB,const unsigned char * datasB,
                     unsigned int PART_COLUMN,unsigned int PART_LINE
                    );
}
