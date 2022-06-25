#include <iostream>
using namespace std;

struct Node {
	Node* next;
	int data;
};

Node* top;//ջ��ָ��

bool empty() {
	return top == NULL;//ջһ��û��ͷ�ڵ�
}//��topָ��Ϊ��ʱ��ʾ��ջ

void Clear() {
	Node* p;
	while (top != NULL) {
		p = top;//p����ָ��top��ָ
		top = top->next;//top������һ�ڵ�
		delete p;//p��ԭ�ڵ�ɾ��
	}
	cout << "��ջ�����" << endl;
}

int Size() {//��ȡջ���ȵĺ���
	Node* p = top;//��ʱָ��pָ��top��ָ
	int count = 0;//���ڼ����ı���
	while (p!=NULL) {//ֻҪp��ָ��գ��ͼ���ѭ��
		count++;
		p = p->next;//ָ��p�ƶ�����һ���ڵ�
	}
	cout << "ջ����Ϊ: " <<count<< endl;
	return count;//�������ռ���ֵ
}

void Push(int value) {//����һ��ֵ
	Node* p = new Node();//��p�����¿��ٵĶ����ڴ�
	cout << "ѹ�� " << value << endl;
	p->data = value;//�����ֵ�����½ڵ�
	p->next = top;//pָ��ڵ��nextָ��top��ָ
	top = p;
}

int Pop() {
	if (empty()) {//��ջ���
		cout << "ջ�գ������ݿɵ���" << endl;
		return 0;
	}
	Node* p = top;//��ʱָ��pָ��top��ָ
	int value = p->data;
	top = top->next;//topָ��������һλ
	delete p;//����ʱָ��ɾ������
	cout << "���� " << value << endl;
	return value;//���ؽڵ�ֵ
}

int GetTop() {
	if (empty()) {//��ջ���
		cout << "ջ�գ�������" << endl;
		return 0;
	}
	cout << "ջ��Ԫ��ֵΪ " <<top->data<<endl;
	return top->data;//����topָ��Ľڵ�ֵ
}

void test() {
	cout << "1.Ԫ����ջ" << endl;
	cout << "2.Ԫ�س�ջ" << endl;
	cout << "3.��ѯջ��Ԫ��ֵ" << endl;
	cout << "4.�����ջ" << endl;
	cout << "5.��������" << endl;
	cout << endl;

	bool j = true;
	while (j) {
		cout << "�����������ţ�";
		int in;
		cin >> in;
		switch (in) {
		case 1:
			int data;
			cout << "����������Ԫ��ֵ��";
			cin >> data;
			Push(data);
			break;
		case 2:
			Pop();
			break;
		case 3:
			GetTop();
			break;
		case 4:
			Clear();
			break;
		case 5:
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
