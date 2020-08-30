// Comp1521 assignment2 smips
// z5248147 by Haoheng Duan, 7/08/2020

// This program prints The instruction (assempler) 
// corresponding to each instruction code 
// It also shows the output produced by syscalls when 
// executing the MIPS instructions.
// Finally it prints the register values when the program terminates

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// maximum values of the array
#define MAX_INSTRUCTIONS 1000
#define MAX_REGISTERS 32

void decodePrintInstructions(int instructions, char *argv, int line);
void decodeExecuteInstructions(int instructions, int *registers, int* line);

int main(int argc, char *argv[]) {
    // check if the number of arguments is true
    if (argc != 2) {
        fprintf(stderr, "the number of arguments is wrong!");
        return 1;
    }   
    // check if the file is opened successfully
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror(argv[1]);
        return 1;
    }
    // use two arrays to store instructions and registers
    int instructions[MAX_INSTRUCTIONS];
    int registers[MAX_REGISTERS] = {0};
    // loop to scan all the instructions to the array
    int i = 0;
    while (i < MAX_INSTRUCTIONS && fscanf(input, "%x", &instructions[i]) == 1) {
        i++;
    }
    // loop to print instructions in assempler
    printf("Program\n");
    for (int line = 0; line < i; line++) {
        printf("%3d: ", line);
        decodePrintInstructions(instructions[line], argv[1], line);
    }
    // loop to execute the instructions and print outputs
    printf("Output\n");
    for (int j = 0; j < i; j++) {
        // when the instruction is syscall
        // It prints the output produced by syscalls  
        if ((instructions[j] & 0x3f) == 0xc && (instructions[j] >> 4 == 0)) {
            if (registers[2] == 1) {
                // $v0 = 1
                printf("%d", registers[4]);
            } else if (registers[2] == 10) {
                // v0 = 10
                break;
            } else if (registers[2] == 11) {
                // v0 = 11
                printf("%c", registers[4]);
            } else {
                // Unknown system call
                printf("Unknown system call: %d\n", registers[2]);
                break;
            }
        } else {
            decodeExecuteInstructions(instructions[j], registers, &j);
        }
        
    }
    // loop to print non 0 registers
    printf("Registers After Execution\n");
    for (int j = 0; j < MAX_REGISTERS; j++) {
        if (registers[j] != 0) {
            printf("$%-3d= %d\n", j, registers[j]);
        }
    }
    return 0;
}

// This function prints the instruction (assempler) 
// corresponding to each instruction code 
void decodePrintInstructions(int instructions, char *argv, int line) {
    int s = 0;
    int t = 0;
    int d = 0;
    int16_t immediate = 0;
    // match different situations
    if ((instructions >> 26) == 0) {
        // check invalid situations
        if (((instructions >> 6) & 0x1f) != 0) {
            printf("%s:%d: invalid instruction code: %08x",
                 argv, line, instructions);
            exit(0);
        }
        s = instructions >> 21;
        t = (instructions >> 16) & 0x1f;
        d = (instructions >> 11) & 0x1f;
        if ((instructions & 0x3f) == 0x20) {
            printf("add  $%d, $%d, $%d\n", d, s, t);
        } else if ((instructions & 0x3f) == 0x22) {
            printf("sub  $%d, $%d, $%d\n", d, s, t);
        } else if ((instructions & 0x3f) == 0x24) {
            printf("and  $%d, $%d, $%d\n", d, s, t);
        } else if ((instructions & 0x3f) == 0x25) {
            printf("or   $%d, $%d, $%d\n", d, s, t);
        } else if ((instructions & 0x3f) == 0x2a) {
            printf("slt  $%d, $%d, $%d\n", d, s, t);
        } else if ((instructions & 0x3f) == 0xc) {
            // check invalid situations
            if ((instructions >> 4) != 0) {
                printf("%s:%d: invalid instruction code: %08x",
                     argv, line, instructions);
                exit(0);
            }
            printf("syscall\n");
        } else {
            // check invalid situations
            printf("%s:%d: invalid instruction code: %08x", 
                argv, line, instructions);
            exit(0);
        }
    } else if ((instructions >> 26) == 0x1c) {
        // check invalid situations
        if ((instructions & 0x7ff) != 2) {
            printf("%s:%d: invalid instruction code: %08x", 
                argv, line, instructions);
            exit(0);
        }
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        d = (instructions >> 11) & 0x1f;
        printf("mul  $%d, $%d, $%d\n", d, s, t);
    } else if ((instructions >> 26) == 0x4) {
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        printf("beq  $%d, $%d, %d\n", s, t, immediate);
    } else if ((instructions >> 26) == 0x5) {
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        printf("bne  $%d, $%d, %d\n", s, t, immediate);
    } else if ((instructions >> 26) == 0x8) {
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        printf("addi $%d, $%d, %d\n", t, s, immediate);
    } else if ((instructions >> 26) == 0xa) {
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        printf("slti $%d, $%d, %d\n", t, s, immediate);
    } else if ((instructions >> 26) == 0xc) {
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        printf("andi $%d, $%d, %d\n", t, s, immediate);
    } else if ((instructions >> 26) == 0xd) {
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        printf("ori  $%d, $%d, %d\n", t, s, immediate);
    } else if ((instructions >> 26) == 0xf) {
        // check invalid situations
        if (((instructions >> 21) & 0x1f) != 0) {
            printf("%s:%d: invalid instruction code: %08x", 
                argv, line, instructions);
            exit(0);
        }
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        printf("lui  $%d, %d\n", t, immediate);
    } else {
        // check invalid situations
        printf("%s:%d: invalid instruction code: %08x", 
            argv, line, instructions);
        exit(0);
    }
}

// This function changes the values of the registers when 
// executing the MIPS instructions.
void decodeExecuteInstructions(int instructions, int *registers, int *line) {
    int s = 0;
    int t = 0;
    int d = 0;
    int16_t immediate = 0;
    // match different situations
    // register[0] can't be changed
    if ((instructions >> 26) == 0) {
        s = instructions >> 21;
        t = (instructions >> 16) & 0x1f;
        d = (instructions >> 11) & 0x1f;
        if ((instructions & 0x3f) == 0x20) {
            // add $d, $s, $t
            if (d != 0) {
                registers[d] = registers[s] + registers[t];
            }
        } else if ((instructions & 0x3f) == 0x22) {
            // sub $d, $s, $t
            if (d != 0) {
                registers[d] = registers[s] - registers[t];
            }
        } else if ((instructions & 0x3f) == 0x24) {
            // and $d, $s, $t
            if (d != 0) {
                registers[d] = registers[s] & registers[t];
            }
        } else if ((instructions & 0x3f) == 0x25) {
            // or $d, $s, $t
            if (d != 0) {
                registers[d] = registers[s] | registers[t];
            }
        } else if ((instructions & 0x3f) == 0x2a) {
            // slt $d, $s, $t
            if (registers[s] < registers[t]) {
                if (d != 0) {
                    registers[d] = 1;
                }
            } else {
                if (d != 0) {
                    registers[d] = 0;
                }
            }
        }
    } else if ((instructions >> 26) == 0x1c) {
        // mul $d, $s, $t
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        d = (instructions >> 11) & 0x1f;
        if (d != 0) {
            registers[d] = registers[s] * registers[t];
        }
    } else if ((instructions >> 26) == 0x4) {
        // beq $s, $t, I
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        if (registers[s] == registers[t]) {
            *line += immediate;
            *line -= 1;
        }
    } else if ((instructions >> 26) == 0x5) {
        // bne $s, $t, I
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        if (registers[s] != registers[t]) {
            *line += immediate;
            *line -= 1;
        }
        
    } else if ((instructions >> 26) == 0x8) {
        // addi $t, $s, I
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        if (t != 0) {
            registers[t] = registers[s] + immediate;
        }
    } else if ((instructions >> 26) == 0xa) {
        // slti $t, $s, I
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        if (t != 0) {
            registers[t] = (registers[s] < immediate);
        }
    } else if ((instructions >> 26) == 0xc) {
        // andi $t, $s, I
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        if (t != 0) {
            registers[t] = registers[s] & immediate;
        }
    } else if ((instructions >> 26) == 0xd) {
        // ori $t, $s, I
        s = (instructions >> 21) & 0x1f;
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        if (t != 0) {
            registers[t] = registers[s] | immediate;
        }
    } else if ((instructions >> 26) == 0xf) {
        // lui $t, I
        t = (instructions >> 16) & 0x1f;
        immediate = instructions & 0xffff;
        if (t != 0) {
            registers[t] = immediate << 16;
        }
    } 
}




