#ifndef FHB_RTYPE_H
#define FHB_RTYPE_H
#include "mips.h"

//R类型指令反汇编
void fhb_add(word);
void fhb_addu(word);
void fhb_and(word);
void fhb_break(word);
void fhb_div(word);
void fhb_divu(word);
void fhb_eret(word);
void fhb_jalr(word);
void fhb_jr(word);
void fhb_mfc0(word);
void fhb_mfc1(word);
void fhb_mfhi(word);
void fhb_mflo(word);
void fhb_mtc0(word);
void fhb_mtc1(word);
void fhb_mthi(word);
void fhb_mtlo(word);
void fhb_mul(word);
void fhb_mult(word);
void fhb_multu(word);
void fhb_nor(word);
void fhb_or(word);
void fhb_sll(word);
void fhb_sllv(word);
void fhb_slt(word);
void fhb_sltu(word);
void fhb_sra(word);
void fhb_srl(word);
void fhb_srlv(word);
void fhb_sub(word);
void fhb_subu(word);
void fhb_syscall(word);
void fhb_xor(word);

#endif