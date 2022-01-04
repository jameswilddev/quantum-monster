# [Quantum Monster](../readme.md) > Hardware Design Notes

## Components

The device is built around an ATmega328P, [the same microcontroller found within the Arduino Uno prototyping board][1], providing:

- An [8-bit CPU][2] clocked at [8MHz using an internal RC oscillator][3].
- [32 general-purpose registers][2] for frequently accessed data such as the current time.
- [2KB of SRAM][2] for infrequently accessed data such as the lists of seen and raised monsters.
- [32KB of flash memory with in-circuit programming][2] for code, data, graphics and audio.
- [1KB of EEPROM][2] for holding save data while the system is powered off.
- [GPIO with interrupts, wake-up on pin change][2] and [internal pull-up resistors][4] for user-facing buttons.
- [PWM channels][2] which can be used to produce audible tones through speakers.
- [Real-time clock functionality][2] for background time-keeping.
- [Support for a reset button][5].
- [A hardware serial port][5] for issuing commands to a display.

This is paired with a Nokia 3310/5110-style display, which in turn uses the PCD8544 LCD controller/driver IC, providing:

- [A 1-bit-per-pixel, 84x48 dot matrix display (divided into 5 rows of 8 pixels).][6]
- [Integrated VRAM][6] (able to retain/refresh the current image without requiring its regeneration/transfer).
- [Simple full-screen effects including inversion, flashing white and flashing black.][7]

A single passive buzzer on the back is connected to one of the microcontroller's PWM outputs.

Power is supplied by a CR2032 battery in a rear-mounted holder.

In addition to the reset button, three general-purpose input buttons are arranged in a line ono the front.

## Software architecture

The microcontroller spends most of its time in [power-save mode][8], awaiting an interrupt from button input, time passing or infrared activity.

TODO

## Power supply

Most of the components used in this project could operate on a wide range of DC voltages, but [the display expects to be signalled at between 2.7VDC and 3.3VDC][6], which should be compatible with the [expected voltage range of between 2.7VDC and 3VDC of a non-depleted CR2032 battery][9] and the [microcontroller's 8MHz internal RC oscillator][10].

For a device such as this, which spends most of its time sleeping until the next interrupt, running at a faster clock speed can produce equal or even lesser power draw than running slower as the [ATmega328P's power draw is documented as scaling below linearly with clock speed][11]; the increased power draw while awake would be offset by the reduction in time spent awake.

TODO serial port speed

## Real-time clock

A 32.768kHz crystal is [connected to the microcontroller's `TOSC1` and `TOSC2` pins][12].  [A prescaler of 1/128][13] is used to reduce this to 256Hz.  Timer 2 overflows every 256 ticks (making it effectively 1Hz), triggering an interrupt which increments in-memory hour/minute/second counters as appropriate.

[Additional reading regarding crystal selection][14].

## Display interfacing

TODO

## Buttons

TODO

## Timing

TODO

## Programming

TODO

## Infrared

TODO

## Buzzer

TODO

## Assembly and configuration

TODO

## Possible cost optimizations

The circuit design opts to include many optional components which may be eliminated to reduce cost and complexity.

### Power Filtering

Having both `C2` and `C3` may be unnecessary; the device would likely still work with only `C2`, especially with `L1` removed.  This was added to follow the [EMC Design Considerations][15]; `L1`'s value was taken from the [ADC Power Connections section of the AVR datasheet][16] as no other specifications of a series inductor's value could be found.

### Reset

`R1`, `D1` and `C1` were added based on [Atmel's recommendations for implementing external reset][17].  `R2` was added as [a consequence of combining these recommendations with a reset button][18].

It is unlikely that this level of hardening is strictly necessary; these parts can most likely be omitted as [the reset pin includes an internal pull-up resistor][19].

#### Infrared Receiver

`R9` and `C5` form the power filtering hardware [recommended by the infrared receiver's datasheet][20].  They seem unusually overspecified.  It seems likely that the filtering used by the microcontroller would be sufficient.

### ICSP

Most inexpensive AVR programmers on the market can only signal at +5VDC, and worse, often mislead the customer by offering a `VCC` +5VDC/+3.3VDC switch (which only affects `VCC`, not `SCK` or `MOSI`).  Attempting to use +5VDC signalling to program the microcontroller will exceed the [absolute maximum ratings if it is running at +3.3VDC][21]. To protect against this, `R3`, `R4`, `R5` and `R6` form two pairs of voltage dividers which drop the +5VDC of `SCK` and `MOSI` down to +3.3VDC.

No other ICSP pins include such dividers as:

- `MISO` is driven by the microcontroller, not the programmer.
- `RESET` is permitted to be as [high as +13VDC][21], regardless of `VCC`.

If the microcontroller is programmed in-circuit before any +5VDC intolerant parts (such as, but not limited to, the display) these resistors can be omitted (but will need to be bridged to avoid open circuit on these lines).

If the microcontroller is pre-programmed out-of-circuit, `J1`, `R3`, `R4`, `R5` and `R6` can all be omitted.

[1]: <https://www.arduino.cc/en/pmwiki.php?n=Main/arduinoBoardUno> "Arduino Uno - Overview"
[2]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, Features"
[3]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, 8.6 Calibrated Internal RC Oscillator"
[4]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, 1.1.3 Port B (PB7:0) XTAL1/XTAL2/TOSC1/TOSC2 & 1.1.4 Port C (PC5:0) & 1.1.6 Port D (PD7:0)"
[5]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, 10.4 External Reset"
[6]: <https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf> "PCD8544 datasheet, 1 FEATURES"
[7]: <https://www.sparkfun.com/datasheets/LCD/Monochrome/Nokia5110.pdf> "PCD8544 datasheet, 7.5 Display address counter"
[8]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, 9.1 Sleep Modes"
[9]: <https://data.energizer.com/pdfs/cr2032.pdf> "Energizer CR2032 datasheet, Continuous Discharge Statistics"
[10]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, 28.4 Speed Grades, Figure 28-1. Maximum Frequency"
[11]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, 28.3 DC Characteristics"
[12]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, Figure 8-2. Crystal Oscillator Connections"
[13]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, 17.10 Timer/Counter Prescaler"
[14]: <http://ww1.microchip.com/downloads/en/Appnotes/AN2648-Selecting_Testing-32KHz-Crystal-Osc-for-AVR-MCUs-00002648B.pdf> "Selecting and Testing 32 KHz Crystal Oscillators for AVR® Microcontrollers"
[15]: <http://ww1.microchip.com/downloads/en/appnotes/atmel-1619-emc-design-considerations_applicationnote_avr040.pdf> "AVR040: EMC Design Considerations, Figure 4-3. Decoupling with Series Inductor"
[16]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf#G1203819> "AVR Instruction Set Manual, Figure 23-9. ADC Power Connections"
[17]: <http://ww1.microchip.com/downloads/en/AppNotes/00002519A.pdf> "AVR® Microcontroller Hardware Design Considerations, Figure 3-1. Recommended Reset Pin Connection"
[18]: <http://ww1.microchip.com/downloads/en/AppNotes/00002519A.pdf> "AVR® Microcontroller Hardware Design Considerations, Figure 3-2. Switch Connection for Reset Pin"
[19]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, 28.2 DC Characteristics (Continued)"
[20]: <http://www.datasheet-pdf.com/PDF/TL1838-Datasheet-Evercolors-790877> "EVERCOLORS TL1838 Datasheet, Application Circuit"
[21]: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf> "ATmega328P datasheet, 28.1 Absolute Maximum Ratings"
