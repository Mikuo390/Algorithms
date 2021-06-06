#define _CRT_SECURE_NO_WARNINGS

#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 //溢出
#define ENDFLAG -3

//Status 是函数的类型，其值是函数结构状态代码
typedef int Status;
typedef char InfoType;
typedef char KeyType;

typedef struct {
	KeyType key;//关键字项
	InfoType otherinfo;//其他数据域
}ElemType;

typedef struct BSTNode {
	ElemType data;//数据域
	struct BSTNode* lchild, * rchild;//左右孩子指针
}BSTNode,*BSTree;

BSTree T;//定义二叉排序树T

//查找
BSTree SearchBST(BSTree T, KeyType key) {
	if ((!T) || key == T->data.key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key);//在左子树中继续查找
	else
		return SearchBST(T->rchild, key);//在右子树中继续查找
}//SearchBST();

//插入
void InsertBST(BSTree& T, ElemType e) {
	//当二叉排序树T中不存在关键字等于e,key的数据元素时，插入该元素
	if (!T) {//找到插入位置 ， 递归结束
		BSTree S = new BSTNode;//生成新结点*S
		S->data = e;//／新结点*S的数据域置为e
		S->lchild = S->rchild = NULL; //新结点* S作为叶子结点
		T = S;//把新结点*S链接到已找到的插入位置
	}//if(!T)
	else if (e.key < T->data.key)
		InsertBST(T->lchild, e);//将*S插入左子树
	else if (e.key < T->data.key)
		InsertBST(T->rchild, e);//将*S插入右子树
}//InsertBST();

//生成
void CreateBST(BSTree& T) {
	//依次读入一个关键字为key的结点，将此节点插入二叉排序树T中
	ElemType e;
	T = NULL;
	cin >> e.key;
	while (e.key != ENDFLAG) {
		InsertBST(T, e);
		cin >> e.key;
	}
}//CreateBST();

//删除
void DeleteBST(BSTree& T, KeyType key) {
	//从二叉排序树T中删除关键字等于key的结点
	BSTree p,f,q,s;
	p = T;
	f = NULL;

	/* while循环从根开始查找关键字等于key的结点 */
	while (p)
	{
		if (p->data.key == key)
			break;//找到关键字等于 key 的结点*p, 结束循环
		f = p;///*f 为*p 的双亲结点
		if (p->data.key > key)
			p = p->lchild;//在*p 的左子树中继续查找
		else
			p = p->rchild;//在*p 的右子树中继续查找
	}//while (p)

	/* 考虑3种情况实现p 所指子树内部的处理： *p 左右子树均不空、 无右子树、 无左子树 */
	if ((p->lchild) && (p->rchild)) {//被删结点*p 左右子树均不空

		q = p; s = p->lchild;

		while (s->rchild) {//在*p 的左子树中继续查找其前驱结点，即最右下结点
			q = s;
			s = s->rchild;//／向右到尽头
		}//while()
		p->data = s->data;///s 指向被删结点的 “前驱＂
		if (q != p)
			p->rchild = s->lchild;//重接*q 的右子树
		else q->lchild = s->lchild;//重接*q 的左子树
		delete s;
		return;
	}//if()

	else if (!p->rchild) {//／被删结点*p 无右子树， 只需重接其左子树
		q = p;
		p = p -> lchild;
	}//else if

	else if (!p->lchild) {//／被删结点*p 无左子树， 只需重接其右子树
		q = p;
		p = p->rchild;
	}//else if

	/*－将 p 所指的子树挂接到其双亲结点*f 相应的位置*/
	if (!f)
		T = p;//被删结点为根结点
	else if (q == f->lchild)
		f->lchild = p;//挂接到*f 的左子树位置
	else
		f->rchild = p;//挂接到*f 的右子树位置
	delete q;
}//CreateBST();
