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

//直接插入排序
void InsertSort(SqList& L) {
	int i, j;
	for (i = 2; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - 1].key) {//若"<"，需将L.r[i]插入有序子表
			L.r[0] = L.r[i];//赋值为哨兵
			for (j = i - 1; L.r[0].key < L.r[j].key; j--) {
				L.r[j + 1] = L.r[j];//记录后移
			}
			L.r[j + 1] = L.r[0];//插入到正确位置
		}
	}
}
