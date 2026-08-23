Note:   The load is a resistive 300W @ 248V AC input.  Using 3 x CT Clamps over the single phase mains cable.

===========


UART 1 Opened (RS485 Port)

IPEM S3-AI - Integrated Firmware for DitroniX Power Energy MonitorSDK Boards

Scanning and Configuring Board.. Please Wait..

Hardware Options and Auto Configuration
────────────────────────────────────────
Scanning I2C Bus for Devices for Auto Configuration ...
 I2C Possible Device(s) found at Address:
 * Hex 0x3C (60)         OLED
 * Hex 0x49 (73)         ADS1115 16-bit ADC
 * Hex 0x4A (74)         TMP102 Temperature Sensor
 * Hex 0x50 (80)         EEPROM
 * Hex 0x58 (88)         EEPROM
 * Hex 0x68 (104)        DS3231SN Accurate RTC
 I2C Bus Scan Complete

IPEM S3-AI IoT Power Energy Monitor Controller

IPEM S3-AI Register Status and Startup Report
ESP32-S3 Serial ID: 64D2A276B144
IPEM S3-AI Firmware Version: 260817
Board Location: Test

Temperature Sensor (TMP102) Initialised

Initialising OLED Display
Done

Software Options
─────────────────
Connecting to the ATM90E36
====================================
ATM90E36 Connected - OK
ATM_SINGLE_PHASE


IPEM S3-AI Hardware Setup and Power-Up Test - Board Initialized

IPEM S3-AI IoT Power Energy Monitor Controller

IPEM S3-AI Register Status and Startup Report
ESP32-S3 Serial ID: 64D2A276B144
IPEM S3-AI Firmware Version: 260817
Board Location: Test
Hardware Configuration for ATM90E36
────────────────────────────────────
AC Voltage Inputs:      Single Input V1 will be used for Current Phase Calculations
Split AC Voltage:       Dual  or Split Voltage Input Disabled
CT Current Clamps:      Configured for 1, 2, 3 Phase

[Status Values]
System Status:          S0:0xC0         S1:0x0
Meter Status:           E0:0x0          E1:0x0

Mains RMS Voltage
──────────────────
- - - - - - - - - - - - - - - - - - - - - - - - - - - 
Voltage 1: 237.91 V (Single Line Voltage Selected)

Mains RMS Current
──────────────────
Current CT1: 1.25 A
Current CT2: 0.00 A
Current CT3: 0.00 A

Current CTN: 1.25 A
- - - - - - - - - - - - - - - - - - - - - - - 
Actual Total Current: 1.25 A (CT1~CT2~CT3)

Calculated RMS Power
─────────────────────
Power V1*I1: 297.39 W   0.30 kW
Power V1*I2: 0.00 W     0.00 kW
Power V1*I3: 0.00 W     0.00 kW
Power V1*I4: 0.00 W
- - - - - - - - - - - - - - - - - - - - - - - - - 
Calculated Total Power: 297.39 W (CT1~CT2~CT3)

Active Power (Absorbed or Used by the Load)
────────────────────────────────────────────
Active Power CT1: 0.30 kW       (Import)
Active Power CT2: 0.00 kW 
Active Power CT3: 0.00 kW 
- - - - - - - - - - - - - - - - - - - - 
Total Active Power: 0.30 kW     (Import)
- - - - - - - - - - - - - - - - - - - - - - - - - - - 
Calculated Total Active Power: 0.30 W (CT1~CT2~CT3)

Re-Active Power
────────────────
ReActive Power CT1: 0.00 VAR
ReActive Power CT2: 0.00 VAR
ReActive Power CT3: 0.00 VAR
- - - - - - - - - - - - - - - - - - - - - - - - 
Total ReActive Power: 0.00 VAR (CT1~CT2~CT3)
- - - - - - - - - - - - - - - - - - - - - - - - - - - - 
Calculated Total Reactive Power: 0.00 W (CT1~CT2~CT3)

Apparent Power (Total Amount of Power Flowing from Source to Load)
───────────────────────────────────────────────────────────────────
Apparent Power CT1: 0.30 VA
Apparent Power CT2: 0.00 VA
Apparent Power CT3: 0.00 VA
- - - - - - - - - - - - - - - - - - - - - - - 
Total Apparent Power: 0.30 VA (CT1~CT2~CT3)
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
Calculated Total Apparent Power: 0.30 VA (CT1~CT2~CT3)


Power Factor
─────────────
Power Factor CT1: 1.00 PF
Power Factor CT2: 0.00 PF
Power Factor CT3: 0.00 PF
- - - - - - - - - - - - - - - 
Total Power Factor: 1.00 PF

Phase Angle
────────────
Phase Angle CT1: 2.80
Phase Angle CT2: 4.20
Phase Angle CT3: 0.00

Voltage Harmonics
──────────────────
Voltage Harmonics CT1: 0.00
Voltage Harmonics CT2: 0.00
Voltage Harmonics CT3: 0.00

Current Harmonics
──────────────────
Current Harmonics CT1: 0.00
Current Harmonics CT2: 0.00
Current Harmonics CT3: 0.00

Other Information
──────────────────
Chip Temperature: 28.00 °C

Mains Frequency: 49.97 Hz

TMP102 PCB Temperature: 33.44 °C
TMP102 PCB Temperature: 92.19 °F


Calibration Register Check

Single Phase Mains Voltage Selected.  Only V1 is used, for CT1, CT2, CT3

Remember to use PCB Jumpers to link V1, V2 and V3
or use external wire jumpers in V1, V2, and V3.

AC Mains Extrapolated Voltage: 237.80 V

UGain V1        0x61    0x4EE8 (20200)  237.80 V

IGain CT1       0x62    0x82DC (33500)  1.25 A  297.25 W
IGain CT2       0x66    0x82DC (33500)  0.00 A  0.24 W
IGain CT3       0x6A    0x82DC (33500)  0.00 A  0.24 W