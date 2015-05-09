#include "hb_rtype.h"

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

word hb_break(string str)
{
	return 0x0d;
}