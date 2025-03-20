#pragma once

namespace GooDisplay
{
    void init_spi();
    void EPD_HW_Init_Fast();

    void EPD_W21_CS_0();
    void EPD_W21_CS_1();
    void EPD_W21_DC_0();
    void EPD_W21_DC_1();
    void EPD_W21_RST_0();
    void EPD_W21_RST_1();

    void Epaper_Write_Command(unsigned char cmd);
    void Epaper_Write_Data(unsigned char data);

    void EPD_Part_Update();
    void EPD_Update();
    void EPD_DeepSleep();
}
