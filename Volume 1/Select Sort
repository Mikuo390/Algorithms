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

void SelectSort(SqList& L) {
	int i, j, k;
	
	for (i = 1; i < L.length; i++) {
		k = i;
		for (j = i + 1; j <= L.length; j++)
			if (L.r[j].key < L.r[k].key)
				k = j;//记录最小值位置
		if (k != i) {
			RedType tmp = L.r[k];
			L.r[k] = L.r[i];
			L.r[i] = tmp;
		}		

	}
}
