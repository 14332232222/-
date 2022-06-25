
#include<iostream>
#include<stdlib.h>
#define Vs  9//默认 
using namespace std;
//邻接矩阵图结构
typedef struct Map {
	int MaxV; //最大顶点数
	int NumV; //真实的顶点数
	int NumEdges; //边数
	char*V; //顶点列表
	int**Edge; //边信息矩阵
} Map;
//图的初始化
void Init_Map(Map *g) {
	g->MaxV = Vs;//最大顶点数初始化
	g->NumV = g->NumEdges = 0; //实际顶点数初始化
	//分配顶点存储列表的空间
	g->V = (char*)malloc(sizeof(char)*(g->MaxV));//行 
	g->Edge = (int**)malloc(sizeof(int*) * g->MaxV);//列 
	for(int i=0; i<g->MaxV; ++i) { //每一行内具体的空间开辟
		g->Edge[i] = (int*)malloc(sizeof(int) * g->MaxV);
	}
	for(int i=0; i<g->MaxV; ++i) { //初始化
		for(int j=0; j<g->MaxV; ++j) {
			g->Edge[i][j] = 0;
		}
	}
}
//获取顶点的位置
int  Get_V(Map *g, char v) {
	for(int i=0; i!=g->NumV; ++i) { //对所有顶点进行遍历
		//判断是否找到顶点v所在位置
		if(g->V[i] == v)
			return i;
	}
	return -1;
}
//打印图信息
void Print_Map(Map *g) {
	printf("  \t");
	for(int i=0; i<g->NumV; ++i) { //获取顶点，并打印
		printf("%c\t",g->V[i]);
	}
	printf("\n");
	for(int i=0; i<g->NumV; ++i) { //打印顶点间边的信息
		printf("%c\t",g->V[i]);
		for(int j=0; j<g->NumV; ++j) {
			printf("%d\t",g->Edge[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//插入顶点
void Insert_V(Map *g, char v) {
	if(g->NumV >= g->MaxV)return;
	else g->V[g->NumV++] = v; //还有空间，放入顶点
}
//插入边：在v1和v2顶点间插入边
void Insert_E(Map *g, char v1, char v2) {
	int p1 = Get_V(g,v1); //获取v1顶点位置
	int p2 =  Get_V(g,v2); //获取v2顶点位置
	if(p1==-1 || p2==-1)
		return;
	if(g->Edge[p1][p2] != 0)return;
	g->Edge[p1][p2] = g->Edge[p2][p1] = 1;
	g->NumEdges++; //记录实际边数
}
//删除边：删除v1和v2顶点间的边
void Delete_E(Map *g, char v1, char v2) {
	//求出两个顶点的下标位置
	int p1 = Get_V(g,v1);
	int p2 =  Get_V(g,v2);
	if(p1==-1 || p2==-1)return;
	if(g->Edge[p1][p2] == 0)
		return;
	g->Edge[p1][p2] = g->Edge[p2][1] = 0;
	g->NumEdges--;
}
//删除顶点
void Delete_V(Map *g, char v) {
	//获取顶点的位置
	int p = Get_V(g,v);
	if(p == -1)
		return;
	//释放顶点
	int numedges = 0;
	for(int i=p; i<g->NumV-1; ++i) {
		g->V[i] = g->V[i+1];
	}
	for(int i=0; i<g->NumV; ++i) {
		if(g->Edge[p][i] != 0) {
			numedges++;
		}
	}
	for(int i=p; i<g->NumV-1; ++i) { //删除行
		for(int j=0; j<g->NumV; ++j) {
			g->Edge[i][j] = g->Edge[i+1][j];
		}
	}

	for(int i=p; i<g->NumV; ++i) { //删除列
		for(int j=0; j<g->NumV; ++j) {
			g->Edge[j][i] = g->Edge[j][i+1];
		}
	}
	g->NumV--;
	g->NumEdges -= numedges;
}
//删除图
void Delete_Map(Map *g) {
	free(g->V);
	g->V = NULL;
	for(int i=0; i<g->NumV; ++i) {
		free(g->Edge[i]);
	}
	free(g->Edge);
	g->Edge = NULL;
	g->MaxV = g->NumEdges = g->NumV = 0;
}
int main() {
	Map G;
	int choice;
	bool x=true;
	for(int i=0; i!=9; ++i)printf("*");
	printf("\n1.初始化.\n");
	printf("2.获取顶点位置.\n");
	printf("3.插入顶点.\n");
	printf("4.删除图.\n");
	printf("5.删除顶点.\n");
	printf("6.插入边.\n");
	printf("7.删除边.\n");
	printf("8.打印图.\n");
	printf("9.结束.\n");
	for(int i=0; i!=9; ++i)printf("*");
	printf("\n");
	while(x) {
		printf("输入选择:\n");
		cin>>choice;
		switch(choice) {
			case 1:
				Init_Map(&G);
				break;
			case 2:
				char v;
				cout << "请输入要获取的顶点:" << endl;;
				cin>>v;
				if(Get_V(&G,v)!=-1) {
					cout<<Get_V(&G,v);
				} else {
					cout << "没有该顶点" << endl;
				}
				break;
			case 3:
				char v1;
				cout<<"请输入要插入的顶点:";
				cin>>v1;
				Insert_V(&G,v1);
				break;
			case 4:
				Delete_Map(&G);
				break;
			case 5:
				char v3;
				cout << "请输入要删除的顶点:";
				cin>>v3;
				Delete_V(&G,v3);
				break;
			case 6:
				char v4,v5;
				cout << "请输入要连接的两个顶点:" << endl;
				cin>>v4>>v5;
				Insert_E(&G,v4,v5);
				break;
			case 7:
				char v6,v7;
				printf("请输入要删除边的两个顶点:\n");
				cin>>v6>>v7;
				Delete_E(&G,v6,v7);
				break;
			case 8:
				Print_Map(&G);
				break;
			case 9:
				x=false;
				break;
		}
	}
	return 0;
}
