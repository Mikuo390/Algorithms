#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

#define OK 1

#define Status int
#define ElemType int

//单链表结点数据结构

typedef struct LNode {
	ElemType data;//数据域
	struct LNode* next;//指针域
}LNode,*LinkList;

//**************************基本操作函数***************************//
//初始化函数
Status InitList(LinkList& L) {
	L = new LNode;////生成头结点 这样删除等操作就不必分第一个结点和其他了
	L->next = NULL;
	return OK;
}

//获取单链表的长度
int ListLength(LinkList L) {
	LinkList p = L;
	int length = 0;
	
	while (p){
		length++;
		p = p->next;
	}
	return length - 1;//去除头结点
}

//插入函数——后插法 插入到第i(1<=i<=length+1)个位置 即i-1之后 不必区分i的位置
bool InsertList(LinkList& L, int i, ElemType e) {

	LinkList s;//插入节点
	LinkList p = L;
	int j = 0;

	while (p && (j < i - 1)) {//j指到i-1位置或者p已经到最后时跳出
		p = p->next;
		j++;
	}

	if (!p || j > i - 1) {
		cout << "插入位置无效！！！" << endl;
		return false;
	}

	s = new LNode;//开辟节点空间
	s->data = e;
	s->next = p->next;//让s节点指向原p节点指向的next域
	p->next = s;
	return true;
}

//删除函数 删除位置i的结点 即删除i-1之后的结点
bool DeleteList(LinkList& L, int i) {
	LinkList p = L;
	int j = 0;
	LinkList q;

	while (p && (j < i - 1)) {//j指到i-1位置
		p = p->next;
		j++;
	}

	if (p == nullptr || !(p->next) || j > i) {
		cout << "删除位置无效！！！" << endl;
		return false;
	}

	q = p->next;
	p->next = q->next;
	free(q);//释放空间
	return true;
}

//查找函数 按值查找 查找第一个等于e的结点 成功返回结点指针，否则返回NULL
LNode* LocateElem(LinkList L, ElemType e) {
	LinkList p = L;
	while (p && (p->data != e))
		p = p->next;
	return p;
}


//**************************功能实现函数**************************//
//遍历输出函数
void PrintList(LinkList L) {
	LinkList p = L->next;//跳过头结点
	if (ListLength(L)) {
		cout << "当前单链表所有元素:";
		while (p)
		{
			cout << p->data;
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "当前单链表已空！" << endl;	
}

//插入功能函数 调用InsertList后插
void Insert(LinkList& L) {
	int place;
	ElemType e;
	bool flag;
	cout << "请输入要插入的位置(从1开始)及元素:" << endl;
	cin >> place >> e;
	flag = InsertList(L, place, e);
	if (flag) {
		cout << "插入成功！！！" << endl;
		PrintList(L);
	}
}

//删除功能函数 调用DeleteList删除
void Delete(LinkList L) {
	int place;
	bool flag;
	cout << "请输入要删除的位置(从1开始):" << endl;
	cin >> place;
	flag = DeleteList(L,place);
	if (flag) {
		cout << "删除成功！！！" << endl;
		PrintList(L);
	}
}

//查找功能函数 调用LocateElem查找
void Search(LinkList L) {
	ElemType e;
	LNode* q;
	cout << "请输入要查找的值:" << endl;
	cin >> e;
	q = LocateElem(L, e);
	if (q)
		cout << "找到该元素！" << endl;
	else
		cout << "未找到该元素！" << endl;
}


//菜单
void menu()
{
	printf("********1.后插    2.删除*********\n");
	printf("********3.查找    4.输出*********\n");
	printf("********5.退出          *********\n");
}

//主函数
int main()
{
	LinkList L; int choice;
	InitList(L);
	while (1)
	{
		menu();
		printf("请输入菜单序号：\n");
		scanf("%d", &choice);

		if (choice == 5) break;
		switch (choice)
		{
		case 1:Insert(L); break;
		case 2:Delete(L); break;
		case 3:Search(L); break;
		case 4:PrintList(L); break;
		default:printf("输入错误！！！\n");
		}
	}
	return 0;
}
