#include "GYW_DisplayCommands.h"
#include "GYW_DisplayInternal.h"
#include "GYW_DisplayResources.h"
#include "../peripherals/lvgl_driver.h"
#include "./GYW_Debug.h"
#include <Arduino.h>
#include <string>
#include <queue>
#include "utils/mpsc.hpp"

// Define virtual and physical resolution dimensions
#define VIRTUAL_WIDTH 854
#define VIRTUAL_HEIGHT 480
#define PHYSICAL_WIDTH 480
#define PHYSICAL_HEIGHT 280

// Scaling factors based on the virtual and physical dimensions
const float scale_factor_x = (float)PHYSICAL_WIDTH / VIRTUAL_WIDTH;
const float scale_factor_y = (float)PHYSICAL_HEIGHT / VIRTUAL_HEIGHT;

// Helper function to scale coordinates to physical resolution
void scaleToPhysical(int16_t& x, int16_t& y)
{
    x = x * scale_factor_x;
    y = y * scale_factor_y;
}

// Helper function to scale font size or other size-based factors (e.g., icon scale)
float scaleFactor(float scale)
{
    return scale * scale_factor_y;
}

uint8_t scaleFontSize(uint8_t fontSize)
{
    return fontSize * scale_factor_y;
}

void processDisplayIconCommand(DisplayCommand* cmd);
void processDisplayTextCommand(DisplayCommand* cmd);
void processClearScreenCommand(DisplayCommand* cmd);
void processDisplayRectangleCommand(DisplayCommand* cmd);
void processSetScreenBrightnessCommand(DisplayCommand* cmd);
void processDisplaySpinnerCommand(DisplayCommand* cmd);

// TODO(arosca): Have explicit messages for each command.
mpsc::Channel<std::function<void()>> draw_calls;

void process_command(DisplayCommand& cmd)
{
    switch (cmd.cmdType)
    {
    case CMD_DISPLAY_ICON:
        processDisplayIconCommand(&cmd);
        break;
    case CMD_DISPLAY_TEXT:
        processDisplayTextCommand(&cmd);
        break;
    case CMD_CLEAR_SCREEN:
        processClearScreenCommand(&cmd);
        break;
    case CMD_DISPLAY_RECTANGLE:
        processDisplayRectangleCommand(&cmd);
        break;
    case CMD_SET_SCREEN_BRIGHTNESS:
        processSetScreenBrightnessCommand(&cmd);
        break;
    case CMD_DISPLAY_SPINNER:
        processDisplaySpinnerCommand(&cmd);
        break;
    default:
        DEBUG_WARNING("Unknown display command: %d\n", cmd.cmdType);
        break;
    }
}


// Display update task
void DisplayUpdateTask(void* pvParameters)
{
    while (true)
    {
        std::vector<std::function<void()>> functions;
        while (true)
        {
            auto f = draw_calls.try_receive();
            if (f.has_value())
            {
                functions.push_back(std::move(*f));
            }
            else
            {
                break;
            }
        }

        for (auto& f : functions)
        {
            f();
        }

        delay(1000);
    }
}

// Initialize display update task
void initDisplayUpdateTask(void)
{
    xTaskCreatePinnedToCore(DisplayUpdateTask, "display_update_task", 8192, NULL, 2, NULL, 1);
}

// Command processing functions

void processDisplayIconCommand(DisplayCommand* cmd)
{
    uint8_t* paramsData = cmd->paramsData;
    size_t paramsLength = cmd->paramsLength;
    std::string iconName = cmd->dataBuffer;

    int index = 0;

    if (paramsLength < 2 + 2 + 4 + 1)
    {
        DEBUG_ERROR("processDisplayIconCommand: Insufficient parameters.\n");
        return;
    }

    int16_t x = (int16_t)((uint16_t)paramsData[index] | ((uint16_t)paramsData[index + 1] << 8));
    index += 2;
    int16_t y = (int16_t)((uint16_t)paramsData[index] | ((uint16_t)paramsData[index + 1] << 8));
    index += 2;
    scaleToPhysical(x, y);

    uint32_t colorValue = ((uint32_t)paramsData[index] << 24) |
        ((uint32_t)paramsData[index + 1] << 16) |
        ((uint32_t)paramsData[index + 2] << 8) |
        (uint32_t)paramsData[index + 3];
    index += 4;

    int8_t scale_byte = (int8_t)paramsData[index++];
    float scale = scaleFactor((scale_byte >= 0) ? 1.0f + (scale_byte / 10.0f) : -((float)scale_byte) / 100.0f);

    uint8_t red = (colorValue >> 24) & 0xFF;
    uint8_t green = (colorValue >> 16) & 0xFF;
    uint8_t blue = (colorValue >> 8) & 0xFF;

    lv_color_t color = lv_color_make(red, green, blue);

    DEBUG_INFO("[processDisplayIconCommand] Icon: '%s'\n", iconName.c_str());
    DEBUG_INFO("[processDisplayIconCommand] Position: (%d, %d)\n", x, y);
    DEBUG_INFO("[processDisplayIconCommand] Scale: %.2f\n", scale);

    draw_calls.send([=]
    {
        displayIcon_internal(iconName.c_str(), x, y, scale, color);
    });
}

void processDisplayTextCommand(DisplayCommand* cmd)
{
    uint8_t* paramsData = cmd->paramsData;
    size_t paramsLength = cmd->paramsLength;
    std::string textData = cmd->dataBuffer;

    int index = 0;

    if (paramsLength < 2 + 2 + 5 + 1 + 4)
    {
        DEBUG_ERROR("processDisplayTextCommand: Insufficient parameters.\n");
        return;
    }

    int16_t x = (int16_t)((uint16_t)paramsData[index] | ((uint16_t)paramsData[index + 1] << 8));
    index += 2;
    int16_t y = (int16_t)((uint16_t)paramsData[index] | ((uint16_t)paramsData[index + 1] << 8));
    index += 2;
    scaleToPhysical(x, y);

    char fontName[6];
    memcpy(fontName, paramsData + index, 5);
    fontName[5] = '\0';
    index += 5;

    uint8_t fontSize = scaleFontSize(paramsData[index++]);

    uint8_t red = paramsData[index++];
    uint8_t green = paramsData[index++];
    uint8_t blue = paramsData[index++];

    lv_color_t color = lv_color_make(red, green, blue);

    DEBUG_INFO("[processDisplayTextCommand] Text: '%s'\n", textData.c_str());
    DEBUG_INFO("[processDisplayTextCommand] Position: (%d, %d)\n", x, y);
    DEBUG_INFO("[processDisplayTextCommand] Font size: %d\n", fontSize);

    draw_calls.send([=]
    {
        displayText_internal(textData.c_str(), x, y, fontName, fontSize, color);
    });
}

void processClearScreenCommand(DisplayCommand* cmd)
{
    uint8_t* paramsData = cmd->paramsData;
    size_t paramsLength = cmd->paramsLength;

    lv_color_t color = lv_color_white();
    if (paramsLength >= 4)
    {
        uint8_t red = paramsData[0];
        uint8_t green = paramsData[1];
        uint8_t blue = paramsData[2];
        color = lv_color_make(red, green, blue);
    }

    DEBUG_INFO("[processClearScreenCommand] Clearing screen with color.\n");

    draw_calls.send([=]
    {
        clearScreen_internal(color);
    });
}

void processDisplayRectangleCommand(DisplayCommand* cmd)
{
    uint8_t* paramsData = cmd->paramsData;
    size_t paramsLength = cmd->paramsLength;

    int index = 0;

    if (paramsLength < 2 + 2 + 2 + 2 + 4)
    {
        DEBUG_ERROR("processDisplayRectangleCommand: Insufficient parameters.\n");
        return;
    }

    int16_t x = (int16_t)((uint16_t)paramsData[index] | ((uint16_t)paramsData[index + 1] << 8));
    index += 2;
    int16_t y = (int16_t)((uint16_t)paramsData[index] | ((uint16_t)paramsData[index + 1] << 8));
    index += 2;
    scaleToPhysical(x, y);

    uint16_t width = (uint16_t)(paramsData[index] | (paramsData[index + 1] << 8));
    index += 2;
    uint16_t height = (uint16_t)(paramsData[index] | (paramsData[index + 1] << 8));
    index += 2;
    width = width * scale_factor_x;
    height = height * scale_factor_y;

    uint8_t red = paramsData[index++];
    uint8_t green = paramsData[index++];
    uint8_t blue = paramsData[index++];

    lv_color_t color = lv_color_make(red, green, blue);

    DEBUG_INFO("[processDisplayRectangleCommand] Rectangle at (%d, %d) size (%d, %d).\n", x, y, width, height);

    draw_calls.send([=]
    {
        displayRectangle_internal(x, y, width, height, color);
    });
}

void processSetScreenBrightnessCommand(DisplayCommand* cmd)
{
    uint8_t* paramsData = cmd->paramsData;
    size_t paramsLength = cmd->paramsLength;

    if (paramsLength < 1)
    {
        DEBUG_ERROR("processSetScreenBrightnessCommand: Insufficient parameters.\n");
        return;
    }

    uint8_t brightness = map(paramsData[0], 0, 255, 0, 100);
    DEBUG_INFO("[processSetScreenBrightnessCommand] Brightness set to: %d\n", brightness);
    setScreenBrightness_internal(brightness);
}

void processDisplaySpinnerCommand(DisplayCommand* cmd)
{
    uint8_t* paramsData = cmd->paramsData;
    size_t paramsLength = cmd->paramsLength;

    if (paramsLength < 2 + 2 + 4 + 1 + 1)
    {
        DEBUG_ERROR("processDisplaySpinnerCommand: Insufficient parameters.\n");
        return;
    }

    int index = 0;

    int16_t x = (int16_t)((uint16_t)paramsData[index] | ((uint16_t)paramsData[index + 1] << 8));
    index += 2;
    int16_t y = (int16_t)((uint16_t)paramsData[index] | ((uint16_t)paramsData[index + 1] << 8));
    index += 2;
    scaleToPhysical(x, y);

    uint8_t red = paramsData[index++];
    uint8_t green = paramsData[index++];
    uint8_t blue = paramsData[index++];

    lv_color_t color = lv_color_make(red, green, blue);

    float scale = scaleFactor((float)paramsData[index++] / 10.0f);
    float spins_per_second = (float)paramsData[index++] / 10.0f;

    DEBUG_INFO("[processDisplaySpinnerCommand] Spinner at (%d, %d) scale %.1f, speed %.1f.\n", x, y, scale,
               spins_per_second);

    draw_calls.send([=]
    {
        displaySpinner_internal(x, y, scale, color, spins_per_second);
    });
}
