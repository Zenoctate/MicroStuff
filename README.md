The project uses binary tools: `avrdude`, `avr-gcc`, `avr-objcopy`.

Many assumptions are made when writing `Makefile`. Targeting Arduino UNO with `atmega328p` microcontroller.

### Goals:

1. Compile and assemble program
2. Link the object files using linker script
3. Extract raw machine code using avr-objcopy
4. Flash the raw machine code only

Aim is to generate a raw binary file without any help from libraries. How the project structure will be to generate the binary file is a TODO part.