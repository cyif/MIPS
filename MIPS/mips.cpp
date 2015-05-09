#include "mips.h"
#include "hb_rtype.h"
#include "hb_othertype.h"
#include "fhb_rtype.h"
#include "fhb_othertype.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
using namespace std;

const string regName[REGISTER_NUM] = {
					"$zero", "$at", "$v0", "$v1",
					"$a0", "$a1", "$a2", "$a3",
					"$t0", "$t1", "$t2", "$t3",
					"$t4", "$t5", "$t6", "$t7",
					"$s0", "$s1", "$s2", "$s3",
					"$s4", "$s5", "$s6", "$s7",
					"$t8", "$t9", "$k0", "$k1",
					"$gp", "$sp", "$fp", "$ra"};

int regValue[REGISTER_NUM] = { 0 };
word vm[MAX_VM] = { 0 };
int PC = 0;

struct label{
	string s;
	int address;
};
label l[MAX_LABEL];
int labelNum = 0;

int main()
{
	cout << "input the MIPS filename:" << endl;
	string filename;
	cin >> filename;
	ifstream infile(filename.c_str());
	string temp;

	//将汇编指令转换为机器码
	while (getline(infile, temp))
	{
		//判断是否存在label
		int pos = temp.find(":", 0);
		if (pos != temp.npos)
		{
			string sub = temp.substr(0, pos);
			l[labelNum].s = sub;
			l[labelNum].address = PC;
			labelNum++;
			
			pos++;
			while (temp.substr(pos,1) == " ") pos++;
			temp = temp.substr(pos, temp.length());
		}
		//将指令转换为机器码并存入虚拟内存
		vm[PC] = hb(temp);
		PC += 4;
	}

	cout << "转化成功！ 当前虚拟内存为：" << endl;
	printVm();
	cout << "按任意键进行单步操作..." << endl;
	getchar();
	PC = 0;
	while (PC >= 0)
	{
		getchar();
		fhb(vm[PC]);
	}
	cout << "程序结束..." << endl;
	getchar();
	return 0;
}

int getRegNum(string str)
{
	if (str == "$ze")
		return 0;
	for (int i = 0; i < 32; i++)
		if (regName[i] == str)
			return i;
	cout << "没有此寄存器!, 请按任意键退出程序..." << endl;
	getchar();
	exit(0);
}

int getAddress(string str)
{
	for (int i = 0; i < labelNum; i += 4)
		if (l[i].s == str)
			return l[i].address;
	cout << "没有此label!, 请按任意键退出程序..." << endl;
	getchar();
	exit(0);
}

void printVm()
{
	int p = 0;
	while (vm[p] != 0)
	{
		cout << p << " : " << bitset<32>(vm[p]) << endl;
		p += 4;
	}
}

word hb(string str)
{
	int pos;
	string order;

	pos = str.find(" ", 0);
	order = str.substr(0, pos);
	if (order == "add")
		return hb_add(str);
	if (order == "break")
		return hb_break(str);
	cout << "指令" << order << "尚未完成, 请按任意键退出程序..." << endl;
	exit(0);
}

void fhb(word code)
{
	word op = code >> 26;
	if (op == 0)
	{
		word func = code & 0x3f;
		if (func == 0x20)
			fhb_add(code);
		if (func == 0x0d)
			fhb_break(code);
	}
}

string removeSpace(string str)
{
	//清除指令中的空格
	string::iterator it = str.begin();
	while ((it = find(it, str.end(), ' ')) != str.end())
	{
		str.erase(it);
		if (it == str.end()) break;
	}
	return str;
}