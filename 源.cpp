#include<stdio.h>
#include<iostream>
#define N 5
using namespace std;
struct studentinfo{
	int num;
	string name;
	int score;
};
void SelectSort(studentinfo num[], int len)
{
	int i, j, k;
	studentinfo temp;
	for (i = 0; i < len; i++)
	{
		k = i;//��¼λ��
		for (j = i + 1; j < len; j++)//���Һ������Сֵ
			if (num[k].score > num[j].score)
				k = j;//��¼λ��
		if (k != i)//����λ��
		{
			temp = num[i];
			num[i] = num[k];
			num[k] = temp;
		}
	}
}

void InsertSort(studentinfo num[], int len){//
	int i, j ;
	studentinfo temp;
	for (i = 0; i < len; i++)
		if (num[i].score < num[i - 1].score)
		{
			temp = num[i];
			num[i] = num[i - 1];
			for (j = i - 1; num[j].score > temp.score && j >= 0; j--)
				num[j + 1] = num[j];
			num[j + 1] = temp;
		}
}

void BubbleSort(studentinfo array[], int len) {//ð������
	studentinfo tem;
	//���ѭ������ ��������� n��Ԫ��������Ҫѭ��n-1�� ��1�� 
	for (int i = 0; i < len - 1; i++) {
		//�ڲ�ѭ�����ƱȽϵĴ��� n��Ԫ�ص�i�˱Ƚ�n-i�� ��2��
		for (int j = 0; j < len - 1 - i; j++) {
			//�Ƚ����ڵ�Ԫ�ش�С Ŀ�ģ�������Ԫ��ѡ�����ƶ������ 
			if (array[j].score > array[j + 1].score) {
				tem = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tem;
			}
		}
	}
}
void BInsertSort(studentinfo num[], int len){
	int i, j, low, high, mid;
	studentinfo key;
	for (i = 1; i < N; i++)
	{
		key = num[i];
		low = 0;
		high = i - 1;
		while (low <= high)//�۰����
		{
			mid = (low + high) / 2;
			if (num[mid].score >= key.score)
				high = mid - 1;//�������keyֵ������ҷ�Χ��С����������
			else
				low = mid + 1;//���С��keyֵ������ҷ�Χ��С����������
		}
		for (j = i - 1; j >= high + 1; j--)
			num[j + 1] = num[j];//��high֮��������������
		num[high + 1] = key;//��keyֵ�����λ��
	}
}

void QuickSort(studentinfo array[], int low, int high) {
	int i = low;
	int j = high;
	if (i >= j) {
		return;
	}

	studentinfo temp = array[low];
	while (i != j) {
		while (array[j].score >= temp.score && i < j) {
			j--;
		}
		while (array[i].score <= temp.score && i < j) {
			i++;
		}
		if (i < j) {
			swap(array[i], array[j]);
		}
	}

	//����׼temp�����Լ���λ�ã�����i��λ�ã�
	swap(array[low], array[i]);
	QuickSort(array, low, i - 1);
	QuickSort(array, i + 1, high);
}
int main()
{
	studentinfo num[N];
	num[0].num = 0; num[0].name = "A"; num[0].score = 10;
	num[1].num = 1; num[1].name = "E"; num[1].score = 30;
	num[2].num = 2; num[2].name = "D"; num[2].score = 20;
	num[3].num = 3; num[3].name = "C"; num[3].score = 50;
	num[4].num = 4; num[4].name = "B"; num[4].score = 40;
	cout << "����ǰ��ѧ���б�" << endl;
	for (int i = 0; i < N; i++) {
		cout << "������" << num[i].name << " ѧ�ţ�" << num[i].num << " ������ " << num[i].score << endl;
	}


	cout << "ѡ�����򷽷�����������ţ�" << endl;
	cout << "1��ֱ�Ӳ������� "<< endl;
	cout << "2���۰�������� "<< endl;
	cout << "3��ð������ "<< endl;
	cout << "4���������� "<< endl;
	cout << "5����ѡ������ "<< endl;
	cout << "6���˳�����" << endl;
	while (true) {
		int sel;
		cin >> sel;
		switch (sel){
			case 1:
				cout << "����ֱ�Ӳ�������" << endl;
				InsertSort(num, N);
				break;
			case 2:
				cout << "���ж��ֲ�������" << endl;
				BInsertSort(num, N);
				break;
			case 3:
				cout << "����ð������" << endl;
				BubbleSort(num, N);
				break;
			case 4:
				cout << "���п�������" << endl;
				QuickSort(num, 0, 4);
				break;
			case 5:
				cout << "���м�ѡ������" << endl;
				SelectSort(num, N);
				break;
			case 6:
				cout << "�����˳�" << endl;
				exit(-1);
		}
		cout << "��������" << endl;
		for (int i = 0; i < N; i++) {//��ӡ������
			cout << "������" << num[i].name << " ѧ�ţ�" << num[i].num << " ������ " << num[i].score << endl;
		}
	}
	//InsertSort(num, N);
	//SelectSort(num, N);
	//BubbleSort(num, N);
	//BInsertSort(num, N);
	QuickSort(num, 0,4);

	for (int i = 0; i < N; i++) {
		cout << "������" << num[i].name << " ѧ�ţ�" << num[i].num << " ������ " << num[i].score << endl;
	}
}
