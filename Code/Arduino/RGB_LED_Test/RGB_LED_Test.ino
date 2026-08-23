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
#include <Adafruit_NeoPixel.h>

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************
// RGB
#define PIN_WS2812B 48  // The ESP32-C5 pin GPIO27 connected to WS2812B
Adafruit_NeoPixel ws2812b(2, PIN_WS2812B, NEO_GRB + NEO_KHZ800);

// **************** FUNCTIONS AND ROUTINES ****************

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200);
  while (!Serial)
    ;  // Wait for serial port to connect
  Serial.println("");

  ws2812b.begin();  // Initialize WS2812B
  ws2812b.clear();  // Turn off RGB for two seconds

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();
  delay(250);

  Serial.println("IPEM S3-AI Bring Up and Test Example Code");
}

// **************** LOOP ****************
void loop() {

  // RED
  ws2812b.setPixelColor(0, ws2812b.Color(150, 0, 0));
  ws2812b.show();
  delay(250);

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);

  // GREEN
  ws2812b.setPixelColor(0, ws2812b.Color(0, 150, 0));   // GREEN
  ws2812b.show();
  delay(250);

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();
  delay(250);

  // BLUE
  ws2812b.setPixelColor(0, ws2812b.Color(0, 0, 150));
  ws2812b.show();
  delay(250);

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);

  // White
  ws2812b.setPixelColor(0, ws2812b.Color(150, 150, 150));
  ws2812b.show();
  delay(250);

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);
}
