SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

CSRC = $(shell find $(SRC_DIR) -name "*.c")
HSRC = $(shell find $(INC_DIR) -name "*.h")
ASRC = $(shell find $(SRC_DIR) -name "*.s")
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%_c.o,$(CSRC)) $(patsubst $(SRC_DIR)/%.s,$(BUILD_DIR)/%_s.o,$(ASRC))

BINFILE = firmware.bin

########################################################################

MICROCONTROLLER = atmega328p
ARCH = avr5
PORT = /dev/ttyACM0		# Probably won't change unless many Arduinos are connected

CC = avr-gcc
AS = avr-as
LD = avr-ld
OBJCOPY = avr-objcopy
FLASHER = avrdude

CFLAGS = -mmcu=$(MICROCONTROLLER) -std=c11 -I$(INC_DIR) -c \
	-ffreestanding -fno-builtin -nostdinc \
	-Wall -Wextra \
	-Wno-misspelled-isr \
	-MMD -MP

AFLAGS = -mmcu=$(MICROCONTROLLER)

LFLAGS = -m $(ARCH) -Tlinker.ld \
	-nostdlib \
	--Map $(BUILD_DIR)/mem.map

OFLAGS = -O binary

FLASHFLAGS = -p $(MICROCONTROLLER) -c arduino -P $(PORT) -b 115200

########################################################################

# Link
$(BINFILE): $(OBJS) linker.ld Makefile
	$(LD) $(LFLAGS) $(OBJS) -o $(BUILD_DIR)/intermediate.elf
	$(OBJCOPY) $(OFLAGS) $(BUILD_DIR)/intermediate.elf $(BINFILE)

# Compile
$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

# Assemble
$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.s
	@mkdir -p $(@D)
	$(AS) $(AFLAGS) $< -o $@

-include $(OBJS:.o=.d)	# Helps to check if header files are changed

########################################################################

flash: $(BINFILE)
	$(FLASHER) $(FLASHFLAGS) -U flash:w:$(BINFILE):r

dump:
	avrdude -p $(MICROCONTROLLER) -c arduino -P $(PORT) -U flash:r:flash.bin:r -U eeprom:r:eeprom.bin:r

check:
	avrdude -p $(MICROCONTROLLER) -c arduino -P $(PORT) -b 115200 -v

clean:
	rm -rf $(BUILD_DIR)/* *.bin

all: $(BINFILE) flash
