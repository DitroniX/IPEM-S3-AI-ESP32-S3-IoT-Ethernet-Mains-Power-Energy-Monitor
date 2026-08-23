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
#include <Wire.h>            // Used to establied serial communication on the I2C bus
#include <SparkFunTMP102.h>  // Used to send and recieve specific information from the sensor

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// Define I2C (Expansion Port)
#define I2C_SDA 8
#define I2C_SCL 9
#define I2C_CLOCK 4000000UL

TMP102 TempSensor;

// Variables TMP102
float TemperatureC;  // TMP102 Temperature C
float TemperatureF;  // TMP102 Temperature F

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

  // Initialize I2C
  Wire.begin(I2C_SDA, I2C_SCL);

  if (!TempSensor.begin(0x4A)) {
    Serial.println("Failed to initialize TMP102");
    while (1)
      ;
  }

  Serial.println("Temperature Sensor (TMP102) Initialised\n");
  delay(100);

  TempSensor.sleep();  // Put sensor to sleep
  
  Serial.println("IPEM S3-AI Bring Up and Test Example Code");
}

// **************** LOOP ****************
void loop() {

  TemperatureC = TempSensor.readTempC();  // Centigrade
  TemperatureF = TempSensor.readTempF();  // Fahrenheit

  Serial.println("TMP102 PCB Temperature: " + String(TemperatureC) + " °C");
  Serial.println("TMP102 PCB Temperature: " + String(TemperatureF) + " °F\n");

  // Return sensor to sleep
  TempSensor.sleep();

  delay(2000);
}
