MEMORY {
    FLASH(rx) : ORIGIN = 0, LENGTH = 32K
    SRAM(rw) : ORIGIN = 0x800100, LENGTH = 2K   /* Why it starts at 0x800100?? Answer given by an LLM, need to study datasheet instead */
    /* EEPROM also is there, but don't care as of the moment */
}


/* 
    JUST testing for now 
    NO IDEA if it should be done like this
*/
SECTIONS {
    .text : {
        s_text = .;
        *(.reset)
        *(.text)
        e_text = .;
    } > FLASH

    .data : {
        s_data = .;
        *(.data)
        *(.bss)
        e_data = .;
    } > SRAM AT> FLASH
}