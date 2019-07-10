#include "hb.h"
#include <iostream>
#include <stdlib.h>

//Rtype
word hb_add(string str)
{
	string sub;
	word code = 0x20;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;
	return code;
}
word hb_addu(string str)
{
	string sub;
	word code = 0x21;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos+1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;
	return code;
}
word hb_and(string str)
{
	string sub;
	word code = 0x24;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;
	return code;
}
word hb_break(string str)
{
	return 0x0d;
}
word hb_div(string str)
{
	string sub;
	word code = 0x2a;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	return code;
}
word hb_divu(string str)
{
	string sub;
	word code = 0x2b;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	return code;
}
word hb_eret(string str)
{
	return 0x42000018;
}
word hb_jalr(string str)
{
	string sub;
	word code = 0x09;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	return code;
}
word hb_jr(string str)
{
	string sub;
	word code = 0x08;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_mfc0(string str)
{
	string sub;
	word code = 0x00;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	code |= 0x10 << 26;
	return code;
}
word hb_mfc1(string str)
{
	string sub;
	word code = 0x00;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos+1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	code |= 0x11 << 26;
	return code;
}
word hb_mfhi(string str)
{
	string sub;
	word code = 0x10;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	return code;
}
word hb_mflo(string str)
{
	string sub;
	word code = 0x12;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	return code;
}
word hb_mtc0(string str)
{
	string sub;
	word code = 0x00;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos+1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	code |= 0x04 << 21;
	code |= 0x10 << 26;

	return code;
}
word hb_mtc1(string str)
{
	string sub;
	word code = 0x00;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	code |= 0x04 << 21;
	code |= 0x11 << 26;

	return code;
}
word hb_mthi(string str)
{
	string sub;
	word code = 0x11;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;
	return code;
}
word hb_mtlo(string str)
{
	string sub;
	word code = 0x13;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;
	return code;
}
word hb_mul(string str)
{
	string sub;
	word code = 0x02;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	code |= 0x1c << 26;
	return code;
}
word hb_mult(string str)
{
	string sub;
	word code = 0x18;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	return code;
}
word hb_multu(string str)
{
	string sub;
	word code = 0x19;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	return code;
}
word hb_nor(string str)
{
	string sub;
	word code = 0x27;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;
	return code;
}
word hb_or(string str)
{
	string sub;
	word code = 0x25;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;
	return code;
}
word hb_sll(string str)
{
	string sub;
	word code = 0x00;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos, 5);
	code |= transSft(sub) << 6;

	return code;
}
word hb_sllv(string str)
{
	string sub;
	word code = 0x04;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos+1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_slt(string str)
{
	string sub;
	word code = 0x2a;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	return code;
}
word hb_sltu(string str)
{
	string sub;
	word code = 0x2b;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	return code;
}
word hb_sra(string str)
{
	string sub;
	word code = 0x03;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos, 5);
	code |= transSft(sub) << 6;

	return code;
}
word hb_srav(string str)
{
	string sub;
	word code = 0x07;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_srl(string str)
{
	string sub;
	word code = 0x02;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos, 5);
	code |= transSft(sub) << 6;

	return code;
}
word hb_srlv(string str)
{
	string sub;
	word code = 0x06;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_sub(string str)
{
	string sub;
	word code = 0x22;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	return code;
}
word hb_subu(string str)
{
	string sub;
	word code = 0x23;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	return code;
}
word hb_syscall(string str)
{
	return 0xc;
}
word hb_xor(string str)
{
	string sub;
	word code = 0x26;
	int pos;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 11;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	return code;
}
//Other type
word hb_j(string str)
{
	string sub;
	word code = 0x02 << 26;
	int pos;

	pos = str.find(" ", 0);
	sub = str.substr(pos + 1);
	word num;
	num = getAddress(sub);
	code |= num;
	return code;
}
word hb_addi(string str)
{
	string sub;
	word code = 0x08 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos + 1);
	num = atoi(sub.c_str());
	code |= num;
	return code;
}
word hb_addiu(string str)
{
	string sub;
	word code = 0x09 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;
	return code;
}
word hb_andi(string str)
{
	string sub;
	word code = 0x0c << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;
	return code;
}
word hb_beq(string str)
{
	string sub;
	word code = 0x04 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos + 1);
	num = getAddress(sub);
	code |= num;
	return code;
}
word hb_bgez(string str)
{
	string sub;
	word code = 0x04 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	code |= 0x01 << 16;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos + 1);
	num = getAddress(sub);
	code |= num;
	return code;
}
word hb_bgezal(string str)              //未完成
{
	return 0;
}
word hb_bgtz(string str)
{
	string sub;
	word code = 0x07 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	code |= 0x00 << 16;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos + 1);
	num = getAddress(sub);
	code |= num;
	return code;
}
word hb_blez(string str)
{
	string sub;
	word code = 0x06 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	code |= 0x00 << 16;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos + 1);
	num = getAddress(sub);
	code |= num;
	return code;
}
word hb_bltz(string str)
{
	string sub;
	word code = 0x01 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	code |= 0x00 << 16;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos + 1);
	num = getAddress(sub);
	code |= num;
	return code;
}
word hb_bltzal(string str)               //未完成
{
	return 0;
}
word hb_bne(string str)
{
	string sub;
	word code = 0x05 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos + 1);
	num = getAddress(sub);
	code |= num;
	return code;
}
word hb_lb(string str)
{
	string sub;
	word code = 0x20 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_lbu(string str)
{
	string sub;
	word code = 0x24 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_lh(string str)
{
	string sub;
	word code = 0x21 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_lhu(string str)
{
	string sub;
	word code = 0x25 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_lui(string str)
{
	string sub;
	word code = 0x0f << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	sub = str.substr(pos + 1);
	num = atoi(sub.c_str());
	code |= num;

	/*pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;*/

	return code;
}
word hb_lw(string str)
{
	string sub;
	word code = 0x23 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	int pos2 = str.find("(", 0);
	sub = str.substr(pos + 1, pos2 - pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_ori(string str)
{
	string sub;
	word code = 0x0d << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_sb(string str)
{
	string sub;
	word code = 0x28 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_sh(string str)
{
	string sub;
	word code = 0x29 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_slti(string str)
{
	string sub;
	word code = 0x0a << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;
	return code;
}
word hb_sltiu(string str)
{
	string sub;
	word code = 0x0b << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;
	return code;
}
word hb_sw(string str)
{
	string sub;
	word code = 0x2b << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	int pos2 = str.find("(", 0);
	sub = str.substr(pos + 1, pos2 - pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_swcl(string str)
{
	string sub;
	word code = 0x39 << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;


	pos = str.find(",", pos);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	return code;
}
word hb_xori(string str)
{
	string sub;
	word code = 0x0e << 26;
	int pos;
	word num;

	pos = str.find("$", 0);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 16;

	pos = str.find("$", pos + 1);
	sub = str.substr(pos, 3);
	code |= getRegNum(sub) << 21;

	pos = str.find(",", pos + 1);
	sub = str.substr(pos);
	num = atoi(sub.c_str());
	code |= num;
	return code;
}
word hb_jal(string str){
	string sub;
	word code = 0x03 << 26;
	int pos;

	pos = str.find(",", 0);
	sub = str.substr(pos);
	word num;
	num = getAddress(sub);
	code |= num;
	return code;
}

word hb(string str)
{
	int pos;
	string order;
	pos = str.find(" ", 0);
	order = str.substr(0, pos);
	if (order == "add")
		return hb_add(str);
	if (order == "addu")
		return hb_addu(str);	
	if (order == "and")
		return hb_and(str);
	if (order == "break")
		return hb_break(str);
	if (order == "div")
		return hb_div(str);
	if (order == "divu")
		return hb_divu(str);
	if (order == "eret")
		return hb_eret(str);
	if (order == "jalr")
		return hb_jalr(str);
	if (order == "jr")
		return hb_jr(str);
	if (order == "mfc0")
		return hb_mfc0(str);
	if (order == "mfc1")
		return hb_mfc1(str);
	if (order == "mfhi")
		return hb_mfhi(str);
	if (order == "mflo")
		return hb_mflo(str);
	if (order == "mtc0")
		return hb_mtc0(str);
	if (order == "mtc1")
		return hb_mtc1(str);
	if (order == "mthi")
		return hb_mthi(str);
	if (order == "mtlo")
		return hb_mtlo(str);
	if (order == "mul")
		return hb_mul(str);
	if (order == "mult")
		return hb_mult(str);
	if (order == "multu")
		return hb_multu(str);
	if (order == "nor")
		return hb_nor(str);
	if (order == "or")
		return hb_or(str);
	if (order == "sll")
		return hb_sll(str);
	if (order == "sllv")
		return hb_sllv(str);
	if (order == "slt")
		return hb_slt(str);
	if (order == "sltu")
		return hb_sltu(str);
	if (order == "sra")
		return hb_sra(str);
	if (order == "srav")
		return hb_srav(str);
	if (order == "srl")
		return hb_srl(str);
	if (order == "srlv")
		return hb_srlv(str);
	if (order == "sub")
		return hb_sub(str);
	if (order == "subu")
		return hb_subu(str);
	if (order == "syscall")
		return hb_syscall(str);
	if (order == "xor")
		return hb_xor(str);
	if (order == "j")
		return hb_j(str);
	if (order == "addi")
		return hb_addi(str);
	if (order == "addiu")
		return hb_addiu(str);
	if (order == "andi")
		return hb_andi(str);
	if (order == "beq")
		return hb_beq(str);
	if (order == "bgez")
		return hb_bgez(str);
	if (order == "bgezal")
		return hb_bgezal(str);
	if (order == "bgtz")
		return hb_bgtz(str);
	if (order == "blez")
		return hb_blez(str);
	if (order == "bltz")
		return hb_bltz(str);
	if (order == "bltzal")
		return hb_bltzal(str);
	if (order == "bne")
		return hb_bne(str);
	if (order == "lb")
		return hb_lb(str);
	if (order == "lbu")
		return hb_lbu(str);
	if (order == "lh")
		return hb_lh(str);
	if (order == "lhu")
		return hb_lhu(str);
	if (order == "lui")
		return hb_lui(str);
	if (order == "lw")
		return hb_lw(str);
	if (order == "ori")
		return hb_ori(str);
	if (order == "sb")
		return hb_sb(str);
	if (order == "sh")
		return hb_sh(str);
	if (order == "slti")
		return hb_slti(str);
	if (order == "sltiu")
		return hb_sltiu(str);
	if (order == "sw")
		return hb_sw(str);
	if (order == "swcl")
		return hb_swcl(str);
	if (order == "xori")
		return hb_xori(str);
	if (order == "jal")
		return hb_jal(str);
	cout << "指令" << order << "尚未完成..." << endl;
	return 0;
}