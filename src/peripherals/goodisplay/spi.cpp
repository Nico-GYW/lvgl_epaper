#include "spi.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

namespace GooDisplay
{
    // SPI control pins
    static constexpr gpio_num_t BUSY_Pin = GPIO_NUM_38;
    static constexpr gpio_num_t RES_Pin = GPIO_NUM_0;
    static constexpr gpio_num_t DC_Pin = GPIO_NUM_14;
    static constexpr gpio_num_t CS_Pin = GPIO_NUM_13;

    // SPI signals
    static constexpr gpio_num_t SCLK_Pin = GPIO_NUM_39;
    static constexpr gpio_num_t MOSI_Pin = GPIO_NUM_40;

    static spi_device_handle_t spi_handle;

    void EPD_W21_CS_0() { gpio_set_level(CS_Pin, 0); }
    void EPD_W21_CS_1() { gpio_set_level(CS_Pin, 1); }
    void EPD_W21_DC_0() { gpio_set_level(DC_Pin, 0); }
    void EPD_W21_DC_1() { gpio_set_level(DC_Pin, 1); }
    void EPD_W21_RST_0() { gpio_set_level(RES_Pin, 0); }
    void EPD_W21_RST_1() { gpio_set_level(RES_Pin, 1); }
    static int isEPD_W21_BUSY() { return gpio_get_level(BUSY_Pin); }

    static void Epaper_READBUSY()
    {
        while (isEPD_W21_BUSY() != 0)
        {
            vTaskDelay(pdMS_TO_TICKS(10));
        }
    }

    void init_spi()
    {
        // GPIO config
        gpio_config_t io_conf = {};
        io_conf.mode = GPIO_MODE_OUTPUT;
        io_conf.pin_bit_mask = (1ULL << RES_Pin) | (1ULL << DC_Pin) | (1ULL << CS_Pin);
        gpio_config(&io_conf);

        io_conf.mode = GPIO_MODE_INPUT;
        io_conf.pin_bit_mask = (1ULL << BUSY_Pin);
        gpio_config(&io_conf);

        // SPI bus config
        spi_bus_config_t buscfg = {};
        buscfg.mosi_io_num = MOSI_Pin;
        buscfg.miso_io_num = -1;
        buscfg.sclk_io_num = SCLK_Pin;
        buscfg.quadwp_io_num = -1;
        buscfg.quadhd_io_num = -1;
        buscfg.max_transfer_sz = 4096;
        ESP_ERROR_CHECK(spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO));

        // SPI device config
        spi_device_interface_config_t devcfg = {};
        devcfg.clock_speed_hz = 10 * 1000 * 1000; // 10 MHz
        devcfg.mode = 0;
        devcfg.spics_io_num = -1; // Manually control CS
        devcfg.queue_size = 1;
        ESP_ERROR_CHECK(spi_bus_add_device(SPI2_HOST, &devcfg, &spi_handle));
    }

    static void SPI_Write(uint8_t val)
    {
        spi_transaction_t t = {};
        t.length = 8; // bits
        t.tx_buffer = &val;
        ESP_ERROR_CHECK(spi_device_transmit(spi_handle, &t));
    }

    void Epaper_Write_Command(uint8_t cmd)
    {
        EPD_W21_CS_0();
        EPD_W21_DC_0();
        SPI_Write(cmd);
        EPD_W21_CS_1();
    }

    void Epaper_Write_Data(uint8_t data)
    {
        EPD_W21_CS_0();
        EPD_W21_DC_1();
        SPI_Write(data);
        EPD_W21_CS_1();
    }

    void EPD_HW_Init_Fast()
    {
        EPD_W21_RST_0();
        vTaskDelay(pdMS_TO_TICKS(10));
        EPD_W21_RST_1();
        vTaskDelay(pdMS_TO_TICKS(10));

        Epaper_Write_Command(0x12); // SWRESET
        Epaper_READBUSY();

        Epaper_Write_Command(0x18); // Built-in temp sensor
        Epaper_Write_Data(0x80);

        Epaper_Write_Command(0x22);
        Epaper_Write_Data(0xB1);
        Epaper_Write_Command(0x20);
        Epaper_READBUSY();

        Epaper_Write_Command(0x1A);
        Epaper_Write_Data(0x64);
        Epaper_Write_Data(0x00);

        Epaper_Write_Command(0x22);
        Epaper_Write_Data(0x91);
        Epaper_Write_Command(0x20);
        Epaper_READBUSY();
    }

    void EPD_Part_Update()
    {
        Epaper_Write_Command(0x22);
        Epaper_Write_Data(0xFF);
        Epaper_Write_Command(0x20);
        Epaper_READBUSY();
    }

    void EPD_Update()
    {
        Epaper_Write_Command(0x22);
        Epaper_Write_Data(0xF7);
        Epaper_Write_Command(0x20);
        Epaper_READBUSY();
    }

    void EPD_Update_Fast()
    {
        Epaper_Write_Command(0x22);
        Epaper_Write_Data(0xC7);
        Epaper_Write_Command(0x20);
        Epaper_READBUSY();
    }

    void EPD_DeepSleep()
    {
        Epaper_Write_Command(0x10);
        Epaper_Write_Data(0x01);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
