#include <stdio.h>
#include "shell.h"
#include "instruction_decoder.h"

void process_instruction()
{	
	 /* execute one instruction here. You should use CURRENT_STATE and modify
     * values in NEXT_STATE. You can call mem_read_32() and mem_write_32() to
     * access memory. */

	NEXT_STATE.PC += 4;
	int current_line = (CURRENT_STATE.PC - 0x400000) / 4;
	printf("Current line is: %i\n", current_line);

	uint32_t instruction_data = mem_read_32(CURRENT_STATE.PC);
	INSTRUCTION_TYPE current_instruction_type = get_instruction_type(instruction_data);

	if(current_instruction_type == R_TYPE_INSTRUCTION) {
		r_instruction current_instruction = decode_r_type_instruction(instruction_data);
		execute_r_instruction(current_instruction);
	}
	if(current_instruction_type == I_TYPE_INSTRUCTION) {
		i_instruction current_instruction = decode_i_type_instruction(instruction_data);
		execute_i_instruction(current_instruction);
	}
	if(current_instruction_type == J_TYPE_INSTRUCTION) {
		j_instruction current_instruction = decode_j_type_instruction(instruction_data);
		execute_j_instruction(current_instruction);
	}
}
