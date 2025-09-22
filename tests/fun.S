    LOAD #1,R0
    PUSH R0
    BSR  print
    WSTR "done !\n"
    HALT
print :
    LOAD -2(LB),R1
    WSTR "a + 5 = "
    WINT
    RTS
