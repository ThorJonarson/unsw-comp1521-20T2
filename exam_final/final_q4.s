# this code reads 1 integer and prints it
# change it to read integers until their sum is >= 42
# and then print their sum

main:
    li  $t0, 0  #sum
loop0:
    bge $t0, 42, end_loop0
    li   $v0, 5        #   scanf("%d", &x);
    syscall  
    add $t0, $t0, $v0

    b loop0
end_loop0:
    move $a0, $t0      #   printf("%d\n", sum);
    li   $v0, 1
    syscall

    li   $a0, '\n'     #   printf("%c", '\n');
    li   $v0, 11
    syscall

    li   $v0, 0        # return 0
    jr   $ra
