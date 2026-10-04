MEMORY {
    FLASH(rx) : ORIGIN = 0, LENGTH = 32K
    SRAM(rw) : ORIGIN = 0x800100, LENGTH = 2K   /* 0x800100 because it needs to distinguish instructions for flash and sram addresses */
    /* EEPROM also is there, but don't care as of the moment */
}

SECTIONS {
    .text : {
        *(.reset)
        *(.text)
    } > FLASH

    .rodata : {
        *(.rodata)
    } > FLASH

    .data : {
        KEEP(*(.data))
        KEEP(*(.bss))   /* Should not have anything because all globals will be defined */
    } > SRAM AT> FLASH

    ld_s_text = LOADADDR(.text);
    ld_text_size = SIZEOF(.text);
    ld_e_text = LOADADDR(.text) + ld_text_size;

    ld_s_data = LOADADDR(.data);
    ld_data_size = SIZEOF(.data);
    ld_e_data = LOADADDR(.data) + ld_data_size;

    /DISCARD/ : {
        *(.comment)
        *(.trampolines)
    }
}