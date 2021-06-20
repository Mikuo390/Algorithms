#define _CRT_SECURE_NO_WARNINGS

#include <cstddef>
#include <iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 //溢出

//Status 是函数的类型，其值是函数结构状态代码
typedef int Status;
typedef char ElemType;

typedef struct student {//数据域
	char data[8];
}EleType;

typedef struct Lnode {
	ElemType data;//数据域
	struct Lnode* next;//指针域
}Lnode, * LinkList;

int i, j;
Lnode* p;
Lnode* tmp;

//带尾指针循环链表的合并
LinkList Connect(LinkList Ta, LinkList Tb) {
	//假设Ta,Tb都是非空的单循环链表
	p = Ta->next;//p存表头结点
	Ta->next = Tb->next->next;//Tb的表头链接Ta表尾
	delete Tb->next;//释放Tb表头结点
	Tb->next = p;//修改指针
	return Tb;
}
