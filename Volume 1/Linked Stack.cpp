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
typedef struct StackNode{
	SElemType data;//数据域
	struct StackNode *next;//
}StackNode,*LinkStack;
LinkStack S;


//栈的初始化
Status InitStack(LinkStack &S) {
	//构造一个空栈，栈顶指针置为空
	S = NULL;
	return OK;
}

//判断链栈是否为空
Status StackEmpty(LinkStack S) {
	if (S == NULL)
		return TRUE;
	else
		return FALSE;
}

////求顺序栈长度
//int StackLength(SqStack S) {
//	return S.top - S.base;
//}
//
////清空顺序栈
//Status	ClearStack(SqStack S) {
//	if (S.base)
//		S.top = S.base;
//	return OK;
//}
//
////销毁顺序栈
//Status DestoryStack(SqStack& S) {
//	if (S.base) {
//		delete S.base;
//		S.stacksize = 0;
//		S.base = S.top = NULL;
//	}
//	return OK;
//}

//链栈的入栈
Status Push(LinkStack& S, SElemType e) {
	StackNode *p = new StackNode;//生成新结点p
	p->data = e;//将新结点数据域置为e
	p->next = S;//将新结点插入栈顶
	S = p;//修改栈顶指针
	return OK;
}

//链栈的出栈
Status Pop(LinkStack& S, SElemType& e) {
	StackNode* p = new StackNode;
	if (S == NULL)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}

//取栈顶元素
SElemType GetTop(LinkStack S) {
	if (S != NULL)
		return S->data;
}
