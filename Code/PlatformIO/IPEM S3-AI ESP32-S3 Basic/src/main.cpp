/*
Dave Williams, DitroniX 2019-2026 (ditronix.net)
IPEM S3-AI - ESP32-S3 | ATM90E36A | WiFi 2.4 | Ethernet (W5500 with PoE) | RS-485 | DS3231SN RTC | IoT Mains Power Energy Monitor

August 2026: Example Code, to demonstrate and test the IPEM S3-AI

Remember!
- Set the BOARD to Use ESP32S3 Dev Module (or similar).
- You can also set the BAUD rate up to 921600 to speed up flashing.
- The SDK does NOT need external power to flash.  It will take Power from the USB 5V.
- The Serial Monitor is configured for BAUD 115200

The purpose of this test code is to cycle through the various main functions of the board as part of bring up testing.

This test code is OPEN SOURCE and formatted for easier viewing.  Although is is not intended for real world use, it may be freely used, or modified as needed.
It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

For board configuration, see https://github.com/DitroniX/IPEM-S3-AI-ESP32-S3-IoT-Ethernet-Mains-Power-Energy-Monitor/wiki/Arduino-IDE

Further information, details and examples can be found on our website or github.com/DitroniX

* ditronix.net
* github.com/DitroniX
* github.com/DitroniX/IPEM-S3-AI-ESP32-S3-IoT-Ethernet-Mains-Power-Energy-Monitor
* github.com/DitroniX/IPEM-S3-AI-ESP32-S3-IoT-Ethernet-Mains-Power-Energy-Monitor/wiki
* hackster.io/DitroniX/ipem-s3-ai-esp32-s3-atm90e36a-iot-ethernet-mains-pwr-monitor-698f14
*/

// Libraries
#include <Arduino.h>

// **************** OUTPUTS ****************
#define RED_LED 2

// **************** SETUP ****************
void setup()
{
    // Stabalise
    delay(250);

    // Initialise UART
    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.println("");

    pinMode(RED_LED, OUTPUT);

    Serial.println("IPEM S3-AI Bring Up and Platform IO Hello World Example Code");
}

// **************** LOOP ****************
void loop()
{
    // RED LED Heatbeat
    digitalWrite(RED_LED, LOW);
    delay(50);
    digitalWrite(RED_LED, HIGH);
    delay(1000);
}