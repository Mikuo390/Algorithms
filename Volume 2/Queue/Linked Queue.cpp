#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define QElemType int

//链队结点数据结构
typedef struct QNode {
	QElemType data;//数据域
	struct QNode* next;//指针域
}QNode,*QueuePtr;
typedef struct {
	struct QNode* front, * rear;//rear指针指向队尾 用于入队 front指针指向队头 用于出队
}LinkQueue;

//**************************基本操作函数***************************//
//初始化
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;//生成新结点，队头队尾指针均指向它
	Q.front->next = NULL;
	return 1;
}

//入队函数
Status EnQueue(LinkQueue& Q, QElemType e) {
	QNode* p;
	p = new QNode;//新结点
	p->data = e;//赋值
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 1;
}

//出队函数
bool DeQueue(LinkQueue& Q, QElemType& e) {
	QueuePtr p;
	if (Q.front == Q.rear)
		return false;//队空
	e = Q.front->next->data; //e返回值 之前写的Q.front->data 炸了，头结点没数据的，一定要注意头结点
	//p=Q.front->next;
	//e=p->data;
	p = Q.front->next;//保留，一会儿释放空间
	Q.front->next = p->next;//出队,注意Q.front->next 不是Q.front 还有头结点
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}

//取队顶函数，用e返回
bool GetHead(LinkQueue& Q, QElemType& e) {
	if (Q.front == Q.rear)
		return false;//队列
	e = Q.front->next->data;
	return true;
}

//**************************功能实现函数***************************//
//菜单
void menu() {
	cout << "********1.入队          2.出队*********" << endl;
	cout << "********3.取队顶元素    4.退出*********" << endl;
}

//入队功能函数
void EnterToQueue(LinkQueue& Q) {
	int n;
	QElemType e;
	int flag;
	cout << "请输入入队元素个数(n>=1)";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个元素的值:";
		cin >> e;
		flag = EnQueue(Q, e);
		if (flag)
			cout << e << "已入队!" << endl;
	}
}

//出队功能函数
void DeleteFromQueue(LinkQueue& Q) {
	int n;
	QElemType e;
	int flag;
	cout << "请输入出队元素个数(n>=1)";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个元素的值:";
		cin >> e;
		flag = EnQueue(Q, e);
		if (flag)
			cout << e << "已出队!" << endl;
	}
}

//取队项功能
void GetHeadOfStack(LinkQueue Q) {
	QElemType e;
	bool flag;
	flag = GetHead(Q, e);
	if (flag)
		cout << "队头元素为:" << e << endl;
	else
		cout << "队已空！！<<endl";
}

//主函数
int main()
{
	LinkQueue Q; int choice;
	InitQueue(Q);
	while (1)
	{
		menu();
		cout << "请输入菜单序号:";
		scanf("%d", &choice);
		if (4 == choice) break;
		switch (choice)
		{
		case 1:EnterToQueue(Q); break;
		case 2:DeleteFromQueue(Q); break;
		case 3:GetHeadOfStack(Q); break;
		default:cout << "输入错误！！！" << endl;
		}
	}
	return 0;
}
