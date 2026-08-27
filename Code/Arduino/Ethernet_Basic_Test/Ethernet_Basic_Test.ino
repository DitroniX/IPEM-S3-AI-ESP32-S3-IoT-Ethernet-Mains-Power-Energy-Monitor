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
#include <ETH.h>
#include <SPI.h>
#include <WiFi.h>

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

static bool eth_connected = false;

// **************** FUNCTIONS AND ROUTINES ****************

void onEvent(arduino_event_id_t event, arduino_event_info_t info) {
  switch (event) {
    case ARDUINO_EVENT_ETH_START:
      Serial.println("ETH Started");
      ETH.setHostname("ipems3ai-eth0");
      break;

    case ARDUINO_EVENT_ETH_CONNECTED:
      Serial.println("ETH Connected");
      break;

    case ARDUINO_EVENT_ETH_GOT_IP:
      Serial.printf("ETH Got IP: '%s'\n", esp_netif_get_desc(info.got_ip.esp_netif));
      ETH.printTo(Serial);
      eth_connected = true;
      break;

    case ARDUINO_EVENT_ETH_LOST_IP:
      Serial.println("ETH Lost IP");
      eth_connected = false;
      break;

    case ARDUINO_EVENT_ETH_DISCONNECTED:
      Serial.println("ETH Disconnected");
      eth_connected = false;
      break;

    case ARDUINO_EVENT_ETH_STOP:
      Serial.println("ETH Stopped");
      eth_connected = false;
      break;
    default:
      break;
  }
}

void testClient(const char* host, uint16_t port) {
  Serial.print("\nconnecting to ");
  Serial.println(host);

  WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    return;
  }
  client.printf("GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
  while (client.connected() && !client.available())
    ;
  while (client.available()) {
    Serial.write(client.read());
  }

  Serial.println("closing connection\n");
  client.stop();
}

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200); 
  while (!Serial)
    ;
  Serial.println("");

  // Use onEvent
  WiFi.onEvent(onEvent);

  // Initialise Ethernet
  SPI.begin(ETH_SPI_SCK, ETH_SPI_MISO, ETH_SPI_MOSI);
  ETH.begin(ETH_TYPE, ETH_ADDR, ETH_CS, ETH_IRQ, ETH_RST, SPI);
}

// **************** LOOP ****************
void loop() {

  // HTTP Page Request
  if (eth_connected) {
    testClient("www.google.com", 80);
  }

  delay(10000);
}