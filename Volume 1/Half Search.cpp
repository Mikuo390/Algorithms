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

//Status 是函数的类型，其值是函数结构状态代码
typedef int Status;
//typedef char ElemType;
typedef char KeyType;

typedef struct {
	KeyType key;//关键字域
	//其他域
}ElemType;

typedef struct {//顺序表结构类型定义
	ElemType* R;//表基址
	int length;//表长
}SSTable;//Sequential Search Table
SSTable ST;//定义顺序表ST

//折半查找——非递归
int Search_Bin(SSTable ST, KeyType key) {
	int mid;
	int low = 1;
	int high = ST.length;

	while (low <= high) {
		mid = (low + high) / 2;
		if (ST.R[mid].key == key)
			return mid;//找到待查找的元素
		else if (key < ST.R[mid].key)//缩小查找区间
			high = mid - 1;//继续在前半区间进行查找
		else
			low = mid + 1;//继续在后半区间进行查找
	}//while(low <= high) 
	return 0;
}//Search_Bin();

//折半查找——递归
int Search_Bin(SSTable ST, KeyType key, int low, int high) {

	if (low > high)
		return 0;//查找不到时返回0
	int mid = (low + high) / 2;

	if (key == ST.R[mid].key)//找到待查找的元素
		return mid;
	else if (key < ST.R[mid].key)//缩小查找区间
		return Search_Bin(ST, key, low, mid - 1);//递归继续在前半区间进行查找
	else
		return Search_Bin(ST, key, mid + 1, high);//递归继续在后半区间进行查找

	return 0;
}//Search_Bin();
