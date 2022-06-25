#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#define MaxVn 30
using namespace std;
int visit[MaxVn];
int arc[MaxVn][MaxVn];
//����
typedef struct VNode {
	int vnext;				//�ڽӽ�㣬�ö����Ӧ���±�
	int weight;			//Ȩֵ
	struct VNode* next;	//����ָ����һ�����
} VNode;
//�������
typedef struct VlistNode {
	char data;		//�洢 ���������
	VNode* fv;		//�߱�ͷָ��
} VlistNode,list[MaxVn];
//�ڽӱ�
typedef struct GMap {
	list adli;		//�ڽӱ�
	int verNum, arcNum;		//��ǰ������������
} Gmlist;
//�����ڽӱ�
void Creat_GM(Gmlist* G) {
	printf("����ͼ1������ͼ0:");
	int flag = 0;
	cin>>flag;
	for (int i = 0; i < MaxVn; i++) {
		G->adli[i].fv = NULL;
	}
	printf("���붥�㡢�߸������ո�����:");
	cin>>G->verNum>>G->arcNum;
	for (int i = 0; i < G->verNum; i++) {
		printf("�������%d�������Ԫ�أ�", i + 1);
		fflush(stdin);
		cin>>G->adli[i].data;
		G->adli[i].fv = NULL;
	}
	int vi, vj;
	int weight;//Ȩ
	for (int i = 0; i < G->arcNum; i++) {
		printf("�������һ������,�ڶ�������,�ߵ�Ȩֵ���ո���,���е�һ�ڶ���������˳������:");
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
//��ӡ�ڽӱ�
void Print(Gmlist* G) {
	printf("���㣺\n");
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
//������ȱ��� ����һ�����㿪ʼ�����������
void DFS(Gmlist *G,int v) {
	//��ǰ�ڵ㱻���ʹ��ı�־
	visit[v] = 1;
	//���ʵ�ǰ�ڵ�
	printf("%c->\t",G->adli[v].data);
	//�Զ����ڱ߱��и��е����б߹�ϵ���б��������==1��ʾ���ڽӵ㣬���һ�Ҫ�жϵ�ǰ�����Ƿ񱻷��ʹ�
	for (int i = 0; i!=G->verNum; i++) {
		if (arc[v][i] == 1 && visit[i]==0) {
			DFS(G,i); //��������������ʹӸö��㿪ʼ�ٴν���DFS����
		}
	}
}
void DFS_m(Gmlist *G) {
	//�������ж���
	for (int i = 0; i!=G->verNum; ++i) {
		//�������Ǿ����Ѷ��������е�һ��Ԫ�ص����������
		if (visit[i] == 0) { //�����ǰ���㴦��δ�����ʵ�״̬���ͶԸö������DFS����
			DFS(G,i);
		}
	}
	printf("^^\n");
}
//������ȱ��� ��һ�����㿪ʼ�����ܹ�ı���
void BFS(Gmlist *G,int v) {
	//���
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

