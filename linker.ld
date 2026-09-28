MEMORY {
    FLASH(rx) : ORIGIN = 0, LENGTH = 32K
    SRAM(rw) : ORIGIN = 0x800100, LENGTH = 2K   /* 0x800100 because it needs to distinguish instructions for flash and sram addresses */
    /* EEPROM also is there, but don't care as of the moment */
}

SECTIONS {
    .text : {
        s_text = .;
        *(.reset)
        *(.text)
        e_text = .;
    } > FLASH

    .data : {
        s_data = .;
        KEEP(*(.data))
        KEEP(*(.bss))
        e_data = .;
    } > SRAM AT> FLASH

    /DISCARD/ : {
        *(.comment)
        *(.trampolines)
    }
}