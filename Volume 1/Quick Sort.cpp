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

int Partition(SqList& L, int low, int high) {
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while (low < high) {
		while (low < high && L.r[high].key >= pivotkey)
			high--;
		while (low < high && L.r[low].key <= pivotkey)
			L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void QSort(SqList& L, int low, int high) {//对顺序表L快速排序
	if (low < high) {//长度大于1
		int pivotloc = Partition(L, low, high);
		//将L.r[low..high]一分为二，pivotloc为枢轴元素排好序的位置
		QSort(L, low, pivotloc - 1);//对低子表递归排序
		QSort(L, pivotloc + 1, high);//对高子表递归排序
	}
}


//void main() {
//	QSort(L, 1, L.length);
//}
