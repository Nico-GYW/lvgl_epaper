#include "spi.hpp"

#include <Arduino.h>
#include <SPI.h>

namespace GooDisplay
{
    //IO settings
    static int BUSY_Pin = A14;
    static int RES_Pin = A15;
    static int DC_Pin = A16;
    static int CS_Pin = A17;
    //SCLK--GPIO23
    //MOSI---GPIO18

    void EPD_W21_CS_0() { digitalWrite(CS_Pin,LOW); }
    void EPD_W21_CS_1() { digitalWrite(CS_Pin,HIGH); }
    void EPD_W21_DC_0() { digitalWrite(DC_Pin,LOW); }
    void EPD_W21_DC_1() { digitalWrite(DC_Pin,HIGH); }
    void EPD_W21_RST_0() { digitalWrite(RES_Pin,LOW); }
    void EPD_W21_RST_1() { digitalWrite(RES_Pin,HIGH); }
    static int isEPD_W21_BUSY() { return digitalRead(BUSY_Pin); }

    static void Epaper_READBUSY(void)
    {
        while (true)
        {
            //=1 BUSY
            if (isEPD_W21_BUSY() == 0) break;;
        }
    }

    void init_spi()
    {
        pinMode(BUSY_Pin, INPUT);
        pinMode(RES_Pin, OUTPUT);
        pinMode(DC_Pin, OUTPUT);
        pinMode(CS_Pin, OUTPUT);

        SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));
        SPI.begin();
    }

    void EPD_HW_Init_Fast()
    {
        EPD_W21_RST_0(); // Module reset
        delay(10); //At least 10ms delay
        EPD_W21_RST_1();
        delay(10); //At least 10ms delay

        Epaper_Write_Command(0x12); //SWRESET
        Epaper_READBUSY();

        Epaper_Write_Command(0x18); //Read built-in temperature sensor
        Epaper_Write_Data(0x80);

        Epaper_Write_Command(0x22); // Load temperature value
        Epaper_Write_Data(0xB1);
        Epaper_Write_Command(0x20);
        Epaper_READBUSY();

        Epaper_Write_Command(0x1A); // Write to temperature register
        Epaper_Write_Data(0x64);
        Epaper_Write_Data(0x00);

        Epaper_Write_Command(0x22); // Load temperature value
        Epaper_Write_Data(0x91);
        Epaper_Write_Command(0x20);
        Epaper_READBUSY();
    }

    static void SPI_Write(unsigned char value)
    {
        SPI.transfer(value);
    }

    void Epaper_Write_Command(unsigned char cmd)
    {
        EPD_W21_CS_1();
        EPD_W21_CS_0();
        EPD_W21_DC_0(); // D/C#   0:command  1:data

        SPI_Write(cmd);
        EPD_W21_CS_1();
    }

    void Epaper_Write_Data(unsigned char data)
    {
        EPD_W21_CS_1();
        EPD_W21_CS_0();
        EPD_W21_DC_1(); // D/C#   0:command  1:data

        SPI_Write(data);
        EPD_W21_CS_1();
    }

    // When the electronic paper screen is updated, do not unplug the electronic paper to avoid damage to the screen.

    void EPD_Part_Update(void)
    {
        Epaper_Write_Command(0x22); //Display Update Control
        Epaper_Write_Data(0xFF);
        Epaper_Write_Command(0x20); //Activate Display Update Sequence
        Epaper_READBUSY();
    }


    void EPD_Update(void)
    {
        Epaper_Write_Command(0x22); //Display Update Control
        Epaper_Write_Data(0xF7);
        Epaper_Write_Command(0x20); //Activate Display Update Sequence
        Epaper_READBUSY();
    }

    void EPD_DeepSleep(void)
    {
        Epaper_Write_Command(0x10); //enter deep sleep
        Epaper_Write_Data(0x01);
        delay(100);
    }
}
