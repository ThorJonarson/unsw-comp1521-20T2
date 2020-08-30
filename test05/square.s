main:
    li $v0, 5           #   scanf("%d", &x);
    syscall             #
    move $t0, $v0
    
    li $t1, 0
    
loop0:    
    bge $t1, $t0, end0
    li $t2, 0
    
loop1:
    bge $t2, $t0, end1
    li $a0, '*'          #   printf("%d\n", 42);
    li $v0, 11
    syscall

    add $t2, $t2, 1
    b loop1
end1:
    add $t1, $t1, 1
    li   $a0, '\n'      #   printf("%c", '\n');
    li   $v0, 11
    syscall
    b loop0

end0:

    li $v0, 0           # return 0
    jr $31
