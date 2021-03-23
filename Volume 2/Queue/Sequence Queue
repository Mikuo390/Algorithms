#define _CRT_SECURE_NO_WARNINGS


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define QElemType int
#define MaxQSize 100

//循环队列数据结构
typedef struct {
	QElemType data[MaxQSize];//数据域
	int front, rear;
}SqQueue;

//***************************基本操作函数**************************//

//初始化
Status InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	return 1;
}

//判断队空函数
bool QueueEmpty(SqQueue Q) {
	if (Q.front != Q.rear)
		return false;
	else
		return true;
}

//入队函数
bool EnQueue(SqQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MaxQSize == Q.front)
		return false;//队列满 牺牲一个格子以判断
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxQSize;//指针加1取模
	return true;
}

//出队
bool DeQueue(SqQueue& Q, QElemType e) {
	if (Q.front == Q.rear)
		return false;
	
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxQSize;
	return true;
}

//取队头
bool GetHead(SqQueue& Q, QElemType& e) {
	if ((Q.rear + 1) % MaxQSize == Q.front)
		return false;//队列满 牺牲一个以判断
	e = Q.data[Q.front];
	return true;
}

//求队列长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MaxQSize) % MaxQSize;
}

//**************************功能实现函数****************************//
//入队功能函数
void EnterToQueue(SqQueue& Q) {
	int n;
	QElemType e;
	int flag;
	cout << "请输入入队元素个数(n>=1):";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个元素的值:";
		cin >> e;
		flag = EnQueue(Q, e);
		if (flag)
			cout << e << "已入队" << endl;
		else {
			cout << "队已满！！！" << endl;
			break;
		}
	}
}
//出队函数
void DeleteFromQueue(SqQueue& Q) {
	int n;
	QElemType e;
	int flag;
	cout << "请输入出队元素个数(n>=1):";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个元素的值:";
		cin >> e;
		flag = DeQueue(Q, e);
		if (flag)
			cout << e << "已入队" << endl;
		else {
			cout << "队已空！！！" << endl;
			break;
		}
	}
}

//获取队头元素，调用
void GetHeadOfQueue(SqQueue Q) {
	QElemType e;
	bool flag;
	flag = GetHead(Q, e);
	if (flag)
		cout << "队头元素为:" << e << endl;
	else
		cout << "队已空！！！" << endl;
}

//获取队长
void GetLengthOfQueue(SqQueue Q) {
	if (QueueLength(Q))
		cout << "顺序队长为:" << QueueLength(Q) << endl;
	else if(QueueLength(Q)==0)
		cout << "顺序队为空队，长度为0！！！"<< endl;
	else
		cout << "未知错误" << endl;
}

//菜单
void menu() {
	cout << "********1.入队         2.出队  *********" << endl;
	cout << "********3.取队头元素   4.取队长*********" << endl;
}

int main() {
	SqQueue Q;
	int choice;
	InitQueue(Q);
	while (1){
		menu();
		cout << "请输入菜单序号:";
		cin >> choice;
		if (choice == 0)
			break;
		switch (choice)
		{
		case 1:EnterToQueue(Q); break;
		case 2:DeleteFromQueue(Q); break;
		case 3:GetHeadOfQueue(Q); break;
		case 4:GetLengthOfQueue(Q); break;
		default:cout << "输入错误！！！" << endl;break;
		}
	}
	return 0;
}
