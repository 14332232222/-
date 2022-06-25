#include <iostream>
using namespace std;
#define maxsize 5
struct SeqStack{
	int data[maxsize];
	int top;
};

SeqStack S;

bool empty(SeqStack &S) {//�ж�ջָ����-1������Ǿ��ǿ�ջ
	return S.top == -1;
}

void Seqstack(SeqStack &S) {//��һ��ָ���ȥ
	S.top = -1;//���ݶ�������ָ��ָ��-1
	cout << "�ѽ���ջ" << endl;
}

void Push(SeqStack &S, int value) {//����һ��ָ���һ����ֵ
	if (S.top == maxsize - 1) {
		cout << "��ջ���������ݲ���ѹ��" << endl;
		return;
	}
	cout << "ѹ�� " << value;
	S.data[++S.top] = value;//�ȼӼ��ڸ�ֵ
	cout << "  ��ǰָ��Ϊ"<<S.top << " " << endl;
}

int  Pop(SeqStack &S) {//����һ������
	if (empty(S)) {//�ж��Ƿ��ջ
		cout << "ջ�գ�������" << endl;
		return 0;
	}
	cout << "���� " << S.data[S.top];
	cout << "  ��ǰָ��Ϊ " << S.top-1 << endl;
	return S.data[S.top--];//�ȴ�ֵ�ټ���
}

int GetTop(SeqStack &S) {//�õ�ջ��ָ��ָ���ֵ
	if (empty(S)) {//�ж��Ƿ��ջ
		cout << "ջ�գ�������" << endl;
		return 0;
	}
	cout << "ջ������Ϊ "<<S.data[S.top] << endl;;
	return S.data[S.top];//�õ���ǰָ��ָ���ֵ
}

void test() {
	cout << "1.Ԫ����ջ" << endl;
	cout << "2.Ԫ�س�ջ" << endl;
	cout << "3.��ѯջ��Ԫ��ֵ" << endl;
	cout << "4.��ʼ��˳��ջ" << endl;

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
			Push(S,data);
			break;
		case 2:
			Pop(S);
			break;
		case 3:
			GetTop(S);
			break;
		case 4:
			SeqStack(S);
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