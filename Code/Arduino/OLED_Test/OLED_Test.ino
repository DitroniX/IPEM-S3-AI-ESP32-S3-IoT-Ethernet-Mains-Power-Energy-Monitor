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
#include <GyverOLED.h>
#include <Adafruit_NeoPixel.h>

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// Define I2C (Expansion Port)
#define I2C_SDA 8
#define I2C_SCL 9
#define I2C_CLOCK 4000000UL

// RGB
#define PIN_WS2812B 48  // The ESP32-S3 connected to WS2812B
Adafruit_NeoPixel ws2812b(1, PIN_WS2812B, NEO_GRB + NEO_KHZ800);

// **************** OUTPUTS ****************
#define LED_Red 2  // Red LED

// OLED Instance. You will need to select your OLED Display. 
// Uncomment/Comment as needed.
GyverOLED<SSD1306_128x32, OLED_BUFFER> oled;  //0.6"
//GyverOLED<SSD1306_128x32, OLED_NO_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
// GyverOLED<SSH1106_128x64> oled; //1.1"

// Draw Battery
void drawBattery(byte percent) {
  oled.drawByte(0b00111100);
  oled.drawByte(0b00111100);
  oled.drawByte(0b11111111);
  for (byte i = 0; i < 100 / 8; i++) {
    if (i < (100 - percent) / 8) oled.drawByte(0b10000001);
    else oled.drawByte(0b11111111);
  }
  oled.drawByte(0b11111111);
}

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200);
  while (!Serial)
    ;  // Wait for serial port to connect
  Serial.println("");

  // Initialise RED LED on GP22
  pinMode(LED_Red, OUTPUT);

  // Initialize I2C
  Wire.begin(I2C_SDA, I2C_SCL);

  ws2812b.begin();  // Initialize WS2812B
  ws2812b.clear();  // Turn off RGB

  Serial.println("IPEM S3-AI - Example Code");
}

// **************** LOOP ****************
void loop() {

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();

  // GREEN
  ws2812b.setPixelColor(0, ws2812b.Color(0, 50, 0));
  ws2812b.show();
  delay(500);


  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(8, 0);
  oled.setScale(2);
  oled.print("IPEM S3-AI");
  oled.update();
  delay(500);

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip

  // BLUE
  ws2812b.setPixelColor(0, ws2812b.Color(0, 0, 50));
  ws2812b.show();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(8, 1);
  oled.setScale(2);
  oled.print("IPEM S3-AI");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(8, 2);
  oled.setScale(2);
  oled.print("IPEM S3-AI");
  oled.update();
  delay(500);

  // RED
  ws2812b.setPixelColor(0, ws2812b.Color(50, 0, 0));
  ws2812b.show();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(8, 1);
  oled.setScale(3);
  oled.print("LAN POE");
  oled.update();

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip

  // BLUE
  ws2812b.setPixelColor(0, ws2812b.Color(0, 0, 50));
  ws2812b.show();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(27, 1);
  oled.setScale(3);
  oled.print("RS485");
  oled.update();

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();

  // GREEN
  ws2812b.setPixelColor(0, ws2812b.Color(0, 50, 0));
  ws2812b.show();
  delay(500);

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(8, 2);
  oled.setScale(2);
  oled.print("IPEM S3-AI");
  oled.update();

  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(24, 1);
  oled.setScale(3);
  oled.print("RTC");
  oled.update();

  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(19, 1);
  oled.setScale(3);
  oled.print("5-20V");
  oled.update();

  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(13, 1);
  oled.setScale(2);
  oled.print("ESP32-S3");
  oled.update();

  delay(500);

  // Heatbeat LED
  digitalWrite(LED_Red, HIGH);
  delay(100);
  digitalWrite(LED_Red, LOW);
}
