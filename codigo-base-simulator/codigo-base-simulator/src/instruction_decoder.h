#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

#include <stdint.h>

typedef enum INSTRUCTION_TYPE {
	R_TYPE_INSTRUCTION,
	I_TYPE_INSTRUCTION,
	J_TYPE_INSTRUCTION,
	INVALID_INSTRUCTION_TYPE
} INSTRUCTION_TYPE;

typedef enum R_INSTRUCTIONS {
	ADD = 0x20,
	ADDU = 0x21,
	SYSCALL = 0xc
} R_INSTRUCTIONS;

typedef enum I_INSTRUCTIONS {
	REGIMM = 0x1,
	BEQ = 0x4,
	BNE = 0x5,
	BLEZ = 0x6,
	BGTZ = 0x7,
	ADDIU = 0x9
} I_INSTRUCTIONS;

typedef enum J_INSTRUCTIONS {
	J = 0x2,
	JAL = 0x3
} J_INSTRUCTIONS;

typedef struct {
	uint32_t op_code;
	uint32_t rs;
	uint32_t rt;
	uint32_t rd;
	uint32_t shamt;
	uint32_t funct;	
} r_instruction;
 
typedef struct {
	uint32_t op_code;
	uint32_t rs;
	uint32_t rt;
	int16_t immediate;
} i_instruction;

typedef struct {
	uint32_t op_code;
	uint32_t address;
} j_instruction;

// Mask a sequence of bits in a word
uint32_t mask_bits(uint32_t word, uint32_t mask, uint32_t shift);

// Returns the registers address from a instruction
uint32_t get_rs_from_instruction(uint32_t instruction);
uint32_t get_rt_from_instruction(uint32_t instruction);
uint32_t get_rd_from_instruction(uint32_t instruction);

// Returns fields from a instruction
uint32_t get_op_code_from_instruction(uint32_t instruction);
uint32_t get_shamnt_from_instruction(uint32_t instruction);
uint32_t get_funct_from_instruction(uint32_t instruction);
int16_t get_immediate_from_instruction(uint32_t instruction);
uint32_t get_address_field_from_instruction(uint32_t instruction);

// Returns a INSTRUCTION_TYPE enum informing if the instruction is r, i or j type
INSTRUCTION_TYPE get_instruction_type(uint32_t instruction);

// Returns a *_instruction type extracted from a 32 bit instruction
r_instruction decode_r_type_instruction(uint32_t instruction);
i_instruction decode_i_type_instruction(uint32_t instruction);
j_instruction decode_j_type_instruction(uint32_t instruction);

void execute_r_instruction(r_instruction instruction);
void execute_i_instruction(i_instruction instruction);
void execute_j_instruction(j_instruction instruction);

#endif