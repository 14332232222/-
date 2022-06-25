#include <iostream>
using namespace std;
#define maxsize 10

struct Queue {
	int* base; // ��ʼ���Ķ�̬����洢�ռ�
	int front; // ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear; // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
};

bool empty(Queue*tmp) {
	return tmp->front == tmp->rear;
}

Queue* SeqQueue() {//���ڹ����¶���
	Queue* q = new Queue();//qָ�������queneʵ������
	q->base = new int[maxsize];//baseָ��ָ������
	q->front = q->rear = 0;//front��rear����Ϊ0
	cout << "�¶����ѹ���" << endl;
	return q;//����һ��qָ��
}

void EnQueue(Queue* tmp,int x) {
	if ((tmp->rear + 1) % maxsize == tmp->front) {//��rear+1����front��ͬ�ͷ���
		cout << "�����������޷����" << endl;
		return;
	}
	tmp->rear = (tmp->rear + 1) % maxsize;//βָ��+1
	tmp->base[tmp->rear] = x;//����ֵ����rear�����±�
	cout << x << " ���" << endl;
}

int DeQueue(Queue* tmp) {
	if (empty(tmp)) {//�ж��Ƿ�նӣ��ն��򷵻�
		cout<<"����Ϊ�գ�������" << endl;
		return 0;
	}
	tmp->front = (tmp->front + 1) % maxsize;//frontָ��+1
	cout << tmp->base[tmp->front]<<" ����" << endl;
	return tmp->base[tmp->front];

}

int GetHead(Queue* tmp) {
	if (empty(tmp)) {//�ն��ж�
		cout << "����Ϊ�գ�������" << endl;
		return 0;
	}
	cout << "������Ԫ��Ϊ " << tmp->base[(tmp->front + 1) % maxsize] << endl;
	return tmp->base[(tmp->front + 1) % maxsize];//����frontָ��+1����±�Ԫ��ֵ
}

void PrintQueue(Queue*tmp) {
	int p = tmp->front;//����һ������p����frontָ��ֵ
	cout << "������Ԫ��Ϊ��";
	while (tmp->rear != p) {//ѭ��������p������rearָ��
		p = (p + 1) % maxsize;//ָ��p+1
		cout<< tmp->base[p] << " ";//��ӡpָ��������±�
	}
	cout << endl;
}

void Clear(Queue*tmp) {
	delete tmp->base;
	delete tmp;
	cout << "˳����������" << endl;
}
void test() {
	Queue* lq2 = NULL;
	cout << "1.������˳�����" << endl;
	cout << "2.Ԫ������" << endl;
	cout << "3.Ԫ�س���" << endl;
	cout << "4.��ѯ����Ԫ��ֵ" << endl;
	cout << "5.���˳�����" << endl;
	cout << "6.��ӡ˳�����" << endl;
	cout << "7.��������" << endl;

	cout << endl;

	bool j = true;
	while (j) {
		cout << "�����������ţ�";
		int in;
		cin >> in;
		switch (in) {
		case 1:
			lq2 = SeqQueue();
			break;
		case 2:
			int data;
			cout << "����������Ԫ��ֵ��";
			cin >> data;
			EnQueue(lq2, data);
			break;
		case 3:
			DeQueue(lq2);
			break;
		case 4:
			GetHead(lq2);
			break;
		case 5:
			Clear(lq2);
			break;
		case 6:
			PrintQueue(lq2);
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
