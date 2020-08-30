# Read a number and print positive multiples of 7 or 11 < n

main:                  # int main(void) {

    la $a0, prompt     # printf("Enter a number: ");
    li $v0, 4
    syscall

    li $v0, 5           # scanf("%d", number);
    syscall

    move $t0, $v0          #   printf("%d", 42);
    li   $s1, 1
    li $t2, 7
    li $t3, 11
while:
    beq $s1, $t0, end
    divu $s1, $t2
    mfhi $t4
    beq $t4, 0, prf
    divu $s1, $t3
    mfhi $t5
    beq $t5, 0, prf
    add $s1, $s1 , 1
    b while

    

prf:
    move $a0, $s1
    li $v0, 1
    syscall
    li   $a0, '\n'      # printf("%c", '\n');
    li   $v0, 11
    syscall
    add $s1, $s1 , 1
    b while

end:
    jr   $ra           # return

    .data
prompt:
    .asciiz "Enter a number: "

