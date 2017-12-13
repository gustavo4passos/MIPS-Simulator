#include "instruction_decoder.h"

uint32_t mask_bits(uint32_t word, uint32_t mask, uint32_t shift) {
	uint32_t shifted_mask = mask << shift;
	uint32_t masked_word = (shifted_mask & word) >> shift;
	return masked_word;
}
uint32_t get_op_code_from_instruction(uint32_t instruction) {
	return mask_bits(instruction, 0x3F, 26);
}

uint32_t get_rs_from_instruction(uint32_t instruction) {
	return mask_bits(instruction, 0x1F, 21);
}

uint32_t get_rt_from_instruction(uint32_t instruction) {
	return mask_bits(instruction, 0x1F, 16);
}

uint32_t get_rd_from_instruction(uint32_t instruction) {
	return mask_bits(instruction, 0x1f, 11);
}

uint32_t get_funct_from_instruction(uint32_t instruction) {
	return mask_bits(instruction, 0x1f, 0);
}

uint32_t get_shamnt_from_instruction(uint32_t instruction) {
	return mask_bits(instruction, 0x3F, 5);
}

uint32_t get_immediate_from_instruction(uint32_t instruction) {
	return mask_bits(instruction, 0xFFF, 0);
}

uint32_t get_address_field_from_instruction(uint32_t instruction) {
	return mask_bits(instruction, 0x3FFFFFF, 0);
}

INSTRUCTION_TYPE get_instruction_type(uint32_t instruction) {
	uint32_t op_code = get_op_code_from_instruction(instruction);

	if(op_code == 0) {
		return R_TYPE_INSTRUCTION;
	}

	// Return 1 if instruction was not recognized
	return -1;
}

r_instruction decode_r_type_instruction(uint32_t instruction) {
	r_instruction tmp;
	tmp.op_code = get_op_code_from_instruction(instruction);
	tmp.rs = get_rs_from_instruction(instruction);
	tmp.rt = get_rt_from_instruction(instruction);
	tmp.rd = get_rd_from_instruction(instruction);
	tmp.shamt = get_shamnt_from_instruction(instruction);
	tmp.funct = get_funct_from_instruction(instruction);

	return tmp;
}

i_instruction decode_i_type_instruction(uint32_t instruction) {
	i_instruction tmp;
	tmp.op_code = get_op_code_from_instruction(instruction);
	tmp.rs = get_rs_from_instruction(instruction);
	tmp.rt = get_rt_from_instruction(instruction);
	tmp.immediate = get_immediate_from_instruction(instruction);

	return tmp;
}

j_instruction decode_j_type_instruction(uint32_t instruction) {
	j_instruction tmp;
	tmp.op_code = get_op_code_from_instruction(instruction);
	tmp.address = get_address_field_from_instruction(instruction);

	return tmp;
}