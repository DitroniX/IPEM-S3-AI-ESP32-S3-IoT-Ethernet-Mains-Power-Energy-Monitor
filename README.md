## IPEM S3-AI ESP32-S3 IoT Ethernet Mains Power Energy Monitor

**Supporting STEM Electronic Internet of Things & Home Automation Technology for Smart Energy Monitoring**

## Welcome to IPEM S3-AI (Preview)
[![DitroniX WiKi Pages](https://github.com/DitroniX/DitroniX/blob/main/Files/GitHub%20WiKi.png?raw=true)](https://github.com/DitroniX/IPEM-S3-AI-ESP32-S3-IoT-Ethernet-Mains-Power-Energy-Monitor/wiki)

[![DitroniX FAQ Pages](https://github.com/DitroniX/DitroniX/blob/main/Files/GitHub%20WiKi%20FAQ.png?raw=true)](https://github.com/DitroniX/IPEM-S3-AI-ESP32-S3-IoT-Ethernet-Mains-Power-Energy-Monitor/wiki/FAQ)

[![DitroniX Discussions](https://github.com/DitroniX/DitroniX/blob/main/Files/GitHub%20Discussions.png?raw=true)](https://github.com/DitroniX/IPEM-S3-AI-ESP32-S3-IoT-Ethernet-Mains-Power-Energy-Monitor/discussions)

[**For Latest Project Updates - Click Here**](https://github.com/DitroniX/ESPKite-ESP32-C6-SX1262-LoRa-RS485-60V-Relays#updates)

[**Compare Mains Power IoT Energy Monitors**](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki/Compare-Mains-Power-IoT-Energy-Monitors)


![IPEM S3-AI](https://github.com/DitroniX/IPEM-S3-AI-ESP32-S3-IoT-Ethernet-Mains-Power-Energy-Monitor/blob/main/Datasheets%20and%20Information/IPEM%20S3-AI%20-%20Overview.png)

### **What is IPEM S3-AI?**

[](https://github.com/DitroniX/EPEM-Ethernet-Power-Energy-Monitor#what-is-epem)

**IPEM S3-AI**  is an acronym for  **IoT Power Energy Monitor**

**IPEM S3-AI**  is a compact and powerful STEM Community board which is designed for IoT monitoring of mains power circuits.

Incorporating the popular ATM90E36A, this high-precision, poly-phase energy metering IC is designed for advanced power monitoring in residential, commercial, and industrial systems.

By incorporating the powerful Espress S3 MCU, with it's Dual-core Tensilica Xtensa LX7 processor (up to 240 MHz), you are able to take advantage of it's built-in vector instruction sets to accelerate machine-learning math operations.

LLM and AI Integration TinyML & Offline AI capability by running quantized, lightweight models locally (e.g., TensorFlow Lite Micro) for tasks like offline voice wake-words, face recognition, and keyword spotting.

**IPEM S3-AI** Also features a seperate dedicated SPI port for the Ethernet.

### **What is a Power Energy Monitor?**

[](https://github.com/DitroniX/EPEM-Ethernet-Power-Energy-Monitor#what-is-a-power-energy-monitor)

A power energy monitor is a device that safely samples the AC voltage and current flow, from one, or more, electrical phases, and from this, derives a range of accurate mains power measurements which can then be used for smart metering, or energy monitoring purposes.

These individual measurements can then be extrapolated into a range of useful real-time data such as total RMS power, active, re-active power, harmonic power, power factor, phase angles, frequency, etc.

The purpose of extracting the power energy data within Solar Inverter installations, as an example, will enable you to much better manage what you do with the available energy, ways of storage, EV Charging, divert under certain conditions, and control flow from, and to, the grid.

All this data is far more extended information than the basic electric meter functionality, allowing for smart IoT systems and greater efficient use of our own energy. It may sound complicated but it does not need to be and all depends on your setup, use-case and what you want to achieve.

### **Where can IPEM S3-AI be used?**

The  **IPEM S3-AI**  board can be used in a number of projects and installations such as:

-   Homes
-   Education
-   Offices
-   Commercial
-   Factories
-   Farms
-   EV Charging
-   Smart Metering
-   Greenhouses
-   Factories
-   Industry
-   Solar Farms
-   Wind Farms
-   Off Grid Systems

## Top Level Features

The full set of **IPEM S3-AI** features are not yet finalised, however, the top level are:

 - **Espressif ESP32-S3-WROOM-1U-N16R8**
	 - Xtensa® dual-core 32-bit LX7 microprocessor (Clock frequency up to 240 MHz)
	 - Edge AI and AIoT Computing Applications
	 - Dedicated vector instructions designed to accelerate neural network (NN)
	 - 16 MB Quad SPI Flash and 8 MB PSRAM (Pseudo Static RAM)
	 - 512 KB SRAM and 384 KB ROM
	 - 2.4 GHz Wi-Fi (802.11 b/g/n up to 150 Mbps) and Bluetooth® 5 (LE) with long-range support
	 - AI Acceleration vector instructions that accelerate neural network computing and signal processing workloads
	 - Ultra-Low Power (ULP) Co-processor allows the module to remain in deep sleep while performing simple tasks, preserving battery life
	 - 
 - **Microchip ATM90E36A** 
	 - High-performance poly-phase energy metering
	 - Wide Dynamic Range 6000:1
	 - Supports 3-phase 4-wire, 3-phase 3-wire, 2-phase, split-phase systems and singles phases
	 - High Accuracy Measuring active energy to within ±0.1% and reactive energy to ±0.2%
	 - 
 - **Ethernet (Dedicated SPI Port)**
	 - -   Ethernet Controller with Full TCP/IP Stack
	 - 
 - **RS-485 / DMX**
	 - For local data gathering and interfacing
	 - 
 - **DIN Mountable**

## Overview

### **RS-485**

[](https://github.com/DitroniX/EPEM-Ethernet-Power-Energy-Monitor#rs-485)

To interfacing to other Smart Meters, Devices and Smart Batteries which have an RS-485 MODBUS interface, the  **IPEM S3-AI**  includes a standard industry interface which allows you to collect, or control, other devices on the RS-485 bus.

This RS-485 interface could also be used to control local CCTV on remote installations, or even send data from the  **IPEM S3-AI**  board over a single twisted pair, up to around 1,200 meters (4,000 feet), in distance. Ideal for farms and remote installations.

### **Calibration**

[](https://github.com/DitroniX/EPEM-Ethernet-Power-Energy-Monitor#calibration)

The ATM90 series of monitor devices are proven for accuracy. The  **IPEM S3-AI**  core is the  [**ATM90E36A**](https://www.microchip.com/en-us/product/atm90e36a)  which is used around the world in power monitoring instruments that also need to measure voltage, current, THD, DFT and mean power.

The  **IPEM S3-AI**  board requires little, to no, calibration and is easy to setup. 

As the  **IPEM S3-AI**  board only safely sample the AC via a low voltage transformer, you are able to monitor varying AC (RMS) voltage mains around the World, such as:

-   USA and Canada which typically is 120 V or 230 V @ 60 Hz
    -   With ranges around 114 V to 126 V
-   Europe and UK which typically is 230 V @ 50 Hz
    -   With ranges around 216 V to 253 V
-   Japan which typically is 100 V @ 50 Hz or 60 Hz
    -   Eastern Japan is 50 Hz, and Western Japan is 60 Hz
-   Should you wish to know more, see this  [Wiki](https://en.wikipedia.org/wiki/Mains_electricity_by_country)

### **CT Clamps and Rogowski Current Transformer**

**IPEM S3-AI**  was designed primarily for the standard CT clamp such as the YHDC SCT-013 100A-50mA. Inputs for each channel 1, 2, 3, plus N are via Terminal Block Connectors.

You can also use Rogowski Current Transformers on any inputs. Each input is configurable using a jumper.

### **Mains Monitoring**

All my boards are designed to be safe and easy to use - with NO live working, mains electricity parts or dangerous exposed high voltages.

The  **IPEM S3-AI**  uses only low voltage 12 V AC such as from a bell transformer and clip on CT Clamps.

#### **Electrical Circuit Types**

The  **IPEM S3-AI**  is capable of monitoring a number of variations in energy monitoring systems such as:

-   Accurately monitors  _both_  Import and Export
-   Single phase (Home, Office etc.)
-   Multiple Single Phases. (Different circuits or home/office rings, Inverters etc.)
-   Dual Phase (2 x Live -Typically for USA. i.e. 2 x 110V)
-   Three Phase Star (3 x Live and 1 x Neutral)
-   Three Phase Delta (3 x Live)

### **Data Output**

Data provided from the  **IPEM S3-AI**  can be extrapolated through your code in any way you wish, in order to easily integrate with your IoT Home Automation system, or Solar Installation monitor.

All software and code is open source, community based and allows you to develop and integrate as you wish.

The main process typically used for publishing data (internally or externally), is via MQTT, or you could use other direct publishing routes such as to Domoticz, Zabbix or Home Assistant.

#### Data from the ATM90E36 includes:

-   Mains RMS Voltage (each phase)
-   Mains Frequency (each phase)
-   Import and Export Values
    -   Mains RMS Current
    -   Calculated RMS Power
    -   Active Power (Absorbed or Used by the Load)
    -   Calculated Total Active Power
    -   Re-Active Power
    -   Calculated Total Reactive Power
    -   Apparent Power (Total Amount of Power Flowing from Source to Load)
    -   Calculated Total Apparent Power
    -   Fundamental Power
    -   Harmonic Power
    -   Power Factor
    -   Phase Angle

### **Programming and Development**

Development is primarily supported through Visual Studio Code (VSCode) and Arduino IDE. This also includes platforms like ESPHome.

A range of libraries are already available which support the devices on the  **IPEM S3-AI**  such as the:

-   ESP32-s3
-   M90E36
-   W5500
-   24C64
-   DS3231
-   TMP102
-   WS2812

Code support is available in my existing  [GitHub](https://github.com/DitroniX)  IPEM and FLiX repositories, with a specific core IPEM S3-AI [code](https://github.com/DitroniX/IPEM-S3-AI-ESP32-S3-IoT-Ethernet-Mains-Power-Energy-Monitor/tree/main/Code)  repository being provided as the board evolves, together with a new  [FLeX](https://github.com/DitroniX/FLEX-DitroniX-Power-Energy-Monitor-Firmware)  test and bring up firmware, which is in development.

This is a worldwide community project and is able to be integrated in so many systems.


## Updates
-   26-06-17 - Preliminary Launch Information

------------

## **Purchase**

* DitroniX Shop - You may also pre-order, and order, via the http://ditronix.net 

* eBay - Our STEM SDK boards and accessories are available from our online shops on [eBay](https://www.ebay.co.uk/usr/ditronixuk) 

[![Display-Type-B](https://raw.githubusercontent.com/DitroniX/DitroniX/main/Files/DitroniX.net%20STEM%20IoT%20eBay.jpg?raw=true)](https://www.ebay.co.uk/usr/ditronixuk)


## **Further Information**

Additional information, and other technical details on this project, maybe found in the related repository pages.

**Repository Folders**

 - **Code** *(Code examples for Arduino  IDE, Raspberry Pi and PlatformIO)*
 -  **Datasheets and Information** *(Component Datasheets, Schematics, Board Layouts, Photos, Technical Documentation)*
 - **Certification** *(Related Repository Project or Part, Certification Information)*

**Repository Tabs**

 - **Wiki** *(Related Repository Wiki pages and Technical User Information)*
 - **Discussions** *(Related Repository User Discussion Forum)*
 - **Issues** *(Related Repository Technical Issues and Fixes)*

***

We value our Customers, Users of our designs and STEM Communities, all over the World . Should you have any other questions, or feedback to share to others, please feel free to:

* Visit the related [Project](https://github.com/DitroniX?tab=repositories) *plus the related* **Discussions** and **Wiki** Pages.  See tab in each separate repository.
* **Project Community Information** can be found at https://www.hackster.io/DitroniX
* [DitroniX.net Website - Contact Us](https://ditronix.net/contact/)
* **Twitter**: [https://twitter.com/DitroniX](https://twitter.com/DitroniX)
* [Supporting the STEM Projects - BuyMeACoffee](https://www.buymeacoffee.com/DitroniX)
*  **LinkedIN**: [https://www.linkedin.com/in/g8puo/](https://www.linkedin.com/in/g8puo/)

***Dave Williams, Maidstone, UK.***

Electronics Engineer | Software Developer | R&D Support | RF Engineering | Product Certification and Testing | STEM Ambassador

## STEM

**Supporting [STEM Learning](https://www.stem.org.uk/)**

Life is one long exciting learning curve, help others by setting the seed to knowledge.

![DitroniX Supporting STEM](https://hackster.imgix.net/uploads/attachments/1606838/stem_ambassador_-_100_volunteer_badge_edxfxlrfbc1_bjdqharfoe1_xbqi2KUcri.png?auto=compress%2Cformat&w=540&fit=max)
