#include "commands.hpp"

#include <array>
#include <esp32-hal.h>
#include <HardwareSerial.h>
#include <misc/lv_area.h>
#include <misc/lv_color.h>

#include "spi.hpp"

namespace GooDisplay
{
    // std::array<unsigned char, DISPLAY_WIDTH * DISPLAY_HEIGHT / 8> buffer = {};

    // void draw_pixel(unsigned int x, unsigned int y, Color color)
    // {
    //     if (x > DISPLAY_WIDTH || y > DISPLAY_HEIGHT)
    //     {
    //         assert(false);
    //         return;
    //     }
    //
    //     std::swap(x, y);
    //
    //     unsigned int i = x / 8 + y * (DISPLAY_HEIGHT / 8);
    //     if (color == Color::BLACK)
    //         buffer[i] = (buffer[i] & ~(1 << (7 - x % 8)));
    //     else
    //         buffer[i] = (buffer[i] | (1 << (7 - x % 8)));
    // }

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
        //Reset
        EPD_W21_RST_0(); // Module reset
        delay(10); //At least 10ms delay
        EPD_W21_RST_1();
        delay(10); //At least 10ms delay

        Epaper_Write_Command(0x3C); //BorderWavefrom
        Epaper_Write_Data(0x80);
        //
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

    void partial_draw(
        lv_color_t* color_p,
        const lv_area_t* area)
    {
        auto width = lv_area_get_width(area);
        auto height = lv_area_get_height(area);

        EPD_Dis_Part(area->y1, DISPLAY_WIDTH - area->x1, width, height);

        Epaper_Write_Command(0x24);

        for (auto x = area->x1; x <= area->x2; x++)
        {
            uint8_t byte = 0;
            uint8_t accumulated = 0;

            for (auto y = area->y1; y <= area->y2; y++)
            {
                lv_color_t pixel = color_p[y * width + x];

                bool white = pixel.full == 0xFF || pixel.full == 0xED || pixel.full == 0xE8;

                byte <<= 1;
                byte |= (white ? 1 : 0);
                accumulated++;

                if (accumulated == 8)
                {
                    GooDisplay::Epaper_Write_Data(byte);
                    byte = 0;
                    accumulated = 0;
                }
            }
        }
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

    void EPD_Dis_Part_myself11(unsigned int x_startA, unsigned int y_startA, const unsigned char* datasA,
                               unsigned int x_startB, unsigned int y_startB, const unsigned char* datasB,
                               unsigned int PART_COLUMN, unsigned int PART_LINE
    )
    {
        unsigned int i;
        unsigned int x_end, y_start1, y_start2, y_end1, y_end2;

        //Data A////////////////////////////
        x_startA = x_startA / 8; //Convert to byte
        x_end = x_startA + PART_LINE / 8 - 1;

        y_start1 = 0;
        y_start2 = y_startA - 1;
        if (y_startA >= 256)
        {
            y_start1 = y_start2 / 256;
            y_start2 = y_start2 % 256;
        }
        y_end1 = 0;
        y_end2 = y_startA + PART_COLUMN - 1;
        if (y_end2 >= 256)
        {
            y_end1 = y_end2 / 256;
            y_end2 = y_end2 % 256;
        }
        //Reset
        EPD_W21_RST_0(); // Module reset
        delay(10); //At least 10ms delay
        EPD_W21_RST_1();
        delay(10); //At least 10ms delay

        Epaper_Write_Command(0x3C); //BorderWavefrom
        Epaper_Write_Data(0x80);
        //
        Epaper_Write_Command(0x44); // set RAM x address start/end, in page 35
        Epaper_Write_Data(x_startA); // RAM x address start at 00h;
        Epaper_Write_Data(x_end); // RAM x address end at 0fh(15+1)*8->128
        Epaper_Write_Command(0x45); // set RAM y address start/end, in page 35
        Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
        Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
        Epaper_Write_Data(y_end2); // RAM y address end at 00h;
        Epaper_Write_Data(y_end1);


        Epaper_Write_Command(0x4E); // set RAM x address count to 0;
        Epaper_Write_Data(x_startA);
        Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
        Epaper_Write_Data(y_start2);
        Epaper_Write_Data(y_start1);


        Epaper_Write_Command(0x24); //Write Black and White image to RAM
        for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)
        {
            Epaper_Write_Data(*datasA);
            datasA++;
        }
        //Data B/////////////////////////////////////
        x_startB = x_startB / 8; //Convert to byte
        x_end = x_startB + PART_LINE / 8 - 1;

        y_start1 = 0;
        y_start2 = y_startB - 1;
        if (y_startB >= 256)
        {
            y_start1 = y_start2 / 256;
            y_start2 = y_start2 % 256;
        }
        y_end1 = 0;
        y_end2 = y_startB + PART_COLUMN - 1;
        if (y_end2 >= 256)
        {
            y_end1 = y_end2 / 256;
            y_end2 = y_end2 % 256;
        }

        Epaper_Write_Command(0x44); // set RAM x address start/end, in page 35
        Epaper_Write_Data(x_startB); // RAM x address start at 00h;
        Epaper_Write_Data(x_end); // RAM x address end at 0fh(15+1)*8->128
        Epaper_Write_Command(0x45); // set RAM y address start/end, in page 35
        Epaper_Write_Data(y_start2); // RAM y address start at 0127h;
        Epaper_Write_Data(y_start1); // RAM y address start at 0127h;
        Epaper_Write_Data(y_end2); // RAM y address end at 00h;
        Epaper_Write_Data(y_end1);


        Epaper_Write_Command(0x4E); // set RAM x address count to 0;
        Epaper_Write_Data(x_startB);
        Epaper_Write_Command(0x4F); // set RAM y address count to 0X127;
        Epaper_Write_Data(y_start2);
        Epaper_Write_Data(y_start1);


        Epaper_Write_Command(0x24); //Write Black and White image to RAM
        for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)
        {
            Epaper_Write_Data(*datasB);
            datasB++;
        }
        EPD_Part_Update();
    }
}
