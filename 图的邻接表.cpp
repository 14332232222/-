#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#define MaxVn 30
using namespace std;
int visit[MaxVn];
int arc[MaxVn][MaxVn];
//顶点
typedef struct VNode {
	int vnext;				//邻接结点，该顶点对应的下标
	int weight;			//权值
	struct VNode* next;	//链域指向下一个结点
} VNode;
//顶点表结点
typedef struct VlistNode {
	char data;		//存储 顶点的数据
	VNode* fv;		//边表头指针
} VlistNode,list[MaxVn];
//邻接表
typedef struct GMap {
	list adli;		//邻接表
	int verNum, arcNum;		//当前定点数、边数
} Gmlist;
//创建邻接表
void Creat_GM(Gmlist* G) {
	printf("有向图1或无向图0:");
	int flag = 0;
	cin>>flag;
	for (int i = 0; i < MaxVn; i++) {
		G->adli[i].fv = NULL;
	}
	printf("输入顶点、边个数（空格间隔）:");
	cin>>G->verNum>>G->arcNum;
	for (int i = 0; i < G->verNum; i++) {
		printf("请输入第%d个顶点的元素：", i + 1);
		fflush(stdin);
		cin>>G->adli[i].data;
		G->adli[i].fv = NULL;
	}
	int vi, vj;
	int weight;//权
	for (int i = 0; i < G->arcNum; i++) {
		printf("请输入第一个顶点,第二个顶点,边的权值（空格间隔,其中第一第二按照输入顺序排序）:");
		cin>>vi>> vj>>weight;
		arc[vi-1][vj-1] = 1;
		VNode* newNode;
		newNode = (VNode*)malloc(sizeof(VNode));
		newNode->next = G->adli[vi - 1].fv;
		newNode->vnext = vj;
		newNode->weight = weight;
		G->adli[vi - 1].fv = newNode;
		if (flag==0) {
			VNode* newNode2;
			newNode2 = (VNode*)malloc(sizeof(VNode));
			newNode2->next = G->adli[vj - 1].fv;
			newNode2->vnext = vi;
			newNode2->weight = weight;
			G->adli[vj - 1].fv = newNode2;
		}
	}
}
//打印邻接表
void Print(Gmlist* G) {
	printf("顶点：\n");
	for (int i = 0; i < G->verNum; i++) {

		printf("%d\t%c\t->\t", i+1, G->adli[i].data);
		VNode* p = G->adli[i].fv;
		while (p!=NULL) {
			printf("(%d,%d)->\t", p->vnext,p->weight);
			p = p->next;
		}
		if (p==NULL) {
			printf("NULL");
		}
		printf("\n\n");
	}
}
//深度优先遍历 即从一个顶点开始尽可能深遍历
void DFS(Gmlist *G,int v) {
	//当前节点被访问过的标志
	visit[v] = 1;
	//访问当前节点
	printf("%c->\t",G->adli[v].data);
	//对顶点在边表中该行的所有边关系进行遍历，如果==1表示是邻接点，并且还要判断当前顶点是否被访问过
	for (int i = 0; i!=G->verNum; i++) {
		if (arc[v][i] == 1 && visit[i]==0) {
			DFS(G,i); //如果满足条件，就从该顶点开始再次进行DFS操作
		}
	}
}
void DFS_m(Gmlist *G) {
	//遍历所有顶点
	for (int i = 0; i!=G->verNum; ++i) {
		//这里我们决定把顶点数组中第一个元素当做遍历起点
		if (visit[i] == 0) { //如果当前顶点处于未被访问的状态，就对该顶点进行DFS操作
			DFS(G,i);
		}
	}
	printf("^^\n");
}
//广度优先遍历 从一个顶点开始尽可能广的遍历
void BFS(Gmlist *G,int v) {
	//标记
	visit[v]=1;
	printf("%c->\t",G->adli[v].data);
	for(int i=0;i!=G->verNum;++i){
		if(arc[v][i]==1&&visit[i]==0){
			visit[i]=1;
			printf("%c->\t",G->adli[i].data);
		}
	}
}
void BFS_m(Gmlist *G) {
	for(int i=0; i!=G->verNum; ++i) {
		if(visit[i]==0) {
			BFS(G,i);
		}
	}
	printf("^^\n");
}
int main() {
	Gmlist *G;
	G = (Gmlist*)malloc(sizeof(Gmlist));
	Creat_GM(G);
	Print(G);
	printf("DFS:");
	DFS_m(G);
	memset(visit,0,sizeof(visit));
	printf("BFS:");
	BFS_m(G);
	return 0;
}

