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

//查找
int Search_Seq0(SSTable ST, KeyType key) {
	//成功返回其位置信息，否则返回0
	for (int i = ST.length; i >= 1; i--)
		if (ST.R[i].key == key)
			return i;
	return 0;
}//Search_Seq();

//其他形式
int Search_Seq1(SSTable ST, KeyType key) {
	int i;
	for (i = ST.length; ST.R[i].key != key; i--)
		if (i<=0)
			break;
	if (i > 0)
		return i;
	else
		return 0;
}//Search_Seq();
//其他形式
int Search_Seq2(SSTable ST, KeyType key) {
	int i;
	for (i = ST.length; ST.R[i].key != key && i > 0; i--)
	if (i > 0)
		return i;
	else
		return 0;
}//Search_Seq();
//算法改进——把查找的数存入数组0
int Search_Seq(SSTable ST, KeyType key) {
	ST.R[0].key = key;
	int i;
	for (i = ST.length; ST.R[i].key != key; i--);
	return i;
}//Search_Seq();

//
