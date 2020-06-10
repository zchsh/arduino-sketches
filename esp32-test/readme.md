## Getting Started

I found [this tutorial](https://electricnoodlebox.com/tutorials/esp32-ttgo-dev-board-with-oled-display-tutorial/) helpful. There were a few missing pieces:

1. You need to download a [`CP210x USB to UART Driver`](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) to make connecting to the ESP32 unit possible.

2. You need to set up `platformio.ini` with a few extra settings. This ensures the correct port is used for upload and serial monitoring. It also matches the `115200` baud rate used in the example tutorial.

   ```
   upload_port = /dev/cu.SLAB_USBtoUART
   monitor_port = /dev/cu.SLAB_USBtoUART
   monitor_speed = 115200
   ```

3. Some ESP32 units have a `Boot` button. You need to hold down the `Boot` button when uploading, otherwise the upload will just show `Connecting...` for a while and then will time out.

4. Some of the lines in the [example tutorial](https://electricnoodlebox.com/tutorials/esp32-ttgo-dev-board-with-oled-display-tutorial/) seem to have been filtered out by HTML sanitizing. For example, the line `#include <Arduino.h>` is usually at the top of files. This line needs to be added back in. I've copied the sample code from the tutorial into `./examples` to avoid any confusion.
