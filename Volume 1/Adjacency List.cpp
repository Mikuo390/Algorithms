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

#define MaxInt 32767//表示极大值，即无限符号
#define MVNum 100//最大定点数

//Status 是函数的类型，其值是函数结构状态代码
typedef int Status;
typedef int ArcType;//设边的权值类型为整型
typedef char VerTexType;//设顶点的数据类型为字符型
typedef int OtherInfo;

//图的结构定义
typedef struct {
	AdjList vertices;//vertices -- vertex的复数
	int vexnum, arcnum;//图当前的顶点数和弧数
}ALGraph;

//弧(边)的结点结构
typedef struct ArcNode {//边结点
	int adjvex;//该边所指向的顶点的位置
	struct ArcNode* nextrac;//指向下一条边的指针
	OtherInfo info;//和边相关的信息
}ArcNode;

//顶点的结点结构
typedef struct VNode{
	VerTexType data;//顶点信息
	ArcNode* firstarc;//指向第一条依附该顶点的边指针
}VNode,AdjList[MVNum];//AdjList表示邻接表类型
//AdjList v == VNode v[MVNum];


//查找顶点
int LocateVex(ALGraph G, VerTexType u) {
	//图G中查找顶点u,存在则返回顶点表中的下标
	//否则返回-1、
	for (int i = 0; i < G.vexnum; i++)
		if (u == G.vertices[i])
			return i;
	return -1;
}

//创建无向网
Status CreateUDG(ALGraph& G) {

	int v1, v2;

	//采用邻接表表示法，创建无向网G
	cin >> G.vexnum >> G.arcnum;//输入总顶点数，总边数
	for (int i = 0; i < G.vexnum; i++) {//输入各点，构造表头结点表
		cin >> G.vertices[i].data;//输入顶点值
		G.vertices[i].firstarc = NULL;//初始化表头结点的指针域
	}

	//构造邻接矩阵
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2;//输入一条边所依附的两个顶点
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);//确定v1和v2在G中的位置

	ArcNode *p1 = new ArcNode;//生成一个新的边结点
	p1->adjvex = j;//邻接点序号为j
	p1->nextrac = G.vertices[i].firstarc;
	G.vertices[i].firstarc = p1;//将新结点*p1插入顶点vi的边表头部

	ArcNode* p2 = new ArcNode;//生成一个新的边结点
	p2->adjvex = i;//邻接点序号为i
	p2->nextrac = G.vertices[j].firstarc;
	G.vertices[j].firstarc = p2;//将新结点*p2插入顶点vj的边表头部

	}
	return OK;
}
