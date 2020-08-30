main:
    li $v0, 5           #   scanf("%d", &x);
    syscall             #
    move $t0, $v0

    li $v0, 5           #   scanf("%d", &y);
    syscall             #
    move $t1, $v0
    li $t2, 0
    add, $t2, $t0, 1
loop0:
    bge $t2, $t1, end0
    beq $t2, 13, endif
if:

    move $a0, $t2       #   printf("%d\n", 42);
    li $v0, 1
    syscall
    li   $a0, '\n'      #   printf("%c", '\n');
    li   $v0, 11
    syscall

endif:
    add $t2, $t2, 1
    b loop0
end0:

    li $v0, 0           # return 0
    jr $31
