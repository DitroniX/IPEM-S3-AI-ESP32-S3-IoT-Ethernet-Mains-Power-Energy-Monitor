/*
  Dave Williams, DitroniX 2019-2026 (ditronix.net)
  IPEM S3-AI - ESP32-S3 | ATM90E36A | WiFi 2.4 | Ethernet (W5500 with PoE) | RS-485 | DS3231SN RTC | IoT Mains Power Energy Monitor

  September 2026: Example Code, to demonstrate and test the IPEM S3-AI
 
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

// Test functions: 
// - RS485 to USB Serial Monitor 
// - USB Serial Monitor to RS485 
// - Automatic RS485 direction control 
// - Automatic "RY" transmission after inactivity of 10 seconds
// - Random transmission interval

#include <Wire.h>

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// USB Serial Monitor
#define DEBUG_BAUD 115200

// RS485 UART
#define RS485_BAUD 9600
#define RXLP 18
#define TXLP 17
#define ENLP 45

// Automatic RY transmission
#define RY_INACTIVITY_TIME 10000UL  // 10 seconds

// Random RY interval
#define RY_RANDOM_MIN 10000UL       // 10 seconds
#define RY_RANDOM_MAX 30000UL       // 30 seconds

// Timing
unsigned long lastActivityTime = 0;
unsigned long nextRYTime = 0;

// **************** FUNCTIONS AND ROUTINES ****************

// Set RS485 transceiver to RECEIVE mode
void rs485ReceiveMode() {
  digitalWrite(ENLP, LOW);
}

// Set RS485 transceiver to TRANSMIT mode
void rs485TransmitMode() {
  digitalWrite(ENLP, HIGH);
}

// Send data over RS485
void rs485Write(const char *data) {

  // Enable RS485 transmitter
  rs485TransmitMode();

  // Send data
  Serial1.print(data);

  // Wait until all UART data has physically been transmitted
  Serial1.flush();

  // Return to receive mode
  rs485ReceiveMode();

  // Record activity
  lastActivityTime = millis();

  // Select a new random RY interval
  nextRYTime = millis() + random(RY_RANDOM_MIN, RY_RANDOM_MAX + 1);
}

// Send all available USB Serial data to RS485
void rs485ForwardSerial() {

  if (Serial.available() > 0) {

    // Enable RS485 transmitter
    rs485TransmitMode();

    // Forward all available bytes
    while (Serial.available() > 0) {
      Serial1.write(Serial.read());
    }

    // Wait for final byte to leave UART
    Serial1.flush();

    // Return to receive mode
    rs485ReceiveMode();

    // Record activity
    lastActivityTime = millis();

    // Select a new random RY interval
    nextRYTime = millis() + random(RY_RANDOM_MIN, RY_RANDOM_MAX + 1);
  }
}

// Read incoming RS485 data
void rs485Read() {

  bool receivedData = false;

  while (Serial1.available() > 0) {

    uint8_t incomingByte = Serial1.read();

    // Output received RS485 data to Serial Monitor
    Serial.write(incomingByte);

    receivedData = true;
  }

  // Any RS485 input resets the inactivity timer
  if (receivedData) {

    lastActivityTime = millis();

    // Select a new random RY interval
    nextRYTime = millis() + random(RY_RANDOM_MIN, RY_RANDOM_MAX + 1);
  }
}

// Check whether automatic RY transmission is required
void checkAutomaticRY() {

  unsigned long now = millis();

  // First require at least 10 seconds of inactivity
  if ((now - lastActivityTime) >= RY_INACTIVITY_TIME) {

    // Check whether the random transmission time has arrived
    if ((long)(now - nextRYTime) >= 0) {

      Serial.println();
      Serial.println("No activity - Sending automatic RY");

      rs485Write("RY ");

      Serial.println("RS485 TX: RY");
    }
  }
}

// **************** SETUP ****************

void setup() {

  // Stabilise
  delay(250);

  // Initialise USB Serial Monitor
  Serial.begin(DEBUG_BAUD);

  while (!Serial) {
    ;
  }

  Serial.println();
  Serial.println("IPEM S3-AI Bring Up and Test Example Code");
  Serial.println();

  // Initialise RS485 enable pin
  pinMode(ENLP, OUTPUT);

  // Start in RECEIVE mode
  rs485ReceiveMode();

  // Initialise UART1 - RS485 Port
  Serial1.begin(RS485_BAUD, SERIAL_8N1, RXLP, TXLP);

  Serial.println("UART 1 Opened (RS485 Port)");
  Serial.println("RS485 UART Baud: 9600");
  Serial.println("RS485 RX: GPIO18");
  Serial.println("RS485 TX: GPIO17");
  Serial.println("RS485 Enable: GPIO45");
  Serial.println();

  Serial.println("RS485 Bidirectional Test");
  Serial.println("Type into the Serial Monitor to transmit over RS485.");
  Serial.println("Received RS485 data will be displayed here.");
  Serial.println();
  Serial.println("Automatic RY enabled.");
  Serial.println("RY starts after 10 seconds of inactivity.");
  Serial.println("Random RY interval: 10 to 30 seconds.");
  Serial.println();

  // Seed random number generator
  randomSeed(micros());

  // Start inactivity timer
  lastActivityTime = millis();

  // Set initial random RY transmission time
  nextRYTime = millis() + random(RY_RANDOM_MIN, RY_RANDOM_MAX + 1);

  Serial.println("IPEM S3-Ai Bring Up and Test Example Code");
  Serial.println("Running RS485 TX/RX Test");  
}

// **************** LOOP ****************

void loop() {

  // ============================================================
  // RS485 RECEIVE
  // ============================================================

  rs485ReceiveMode();

  rs485Read();

  // ============================================================
  // SERIAL MONITOR -> RS485 TRANSMIT
  // ============================================================

  rs485ForwardSerial();

  // ============================================================
  // AUTOMATIC RY TRANSMISSION
  // ============================================================

  checkAutomaticRY();
}
