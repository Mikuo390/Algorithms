#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>

//函数结构状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 //溢出

//Status 是函数的类型，其值是函数结构状态代码
typedef int Status;
typedef char ElemType;

int i, j;

#define MAXSIZE 100
typedef struct {
	ElemType* elem;
	int length;
}SqList;

//线性表的初始化(参数引用)
Status InitList_Sq(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//销毁线性表
void DestoryList(SqList& L) {
	if (L.elem)
		delete L.elem;
}

//清空线性表L
void ClearList(SqList& L) {
	L.length = 0;
}

//求线性表L的长度
int GetLength(SqList L) {
	return (L.length);
}

//判断线性表L释放为空
int IsEmpty(SqList L) {
	if (L.length == 0) 
		return 1;
	else 
		return 0;
}

//顺序表的取第i的值
ElemType GetElem(SqList L, int i) {
	if (i<1 || i>L.length)
		return ERROR;
	return L.elem[i - 1];
}

//查找L中e的位序
int LocateElem(SqList L, ElemType e) {
	for (i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;
	return 0;
}

//顺序表的插入
Status LsitInsert_Sq(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	L.length++;
	L.elem[i - 1] = e;
	return OK;
}

//线性表的删除
Status ListDelete_Sq(SqList& L, int i) {
	if (i<1 || i>L.length + 1)
		return ERROR;
	for (j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];
	L.length--;
}



int main() {

}
