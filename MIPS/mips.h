#ifndef MIPS_H
#define MIPS_H

#include <string>
using namespace std;
#define MAX_VM 10000
#define REGISTER_NUM 32
#define MAX_LABEL 1000

typedef unsigned long word; //定义word类型,存放二进制机器码

extern const string regName[]; //寄存器
extern int regValue[]; //寄存器值
extern word vm[]; //虚拟内存
extern int PC; //程序运行处的地址

word hb(string);	//将一条汇编指令转换为机器码
int getRegNum(string); //获取某个寄存器的序号
int getAddress(string); //获取某个label的地址
void printVm(); //输出虚拟内存
void fhb(word); //将机器码反汇编，实现相应操作
string removeSpace(string); //将字符串中的空格清除

#endif