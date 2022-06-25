#include <iostream>
using namespace std;
struct Node {//Ԫ���ڵ��������ָ����
	Node* next;
	int data;
};

Node* head; Node* tail;
int curlength;

bool empty() {//�ж������Ƿ�Ϊ��
	return head->next == NULL;//ͷ�ڵ�ָ��ָ��NULL
}

void CreateList() {//����һ��ֻ��ͷ�ڵ������
	Node* p = new Node();
	p->data = 0;
	p->next = NULL;
	head = p;
	tail = p;
	cout << "�Ѵ����±�" << endl;
}

void tailinsert() {//β�巨
	Node* tmp = new Node();
	cout << "�����½ڵ�data: ";
	cin >> tmp->data;//���½ڵ�����ݸ�ֵ
	tmp->next = NULL;//���½ڵ��ָ�븳ֵ
	tail->next = tmp;//βָ��Ľڵ�nextָ���½ڵ�
	tail = tmp;//βָ��Ǩ��
}
void Clear() {
	Node* p, * tmp;//������ʱָ�룬tmp����ɾ�ڵ�
	p = head->next;//pָ��ͷ�ڵ���һλ�ڵ�
	while(p != NULL) {//tmp��pͨ�������������ڵ�ȫ��ɾ�������ֻʣͷ�ڵ�
		tmp = p;
		p = p->next;
		delete tmp;
	}
	head->next = NULL;//ͷ�ڵ�nextָ��ָ��NULL
	tail = head;//tailָ��head�ļ�ͷָ��
	curlength = 0;
	cout << "���������" << endl;
}

void Traverse(){
	if (empty()) {
		cout << "����Ϊ�գ�������" << endl;
		return;
	}
	Node* p = head->next;//pָ��1�Žڵ�
	cout << "result: ";
	while (p != NULL) {//�������нڵ㲢��ӡ����
		cout <<"����������Ϊ: " << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

Node* Getposition(int i){
	if ( i < -1 || i > curlength - 1)//�ж������Ƿ�Ϸ� 
		return NULL;
	Node* p = head;//pָ��head��ָ��ͷ�ڵ㣩
	int count = 0;
	while (count < i) {//��count������i��ֵʱ����������pָ��ĵ�ַ������˵����pָ�룩
		p = p->next;
		count++;
	}
	return p;
}

int Search(int value) {
	Node* p = head->next;//ָ��pָ��1�Žڵ�
	int count = 0;
	while(p != NULL && p->data != value) {//��p�Ȳ�ָ��NULL��pָ��Ľڵ�dataҲ����Ҫ�����Ĳ���
		p = p->next;//p�ƶ�����һ���ڵ�
		count++;//����+1
	}
	if(p == NULL)
		return - 1;
	else
		return count;//���ؼ���ֵ
}

void Insert(int i,int value) {
	Node* p, * q;
	if (i < 0 || i > curlength)//�ж�����ֵ�ںϷ���Χ��
		return ;
	p = Getposition(i - 1);
	q = new Node();
	q->data = value; 
	q->next = p->next;
	p->next = q;
	if (p == tail) 
		tail = q;
	curlength++;//������+1
}

void Delete(int i) {
	Node* pre, * p;
	if (i < 0 || i > curlength)//�ж�����ֵ�ںϷ���Χ��
		return ;
	pre = Getposition(i );//preָ��i�Žڵ�
	p = pre->next;//pָ��pre��ָ�ڵ���һ���ڵ�
	if(p == tail) {
		tail = pre;
		pre->next = NULL;
		delete p;
	}
	else{
		pre->next = p->next;
		delete p;
	}
	curlength--;//ʵ�ʳ���-1
}

void Inverse() {
	Node* p, * tmp;
	p = head->next;
	head->next = NULL;
	if(p != NULL)
		tail = p;
	while(p != NULL) {
		tmp = p->next;
		p->next = head->next;
		head->next = p;
		p = tmp;
	}
}

int Visit(int i) {
	Node* p = head->next;//pָ��ָ��ͷ�ڵ���һ���ڵ�
	int count = 0;
	if (i < 0 || i > curlength-1)//�ж�����ֵ�ںϷ���Χ��
		return 0;
	while(count < i) {
		p = p->next;//pָ���ƶ�����һ���ڵ�
		count++;//��������
	}
	return p->data;
}
