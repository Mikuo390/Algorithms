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

typedef struct {
	SElemType* base;//初始化的动态分配存储空间
	int front;//头指针
	int rear;//尾指针
}SqQueue;

//队列初始化
Status InitQueue(SqQueue& Q) {
	Q.base = new SElemType[MAXSIZE];//分配空间
	if (!Q.base)
		exit(OVERFLOW);//存储分配失败
	Q.front = Q.rear = 0;
	return OK;
}

//求队列的长度
int QueueLength(SqQueue Q) {
	return ((Q.rear - Q.front + MAXSIZE) % MAXSIZE);
}

//循环队列入队
Status EnQueue(SqQueue& Q, SElemType e) {
	if ((Q.rear + 1) * MAXSIZE == Q.front)
		return ERROR;//队满
	Q.base[Q.rear] = e;//新元素加入队尾
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

//循环队列出队
Status DeQueue(SqQueue& Q, SElemType e) {
	if (Q.rear == Q.front)
		return ERROR;//队空
	e = Q.base[Q.front];//b保存队头元素
	Q.front = (Q.front + 1) % MAXSIZE;//对头指针+1
	return OK;
}

SElemType GetHead(SqQueue Q) {
	if (Q.rear != Q.front)//队列不为空
		return Q.base[Q.front];
		//返回队头指针元素的值，队头指针不变
}

