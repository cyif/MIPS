#ifndef HB_RTYPE_H
#define HB_RTYPE_H

#include "mips.h"

//R¿‡–Õ÷∏¡Ó
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

#endif