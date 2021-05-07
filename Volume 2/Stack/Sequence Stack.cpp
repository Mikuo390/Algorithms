#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 //溢出

#define MaxSize 100
#define SElemType int
#define Status int
using namespace std;

//栈数据结构
typedef struct Stack {
	SElemType* base;//栈底指针 不变
	SElemType* top;//栈顶指针 一直在栈顶元素上一个位置
	int stacksize;//栈可用的最大容量
}SqStack;

//**************************************基本操作函数************************************//

//初始化函数
Status InitStack(SqStack& S) {

	S.base = new SElemType[MaxSize];

	if (!S.base) {
		cout << "分配失败" << endl;
		return 0;
	}

	S.top = S.base;//栈顶指针与栈底相同，top应该高于或等于base
	S.stacksize = MaxSize;
	return 1;
}

//判断栈是否为空
bool StackEmpty(SqStack S) {
	if (S.top == S.base)
		return true;
	else
		return false;
}

//求栈的长度
int StackLength(SqStack S) {
	return S.top - S.base;
}

//清空顺序栈
Status ClearStack(SqStack S) {
	if (S.base)
		S.top = S.base;
	return OK;
}

//删除顺序栈
Status DestroyStack(SqStack& S) {
	if (S.base) {
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

//入栈
Status Push(SqStack& S, SElemType e) {

	if (S.top - S.base == S.stacksize)
		return 0;
	*S.top++ = e;
	return 1;
}

//出栈
Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base)
		return 0;//栈空
	e = *--S.top;//先减减 指向栈顶元素，再给e
	return 1;
}

//得到栈顶元素，不修改指针
bool GetTop(SqStack S, SElemType& e) {
	if (S.top == S.base)
		return false;
	else
		e = *--S.top;
	return true;
}

//********************************功能实现函数**************************************//
//菜单
void menu(){
	printf("********1.入栈      2.出栈*********\n");
	printf("********3.取栈顶    4.退出*********\n");
}


//入栈功能函数 调用Push函数
void PushToStack(SqStack& S) {
	int n;
	SElemType e;
	int flag;
	cout << "请输入入栈元素个数(>=1)：\n";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个元素的值:";
		cin >> e;
		flag = Push(S, e);
		if (flag)
			cout << e << "已入栈" << endl;
		else {
			cout << "栈已满" << endl;
			break;
		}			
	}
}

//出栈功能函数
void PopFromStack(SqStack& S) {
	int n; 
	SElemType e; 
	int flag;
	cout << "请输入出栈元素个数(>=1)：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		flag = Pop(S, e);
		if (flag)
			cout << e << "已出栈" << endl;
		else {
			cout << "栈已空！！！" << endl;
			break;
		}
	}
}


//取栈顶功能函数 调用GetTop
void GetTopOfStack(SqStack& S)
{
	SElemType e; 
	bool flag;
	flag = GetTop(S, e);
	if (flag)
		cout << "栈顶元素为:%d" << e << endl;
	else
		cout << "栈已空！！！" << endl;;
}


//主函数
int main()
{
	SqStack s; int choice;
	InitStack(s);
	while (1)
	{
		menu();
		cout << "请输入菜单序号：" << endl;
		cin >> choice;
		if (choice == 4) break;
		switch (choice)
		{
		case 1:PushToStack(s); break;
		case 2:PopFromStack(s); break;
		case 3:GetTopOfStack(s); break;
		default:printf("输入错误！！！\n");
		}
	}
	return 0;
}
