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
#include <SPI.h>
#include <Ethernet.h>  // Remember to install the Ethenet Library (i.e. Ethernet by Various)

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// W5500 Config
#define ETH_TYPE ETH_PHY_W5500
#define ETH_ADDR 1
#define ETH_IRQ 14 // 14
#define ETH_RST 15 // 15

// SPI pins
#define ETH_SPI_SCK 12 // 12
#define ETH_SPI_MISO 13 // 13
#define ETH_SPI_MOSI 11 // 11
#define ETH_CS 10 // 10

// **************** OUTPUTS ****************

// Define Static MAC and IP
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);
IPAddress dns(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// **************** FUNCTIONS AND ROUTINES ****************

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("");

  Serial.println("Starting Ethernet connection...");

  // Initialise IRQ
  pinMode(ETH_IRQ, OUTPUT);  
  digitalWrite(ETH_IRQ, HIGH);

  //Set the CS pin, required for ESP32 as the arduino default is different
  Ethernet.init(ETH_CS);

  //Start the Ethernet connection
  Ethernet.begin(mac, ip, dns, subnet);

  //Hardware check
  Serial.println("Checking Ethernet hardware...");

  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("ERROR: No Ethernet hardware detected!");
    return;
  } else {
    Serial.println("Ethernet Hardware Detected!");
  }

  //Check if cable is connected
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Link is OFF. Check cable connection.");
  } else {
    Serial.println("Link is ON. Cable is connected. Ready to go!");
    Serial.println("Static Ethernet Settings Configured");
    Serial.print("To test connection, please ping from another device on the LAN: ");
    Serial.println(ip);
  }
}

// **************** LOOP ****************
void loop() {
}
