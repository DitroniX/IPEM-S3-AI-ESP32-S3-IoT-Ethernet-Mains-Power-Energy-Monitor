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

#include <ETH.h>
#include <SPI.h>
#include <Network.h>
#include <ESPping.h> // Library https://github.com/dvarrel/ESPping

// ---------- Pin configuration (change if needed) ----------
#define ETH_TYPE ETH_PHY_W5500
#define ETH_ADDR 1
#define ETH_IRQ 14 // 14
#define ETH_RST 15 // 15

// SPI pins
#define ETH_SPI_SCK 12 // 12
#define ETH_SPI_MISO 13 // 13
#define ETH_SPI_MOSI 11 // 11
#define ETH_CS 10 // 10

// ---------- Status variables ----------
static bool eth_connected = false;
static unsigned long lastCheck = 0;
const unsigned long CHECK_INTERVAL = 5000;   // check every 5 seconds

// ---------- Event callback ----------
void onEvent(arduino_event_id_t event, arduino_event_info_t info) {
  switch (event) {
    case ARDUINO_EVENT_ETH_START:
      Serial.println("[ETH] Started");
      // Optional: ETH.setHostname("esp32s3-w5500");
      break;

    case ARDUINO_EVENT_ETH_CONNECTED:
      Serial.println("[ETH] Link UP (cable connected)");
      break;

    case ARDUINO_EVENT_ETH_GOT_IP:
      Serial.println("[ETH] Got IP address");
      Serial.print("      Local IP : ");
      Serial.println(ETH.localIP());
      Serial.print("      Subnet   : ");
      Serial.println(ETH.subnetMask());
      Serial.print("      Gateway  : ");
      Serial.println(ETH.gatewayIP());
      Serial.print("      DNS      : ");
      Serial.println(ETH.dnsIP());
      Serial.print("      MAC      : ");
      Serial.println(ETH.macAddress());
      eth_connected = true;
      break;

    case ARDUINO_EVENT_ETH_LOST_IP:
      Serial.println("[ETH] Lost IP");
      eth_connected = false;
      break;

    case ARDUINO_EVENT_ETH_DISCONNECTED:
      Serial.println("[ETH] Link DOWN (cable disconnected)");
      eth_connected = false;
      break;

    case ARDUINO_EVENT_ETH_STOP:
      Serial.println("[ETH] Stopped");
      eth_connected = false;
      break;

    default:
      break;
  }
}

void setup() {
  Serial.begin(115200);
  delay(800);
  Serial.println("\n=== IPEM S3-AI ESP32-S3 + W5500 Ethernet Test ===");

  // Register event handler
  Network.onEvent(onEvent);

  // Configuration
  SPI.begin(ETH_SPI_SCK, ETH_SPI_MISO, ETH_SPI_MOSI);
  ETH.begin(ETH_TYPE, ETH_ADDR, ETH_CS, ETH_IRQ, ETH_RST, SPI);

  Serial.println("Initializing IPEM S3-A W5500...");

  Serial.println("ETH.begin() OK – waiting for link & IP...");
}

void loop() {

  // Periodic communications / health check
  if (millis() - lastCheck >= CHECK_INTERVAL) {
    lastCheck = millis();

    Serial.println("----- IPEM S3-A W5500 Status Check -----");
    Serial.print("Link up      : ");
    Serial.println(ETH.linkUp() ? "YES" : "NO");
    
    Serial.print("Connected    : ");
    Serial.println(eth_connected ? "YES" : "NO");
    
    if (ETH.linkUp()) {
      Serial.print("Local IP     : ");
      Serial.println(ETH.localIP());
      Serial.print("Full duplex  : ");
      Serial.println(ETH.fullDuplex() ? "YES" : "NO");
      Serial.print("Link speed   : ");
      Serial.print(ETH.linkSpeed());
      Serial.println(" Mbps");

      Serial.print("Pinging Gateway ");
      Serial.println(ETH.gatewayIP());

      if(Ping.ping(ETH.gatewayIP())) {
        Serial.println("Success!!");
      } else {
        Serial.println("Error :(");
      }

    } else {
      Serial.println("No physical link – check ethernet cable or connection");
    }
    Serial.println("------------------------------\n");
  }

  // Delay
  delay(1000);
}