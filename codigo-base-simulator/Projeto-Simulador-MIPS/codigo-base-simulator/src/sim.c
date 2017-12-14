#include <stdio.h>
#include "shell.h"
#include "instruction_decoder.h"

void process_instruction()
{
	NEXT_STATE.PC += 4;

	uint32_t current_instruction = mem_read_32(CURRENT_STATE.PC);

	uint32_t op_code = get_op_code_from_instruction(current_instruction);
	if(op_code == 0) {
		r_instruction tmp = decode_r_type_instruction(current_instruction);
		if(tmp.funct == 0xc) {
			RUN_BIT = 0;
		}
	}
	printf("Current instruction: %x\n", op_code);
	printf("RS: %x\n", get_rs_from_instruction(current_instruction));
	printf("RT %x\n", get_rt_from_instruction(current_instruction));
	printf("Immediate: %i\n", get_immediate_from_instruction(current_instruction));
	printf("Funct: %x\n", get_funct_from_instruction(current_instruction));

	INSTRUCTION_TYPE current = get_instruction_type(current_instruction);
	if(current == R_TYPE_INSTRUCTION) {
		printf("This instruction is an r type instruction.\n");
	}

	if(op_code == 9) {
		printf("Running addiu instruction...\n");
		uint32_t rs_address = get_rs_from_instruction(current_instruction);
		uint32_t rt_address = get_rt_from_instruction(current_instruction);
		uint32_t immediate = get_immediate_from_instruction(current_instruction);

		uint32_t rs_value = CURRENT_STATE.REGS[rs_address];
		uint32_t rt_final_value = rs_value + immediate;
		NEXT_STATE.REGS[rt_address] = rt_final_value;
	}


	 /* execute one instruction here. You should use CURRENT_STATE and modify
     * values in NEXT_STATE. You can call mem_read_32() and mem_write_32() to
     * access memory. */
}
