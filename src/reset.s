.section .reset
.global reset

.extern start

reset:
    rjmp start
