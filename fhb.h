#ifndef FHB_H
#define FHB_H

#include "mips.h"
#define EXECUTIVE_MODE 1 //执行
#define TRANS_MODE 2 //转化

void fhb(word, int); //将机器码反汇编

//R类型指令反汇编
void fhb_add(word, int);
void fhb_addu(word, int);
void fhb_and(word, int);
void fhb_break(word, int);
void fhb_div(word, int);
void fhb_divu(word, int);
void fhb_eret(word, int);
void fhb_jalr(word, int);
void fhb_jr(word, int);
void fhb_mfc0(word, int);
void fhb_mfc1(word, int);
void fhb_mfhi(word, int);
void fhb_mflo(word, int);
void fhb_mtc0(word, int);
void fhb_mtc1(word, int);
void fhb_mthi(word, int);
void fhb_mtlo(word, int);
void fhb_mul(word, int);
void fhb_mult(word, int);
void fhb_multu(word, int);
void fhb_nor(word, int);
void fhb_or(word, int);
void fhb_sll(word, int);
void fhb_sllv(word, int);
void fhb_slt(word, int);
void fhb_sltu(word, int);
void fhb_sra(word, int);
void fhb_srl(word, int);
void fhb_srlv(word, int);
void fhb_sub(word, int);
void fhb_subu(word, int);
void fhb_syscall(word, int);
void fhb_xor(word, int);
void fhb_srav(word, int);

//I类型和其他类型反汇编
void fhb_addi(word, int);
void fhb_addiu(word, int);
void fhb_andi(word, int);
void fhb_beq(word, int);
void fhb_bgez(word, int);
void fhb_bgezal(word, int);
void fhb_bgtz(word, int);
void fhb_blez(word, int);
void fhb_bltz(word, int);
void fhb_bltzal(word, int);
void fhb_bne(word, int);
void fhb_lb(word, int);
void fhb_lbu(word, int);
void fhb_lh(word, int);
void fhb_lhu(word, int);
void fhb_lui(word, int);
void fhb_lw(word, int);
void fhb_ori(word, int);
void fhb_sb(word, int);
void fhb_sh(word, int);
void fhb_slti(word, int);
void fhb_sltiu(word, int);
void fhb_sw(word, int);
void fhb_xori(word, int);
void fhb_j(word, int);
void fhb_jal(word, int);

#endif