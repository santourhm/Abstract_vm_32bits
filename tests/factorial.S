    LOAD #5, R1       
    PUSH R1
    BSR fact
    SUBSP #1
    WSTR "fact(12) = "
    LOAD R0, R1
    WINT
    WNL
    HALT

fact :
    LOAD -2(LB), R1     
    CMP #1, R1
    BLE fact_base

    LOAD R1, R3         

    SUB #1, R1
    PUSH R1
    BSR fact
    SUBSP #1

    LOAD R0, R2
    MUL R3, R2          
    LOAD R2, R0
    RTS


fact_base :
    LOAD #1, R0
    RTS
