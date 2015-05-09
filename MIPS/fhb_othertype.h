#ifndef FHB_OTHERTYPE_H
#define FHB_OTHERTYPE_H
#include "mips.h"

//I类型和其他类型反汇编
void fhb_addi(word);
void fhb_addiu(word);
void fhb_andi(word);
void fhb_beq(word);
void fhb_bgez(word);
void fhb_begzal(word);
void fhb_bgtz(word);
void fhb_blez(word);
void fhb_bltz(word);
void fhb_bltzal(word);
void fhb_bne(word);
void fhb_lb(word);
void fhb_lbu(word);
void fhb_lh(word);
void fhb_lhu(word);
void fhb_lui(word);
void fhb_lw(word);
void fhb_ori(word);
void fhb_sb(word);
void fhb_sh(word);
void fhb_slti(word);
void fhb_sltiu(word);
void fhb_sw(word);
void fhb_xori(word);
void fhb_j(word);
void fhb_jal(word);
#endif
