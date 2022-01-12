EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 61C9CE3A
P 6700 3250
F 0 "U1" H 6056 3296 50  0000 R CNN
F 1 "ATmega328P-PU" H 6056 3205 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 6700 3250 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 6700 3250 50  0001 C CNN
	1    6700 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 61CF5334
P 3000 3100
F 0 "D2" H 2993 3317 50  0000 C CNN
F 1 "LED" H 2993 3226 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm_IRBlack" H 3000 3100 50  0001 C CNN
F 3 "~" H 3000 3100 50  0001 C CNN
	1    3000 3100
	0    -1   -1   0   
$EndComp
NoConn ~ 5250 1050
$Comp
L power:GND #PWR01
U 1 1 61D1516F
P 5250 1250
F 0 "#PWR01" H 5250 1000 50  0001 C CNN
F 1 "GND" H 5255 1077 50  0000 C CNN
F 2 "" H 5250 1250 50  0001 C CNN
F 3 "" H 5250 1250 50  0001 C CNN
	1    5250 1250
	1    0    0    -1  
$EndComp
Text GLabel 4750 1000 1    50   Input ~ 0
MISO
Text GLabel 7300 2450 2    50   Output ~ 0
MISO
Text GLabel 4750 1300 3    50   Output ~ 0
RESET
Text GLabel 7300 3550 2    50   Input ~ 0
RESET
Text GLabel 7300 2650 2    50   BiDi ~ 0
XTAL1
Text GLabel 3100 4300 0    50   BiDi ~ 0
XTAL1
Text GLabel 3400 4300 2    50   BiDi ~ 0
XTAL2
Text GLabel 7300 2750 2    50   BiDi ~ 0
XTAL2
$Comp
L Device:Crystal Y1
U 1 1 61D17974
P 3250 4300
F 0 "Y1" H 3250 4568 50  0000 C CNN
F 1 "32.768kHz" H 3250 4477 50  0000 C CNN
F 2 "Crystal:Crystal_C38-LF_D3.0mm_L8.0mm_Horizontal" H 3250 4300 50  0001 C CNN
F 3 "~" H 3250 4300 50  0001 C CNN
	1    3250 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 61D1E12F
P 5400 1150
F 0 "R5" V 5193 1150 50  0000 C CNN
F 1 "10K" V 5284 1150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5330 1150 50  0001 C CNN
F 3 "~" H 5400 1150 50  0001 C CNN
	1    5400 1150
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J1
U 1 1 61D13492
P 4950 1150
F 0 "J1" H 5000 1467 50  0000 C CNN
F 1 "ICSP" H 5000 1376 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 4950 1150 50  0001 C CNN
F 3 "~" H 4950 1150 50  0001 C CNN
	1    4950 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 61D1F73B
P 4600 1150
F 0 "R4" V 4393 1150 50  0000 C CNN
F 1 "10K" V 4484 1150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4530 1150 50  0001 C CNN
F 3 "~" H 4600 1150 50  0001 C CNN
	1    4600 1150
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 61D1FF64
P 5550 1300
F 0 "R6" H 5620 1346 50  0000 L CNN
F 1 "20K" H 5620 1255 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5480 1300 50  0001 C CNN
F 3 "~" H 5550 1300 50  0001 C CNN
	1    5550 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 61D205B1
P 4450 1300
F 0 "R3" H 4520 1346 50  0000 L CNN
F 1 "20K" H 4520 1255 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4380 1300 50  0001 C CNN
F 3 "~" H 4450 1300 50  0001 C CNN
	1    4450 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1050 4750 1000
Wire Wire Line
	4750 1300 4750 1250
$Comp
L power:GND #PWR08
U 1 1 61D223FC
P 4450 1450
F 0 "#PWR08" H 4450 1200 50  0001 C CNN
F 1 "GND" H 4455 1277 50  0000 C CNN
F 2 "" H 4450 1450 50  0001 C CNN
F 3 "" H 4450 1450 50  0001 C CNN
	1    4450 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 61D22773
P 5550 1450
F 0 "#PWR09" H 5550 1200 50  0001 C CNN
F 1 "GND" H 5555 1277 50  0000 C CNN
F 2 "" H 5550 1450 50  0001 C CNN
F 3 "" H 5550 1450 50  0001 C CNN
	1    5550 1450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW3
U 1 1 61D385F8
P 4500 2850
F 0 "SW3" H 4500 3085 50  0000 C CNN
F 1 "B" H 4500 2994 50  0000 C CNN
F 2 "Button_Switch_THT:SW_TH_Tactile_Omron_B3F-10xx" H 4500 2850 50  0001 C CNN
F 3 "~" H 4500 2850 50  0001 C CNN
	1    4500 2850
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_SPST SW4
U 1 1 61D38A0A
P 5050 2850
F 0 "SW4" H 5050 3085 50  0000 C CNN
F 1 "C" H 5050 2994 50  0000 C CNN
F 2 "Button_Switch_THT:SW_TH_Tactile_Omron_B3F-10xx" H 5050 2850 50  0001 C CNN
F 3 "~" H 5050 2850 50  0001 C CNN
	1    5050 2850
	0    -1   -1   0   
$EndComp
$Comp
L Device:Buzzer BZ1
U 1 1 61D47E46
P 4500 4550
F 0 "BZ1" H 4652 4579 50  0000 L CNN
F 1 "Buzzer" H 4652 4488 50  0000 L CNN
F 2 "Buzzer_Beeper:MagneticBuzzer_PUI_AT-0927-TT-6-R" V 4475 4650 50  0001 C CNN
F 3 "~" V 4475 4650 50  0001 C CNN
	1    4500 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 61D488E3
P 4400 4250
F 0 "R7" V 4193 4250 50  0000 C CNN
F 1 "195R" V 4284 4250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4330 4250 50  0001 C CNN
F 3 "~" H 4400 4250 50  0001 C CNN
	1    4400 4250
	-1   0    0    1   
$EndComp
Text GLabel 7300 4150 2    50   Output ~ 0
DISPLAY_CLOCK
Text GLabel 7300 3850 2    50   Output ~ 0
DISPLAY_MOSI
Text GLabel 5600 1150 2    50   Output ~ 0
MOSI
Wire Wire Line
	5600 1150 5550 1150
Connection ~ 5550 1150
Text GLabel 4400 1150 0    50   Output ~ 0
SCK
Wire Wire Line
	4450 1150 4400 1150
Connection ~ 4450 1150
Text GLabel 7300 2350 2    50   Input ~ 0
MOSI
Text GLabel 7300 2550 2    50   Input ~ 0
SCK
$Comp
L power:GND #PWR0111
U 1 1 61D8C9ED
P 6700 4750
F 0 "#PWR0111" H 6700 4500 50  0001 C CNN
F 1 "GND" H 6705 4577 50  0000 C CNN
F 2 "" H 6700 4750 50  0001 C CNN
F 3 "" H 6700 4750 50  0001 C CNN
	1    6700 4750
	1    0    0    -1  
$EndComp
Text GLabel 7300 4250 2    50   Output ~ 0
DISPLAY_DATA_COMMAND
Text GLabel 7300 4350 2    50   Output ~ 0
SPEAKER
Text GLabel 8150 2600 2    50   Input ~ 0
A_BUTTON
Text GLabel 8350 2800 2    50   Input ~ 0
B_BUTTON
Text GLabel 7300 3150 2    50   Input ~ 0
C_BUTTON
Text GLabel 7300 2150 2    50   Output ~ 0
LINK_TRANSMITTER
NoConn ~ 7300 3250
NoConn ~ 7300 2250
$Comp
L power:GND #PWR06
U 1 1 61D10F35
P 3950 3050
F 0 "#PWR06" H 3950 2800 50  0001 C CNN
F 1 "GND" H 3955 2877 50  0000 C CNN
F 2 "" H 3950 3050 50  0001 C CNN
F 3 "" H 3950 3050 50  0001 C CNN
	1    3950 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 61D111FD
P 4500 3050
F 0 "#PWR010" H 4500 2800 50  0001 C CNN
F 1 "GND" H 4505 2877 50  0000 C CNN
F 2 "" H 4500 3050 50  0001 C CNN
F 3 "" H 4500 3050 50  0001 C CNN
	1    4500 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 61D1141D
P 5050 3050
F 0 "#PWR011" H 5050 2800 50  0001 C CNN
F 1 "GND" H 5055 2877 50  0000 C CNN
F 2 "" H 5050 3050 50  0001 C CNN
F 3 "" H 5050 3050 50  0001 C CNN
	1    5050 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 61D11914
P 4400 4650
F 0 "#PWR013" H 4400 4400 50  0001 C CNN
F 1 "GND" H 4405 4477 50  0000 C CNN
F 2 "" H 4400 4650 50  0001 C CNN
F 3 "" H 4400 4650 50  0001 C CNN
	1    4400 4650
	1    0    0    -1  
$EndComp
Text GLabel 3900 2600 0    50   Output ~ 0
A_BUTTON
Text GLabel 4450 2600 0    50   Output ~ 0
B_BUTTON
Text GLabel 5000 2600 0    50   Output ~ 0
C_BUTTON
$Comp
L Device:R R8
U 1 1 61D12D22
P 3000 2800
F 0 "R8" H 2930 2754 50  0000 R CNN
F 1 "270R" H 2930 2845 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2930 2800 50  0001 C CNN
F 3 "~" H 3000 2800 50  0001 C CNN
	1    3000 2800
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 61D13797
P 3000 3250
F 0 "#PWR012" H 3000 3000 50  0001 C CNN
F 1 "GND" V 3005 3122 50  0000 R CNN
F 2 "" H 3000 3250 50  0001 C CNN
F 3 "" H 3000 3250 50  0001 C CNN
	1    3000 3250
	1    0    0    -1  
$EndComp
Text GLabel 2950 2600 0    50   Input ~ 0
LINK_TRANSMITTER
Text GLabel 7300 3350 2    50   Input ~ 0
LINK_RECEIVER_DATA
Text GLabel 1450 3100 0    50   Output ~ 0
LINK_RECEIVER_DATA
$Comp
L power:GND #PWR014
U 1 1 61D17EF9
P 1750 3300
F 0 "#PWR014" H 1750 3050 50  0001 C CNN
F 1 "GND" V 1755 3172 50  0000 R CNN
F 2 "" H 1750 3300 50  0001 C CNN
F 3 "" H 1750 3300 50  0001 C CNN
	1    1750 3300
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC240 Q1
U 1 1 61D1851E
P 1650 3100
F 0 "Q1" H 1841 3146 50  0000 L CNN
F 1 "VS1838B" H 1841 3055 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92L_Inline_Wide" H 1850 3200 50  0001 C CNN
F 3 "~" H 1650 3100 50  0001 C CNN
	1    1650 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 61D19A17
P 1750 2750
F 0 "R9" H 1680 2704 50  0000 R CNN
F 1 "100R" H 1680 2795 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1680 2750 50  0001 C CNN
F 3 "~" H 1750 2750 50  0001 C CNN
	1    1750 2750
	-1   0    0    1   
$EndComp
$Comp
L Device:CP C5
U 1 1 61D19BFB
P 2300 3100
F 0 "C5" H 2418 3146 50  0000 L CNN
F 1 "47uF" H 2418 3055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 2338 2950 50  0001 C CNN
F 3 "~" H 2300 3100 50  0001 C CNN
	1    2300 3100
	1    0    0    -1  
$EndComp
Text GLabel 7300 3450 2    50   Output ~ 0
LINK_RECEIVER_POWER
Wire Wire Line
	2300 2900 1750 2900
Connection ~ 1750 2900
Wire Wire Line
	2300 2900 2300 2950
Text GLabel 1700 2600 0    50   Input ~ 0
LINK_RECEIVER_POWER
Wire Wire Line
	2300 3250 2300 3300
Wire Wire Line
	2300 3300 1750 3300
Connection ~ 1750 3300
Wire Wire Line
	2950 2600 3000 2600
Wire Wire Line
	3000 2600 3000 2650
Wire Wire Line
	1750 2600 1700 2600
Text GLabel 4350 4050 0    50   Input ~ 0
SPEAKER
Wire Wire Line
	4400 4100 4400 4050
Wire Wire Line
	4400 4050 4350 4050
Wire Wire Line
	4400 4400 4400 4450
Text GLabel 6700 1750 1    50   Input ~ 0
FILTERED_VCC
Text GLabel 6800 1750 1    50   Input ~ 0
FILTERED_VCC
NoConn ~ 6100 2050
$Comp
L Switch:SW_SPST SW2
U 1 1 61CFD685
P 3950 2850
F 0 "SW2" H 3950 3085 50  0000 C CNN
F 1 "A" H 3950 2994 50  0000 C CNN
F 2 "Button_Switch_THT:SW_TH_Tactile_Omron_B3F-10xx" H 3950 2850 50  0001 C CNN
F 3 "~" H 3950 2850 50  0001 C CNN
	1    3950 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3900 2600 3950 2600
Wire Wire Line
	3950 2600 3950 2650
Wire Notes Line
	3850 4950 3850 3900
Wire Notes Line
	3850 3900 5000 3900
Wire Notes Line
	5000 3900 5000 4950
Wire Notes Line
	5000 4950 3850 4950
Text Notes 3850 3850 0    50   ~ 0
SPEAKER
Wire Notes Line
	550  3900 550  5200
Wire Wire Line
	4450 2600 4500 2600
Wire Wire Line
	4500 2600 4500 2650
Wire Wire Line
	5000 2600 5050 2600
Wire Wire Line
	5050 2600 5050 2650
Wire Notes Line
	3400 3350 3400 2450
Text Notes 3400 2400 0    50   ~ 0
BUTTONS
Wire Notes Line
	4100 650  5950 650 
Wire Notes Line
	5950 650  5950 1750
Wire Notes Line
	5950 1750 4100 1750
Wire Notes Line
	4100 1750 4100 650 
Text Notes 4100 600  0    50   ~ 0
ICSP
Wire Notes Line
	5250 3350 5250 2450
Wire Notes Line
	3400 2450 5250 2450
Wire Notes Line
	3400 3350 5250 3350
Wire Notes Line
	2700 3900 2700 4500
Wire Notes Line
	2700 4500 3800 4500
Wire Notes Line
	3800 4500 3800 3900
Wire Notes Line
	3800 3900 2700 3900
Text Notes 2700 3850 0    50   ~ 0
REAL-TIME CLOCK
Text Notes 550  3850 0    50   ~ 0
DISPLAY
Wire Notes Line
	2650 3900 2650 5200
Wire Notes Line
	550  3900 2650 3900
Wire Notes Line
	550  5200 2650 5200
Wire Notes Line
	1900 2250 550  2250
Wire Notes Line
	550  650  1900 650 
Wire Notes Line
	1900 650  1900 2250
Wire Notes Line
	550  650  550  2250
Text Notes 550  600  0    50   ~ 0
RESET
Wire Wire Line
	1000 1250 950  1250
Wire Wire Line
	1400 1950 1000 1950
Wire Wire Line
	1400 1550 1400 1950
Connection ~ 1000 950 
Wire Wire Line
	1400 950  1000 950 
Wire Wire Line
	1250 4300 1950 4300
Text GLabel 950  1250 0    50   Input ~ 0
RESET
Wire Wire Line
	1000 1250 1400 1250
$Comp
L power:VCC #PWR0104
U 1 1 61D6CBC3
P 1000 950
F 0 "#PWR0104" H 1000 800 50  0001 C CNN
F 1 "VCC" H 1015 1123 50  0000 C CNN
F 2 "" H 1000 950 50  0001 C CNN
F 3 "" H 1000 950 50  0001 C CNN
	1    1000 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 61D6C3F3
P 1000 1950
F 0 "#PWR0102" H 1000 1700 50  0001 C CNN
F 1 "GND" H 1005 1777 50  0000 C CNN
F 2 "" H 1000 1950 50  0001 C CNN
F 3 "" H 1000 1950 50  0001 C CNN
	1    1000 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 61D1DA99
P 950 4300
F 0 "#PWR02" H 950 4050 50  0001 C CNN
F 1 "GND" V 955 4172 50  0000 R CNN
F 2 "" H 950 4300 50  0001 C CNN
F 3 "" H 950 4300 50  0001 C CNN
	1    950  4300
	0    1    1    0   
$EndComp
$Comp
L Device:C C4
U 1 1 61D1C6DF
P 1100 4300
F 0 "C4" V 848 4300 50  0000 C CNN
F 1 "10uF" V 939 4300 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 1138 4150 50  0001 C CNN
F 3 "~" H 1100 4300 50  0001 C CNN
	1    1100 4300
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR04
U 1 1 61D1C470
P 1950 4500
F 0 "#PWR04" H 1950 4350 50  0001 C CNN
F 1 "VCC" V 1965 4627 50  0000 L CNN
F 2 "" H 1950 4500 50  0001 C CNN
F 3 "" H 1950 4500 50  0001 C CNN
	1    1950 4500
	0    -1   -1   0   
$EndComp
$Comp
L power:VCC #PWR05
U 1 1 61D1BADF
P 1950 5000
F 0 "#PWR05" H 1950 4850 50  0001 C CNN
F 1 "VCC" V 1965 5127 50  0000 L CNN
F 2 "" H 1950 5000 50  0001 C CNN
F 3 "" H 1950 5000 50  0001 C CNN
	1    1950 5000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 61D1B73B
P 1950 4400
F 0 "#PWR03" H 1950 4150 50  0001 C CNN
F 1 "GND" V 1955 4272 50  0000 R CNN
F 2 "" H 1950 4400 50  0001 C CNN
F 3 "" H 1950 4400 50  0001 C CNN
	1    1950 4400
	0    1    1    0   
$EndComp
Text GLabel 1950 4900 0    50   Input ~ 0
DISPLAY_CLOCK
Text GLabel 1950 4800 0    50   Input ~ 0
DISPLAY_MOSI
Text GLabel 1950 4700 0    50   Input ~ 0
DISPLAY_DATA_COMMAND
Text GLabel 1950 4200 0    50   Input ~ 0
DISPLAY_RESET
$Comp
L power:GND #PWR07
U 1 1 61D19BA3
P 1950 4600
F 0 "#PWR07" H 1950 4350 50  0001 C CNN
F 1 "GND" V 1955 4472 50  0000 R CNN
F 2 "" H 1950 4600 50  0001 C CNN
F 3 "" H 1950 4600 50  0001 C CNN
	1    1950 4600
	0    1    1    0   
$EndComp
Connection ~ 1000 1250
Connection ~ 1400 1250
$Comp
L Device:C C1
U 1 1 61CFF275
P 1400 1400
F 0 "C1" H 1515 1446 50  0000 L CNN
F 1 "100nF" H 1515 1355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 1438 1250 50  0001 C CNN
F 3 "~" H 1400 1400 50  0001 C CNN
	1    1400 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:D D1
U 1 1 61CFE870
P 1400 1100
F 0 "D1" V 1354 1180 50  0000 L CNN
F 1 "1N4148" V 1445 1180 50  0000 L CNN
F 2 "Diode_THT:D_DO-34_SOD68_P7.62mm_Horizontal" H 1400 1100 50  0001 C CNN
F 3 "~" H 1400 1100 50  0001 C CNN
	1    1400 1100
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 61CFE3F4
P 1000 1100
F 0 "R1" H 930 1054 50  0000 R CNN
F 1 "4.7K" H 930 1145 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 930 1100 50  0001 C CNN
F 3 "~" H 1000 1100 50  0001 C CNN
	1    1000 1100
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x09 J2
U 1 1 61CE1E21
P 2150 4600
F 0 "J2" H 2230 4642 50  0000 L CNN
F 1 "PCD8544" H 2230 4551 50  0000 L CNN
F 2 "Quantum_Monster:PCD8544" H 2150 4600 50  0001 C CNN
F 3 "~" H 2150 4600 50  0001 C CNN
	1    2150 4600
	1    0    0    -1  
$EndComp
Wire Notes Line
	550  2450 3350 2450
Wire Notes Line
	3350 2450 3350 3700
Wire Notes Line
	3350 3700 550  3700
Wire Notes Line
	550  3700 550  2450
Text Notes 550  2400 0    50   ~ 0
LINK
$Comp
L Device:Battery_Cell BT1
U 1 1 61C9A786
P 3550 1150
F 0 "BT1" H 3668 1246 50  0000 L CNN
F 1 "CR2032" H 3668 1155 50  0000 L CNN
F 2 "Quantum_Monster:CR2032" V 3550 1210 50  0001 C CNN
F 3 "~" V 3550 1210 50  0001 C CNN
	1    3550 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 61D0DCD6
P 2650 1400
F 0 "C2" H 2765 1446 50  0000 L CNN
F 1 "100nF" H 2765 1355 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 2688 1250 50  0001 C CNN
F 3 "~" H 2650 1400 50  0001 C CNN
	1    2650 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 61D0E425
P 3100 1100
F 0 "C3" H 3215 1146 50  0000 L CNN
F 1 "10uF" H 3215 1055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 3138 950 50  0001 C CNN
F 3 "~" H 3100 1100 50  0001 C CNN
	1    3100 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 61D8AB20
P 2650 1550
F 0 "#PWR0107" H 2650 1300 50  0001 C CNN
F 1 "GND" H 2655 1377 50  0000 C CNN
F 2 "" H 2650 1550 50  0001 C CNN
F 3 "" H 2650 1550 50  0001 C CNN
	1    2650 1550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0108
U 1 1 61D8B53C
P 2650 950
F 0 "#PWR0108" H 2650 800 50  0001 C CNN
F 1 "VCC" H 2665 1123 50  0000 C CNN
F 2 "" H 2650 950 50  0001 C CNN
F 3 "" H 2650 950 50  0001 C CNN
	1    2650 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:L L1
U 1 1 61DB9E99
P 2650 1100
F 0 "L1" H 2703 1146 50  0000 L CNN
F 1 "10uH" H 2703 1055 50  0000 L CNN
F 2 "Inductor_THT:L_Axial_L5.3mm_D2.2mm_P7.62mm_Horizontal_Vishay_IM-1" H 2650 1100 50  0001 C CNN
F 3 "~" H 2650 1100 50  0001 C CNN
	1    2650 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 950  3100 950 
Connection ~ 2650 950 
Connection ~ 3100 950 
Wire Wire Line
	3100 950  2650 950 
Wire Wire Line
	2650 1550 3100 1550
Wire Wire Line
	3100 1550 3100 1250
Connection ~ 2650 1550
Wire Wire Line
	3550 1250 3550 1550
Wire Wire Line
	3550 1550 3100 1550
Connection ~ 3100 1550
Text GLabel 2600 1250 0    50   Output ~ 0
FILTERED_VCC
Wire Wire Line
	2600 1250 2650 1250
Connection ~ 2650 1250
Wire Notes Line
	1950 650  1950 1850
Wire Notes Line
	1950 1850 4050 1850
Wire Notes Line
	4050 1850 4050 650 
Wire Notes Line
	4050 650  1950 650 
Text Notes 1950 600  0    50   ~ 0
POWER
Text GLabel 7300 3050 2    50   Output ~ 0
DISPLAY_RESET
$Comp
L Device:R R2
U 1 1 61CFFBE6
P 1000 1800
F 0 "R2" H 930 1754 50  0000 R CNN
F 1 "330R" H 930 1845 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 930 1800 50  0001 C CNN
F 3 "~" H 1000 1800 50  0001 C CNN
	1    1000 1800
	-1   0    0    1   
$EndComp
Connection ~ 1000 1950
$Comp
L Switch:SW_SPST SW1
U 1 1 61D00CAA
P 1000 1450
F 0 "SW1" V 954 1548 50  0000 L CNN
F 1 "RESET" V 1045 1548 50  0000 L CNN
F 2 "Button_Switch_THT:SW_TH_Tactile_Omron_B3F-10xx" H 1000 1450 50  0001 C CNN
F 3 "~" H 1000 1450 50  0001 C CNN
	1    1000 1450
	0    1    -1   0   
$EndComp
$EndSCHEMATC
