#define _CRT_SECURE_NO_WARNINGS

/*
CreateList(SqList& L, int n) 参数：顺序表L，顺序表长度n 功能：创建长度为的顺序表 时间复杂度：O(n)
InitList(SqList& L) 参数：顺序表L 功能：初始化 时间复杂度 : O(1)
InsertList(SqList& L, int i, ElemType e) 参数 : 顺序表L, 位置i, 元素e 功能：位置i处插入元素e 时间复杂度 : O(n)
ListDelete(SqList& L, int i) 参数 : 顺序表L, 位置i 功能：删除位置i处元素 时间复杂度 : O(n)
LocateElem(SqList L, ElemType e) 参数 : 顺序表L, 元素e 功能：返回第一个等于e的元素的位置 时间复杂度 : O(n)
Reverse(SqList& L) 参数：顺序表L 倒置函数 将原顺序表直接倒置
PrintList(SqList L) 参数 : 顺序表L 功能：遍历L，并输出
SplitSort(SqList& L) 参数：顺序表L 功能：分开奇偶，并分开排序
ClearList(SqList& L) 参数：顺序表L 功能：清空顺序表
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 //溢出

#define MaxSize 100
#define ElemType int
#define Status int
using namespace std;

//顺序表数据结构

typedef struct {
	ElemType *data;//顺序表元素
	//ElemType data[MaxSize];
	int length;//表示顺序表当前长度
}SqList;


//***************************基本操作函数*******************************//

//初始化顺序表函数，构造一个空的顺序表
Status InitList(SqList& L) {
	L.data = new ElemType[MaxSize];//初始话说数据为0
	L.length = 0;//初始化长度为0
	return 0;
}

//创建顺序表函数
bool CreateList(SqList& L, int n)
{
	if (n<0 || n>MaxSize)false;//n非法
	for (int i = 0; i < n; i++)
	{
		cin >> L.data[i];
		L.length++;
	}
	return true;
}

//清空顺序表
void ClearList(SqList& L) {
	L.length = 0;//长度设置为0
}

//销毁线性表
void DestroyList(SqList& L) {
	if (L.data)
		delete L.data;//释放存储空间
}

//求线性表的长度
int GetLength(SqList L) {
	return L.length;
}

//判断线性表L是否为空
bool isEmpty(SqList L) {
	if (L.length == 0)
		return true;
	else
		return false;
}

//查找函数按位置从小到大查找第一个值等于e的元素 并返回位置
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e)
			return i + 1;
	}//for
	return 0;
}

//取值函数（根据位置i获取相应位置数据元素的内容）
int GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.data[i - 1];
	return OK;
}

//倒置函数 将顺序表直接倒置
void ReverseList(SqList& L) {
	if(L.length)
		for (int i = 0; i < L.length - 1 - i; i++)
		{
			int tmp = L.data[i];
			L.data[i] = L.data[L.length - 1 - i];
			L.data[L.length - 1 - i] = tmp;
		}
}

//插入
bool InsertList(SqList& L, int i, ElemType e) {

	int j;

	if (i<1 || i>L.length + 1) {
		cout << "存储位置无效" << endl;
		return false;
	}
		
	if (L.length == MaxSize) {
		cout << "当前存储空间已满" << endl;
		return false;
	}
		

	for (j = L.length - 1; j >= i - 1; j--)
		L.data[j + 1] = L.data[j];//元素后移
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//删除
bool DeleteList(SqList& L, int i) {

	int j;

	if (L.length == 0)
		return false;

	if (i<1 || i>L.length + 1)
		return false;

	for (j = i; j <= L.length - 1; j++)
		L.data[j - 1] = L.data[j];//前移动
	L.length--;
	return true;
}

//********************************功能函数*****************************************//

//输出功能函数 按位置从小到大输出顺序表所有元素
void PrintList(SqList L) {
	cout << "当前顺序表所有元素：";
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
}

//创建顺序表函数
void Create(SqList& L) {
	int n;
	bool flag;
	L.length = 0;
	cout << "请输入要创建的顺序表长度(>1):";
	cin >> n;
	cout << "请输入" << n << "个数（空格隔开）:";
	flag = CreateList(L, n);

	if (flag) {
		cout << "创建成功！" << endl;
		PrintList(L);
	}
	else
		cout << "插入成功！" << endl;
}

//插入功能函数 调用InsertList完成顺序表元素插入 调用PrintList函数显示插入成功后的结果
void Insert(SqList& L) {
	int place;
	ElemType e;
	bool flag;
	cout << "请输入要插入的位置(从1开始)及元素:" << endl;
	cin >> place >> e;
	flag = InsertList(L, place, e);
	if (flag) {
		cout << "插入成功！！！" << endl;
		PrintList(L);
	}
}

//删除功能函数 调用ListDelete函数完成顺序表的删除 调用PrintList函数显示插入成功后的结果
void Delete(SqList& L) {
	int place;
	bool flag;
	cout << "请输入要删除的位置(从1开始):" << endl;
	cin >> place;
	flag = DeleteList(L, place);
	if (flag) {
		cout << "删除成功！！！" << endl;
		PrintList(L);
	}
}


//查找功能函数 调用LocateElem查找元素
void Search(SqList L) {
	ElemType e;
	int flag;
	cout << "请输入要查找的值:" << endl;
	cin >> e;
	flag = LocateElem(L, e);
	if (flag) {
		cout << "该元素位置为：" << flag << endl;
	}
	else
		cout << "未找到该元素！" << endl;
}

void Length(SqList L) {

	int len = GetLength(L);

	cout << "顺序表的长度：" << len << endl;
}

//菜单
void menu()
{
	printf("\n");
	printf("********1.创建                        2.插入*********\n");
	printf("********3.删除                        4.查找*********\n");
	printf("********5.倒置                        6.长度*********\n");
	printf("********7.输出                        8.清空*********\n");
	printf("********9.退出                        0.退出*********\n");
	printf("\n");
}

int main() {
	SqList L;
	int choice;
	InitList(L);

	while (1) {
		menu();
		cout << "请输入菜单序号:" ;
		cin >> choice;
		if (choice == 9) break;

		switch (choice)
		{
		case 1:Create(L); break;
		case 2:Insert(L); break;
		case 3:Delete(L); break;
		case 4:Search(L); break;
		case 5:ReverseList(L); break;
		case 6:Length(L); break;
		case 7:PrintList(L); break;
		case 8:ClearList(L); break;
		default:printf("输入错误！！！\n");
		}
	}
}
