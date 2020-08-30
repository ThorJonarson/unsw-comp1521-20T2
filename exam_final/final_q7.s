# this code reads 1 integer and prints it
# change it to read integers until their sum is >= 42
# and then print theintgers read in reverse order

main:
    li   $t0, 0  #sum
    li   $t1, 0  #i
loop0:
    bge  $t0, 42, end_loop0
    li   $v0, 5        #   scanf("%d", &x);
    syscall  
    la   $t2, numbers
    li   $t3, 4
    mul  $t3, $t3, $t1
    add  $t2, $t2, $t3
    sw   $v0, ($t2)
    addi $t1, $t1, 1
    add  $t0, $t0, $v0

    b loop0
end_loop0:

loop1:
    ble  $t1, 0, end_loop1
    sub  $t1, $t1, 1
    la   $t2, numbers
    li   $t3, 4
    mul  $t3, $t3, $t1
    add  $t2, $t2, $t3
    lw   $t4, ($t2)
    move $a0, $t4      #   printf("%d\n", sum);
    li   $v0, 1
    syscall

    li   $a0, '\n'     #   printf("%c", '\n');
    li   $v0, 11
    syscall
    b loop1
end_loop1:

    li   $v0, 0        # return 0
    jr   $ra
    
    
    
.data

numbers: .space 4000
