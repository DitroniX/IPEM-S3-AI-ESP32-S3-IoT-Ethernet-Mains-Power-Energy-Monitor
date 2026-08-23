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

/*
  I2C_EEPROM_VERSION: 1.9.4

  Size of Measurement: 	12

  EEPROM Read: 	1745

  Mock Example Measurements

  Temperature:	22.50
  Humidity:	53.10
  Pressure:	516.90

  Test timing writeByte	TIME: 458
  Test timing readByte	TIME: 2566
  Test Timing Total	TIME: 3024

  IPEM S3-AI Bring Up and Test Example Code
*/

// Libraries
#include "Wire.h"
#include "I2C_eeprom.h"

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

I2C_eeprom ee(0x50, I2C_DEVICESIZE_24LC64);

uint32_t start, duration, totals = 0;

struct
{
  float temperature;
  float humidity;
  float pressure;
} measurement;

// Define I2C (Expansion Port)
#define I2C_SDA 8
#define I2C_SCL 9
#define I2C_CLOCK 4000000UL

// **************** FUNCTIONS AND ROUTINES ****************

// **************** SETUP ****************
void setup() {

  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200, SERIAL_8N1);  // U0
  while (!Serial)
    ;  // Wait for serial port to connect

  // Library Version for your Reference
  Serial.println(__FILE__);
  Serial.print("I2C_EEPROM_VERSION: ");
  Serial.println(I2C_EEPROM_VERSION);
  Serial.println("");

  // Initialize I2C
  Wire.begin(I2C_SDA, I2C_SCL);

  // Initialize EEPROM
  ee.begin();
  if (!ee.isConnected()) {
    Serial.println("ERROR: Can't find eeprom (stopped)...");
  }

  Serial.print("Size of Measurement: \t");
  Serial.println(sizeof(measurement));

  Serial.print("\n");

  // Clear Measurements Struct
  measurement.temperature = 0;
  measurement.humidity = 0;
  measurement.pressure = 0;

  // Read Measurements from EEPROM
  start = micros();
  ee.readBlock(0, (uint8_t *)&measurement, sizeof(measurement));
  duration = micros() - start;
  Serial.print("EEPROM Read: \t");
  Serial.println(duration);
  delay(10);

  Serial.println("\nMock Example Measurements\n");

  Serial.print("Temperature:\t");
  Serial.println(measurement.temperature);
  Serial.print("Humidity:\t");
  Serial.println(measurement.humidity);
  Serial.print("Pressure:\t");
  Serial.println(measurement.pressure);

  Serial.print("\n");

  // Write Test
  totals = 0;
  Serial.print("Test timing writeByte\t");
  start = micros();
  ee.writeByte(10, 1);
  duration = micros() - start;
  Serial.print("TIME: ");
  Serial.println(duration);
  totals += duration;

  // Read Test
  Serial.print("Test timing readByte\t");
  start = micros();
  ee.readByte(10);
  duration = micros() - start;
  Serial.print("TIME: ");
  Serial.println(duration);
  totals += duration;

  Serial.print("Test Timing Total\tTIME: ");
  Serial.println(totals);

  Serial.print("\n");

  Serial.println("IPEM S3-AI Bring Up and Test Example Code");
}


void loop() {
}
