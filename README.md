# LVGL 8.4 + GxEPD2_BW Integration for ESP32-S3 with Waveshare ePaper

## Project Overview
This repository provides an integration of LVGL 8.4 with GxEPD2_BW to drive a Waveshare 3.7" ePaper display (480×280, 4 grayscale levels, SPI) on an ESP32-S3 Box using PlatformIO (Arduino framework).

## Features
- Supports 4 grayscale levels and can be extended to displays with more or fewer levels.
- Partial and full refresh control for optimized performance.
- Low-power optimized for energy-efficient applications.
- Easy display switching with minimal modifications.
- Uses PlatformIO and the Arduino framework for ESP32-S3 development.

## Setup and Installation

### Dependencies
Ensure you have PlatformIO installed and configured.  
Add the following library dependencies in your `platformio.ini`:

```ini
[env:esp32s3box]
platform = espressif32
board = esp32s3box
framework = arduino

; Flash configuration
board_build.flash_mode = qio
board_build.flash_freq = 80m
board_build.partitions = default_8MB.csv
board_flash_size = 8MB
board_upload.flash_size = 8MB

lib_deps = 
    ZinggJM/GxEPD2
```

### Getting Started
1. Clone this repository  
   ```bash
   git clone https://github.com/your-repo/lvgl-epaper-esp32.git
   cd lvgl-epaper-esp32
   ```
2. Open the project in PlatformIO.
3. Build and upload the firmware to the ESP32-S3 Box.
4. Test the display and adjust configurations if needed.

## Contributions
Contributions and feedback are welcome. Feel free to submit issues or pull requests to improve the project.

## License
This project is licensed under the MIT License.
