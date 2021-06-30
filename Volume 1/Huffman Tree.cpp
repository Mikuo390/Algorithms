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

#define MAX_TREE_SIZE 100

typedef int Status;
typedef char TElemType;

typedef struct {
	int weight;
	int parent, lch, rch;
}HTNode,*HuffmanTree;

//构造哈夫曼树
void CreatHuffmanTree(HuffmanTree HT, int n) {
	if (n <= 1)
		return;
	int m = 2 * n - 1;//数组2n-1个元素
	HT = new HTNode[m + 1];//0号单元未用，HT[m]表示根节点
	for (int i = 1; i <= m; i++) {//将2n-1个元素的lch,rch,parent置为0
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> HT[i].weight;//输入前n个元素的weight值

	//初始化结束，开始建议哈夫曼树

	for (int i = n + 1; i <= m; i++) {//合并产生n-1个结点——构造Huffman树
		Select(HT, i - 1, s1, s2);
		//在HT[k](1＜=k<=i-1)中选择两个其双亲域为0
		//且权值最小的结点，并返回他们在HT中的序号s1和s2
		HT[s1].parent = i;
		HT[s2].parent = i;//从F中删除s1,s2
		HT[i].lch = s1;
		HT[i].rch = s2;//s1,s2分别作为i的左右孩子
		HT[i].weight = HT[s1].weightHT[s2].weight;//i的权值为左右孩子权值之和
	}
}

//编码
void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n) {
	int i;
	//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
	HC = new char* [n + 1];//分配n个字符编码的头指针矢量
	cd = new char[n];//分配临时存放编码的动态数组空间
	cd[n - 1] = '\0';//编码结束符
	for (int i = 1; i <= n; i++) {//逐个字符求哈夫曼编码
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (f != 0) {
			start--;//回溯一次start向前指一个位置
			if (HT[f].lchild == c)
				cd[start] = '0';//结点c是f的左孩子，则生成代码0
			else
				cd[start] = '1';//结点c是f的右孩子，则生成代码1
		}//将求出第i个字符的编码
		HC[i] = new char[n - start];//为第i个字符串编码分配工具
		strcpy(HC[i], &cd[start]);
		//将求得的编码从临时空间cd赋值到HC的当前行中
	}
	delete cd;//释放临时空间
}
