#include <iostream>
using namespace std;

struct Node;
struct LinkQueue{//��װһ�������нṹ��
	Node* front;
	Node* rear;
};

struct Node {//��װһ���ڵ�ṹ��
	Node* next;//Ԫ��ָ����
	int data;//Ԫ��������
};

bool empty(LinkQueue*tmp) {
	return tmp->front == NULL;//ͷָ��ָ���ʱ����Ϊ�ǿ��б�
}

void Clear(LinkQueue*tmp) {//��������к���
	Node* p;
	while (tmp->front != NULL) {
		p = tmp->front;
		tmp->front = tmp->front->next;
		delete p;
	}
	tmp->rear = NULL;
	cout << "���������" << endl;
}

int Size(LinkQueue*tmp) {//��ѯ�����г���
	Node* p = tmp->front;
	int count = 0;//����������ʼ��Ϊ0
	while (p) {
		count++;//����ֵ����
		p = p->next;//��ʱָ������һ���ڵ�λ��
	}
	cout << "���г���Ϊ " << count << endl;
	return count;
}
void EnQueue(LinkQueue*tmp,int x) {//���к���
	if (tmp->rear == NULL) {//��rearָ���ÿ�ʱ������ûԪ��ʱ��
		tmp->front = tmp->rear = new Node();//front��rearָ���½ڵ�
		tmp->front->data = x;
		cout << x << " ����" << endl;
	}
	else {//��ʱ������Ԫ��
		tmp->rear->next = new Node();//βָ��ָ��ڵ��nextָ��ָ���½ڵ�
		tmp->rear->next->data = x;
		tmp->rear = tmp->rear->next;
		cout << x << " ����" << endl;
	}
}

int  DeQueue(LinkQueue*tmp) {//���к���
	if (empty(tmp)) {
		cout << "����Ϊ�գ���Ԫ�ؿɳ���" << endl;
		return 0;
	}
	Node* p = tmp->front;
	int value = tmp->front->data;
	tmp->front = tmp->front->next;
	if (tmp->front == NULL)//��ΨһԪ�س��к󣬶�����Ԫ�أ��׽ڵ��β�ڵ㶼�ÿ�
		tmp->rear == NULL;
	delete p;
	cout << value << " ����" << endl;
	return value;
}

int GetHead(LinkQueue* tmp) {//�õ�����Ԫ��ֵ
	if (empty(tmp)) {
		cout << "����Ϊ�գ���Ԫ��" << endl;
		return 0;
	}
	cout << "����Ԫ��ֵΪ " << tmp->front->data<<endl;
	return tmp->front->data;
}

LinkQueue* CreateLinkQueue() {//��ʼ����ʽ����
	LinkQueue* tmp = new LinkQueue();//����ռ�
	tmp->front == NULL;//ͷָ���ÿ�
	tmp->rear == NULL;//βָ���ÿ�
	cout << "�Ѵ����¶���" << endl;
	return tmp;
}

void test() {
	LinkQueue* lq1=NULL;
	cout << "1.��������ʽ����" << endl;
	cout << "2.Ԫ������" << endl;
	cout << "3.Ԫ�س���" << endl;
	cout << "4.��ѯ��ʽ���г���" << endl;
	cout << "5.��ѯ����Ԫ��ֵ" << endl;
	cout << "6.�����ʽ����" << endl;
	cout << "7.��������" << endl;
	cout << endl;

	bool j = true;
	while (j) {
		cout << "�����������ţ�";
		int in;
		cin >> in;
		switch (in) {
			case 1:
				lq1 = CreateLinkQueue();
				break;
			case 2:
				int data;
				cout << "����������Ԫ��ֵ��";
				cin >> data;
				EnQueue(lq1, data);
				break;
			case 3:
				DeQueue(lq1);
				break;
			case 4:
				Size(lq1);
				break;
			case 5:
				GetHead(lq1);
				break;
			case 6:
				Clear(lq1);
				break;
			case 7:
				j = false;
				break;
			default:
				cout << "�����������������������" << endl;
				break;
		}
	}
}

int main() {
	test();
}
