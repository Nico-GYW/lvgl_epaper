#include "commands.hpp"

#include <esp32-hal.h>

#include "spi.hpp"

namespace GooDisplay
{
    void partial_draw(
        unsigned int x_start, unsigned int y_start,
        const unsigned char* buffer, unsigned int width,
        unsigned int height)
    {
        // Convert x_start to byte
        x_start /= 8;
        unsigned int x_end = x_start + width / 8 - 1;

        auto [y_start1, y_start2] = std::div(y_start, 256);
        auto [y_end1, y_end2] = std::div(y_start + height - 1, 256);

        // Reset
        EPD_W21_RST_0(); // Module reset
        delay(10);
        EPD_W21_RST_1();
        delay(10);

        Epaper_Write_Command(0x3C); // BorderWaveform
        Epaper_Write_Data(0x80);

        Epaper_Write_Command(0x44); // Set RAM x address start/end
        Epaper_Write_Data(x_start); // RAM x address start
        Epaper_Write_Data(x_end); // RAM x address end

        Epaper_Write_Command(0x45); // Set RAM y address start/end
        Epaper_Write_Data(y_start2); // RAM y address start
        Epaper_Write_Data(y_start1); // RAM y address start high byte
        Epaper_Write_Data(y_end2); // RAM y address end
        Epaper_Write_Data(y_end1); // RAM y address end high byte

        Epaper_Write_Command(0x4E); // Set RAM x address count
        Epaper_Write_Data(x_start);
        Epaper_Write_Command(0x4F); // Set RAM y address count
        Epaper_Write_Data(y_start2);
        Epaper_Write_Data(y_start1);

        Epaper_Write_Command(0x24); // Write Black and White image to RAM
        for (unsigned int i = 0; i < height; ++i)
        {
            for (unsigned int j = 0; j < width / 8; ++j)
            {
                Epaper_Write_Data(buffer[i * (width / 8) + j]);
            }
        }

        EPD_Part_Update();
    }

    void clear_screen(Color color)
    {
        Epaper_Write_Command(0x24);
        for (unsigned int i = 0; i < 5808; i++)
            Epaper_Write_Data(color == Color::BLACK ? 0x00 : 0xff);

        EPD_Update();
    }
}
