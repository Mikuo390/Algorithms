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
typedef char QElemType;

typedef struct {
	QElemType data;//初始化的动态分配存储空间
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;//头指针
	QueuePtr rear;//尾指针
}LinkQueue;

//链队列初始化
Status InitQueue(LinkQueue& Q) {
	//Q.front = Q.rear = new QNode[MAXSIZE];//分配空间
	Q.front = Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);//存储分配失败
	Q.front->next = NULL;
	return OK;
}

//链队列的销毁
Status DestroyQueue(LinkQueue& Q) {
	QNode *p;
	while (Q.front){
		//p = Q.front->next;
		//free(Q.front);
		//Q.front = p;

		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

//链队列的操作——将元素e入队
Status EnQueue(LinkQueue& Q, QElemType e) {

	QNode* p=(QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

//链队列出列
Status DeQueue(LinkQueue& Q, QElemType& e) {
	QNode* p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	return OK;
}

//求链队列的队头元素
Status GetHead(LinkQueue Q, QElemtype& e) {
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.front->next->data;
	return OK;
}
