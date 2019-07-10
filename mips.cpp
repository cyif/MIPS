#include "mips.h"
#include "hb.h"
#include "fhb.h"
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

word vm[MAX_VM] = { 0 };
label l[MAX_LABEL];
int regValue[REGISTER_NUM] = { 0 };
int memory[MAX_MEMORY] = { 0 };
int PC = 0;
int labelNum = 0;
int hi = 0, lo = 0;
int sumIns = 0;

int main()
{
	/*cout << "input the MIPS filename:" << endl;
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
	getchar();*/
	char ch;
	string ins[MAX_INS];


	cout << "请输入命令：" << endl;
	cout << "R: 查看寄存器" << endl;
	cout << "D: 数据方式查看内存" << endl;
	cout << "U: 指令方式查看内存" << endl;
	cout << "A: 写汇编指令到内存" << endl;
	cout << "T: 单步执行内存中的指令" << endl;
	cout << "Q: 退出" << endl;
	while (1)
	{
		cin >> ch;
		getchar();
		switch (ch)
		{
		case 'R': case 'r':
		cout << l[labelNum].s << endl;
			outputReg();
			break;
		case 'D': case 'd':
			printVm(DATA_MODE);
			break;
		case 'U': case 'u':
			printVm(INSTRUCTION_MODE);
			break;
		case 'A': case 'a':
			cleanVm();
			cout << "请输入指令，最后一行请输入end" << endl;
			getline(cin, ins[sumIns]);
			while (ins[sumIns] != "end")
			{
				//判断是否存在label
				int pos = ins[sumIns].find(":", 0);
				if (pos != ins[sumIns].npos)
				{
					l[labelNum].s = ins[sumIns].substr(0, pos);
					l[labelNum].address = PC;
					labelNum++;
					//将label从指令中去除
					pos++;
					while (ins[sumIns].substr(pos, 1) == " ") pos++;
					ins[sumIns] = ins[sumIns].substr(pos, ins[sumIns].length());
				}
				//将指令转换为机器码并存入虚拟内存
				PC += 4;
				sumIns++;
				getline(cin, ins[sumIns]);
			}
			for (int i = 0; i < PC; i+=4)
				vm[i] = hb(ins[i/4]);
			PC = 0;
			break;
		case 'T': case 't':
			if (PC == -1 || vm[PC] == 0)
				cout << "当前PC处没有可执行的指令" << endl;
			else
				fhb(vm[PC], EXECUTIVE_MODE);
			break;
		case 'Q': case 'q':
			exit(1);
			break;
		default:
			cout << "指令不正确!" << endl;
		}
	}
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
	cout << str << "没有此label!, 请按任意键退出程序..." << endl;
	getchar();
	exit(0);
}

void printVm(int mode)
{
	int p = 0;
	while (vm[p] != 0)
	{
		cout << p << " : ";
		if (mode == DATA_MODE)
			cout << bitset<32>(vm[p]) << endl;
		else if (mode == INSTRUCTION_MODE)
			fhb(vm[p], TRANS_MODE);
		p += 4;
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
int transSft(string str)
{
	int i , k, num=0, tmp;
	for (i = 4; i > 0; i++){
		tmp = str[i] - 48;
		for (k = i; k>1; k--){
			tmp *= 10;
		}
		num += tmp;
	}
	return num;
}
string find_label(int L)
{
	for (int i = 0; i < MAX_LABEL; i += 4){
		if (l[i].address == L)
			return l[i].s;
	}
	return "";
}
void outputReg()
{
	cout << "PC : " << PC << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int num = i * 4 + j;
			cout << regName[num] << ":" << regValue[num];
			cout << "    ";
		}
		cout << endl;
	}
	cout << "hi : " << hi << "    "
		<< "lo : " << lo << endl;
}

void cleanVm()
{
	for (int i = 0; i < MAX_VM; i++)
		vm[i] = 0;
	PC = 0;
	sumIns = 0;
}