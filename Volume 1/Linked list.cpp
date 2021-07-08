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

int i, j;
Lnode* p;
Lnode* tmp;



typedef struct student {//数据域
	char num[8];
	char name[8];
	int score;
}ElemType;

typedef struct Lnode {
	ElemType data;//数据域
	struct Lnode* next;//指针域
}Lnode,*LinkList;

//初始化链表
Status InitList_L(LinkList& L) {
	L = new Lnode;
	L->next = NULL;
	return OK;
}

//判断链表是否为空
int ListEmpty(LinkList L) {
	if (L->next)//若L为空表，则返回1
		return 0;//否则返回0
	else
		return 1;
}

//销毁单链表L
Status DestoryList_L(LinkList& L) {
	Lnode* p;//或LinkList p;
	while (L){
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}

//清空链表L
Status ClearList(LinkList& L) {
	Lnode* p,*tmp;//LinkList p,tmp;
	p = L->next;
	while (p){
		tmp = p->next;
		delete p;
		p = tmp;
	}
	L->next = NULL;
	return OK;
}

//求单链表L的表长
int ListLength_L(LinkList L) {//返回L中数据元素个数
	LinkList p;
	p = L->next;//p指向第一个结点
	i = 0;
	while (p){//遍历单链表，统计节点数
		i++;
		p = p->next;
	}
	//for (i = 0; p; i++) {
	//	p = p->next;
	//}
	return i;//返回链表长度
}

//取单链表中第i个元素的内容
Status GetElem_L(LinkList L, int i, ElemType& e) {
	//活出线性表L的某个数据元素的内容，通过变量e返回
	//Lnode* p;
	p = L->next;
	j = 1;
	while (p && j < i) {//向后扫描，直到p指向第i个元素
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;//第i个元素不存在
	e = p->data;//取第i个元素
	return OK;
}//GetElem_L

//按值查找-根据指定数据获取该数据所在的位置
Lnode *LocatElem_L(LinkList L,ElemType e){
	//在线性表L中查找值为e的数据元素
	//找到，则返回L中值为e的数据元素的地址
	//查找失败返回NULL
	p = L->next;
	while (p && p->data != 0)
		p = p->next;
	return p;
}

//按值查找-根据指定数据获取该数据所在的位置
int LocateElem_L(LinkList L, ElemType e) {
	//在线性表L中查找值为e的数据元素的位置序号
	p = L->next;
	j = 1;
	while (p && p->data != e) {
		p = p->next;
		j++;
	}
	if (p)
		return j;
	else
		return 0;
}

//插入-在第i个结点前插入值为e的新结点
Status ListInsert_L(LinkList& L, int i, ElemType e) {
	Lnode* s;
	p = L;
	j = 0;
	while (p && j<i-1){
		p = p->next;
		j++;//寻找第i-1个结点,p指向i-1结点
	}
	if (!p || j > i - 1)//i大于表长+1或小于1
		return ERROR;//插入位置非法
	s = new Lnode;//生成新结点s
	s->data = e;//将结点s的数据域置为e
	s->next = p->next;//将结点s插入L中
	p->next = s;
	return OK;
}

//将链表L中第i个数据元素删除
Status ListDelete_L(LinkList& L, int i, ElemType& e) {
	p = L;
	j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		j++;//寻找第i个结点，并令p指向其前驱
	}
	if (!(p->next) || j > i - 1)
		return ERROR;//删除位置不合理
	tmp = p->next;//临时保存被删结点的地址以备释放
	p->next = tmp->next;//改变删除结点前驱结点的指针域
	e = tmp->data;//保存删除结点的数据域
	delete tmp;//释放删除结点的空间
	return OK;
}

//单链表的建立——头插法
void CreateList_H(LinkList& L, int n) {
	L = new Lnode;
	L->next = NULL;//先建立一个带头头结点的单链表
	for (i = n; i > 0; i--) {
		p = new Lnode;//生成新结点p
		scanf(&p->data);//生成新结点，输入元素值
		//cin >> p->data;
		p->next = L->next;//插入到表头
		L->next = p;
	}
}

//单链表的建立——尾插法
void CreateList_R(LinkList& L, int n) {
	Lnode* r;
	L = new Lnode;
	L->next = NULL;
	r = L;//尾指针r指向头结点
	for (i = 0; i < n; i++) {
		p = new Lnode;
		scanf(&p->data);//生成新结点，输入元素值
		//cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;//r指向新的尾结点
	}
}
