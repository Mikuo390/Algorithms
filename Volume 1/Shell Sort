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

//希尔排序
void ShellInsert(SqList& L, int dk) {
	//对顺序表L进行一趟增量为dk的Shell排序，dk为步长因子
	int i, j;
	for (i = dk + 1; i <= L.length; i++)
		if (L.r[i].key < L.r[i - dk].key) {
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && (L.r[0].key < L.r[j].key); j = j - dk)
				L.r[j + dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}//if (L.r[i].key < L.r[i - dk].key)
}//ShellInsert();

void ShellSort(SqList& L, int dlta[], int t) {
	//按照增量序列dlta[0..t-1]对顺序表L作希尔排序
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(L, dlta[k]);//一趟增量为dlta[k]的插入排序
}//ShellSort
