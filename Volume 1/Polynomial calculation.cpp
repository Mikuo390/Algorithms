#define _CRT_SECURE_NO_WARNINGS

#include <cstddef>
#include <iostream>
using namespace std;

//typedef struct DataNode {//数据域
//	float coef;//系数
//	int expn;//指数
//}ElemType;
//
//typedef struct PNode {
//	ElemType* data;//数据域
//	struct	PNode* next;//指针域
//}PNode, * Polynomial;


typedef struct PNode {
	float coef;//系数
	int expn;//指数
	struct	PNode* next;//指针域
}PNode, * Polynomial;

int i;

void CreatePolyn(Polynomial& P, int n) {
	//输入m项的系数和指数，建立表示多项式的有序链表P
	PNode* s, * p,* pre,* q;
	P = new PNode;
	P->next = NULL;//先建立一个带头结点的单链表
	
	for (i = 1; i <= n; i++) {//依次输入n个非零项
		s = new PNode;//生成新结点
		cin >> s->coef >> s->expn;//输入系数和指数
		pre = P;//pre用于保存q的前驱，初值为头结点
		q = P->next;//q初始化，指向首元结点
		while (q && q->expn < s->expn) {//找到第一个大于输入项指数的项*q
			pre = q;
			q = q->next;
		}
		s->next = q;//将输入项s插入到q和其前驱结点pre之间
		pre->next = s;
	}
}
