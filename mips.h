#ifndef MIPS_H
#define MIPS_H

#include <string>
using namespace std;
#define EPC -1
#define MAX_VM 10000
#define REGISTER_NUM 32
#define MAX_LABEL 1000
#define MAX_INS 1000
#define MAX_MEMORY 10000
#define DATA_MODE 1
#define INSTRUCTION_MODE 2

typedef unsigned long word; //定义word类型,存放二进制机器码
struct label{
	string s;
	int address;
}; //定义label结构体，存放所有label名称与地址

extern const string regName[]; //寄存器
extern int regValue[]; //寄存器值
extern word vm[]; //虚拟内存
extern int PC; //程序运行处的地址
extern label l[]; //存放所有Label
extern int hi, lo; //hilo寄存器
extern int memory[]; //内存

int getRegNum(string); //获取某个寄存器的序号
int getAddress(string); //获取某个label的地址
void printVm(int); //输出虚拟内存
string removeSpace(string); //将字符串中的空格清除
int transSft(string); //获取位移量
string find_label(int); //根据地址获取Label
void outputReg(); //输出当前寄存器的值
void cleanVm(); //清空内存

#endif