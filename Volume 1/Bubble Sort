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

void bubble_sort(SqList& L) {
	int m, i, j;
	RedType x;//交换临时存储

	for (i = 0; i <= L.length - 1; i++) {//总共i趟
		for (j = 1; j <= L.length - i; j++) {
			//这里L.length-1-i是因为下标0用作哨兵了

			if (L.r[j].key > L.r[j + 1].key) {//发生逆序
				x = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = x;
			}//if (L.r[j].key > L.r[j + 1].key)

		}//for (j = 1; j <= L.length - 1 - i; j++)

	}//for (i = 0; i <= L.length - 1; i++)

}//bubble_sort();

//改进版
void bubble_sort(SqList& L) {
	int flag, i, j;
	RedType x;//交换临时存储

	for (i = 0; i <= L.length - 1; i++) {//总共i趟
		flag = 0;
		for (j = 1; j <= i; j++) {

			if (L.r[j].key > L.r[j + 1].key) {//发生逆序
				flag = 1;//发生交换，flag置为1，若没有发生交换，flag=0
				x = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = x;
			}//if (L.r[j].key > L.r[j + 1].key)

		}//for (j = 1; j <= L.length - 1 - i; j++)

	}//for (i = 0; i <= L.length - 1; i++)

}//bubble_sort();
