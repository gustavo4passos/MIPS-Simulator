#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "instruction_decoder.h"
#include "shell.h"

/***************************************/
/*		R_TYPE                         */
/***************************************/
void add(r_instruction instruction);
void addu(r_instruction instruction);
void syscall(r_instruction instruction);


/***************************************/
/*		I_TYPE                         */
/***************************************/
void beq(i_instruction instruction);
void bne(i_instruction instruction);
void bgez(i_instruction instruction);
void blez(i_instruction instruction);
void bgtz(i_instruction instruction);
void addiu(i_instruction instruction);


/***************************************/
/*		J_TYPE                         */
/***************************************/
void j(j_instruction instruction); 
void jal(j_instruction instruction);

#endif