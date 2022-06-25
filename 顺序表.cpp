#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int Elemtype;
struct linearlist {//ֱ����ջ����������
	int curlength;
	int data[MAXSIZE];
};
linearlist list1;//ȫ�ֱ���list1
bool Empty() {
	return list1.curlength == 0;//�ж�˳���Ԫ�س����Ƿ�Ϊ0
}

void Traverse() {
	if (Empty()) {//ʹ��Empty�����ж��Ƿ�ձ�
		cout << "Sequence list is empty";
	}
	else {//���ǿձ��ʱ��ִ�����´���
		cout << "result:";
		for (int i = 0; i < list1.curlength; ++i) {//forѭ����ӡdata[]������Ԫ��
			cout << list1.data[i] << " ";
		}
		cout << endl;
	}
}

int Search(int value) {//����Ҫ���ҵ���ֵ
	for (int i = 0; i < list1.curlength; ++i) {//����data[]
		if (value == list1.data[i])//����ֵ��������һ��Ԫ��ֵ
			return i;//�������Ԫ�ص��±�
	}
	return -1;
}

void Insert(int value, int i) {
	if (i < 0 || i>list1.curlength) {
		cout << "this Sequence is full" << endl;
		return;
	}
	if (list1.curlength == MAXSIZE)//��˳�������
		//Resize();//������洢�ռ�
	for (int j = list1.curlength; j >= i; j--) {//�Ѽ���������±�Ԫ���Լ������Ԫ�������һλ
		list1.data[j] = list1.data[j - 1];
	}
	list1.data[i] = value;//��valueд��data[i]
	list1.curlength++;//Ԫ��ʵ�ʳ���+1
}

void Delete(int i) {
	if (i < 0 || i > list1.curlength)
		return ;
	for (int j = i; j < list1.curlength; j++)
		list1.data[j - 1] = list1.data[j];
	list1.curlength--;
}

void Inverse() {
	int tmp;//��ʱ����
	for (int i = 0; i < list1.curlength / 2; i++) {
		tmp = list1.data[i];//��ʱ�����ݴ�Ԫ��ֵ
		list1.data[i] = list1.data[list1.curlength - 1 - i];//�����һλԪ�ؿ�������һ���±괦
		list1.data[list1.curlength - 1 - i] = tmp;//��ʱ�����ݴ�ֵ���������һ��Ԫ�ش�����ɽ���
	}
}

void Resize() {//Resize��������˳������������ֻ�������ڶ���������˳�����ջ�������ı��޷�ʹ��
	Elemtype * p = list1.data;
	int a = MAXSIZE * 2;
	list1.data = new Elemtype[a];
	for (int i = 0; i < list1.curlength; i++)//���Ĵ��룬��ԭ���ľɱ������±�����
		list1.data[i] = p[i];
	delete[] p;
}

int Visit(int i) {
	if ( i < 0 || i > list1.curlength)
		return 0;
	return list1.data[i];
}

/*int main() {

}
*/