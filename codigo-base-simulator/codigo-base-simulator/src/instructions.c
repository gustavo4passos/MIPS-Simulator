#include "instructions.h"
#include <stdio.h>

// R type
void add(r_instruction instruction) {
	NEXT_STATE.REGS[instruction.rd] = CURRENT_STATE.REGS[instruction.rs] + CURRENT_STATE.REGS[instruction.rt];
}

void addu(r_instruction instruction) {
	add(instruction);
}

void syscall(r_instruction instruction) {

	// If syscall is called with v0 = 10, stop the simulator
	if(CURRENT_STATE.REGS[2] == 0xa) {
		RUN_BIT = 0;
	}
}

// I type 
void addiu(i_instruction instruction) {
	NEXT_STATE.REGS[instruction.rt] = CURRENT_STATE.REGS[instruction.rs] + instruction.immediate;
}

// 0x4
void beq(i_instruction instruction) {
	if(CURRENT_STATE.REGS[instruction.rs] == CURRENT_STATE.REGS[instruction.rt]) {
		NEXT_STATE.PC += (instruction.immediate << 2);
	}
}

// 0x5
void bne(i_instruction instruction) {
	if(CURRENT_STATE.REGS[instruction.rs] != CURRENT_STATE.REGS[instruction.rt]) {
		NEXT_STATE.PC += (instruction.immediate << 2);
	}
}

void blez(i_instruction instruction) {
	if(CURRENT_STATE.REGS[instruction.rs] <= 0) {
		NEXT_STATE.PC += (instruction.immediate << 2);
		printf("Jumped.\n");
	}
	else {
		printf("Didn't jump.\n");
	}
}

void bgtz(i_instruction instruction) {
	if(CURRENT_STATE.REGS[instruction.rs] > 0) {
		NEXT_STATE.PC += (instruction.immediate << 2);
		printf("BGTZ jumped.\n");
	}
	else {
		printf("BGTZ didn't jump\n");
	}
}
// J type
// 0x2
void j(j_instruction instruction) {
	NEXT_STATE.PC = instruction.address << 2;
}

void jal(j_instruction instruction) {
	NEXT_STATE.REGS[31] = CURRENT_STATE.PC + 4;
	NEXT_STATE.PC = instruction.address << 2;
}