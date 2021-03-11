#define _CRT_SECURE_NO_WARNINGS

#include <cstddef>
#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 //溢出

#define MAXSIZE 20//设记录不超过20个

//Status 是函数的类型，其值是函数结构状态代码
typedef int Status;
typedef int KeyType;//设关键字为整型量(int型)
typedef int InfoType;

typedef struct {//定义每个记录（数据元素）的结构
	KeyType key;//关键字
	InfoType otherinfo;//其他数据项
}RedType;//Record Type

typedef struct {//定义顺序表的结构
	RedType r[MAXSIZE + 1];//存储顺序表的向量
			//r[0]一般作哨兵或缓冲区
	int length;//顺序表的长度
}SqList;


//堆调整
void HeapAdjust(elem R[], int s, int m) {
	//已知R[s..m]中记录的关键字除R[s]之外均满足堆的定义
	//本函数调整R[s]的关键字，使R[s..m]成为一个打根堆
	rc = R[s];
	for (j = 2 * s; j <= m; j * 2) {//沿key较大的孩子结点向下筛选
		if (j < m && R[j] < R[j + 1])
			j++;//j为key较大的记录的下标
		if (rc >= R[j])
			break;
		R[s] = R[j];
		s = j;//rc应插入在位置s上
	}
	R[s] = rc;//插入
}

////建立小根堆
//for (int i = n / 2; i >= i; i--)
//	HeapAdjust(R, i, n);

//堆排序
void HeapSort(elem R[]) {
	int i;
	for (i = n / 2; i >= i; i--)
		HeapAdjust(R, i, n);//建立初始堆
	for (i = n; i > 1; i--) {//进行n-1趟排序
		Swap(R[1], R[i]);//根与最后一个元素交换
		HeapAdjust(R, 1, i - 1);//对R[1]到R[i-1]重新建堆
	}
}
