#include "fhb_rtype.h"
#include <iostream>

void fhb_add(word code)
{
	string reg1, reg2, reg3;
	int num1, num2, num3;
	code >>= 11;
	num1 = code & 0x1f;
	num2 = (code >> 10) & 0x1f;
	num3 = (code >> 5) & 0x1f;
	reg1 = regName[num1];
	reg2 = regName[num2];
	reg3 = regName[num3];
	regValue[num1] = regValue[num2] + regValue[num3];

	cout << reg1 << " = " << reg2 << " + " << reg3 
		<< " = " << regValue[num1] << endl;

	PC += 4;
}

void fhb_break(word code)
{
	cout << "break" << endl;
	PC = -1;
}