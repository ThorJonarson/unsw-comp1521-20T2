# read a mark and print the corresponding UNSW grade

main:
    la $a0, prompt      # printf("Enter a mark: ");
    li $v0, 4
    syscall

    li $v0, 5           # scanf("%d", mark);
    syscall

    blt $v0, 50, fail
    blt $v0, 65, pass
    blt $v0, 75, critic
    blt $v0, 85, distictive
    b highdis

fail:
    la $a0, fl 
    li $v0, 4
    syscall         # printf("FL\n");
    b endif
    
pass:   
    la $a0, ps
    li $v0, 4
    syscall
    b endif

critic:
    la $a0, cr
    li $v0, 4
    syscall
    b endif
    
distictive:
    la $a0, dn
    li $v0, 4
    syscall
    b endif
    
highdis:
    la $a0, hd
    li $v0, 4
    syscall
    b endif
    
endif:
    jr $ra              # return

    .data
prompt:
    .asciiz "Enter a mark: "
fl:
    .asciiz "FL\n"
ps:
    .asciiz "PS\n"
cr:
    .asciiz "CR\n"
dn:
    .asciiz "DN\n"
hd:
    .asciiz "HD\n"
