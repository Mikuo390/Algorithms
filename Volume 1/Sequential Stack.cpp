#define _CRT_SECURE_NO_WARNINGS

#include <cstddef>
#include <iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 //溢出

#define MAXSIZE 100//栈的最大容量

typedef int Status;
typedef char SElemType;

//定义
typedef struct {
	SElemType* base;//栈底指针
	SElemType* top;//栈顶指针
	int stacksize;//栈可用最大容量
}SqStack;


//栈的初始化
Status InitStack(SqStack &S) {//构造一个空栈
	S.base = new SElemType[MAXSIZE];
	//S.base = (SElemType*)malloc(MAXSIZE*sizeof(SElemType));
	if (S.base)
		exit(OVERFLOW);//存储分配失败
	S.top = S.base;//栈顶指针等于栈底指针
	S.stacksize = MAXSIZE;
}

//判断栈是否为空
Status StackEmpty(SqStack S) {
	if (S.top == S.base)//若栈为空，
		return TRUE;//返回true
	else
		return FALSE;
}

//求顺序栈长度
int StackLength(SqStack S) {
	return S.top - S.base;
}

//清空顺序栈
Status	ClearStack(SqStack S) {
	if (S.base)
		S.top = S.base;
	return OK;
}

//销毁顺序栈
Status DestoryStack(SqStack& S) {
	if (S.base) {
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

//顺序栈的入栈
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)//栈满
		return ERROR;
	*S.top++ = e;
	return OK;
}

//顺序栈的出栈
Status Pop(SqStack& S, SElemType& e) {
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK;
	if (S.top == S.base)
		return ERROR;//否则返回ERROR
	e = *--S.top;
	return OK;
}
