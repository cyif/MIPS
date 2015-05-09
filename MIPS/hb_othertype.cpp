#include "hb_othertype.h"

word hb_j(string str)
{
	string sub;
	word code = 0x02 << 26;
	int pos;

	pos = str.find(" ", 0);
	sub = str.substr(pos);
	word num;
	num = getAddress(sub);
	code |= num;
	return code;
}