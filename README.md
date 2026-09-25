The project uses binary tools: `avrdude`, `avr-gcc`, `avr-objcopy`.

Many assumptions are made when writing `Makefile`. Targeting Arduino UNO with `atmega328p` microcontroller.

### Steps:

1. Compile and assemble program
2. Extract raw machine code
3. Flash the raw machine code only

Notes: Aim is to generate a raw binary file. How the project structure will be to generate the binary file is a TODO part.