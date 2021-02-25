#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#include <cstddef>
#include <iostream>

//函数结构状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2 //溢出

#define MAXSIZE 100

typedef int Status;
typedef char TElemType;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;//左右孩子指针
}BiTNode, * BiTree;

typedef struct {
	BiTNode data[MAXSIZE];//存放队中元素
	int front, rear;//队头和队尾指针
}SqQueue;//顺序循环队列类型


void LevelOrder(BiTNode* b) {
	BiTNode* p;
	SqQueue* qu;
	InitQueue(qu);//初始化队列
	enQueue(qu, b);//根结点指针进入队列
	while (!QueueEmpty(qu)) {//队不为空，则循环
		deQueue(qu, p);//出队结点p
		cout << p->data;//访问结点p
		//printf("%c", p->data);
		if (p->lchild != NULL)//有左孩子进队
			enQueue(qu, p->lchild);
		if (p->rchild != NULL)//有右孩子进队
			enQueue(qu, p->rchild);
	}
}

//建立二叉树
Status CreateBiTree(BiTree& T) {
	scanf(&ch);//cin>>ch;
	if (ch == "#")
		T = NULL;
	else {
		if (!(T = new BiTNode))
			exit(OVERFLOW);
		T->data = ch;//生成根结点
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}
	return OK;
}

//复制二叉树
int Copy(BiTree T, BiTree& NewT) {
	if (T == NULL) {
		NewT = NULL;
		return 0;
	}
	else{
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}

//计算深度
int Depth(BiTree T) {
	if (T == NULL)
		return 0;
	else{
		int l = Depth(T->lchild);
		int r = Depth(T->rchild);
		if (l > r)
			return (l + 1);
		else
			return (r + 1);
	}
}

//计算结点总数
int NodeCount(BiTree T) {
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

//计算叶子结点数
int LeafCount(BiTree T) {
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeafCount(T->lchild) + LeafCount(T->rchild);
}
