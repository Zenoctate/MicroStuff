.section .text

.global load_SRAM

load_SRAM:
    ; Load the start address of .data in SRAM into X register (r26:r27)
    ldi r26, lo8(s_data)
    ldi r27, hi8(s_data)
    
    ; Load the start address of .data in Flash into Z register (r30:r31)
    ; TODO: don't do this
    ldi r30, lo8(e_text)
    ldi r31, hi8(e_text)
    
    ; Load the length of .data section into r24:r25
    ldi r24, lo8(data_size)
    ldi r25, hi8(data_size)
    
    ; Check if there's anything to copy
    or r24, r25
    breq end_load_SRAM
    
    copy_loop:
        ; Load byte from Flash (Z) into r0
        lpm r0, Z+
        
        ; Store byte to SRAM (X)
        st X+, r0
        
        ; Decrement counter
        sbiw r24, 1
        
        ; Continue if counter > 0
        brne copy_loop
    
end_load_SRAM:
    ret
