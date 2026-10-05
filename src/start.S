.section .reset

.extern main
.extern ISR_timer0A

; Reset vector
    jmp     reset_handle        ; 0x0000 RESET

; External interrupts
    jmp     ISR_unused          ; 0x0002 INT0
    jmp     ISR_unused          ; 0x0004 INT1

; Pin-change interrupts
    jmp     ISR_unused          ; 0x0006 PCINT0
    jmp     ISR_unused          ; 0x0008 PCINT1
    jmp     ISR_unused          ; 0x000A PCINT2

; Watchdog
    jmp     ISR_unused          ; 0x000C WDT
    
; Timer2
    jmp     ISR_unused          ; 0x000E TIMER2_COMPA
    jmp     ISR_unused          ; 0x0010 TIMER2_COMPB
    jmp     ISR_unused          ; 0x0012 TIMER2_OVF

; Timer1
    jmp     ISR_unused          ; 0x0014 TIMER1_CAPT
    jmp     ISR_unused          ; 0x0016 TIMER1_COMPA
    jmp     ISR_unused          ; 0x0018 TIMER1_COMPB
    jmp     ISR_unused          ; 0x001A TIMER1_OVF

; Timer0
    jmp     ISR_timer0A         ; 0x001C TIMER0_COMPA
    jmp     ISR_unused          ; 0x001E TIMER0_COMPB
    jmp     ISR_unused          ; 0x0020 TIMER0_OVF

; Serial peripherals
    jmp     ISR_unused          ; 0x0022 SPI_STC
    jmp     ISR_unused          ; 0x0024 USART_RX
    jmp     ISR_unused          ; 0x0026 USART_UDRE
    jmp     ISR_unused          ; 0x0028 USART_TX

; Other peripherals
    jmp     ISR_unused          ; 0x002A ADC
    jmp     ISR_unused          ; 0x002C EE_READY
    jmp     ISR_unused          ; 0x002E ANALOG_COMP
    jmp     ISR_unused          ; 0x0030 TWI
    jmp     ISR_unused          ; 0x0032 SPM_READY

reset_handle:
    ; Set SP to 0x08FF
    ldi     r16, 0x08
    out     0x3E, r16   ; SPH
    ldi     r16, 0xFF
    out     0x3D, r16   ; SPL

    jmp main

ISR_unused:
    reti
