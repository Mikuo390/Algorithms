#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define SElemType int

//链栈结点数据结构
typedef struct StackNode
{
	SElemType data;//数据域
	struct StackNode* next;//指针域
}StackNode, * LinkStack;

//**************************基本操作函数***************************//
//初始化
Status InitStack(LinkStack& S) {
	S = NULL;////生成空栈 以单链表表头为栈顶 注意，链栈没有像链表似的头结点
	return 1;
}

//判断是否为空栈
bool StackEmpty(LinkStack S) {
	if (S == NULL)
		return true;
	else
		return false;
}

//判断栈中有多少元素
int StackLength(LinkStack S) {
	LinkStack p;
	p = S;
	int length=0;
	while (p) {
		p = p->next;
		length++;
	}
	return length;
}

//入栈函数 将e压入栈
Status Push(LinkStack& S, SElemType e) {
	StackNode* p;
	p = new StackNode;//生成新结点
	p->data = e;//赋值
	p->next = S;//压入栈顶
	S = p;
	return 1;
}

//出栈函数 栈顶用e返回，注意释放空间
bool Pop(LinkStack& S,SElemType& e) {
	LinkStack p;
	if (S == NULL)
		return false;//栈空
	e = S->data;//返回的值
	p = S;
	S = S->next;
	free(p);//delete
	return true;
}

//取栈顶函数
bool GetTop(LinkStack& S, SElemType& e) {
	if (S == NULL)
		return false;
	e = S->data;
	return true;
}

//**************************功能实现函数***************************//

//菜单
void menu()
{
	printf("********1.入栈          2.出栈*********\n");
	printf("********3.取栈顶元素    4.打印*********\n");
}

//打印栈元素
Status PrintStack(LinkStack S) {
	LinkStack p;
	p = S;
	if (StackLength(S)) {
		cout << "栈长度为" << StackLength(S)<<endl;
		cout << "---" << endl;
		while (p) {
			cout << "|" << p->data << "|" << endl;
			cout << "---" << endl;
			p = p->next;
		}
	}
	else
		cout << "栈为空！！！";
	return 1;
}

//入栈功能函数 调用Push函数
void PushToStack(LinkStack& S) {
	SElemType e;
	int flag;
	int n;
	cout << "请输入入栈元素个数(>=1)：";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个元素的值：";
		cin >> e;
		flag = Push(S, e);
		if (flag)
			cout << e << "已入栈" << endl;
	}
}

//出栈功能函数 调用Pop函数
void PopFromStack(LinkStack& S) {
	SElemType e;
	int flag;
	int n;
	cout << "请输入出栈元素个数(>=1)：";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个元素的值：";
		cin >> e;
		flag = Pop(S, e);
		if(flag)
			cout << e << "已出栈" << endl;
		else {
			cout << "栈已空！！！" << endl;
			break;
		}
	}
}

//取栈顶功能函数 调用GetTop函数
void GetTopOfStack(LinkStack S)
{
	SElemType e; 
	bool flag;
	flag = GetTop(S, e);
	if (flag)
		cout << "栈顶元素为" << e << endl;
	else
		cout << "栈已空！！！" << endl;
}


//主函数
int main()
{
	LinkStack S; int choice;
	InitStack(S);
	while (1)
	{
		menu();
		cout << "请输入菜单序号：";
		scanf("%d", &choice);
		if (choice == 0) break;
		switch (choice)
		{
		case 1:PushToStack(S); break;
		case 2:PopFromStack(S); break;
		case 3:GetTopOfStack(S); break;
		case 4:PrintStack(S); break;
		default:cout << "输入错误！！！" << endl;
		}
	}
	return 0;
}
