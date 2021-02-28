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

typedef struct {//数据域
	VerTexType vexs[MVNum];//顶点表
	ArcType arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;//图的当前点数和边数
}AMGraph;//Adjacency Matrix Graph

//查找顶点
int LocateVex(AMGraph G, VerTexType u) {
	//图G中查找顶点u,存在则返回顶点表中的下标
	//否则返回-1
	for (int i = 0; i < G.vexnum; i++)
		if (u == G.vexs[i])
			return i;
	return -1;
}

//创建无向网
Status CreateUDN(AMGraph& G) {

	int v1, v2, w;

	//采用邻接矩阵表示法，创建无向网G
	cin >> G.vexnum >> G.arcnum;//输入总顶点数，总边数
	for (int i = 0; i < G.vexnum; i++)
		cin >> G.vexs;//依次输入点的信息
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = MaxInt;//边的权值均置为极大值

	//构造邻接矩阵
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2 >> w;//输入一条边所依附的顶点及边的权值
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);//确定v1和v2在G中的位置
		G.arcs[i][j] = w;//边<v1,v2>权值置为w
	}
	return OK;
}
