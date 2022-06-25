
#include<iostream>
#include<stdlib.h>
#define Vs  9//Ĭ�� 
using namespace std;
//�ڽӾ���ͼ�ṹ
typedef struct Map {
	int MaxV; //��󶥵���
	int NumV; //��ʵ�Ķ�����
	int NumEdges; //����
	char*V; //�����б�
	int**Edge; //����Ϣ����
} Map;
//ͼ�ĳ�ʼ��
void Init_Map(Map *g) {
	g->MaxV = Vs;//��󶥵�����ʼ��
	g->NumV = g->NumEdges = 0; //ʵ�ʶ�������ʼ��
	//���䶥��洢�б�Ŀռ�
	g->V = (char*)malloc(sizeof(char)*(g->MaxV));//�� 
	g->Edge = (int**)malloc(sizeof(int*) * g->MaxV);//�� 
	for(int i=0; i<g->MaxV; ++i) { //ÿһ���ھ���Ŀռ俪��
		g->Edge[i] = (int*)malloc(sizeof(int) * g->MaxV);
	}
	for(int i=0; i<g->MaxV; ++i) { //��ʼ��
		for(int j=0; j<g->MaxV; ++j) {
			g->Edge[i][j] = 0;
		}
	}
}
//��ȡ�����λ��
int  Get_V(Map *g, char v) {
	for(int i=0; i!=g->NumV; ++i) { //�����ж�����б���
		//�ж��Ƿ��ҵ�����v����λ��
		if(g->V[i] == v)
			return i;
	}
	return -1;
}
//��ӡͼ��Ϣ
void Print_Map(Map *g) {
	printf("  \t");
	for(int i=0; i<g->NumV; ++i) { //��ȡ���㣬����ӡ
		printf("%c\t",g->V[i]);
	}
	printf("\n");
	for(int i=0; i<g->NumV; ++i) { //��ӡ�����ߵ���Ϣ
		printf("%c\t",g->V[i]);
		for(int j=0; j<g->NumV; ++j) {
			printf("%d\t",g->Edge[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//���붥��
void Insert_V(Map *g, char v) {
	if(g->NumV >= g->MaxV)return;
	else g->V[g->NumV++] = v; //���пռ䣬���붥��
}
//����ߣ���v1��v2���������
void Insert_E(Map *g, char v1, char v2) {
	int p1 = Get_V(g,v1); //��ȡv1����λ��
	int p2 =  Get_V(g,v2); //��ȡv2����λ��
	if(p1==-1 || p2==-1)
		return;
	if(g->Edge[p1][p2] != 0)return;
	g->Edge[p1][p2] = g->Edge[p2][p1] = 1;
	g->NumEdges++; //��¼ʵ�ʱ���
}
//ɾ���ߣ�ɾ��v1��v2�����ı�
void Delete_E(Map *g, char v1, char v2) {
	//�������������±�λ��
	int p1 = Get_V(g,v1);
	int p2 =  Get_V(g,v2);
	if(p1==-1 || p2==-1)return;
	if(g->Edge[p1][p2] == 0)
		return;
	g->Edge[p1][p2] = g->Edge[p2][1] = 0;
	g->NumEdges--;
}
//ɾ������
void Delete_V(Map *g, char v) {
	//��ȡ�����λ��
	int p = Get_V(g,v);
	if(p == -1)
		return;
	//�ͷŶ���
	int numedges = 0;
	for(int i=p; i<g->NumV-1; ++i) {
		g->V[i] = g->V[i+1];
	}
	for(int i=0; i<g->NumV; ++i) {
		if(g->Edge[p][i] != 0) {
			numedges++;
		}
	}
	for(int i=p; i<g->NumV-1; ++i) { //ɾ����
		for(int j=0; j<g->NumV; ++j) {
			g->Edge[i][j] = g->Edge[i+1][j];
		}
	}

	for(int i=p; i<g->NumV; ++i) { //ɾ����
		for(int j=0; j<g->NumV; ++j) {
			g->Edge[j][i] = g->Edge[j][i+1];
		}
	}
	g->NumV--;
	g->NumEdges -= numedges;
}
//ɾ��ͼ
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
	printf("\n1.��ʼ��.\n");
	printf("2.��ȡ����λ��.\n");
	printf("3.���붥��.\n");
	printf("4.ɾ��ͼ.\n");
	printf("5.ɾ������.\n");
	printf("6.�����.\n");
	printf("7.ɾ����.\n");
	printf("8.��ӡͼ.\n");
	printf("9.����.\n");
	for(int i=0; i!=9; ++i)printf("*");
	printf("\n");
	while(x) {
		printf("����ѡ��:\n");
		cin>>choice;
		switch(choice) {
			case 1:
				Init_Map(&G);
				break;
			case 2:
				char v;
				cout << "������Ҫ��ȡ�Ķ���:" << endl;;
				cin>>v;
				if(Get_V(&G,v)!=-1) {
					cout<<Get_V(&G,v);
				} else {
					cout << "û�иö���" << endl;
				}
				break;
			case 3:
				char v1;
				cout<<"������Ҫ����Ķ���:";
				cin>>v1;
				Insert_V(&G,v1);
				break;
			case 4:
				Delete_Map(&G);
				break;
			case 5:
				char v3;
				cout << "������Ҫɾ���Ķ���:";
				cin>>v3;
				Delete_V(&G,v3);
				break;
			case 6:
				char v4,v5;
				cout << "������Ҫ���ӵ���������:" << endl;
				cin>>v4>>v5;
				Insert_E(&G,v4,v5);
				break;
			case 7:
				char v6,v7;
				printf("������Ҫɾ���ߵ���������:\n");
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
