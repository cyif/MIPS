#ifndef HB_H
#define HB_H

#include "mips.h"

word hb(string); //将一条汇编指令转换为机器码

//R类型指令
word hb_add(string);
word hb_addu(string);
word hb_and(string);
word hb_break(string);
word hb_div(string);
word hb_divu(string);
word hb_eret(string);
word hb_jalr(string);
word hb_jr(string);
word hb_mfc0(string);
word hb_mfc1(string);
word hb_mfhi(string);
word hb_mflo(string);
word hb_mtc0(string);
word hb_mtc1(string);
word hb_mthi(string);
word hb_mtlo(string);
word hb_mul(string);
word hb_mult(string);
word hb_multu(string);
word hb_nor(string);
word hb_or(string);
word hb_sll(string);
word hb_sllv(string);
word hb_slt(string);
word hb_sltu(string);
word hb_sra(string);
word hb_srl(string);
word hb_srlv(string);
word hb_sub(string);
word hb_subu(string);
word hb_syscall(string);
word hb_xor(string);

//I类型和其他类型
word hb_addi(string);
word hb_addiu(string);
word hb_andi(string);
word hb_beq(string);
word hb_bgez(string);
word hb_begzal(string);
word hb_bgtz(string);
word hb_blez(string);
word hb_bltz(string);
word hb_bltzal(string);
word hb_bne(string);
word hb_lb(string);
word hb_lbu(string);
word hb_lh(string);
word hb_lhu(string);
word hb_lui(string);
word hb_lw(string);
word hb_ori(string);
word hb_sb(string);
word hb_sh(string);
word hb_slti(string);
word hb_sltiu(string);
word hb_sw(string);
word hb_xori(string);
word hb_j(string);
word hb_jal(string);

#endif