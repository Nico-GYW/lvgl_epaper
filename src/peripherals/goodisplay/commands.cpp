#include "commands.hpp"

#include <array>
#include <freertos/FreeRTOS.h>
#include <portmacro.h>
#include <freertos/projdefs.h>
#include <freertos/task.h>
#include <misc/lv_color.h>

#include "spi.hpp"

namespace GooDisplay
{
    void EPD_Dis_Part(unsigned int x_start, unsigned int y_start, unsigned int PART_COLUMN,
                      unsigned int PART_LINE)
    {
        unsigned int i;
        unsigned int x_end, y_start1, y_start2, y_end1, y_end2;
        x_start = x_start / 8;
        x_end = x_start + PART_LINE / 8 - 1;

        y_start1 = 0;
        y_start2 = y_start;
        if (y_start >= 256)
        {
            y_start1 = y_start2 / 256;
            y_start2 = y_start2 % 256;
        }
        y_end1 = 0;
        y_end2 = y_start + PART_COLUMN - 1;
        if (y_end2 >= 256)
        {
            y_end1 = y_end2 / 256;
            y_end2 = y_end2 % 256;
        }

        Epaper_Write_Command(0x44); // set RAM x address start/end, in page 35
        Epaper_Write_Data(x_start); // RAM x address start at 00h;
        Epaper_Write_Data(x_end); // RAM x address end at 0fh(15+1)*8->128
        Epaper_Write_Command(0x45); // set RAM y address start/end, in page 35
        Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
        Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
        Epaper_Write_Data(y_end2); // RAM y address end at 00h;
        Epaper_Write_Data(y_end1); // ????=0

        Epaper_Write_Command(0x4E); // set RAM x address count to 0;
        Epaper_Write_Data(x_start);
        Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
        Epaper_Write_Data(y_start2);
        Epaper_Write_Data(y_start1);
    }

    void begin_partial_draw()
    {
        //Reset
        EPD_W21_RST_0(); // Module reset
        vTaskDelay(pdMS_TO_TICKS(10)); // At least 10ms delay
        EPD_W21_RST_1();
        vTaskDelay(pdMS_TO_TICKS(10)); // At least 10ms delay

        Epaper_Write_Command(0x3C); //BorderWavefrom
        Epaper_Write_Data(0x80);
    }

    std::vector<std::byte> transform_buffer(lv_color_t* buffer, uint16_t width, uint16_t height)
    {
        std::vector<std::byte> transformed_buffer;
        transformed_buffer.reserve(width * height / 8);

        for (size_t x = 0; x < width; x++)
        {
            uint8_t byte = 0;
            uint8_t accumulated = 0;

            for (size_t y = 0; y < height; y++)
            {
                lv_color_t pixel = buffer[y * width + x];

                bool white = pixel.full == 0xFF || pixel.full == 0xED || pixel.full == 0xE8;

                byte <<= 1;
                byte |= (white ? 1 : 0);
                accumulated++;

                if (accumulated == 8)
                {
                    transformed_buffer.push_back(static_cast<std::byte>(byte));
                    byte = 0;
                    accumulated = 0;
                }
            }
        }

        return transformed_buffer;
    }

    void partial_draw(const PartialFramebuffer& partial_framebuffer)
    {
        EPD_Dis_Part(
            partial_framebuffer.y,
            DISPLAY_WIDTH - partial_framebuffer.x - 1,
            partial_framebuffer.width,
            partial_framebuffer.height);

        Epaper_Write_Command(0x24);

        for (auto byte : partial_framebuffer.buffer)
            Epaper_Write_Data(static_cast<uint8_t>(byte));
    }

    void partial_update()
    {
        EPD_Part_Update();
    }

    void fill(Color color)
    {
        // buffer.fill(color == Color::BLACK ? 0x00 : 0xff);
    }

    void clear_screen(Color color)
    {
        // fill(color);

        Epaper_Write_Command(0x24);
        for (unsigned int i = 0; i < DISPLAY_WIDTH * DISPLAY_HEIGHT / 8; i++)
            Epaper_Write_Data(color == Color::BLACK ? 0x00 : 0xff);

        Epaper_Write_Command(0x26);
        for (unsigned int i = 0; i < DISPLAY_WIDTH * DISPLAY_HEIGHT / 8; i++)
            Epaper_Write_Data(color == Color::BLACK ? 0x00 : 0xff);

        EPD_Update_Fast();
    }
}
