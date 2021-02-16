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

typedef struct DuLNode {
	ElemType data;//数据域
	struct DuLNode *prior,* next;//指针域
}DuLNode, * DuLinkList;

int i, j;
DuLNode* p;
DuLNode* s;
DuLNode* tmp;

//

//双向链表的插入
Status ListInsert_Dul(DuLinkList& L, int i, ElemType e) {
	//在带头结点的双向循环链表L中第i个位置之前插入元素e
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	s = new DuLNode;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
}

//双向链表的删除
Status ListDelete_DuL(DuLinkList& L, int i, ElemType& e) {
	//删除带头结点的双向循环链表L中第i个元素，并用元素e返回
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}
