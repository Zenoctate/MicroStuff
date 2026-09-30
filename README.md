The project uses binary tools: `avrdude`, `avr-gcc`, `avr-as`, `avr-ld`, `avr-objcopy`.

Many assumptions are made when writing `Makefile`. Targeting Arduino UNO with `atmega328p` microcontroller.

Flashing the raw binary files only (not using `ihex`). Goal is to generate a raw binary file without any help from libraries but only build tools and binutils.

Constants will most always be written using `#define`. All global variables will always be initiallized.

Arduino uses UART + bootloader to be programmed, not touching those at all. Fuse bits are configured with default arduino values.