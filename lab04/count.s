# read a number n and print the integers 1..n one per line

main:                           # int main(void)
    la  $a0, prompt             # printf("Enter a number: ");
    li  $v0, 4
    syscall

    li  $v0, 5                  # scanf("%d", number);
    syscall
    
    li $s1, 1
    move $s2, $v0

startwhile:
    bgt $s1, $s2, end

    move  $a0, $s1                 
    li  $v0, 1
    syscall

    li $a0, '\n'      # printf("%c", '\n');
    li   $v0, 11
    syscall
    
    add $s1, $s1, 1
    b startwhile
    
end:
    jr  $ra                     # return

    .data
prompt:
    .asciiz "Enter a number: "
