#include "fhb.h"
#include <stdlib.h>
#include <iostream>

void fhb_add(word code, int mode)
{
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "add " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] + regValue[num3];
		PC += 4;
	}
}
void fhb_addu(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "addu " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = (unsigned int)regValue[num2] + (unsigned int)regValue[num3];
		PC += 4;
	}
}
void fhb_and(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "and " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] & regValue[num3];
		PC += 4;
	}
}
void fhb_div(word code, int mode){
	string reg1, reg2;
	int num1, num2;
	num1 = (code >> 21) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "div " << reg1 << "," << reg2 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		hi = regValue[num1] / regValue[num2];
		lo = regValue[num1] % regValue[num2];
		PC += 4;
	}
}
void fhb_divu(word code, int mode){
	string reg1, reg2;
	int num1, num2;
	num1 = (code >> 21) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "divu " << reg1 << "," << reg2 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		hi = (unsigned int)regValue[num1] / (unsigned int)regValue[num2];
		lo = (unsigned int)regValue[num1] % (unsigned int)regValue[num2];
		PC += 4;
	}
}
void fhb_eret(word code, int mode){
	cout << "eret" << endl;
	if (mode == EXECUTIVE_MODE)
		PC = EPC;
}
void fhb_jalr(word code, int mode){
	string reg1, reg2;
	int num1, num2;
	num1 = (code >> 21) & 0x1f;
	num2 = (code >> 11) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "jalr " << reg1 << "," << reg2 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num2] = PC + 4;
		PC = regValue[num1];
	}
}
void fhb_jr(word code, int mode){
	string reg1;
	int num1;
	num1 = (code >> 21) & 0x1f;
	reg1 = regName[num1];

	cout << "jr " << reg1 << endl;
	if (mode == EXECUTIVE_MODE)
		PC = regValue[num1];
}
void fhb_mfc0(word code, int mode){
	string reg1, reg2;
	int num1, num2;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 11) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "mfc0 " << reg1 << "," << reg2 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2];
		PC += 4;
	}
}
void fhb_mfc1(word code, int mode){
	string reg1, reg2;
	int num1, num2;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 11) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "mfc1 " << reg1 << "," << reg2 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2];
		PC += 4;
	}
}
void fhb_mfhi(word code, int mode){
	string reg1;
	int num1;
	num1 = (code >> 11) & 0x1f;
	reg1 = regName[num1];

	cout << "mfhi " << reg1 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = hi;
		PC += 4;
	}
}
void fhb_mflo(word code, int mode){
	string reg1;
	int num1;
	num1 = (code >> 11) & 0x1f;
	reg1 = regName[num1];

	cout << "mflo " << reg1 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = lo;
		PC += 4;
	}
}
void fhb_mtc0(word code, int mode){
	string reg1, reg2;
	int num1, num2;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 11) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "mtc0 " << reg1 << "," << reg2 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num2] = regValue[num1];
		PC += 4;
	}
}
void fhb_mtc1(word code, int mode){
	string reg1, reg2;
	int num1, num2;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 11) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "mtc1 " << reg1 << "," << reg2 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num2] = regValue[num1];
		PC += 4;
	}
}
void fhb_mthi(word code, int mode){
	string reg1;
	int num1;
	num1 = (code >> 21) & 0x1f;
	reg1 = regName[num1];

	cout << "mthi " << reg1 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		hi = regValue[num1];
		PC += 4;
	}
}
void fhb_mtlo(word code, int mode){
	string reg1;
	int num1;
	num1 = (code >> 21) & 0x1f;
	reg1 = regName[num1];

	cout << "mtlo " << reg1 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		lo = regValue[num1];
		PC += 4;
	}
}
void fhb_mul(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "mul " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] * regValue[num3];
		PC += 4;
	}
}
void fhb_mult(word code, int mode){
	string reg1, reg2;
	int num1, num2;
	num1 = (code >> 21) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "mult " << reg1 << "," << reg2 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		hi = regValue[num1] * regValue[num2];
		lo = regValue[num1] * regValue[num2];
		PC += 4;
	}
}
void fhb_multu(word code, int mode){
	string reg1, reg2;
	int num1, num2;
	num1 = (code >> 21) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "multu " << reg1 << "," << reg2 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		hi = (unsigned int)regValue[num1] * (unsigned int)regValue[num2];
		lo = (unsigned int)regValue[num1] * (unsigned int)regValue[num2];
		PC += 4;
	}
}
void fhb_nor(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "nor " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = ~(regValue[num2] | regValue[num3]);
		PC += 4;
	}
}
void fhb_or(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "or " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] * regValue[num3];
		PC += 4;
	}
}
void fhb_sll(word code, int mode){
	string reg1, reg2;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	num3 = (code >> 6) & 0x1f;

	cout << "sll " << reg1 << "," << reg2 << "," << num3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] << num3;
		PC += 4;
	}
}
void fhb_sllv(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	num3 = (code >> 21) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "sllv " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] << regValue[num3];
		PC += 4;
	}
}
void fhb_slt(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "slt " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = 0;
		if (regValue[num2] < regValue[3])
			regValue[num1] = 1;
		PC += 4;
	}
}
void fhb_sltu(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "sltu " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = 0;
		if ((unsigned int)regValue[num2] < (unsigned int)regValue[3])
			regValue[num1] = 1;
		PC += 4;
	}
}
void fhb_sra(word code, int mode){
	string reg1, reg2;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	num3 = (code >> 6) & 0x1f;

	cout << "sra " << reg1 << "," << reg2 << "," << num3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] >> num3;
		PC += 4;
	}
}
void fhb_srav(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	num3 = (code >> 21) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "srav " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] >> regValue[num3];
		PC += 4;
	}
}
void fhb_srl(word code, int mode){
	string reg1, reg2;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	num3 = (code >> 6) & 0x1f;

	cout << "srl " << reg1 << "," << reg2 << "," << num3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = (unsigned int)regValue[num2] >> num3;
		PC += 4;
	}
}
void fhb_srlv(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	num3 = (code >> 21) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "srlv " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = (unsigned int)regValue[num2] >> regValue[num3];
		PC += 4;
	}
}
void fhb_sub(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "sub " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] - regValue[num3];
		PC += 4;
	}
}
void fhb_subu(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "subu " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = (unsigned int)regValue[num2] - (unsigned int)regValue[num3];
		PC += 4;
	}
}
void fhb_syscall(word code, int mode){
	cout << "syscall" << endl;
}
void fhb_xor(word code, int mode){
	string reg1, reg2, reg3;
	int num1, num2, num3;
	num1 = (code >> 11) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	num3 = (code >> 16) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];

	cout << "xor " << reg1 << "," << reg2 << "," << reg3 << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] ^ regValue[num3];
		PC += 4;
	}
}

void fhb_break(word code, int mode)
{
	cout << "break" << endl;
	if (mode == EXECUTIVE_MODE)
		PC = EPC;
}
void fhb_addi(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "addi " << reg1 << "," << reg2 << "," << imm << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] + imm;
		PC += 4;
	}
}
void fhb_addiu(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "addiu " << reg1 << "," << reg2 << "," << imm << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = (unsigned int)regValue[num2] + imm;
		PC += 4;
	}
}
void fhb_andi(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "andi " << reg1 << "," << reg2 << "," << imm << endl;
	if (mode == EXECUTIVE_MODE)
	{
		regValue[num1] = regValue[num2] & imm;
		PC += 4;
	}

}
void fhb_beq(word code, int mode){
	string reg1, reg2,s;
	int num1, num2, L;
	num1 = (code >> 21) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	L = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];
	s = find_label(L);

	cout << "beq " << reg1 << "," << reg2 << "," << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		if (regValue[num1] == regValue[num2])
			PC = L;
	}
}
void fhb_bgez(word code, int mode){
	string reg1,s;
	int num1, L;
	num1 = (code >> 21) & 0x1f;
	L = code & 0xffff;
	reg1 = regName[num1];
	s = find_label(L);

	cout << "bgez " << reg1 << "," << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		if (regValue[num1] >= 0)
			PC = L;
	}
}
void fhb_bgezal(word code, int mode){
	string reg1,s;
	int num1, L;
	num1 = (code >> 21) & 0x1f;
	L = code & 0xffff;
	reg1 = regName[num1];
	s = find_label(L);

	cout << "bgezal " << reg1 << "," << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		if (regValue[num1] >= 0)
		{ 
			PC = L;
			regValue[31] = PC;
		}
	}
}
void fhb_bgtz(word code, int mode){
	string reg1,s;
	int num1, L;
	num1 = (code >> 21) & 0x1f;
	L = code & 0xffff;
	reg1 = regName[num1];
	s = find_label(L);

	cout << "bgtz " << reg1 << "," << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		if (regValue[num1] > 0)
			PC = L;
	}
}
void fhb_blez(word code, int mode){
	string reg1,s;
	int num1, L;
	num1 = (code >> 21) & 0x1f;
	L = code & 0xffff;
	reg1 = regName[num1];
	s = find_label(L);

	cout << "blez " << reg1 << "," << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		if (regValue[num1] <= 0)
			PC = L;
	}
}
void fhb_bltz(word code, int mode){
	string reg1,s;
	int num1, L;
	num1 = (code >> 21) & 0x1f;
	L = code & 0xffff;
	reg1 = regName[num1];
	s = find_label(L);

	cout << "bltz " << reg1 << "," << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		if (regValue[num1] < 0)
			PC = L;
	}
}
void fhb_bltzal(word code, int mode){
	string reg1,s;
	int num1, L;
	num1 = (code >> 21) & 0x1f;
	L = code & 0xffff;
	reg1 = regName[num1];
	s = find_label(L);

	cout << "bltzal " << reg1 << "," << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		if (regValue[num1] < 0)
		{
			PC = L;
			regValue[31] = PC;
		}
	}
}
void fhb_bne(word code, int mode){
	string reg1, reg2,s;
	int num1, num2, L;
	num1 = (code >> 21) & 0x1f;
	num2 = (code >> 16) & 0x1f;
	L = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];
	s = find_label(L);

	cout << "bne " << reg1 << "," << reg2 << "," << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		if (regValue[num1] != regValue[num2])
			PC = L;
	}
}
void fhb_lb(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "lb " << reg1 << "," << imm << "(" << reg2 << ")" << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		regValue[num1] = memory[regValue[num2] + imm];
	}
}
void fhb_lbu(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "lbu " << reg1 << "," << imm << "(" << reg2 << ")" << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		regValue[num1] = memory[regValue[num2] + imm];
	}
}
void fhb_lh(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "lh " << reg1 << "," << imm << "(" << reg2 << ")" << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		regValue[num1] = memory[regValue[num2] + imm];
	}
}
void fhb_lhu(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "lhu " << reg1 << "," << imm << "(" << reg2 << ")" << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		regValue[num1] = memory[regValue[num2] + imm];
	}
}
void fhb_lui(word code, int mode){
	string reg1;
	int num1, imm;
	num1 = (code >> 16) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];

	cout << "lui " << reg1 << "," << imm << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		regValue[num1] = imm;
	}
}
void fhb_lw(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "lw " << reg1 << "," << imm << "(" << reg2 << ")" << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		regValue[num1] = memory[regValue[num2] + imm];
	}
}
void fhb_ori(word)
{
}
void fhb_sb(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "sb " << reg1 << "," << imm << "(" << reg2 << ")" << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		memory[regValue[num2] + imm] = regValue[num1];
	}
}
void fhb_sh(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "sh " << reg1 << "," << imm << "(" << reg2 << ")" << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		memory[regValue[num2] + imm] = regValue[num1];
	}
}
void fhb_slti(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "slti " << reg1 << "," << reg2 << "," << imm << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		regValue[num1] = 0;
		if (regValue[num2] < imm)
			regValue[num1] = 1;
	}
}
void fhb_sltiu(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "sltiu " << reg1 << "," << reg2 << "," << imm << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		regValue[num1] = 0;
		if ((unsigned int)regValue[num2] < (unsigned int)imm)
			regValue[num1] = 1;
	}

}
void fhb_sw(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "sw " << reg1 << "," << imm << "(" << reg2 << ")" << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		memory[regValue[num2] + imm] = regValue[num1];
	}
}
void fhb_xori(word code, int mode){
	string reg1, reg2;
	int num1, num2, imm;
	num1 = (code >> 16) & 0x1f;
	num2 = (code >> 21) & 0x1f;
	imm = code & 0xffff;
	reg1 = regName[num1];
	reg2 = regName[num2];

	cout << "xori " << reg1 << "," << reg2 << "," << imm << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC += 4;
		regValue[num1] = regValue[num2] ^ imm;
	}
}
void fhb_j(word code, int mode){
	int L;
	string s;
	L = code & 0x3ffffff;
	s = find_label(L);

	cout << "j " << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC = L;
	}
}
void fhb_jal(word code, int mode){
	int L;
	string s;
	L = code & 0x3ffffff;
	s = find_label(L);

	cout << "jal " << s << endl;
	if (mode == EXECUTIVE_MODE)
	{
		PC = L;
		regValue[31] = PC + 4;
	}
}
void fhb(word code, int mode){
	int op, func;
	op = code >> 26;
	func = code & 0x3f;
	if (op == 0){
		switch (func){
		case 0x20:fhb_add(code, mode); break;
		case 0x21:fhb_addu(code, mode); break;
		case 0x24:fhb_and(code, mode); break;
		case 0x0d:fhb_break(code, mode); break;
		case 0x1a:fhb_div(code, mode); break;
		case 0x1b:fhb_divu(code, mode); break;
		case 9:fhb_jalr(code, mode); break;
		case 8:fhb_jr(code, mode); break;
		case 0x10:fhb_mfhi(code, mode); break;
		case 0x12:fhb_mflo(code, mode); break;
		case 0x11:fhb_mthi(code, mode); break;
		case 0x13:fhb_mtlo(code, mode); break;
		case 0x18:fhb_mult(code, mode); break;
		case 0x19:fhb_multu(code, mode); break;
		case 0x27:fhb_nor(code, mode); break;
		case 0x25:fhb_or(code, mode); break;
		case 0:fhb_sll(code, mode); break;
		case 4:fhb_sllv(code, mode); break;
		case 0x2a:fhb_slt(code, mode); break;
		case 0x2b:fhb_sltu(code, mode); break;
		case 3:fhb_sra(code, mode); break;
		case 7:fhb_srav(code, mode); break;
		case 2:fhb_srl(code, mode); break;
		case 6:fhb_srlv(code, mode); break;
		case 0x22:fhb_sub(code, mode); break;
		case 0x23:fhb_subu(code, mode); break;
		case 0xc:fhb_syscall(code, mode); break;
		case 0x26:fhb_xor(code, mode); break;
		}
	}
	else if (op == 0x10){
		switch (func){
		case 0x18:fhb_eret(code, mode); break;
		case 0:
			if ((code >> 21) & 0x1f == 0)
				fhb_mfc0(code, mode);
			else
				fhb_mtc0(code, mode);
			break;
		}
	}
	else if (op == 0x11){
		if ((code >> 21) & 0x1f == 0)
			fhb_mfc1(code, mode);
		else
			fhb_mtc1(code, mode);
	}
	else if (op == 0x1c)
		fhb_mul(code, mode);
	else if (op == 1){
		int rt;
		rt = (code >> 16) & 0x1f;
		switch (rt){
		case 1:fhb_bgez(code, mode); break;
		case 17:fhb_bgezal(code, mode); break;
		case 0:fhb_bltz(code, mode); break;
		case 16:fhb_bltzal(code, mode); break;
		}
	}
	else if (op == 2)
		fhb_j(code, mode);
	else if (op == 3)
		fhb_jal(code, mode);
	else if (op == 4)
		fhb_beq(code, mode);
	else if (op == 5)
		fhb_bne(code, mode);
	else if (op == 6) 
		fhb_blez(code, mode);
	else if (op == 7)
		fhb_bgtz(code, mode);
	else if (op == 8)
		fhb_addi(code, mode);
	else if (op == 9)
		fhb_addiu(code, mode);
	else if (op == 0x0c)
		fhb_andi(code, mode);
	else if (op == 0x20)
		fhb_lb(code, mode);
	else if (op == 0x24)
		fhb_lbu(code, mode);
	else if (op == 0x21)
		fhb_lh(code, mode);
	else if (op == 0x25)
		fhb_lhu(code, mode);
	else if (op == 0x0f)
		fhb_lui(code, mode);
	else if (op == 0x23)
		fhb_lw(code, mode);
	else if (op == 0x28)
		fhb_sb(code, mode);
	else if (op == 0x29)
		fhb_sh(code, mode);
	else if (op == 0x0a)
		fhb_slti(code, mode);
	else if (op == 0x0b)
		fhb_sltiu(code, mode);
	else if (op == 0x2b)
		fhb_sw(code, mode);
	else if (op == 0x0e)
		fhb_xori(code, mode);
}