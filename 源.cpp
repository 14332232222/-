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
		k = i;//记录位置
		for (j = i + 1; j < len; j++)//查找后面的最小值
			if (num[k].score > num[j].score)
				k = j;//记录位置
		if (k != i)//交换位置
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

void BubbleSort(studentinfo array[], int len) {//冒泡排序
	studentinfo tem;
	//外层循环控制 排序的趟数 n个元素排序需要循环n-1次 【1】 
	for (int i = 0; i < len - 1; i++) {
		//内层循环控制比较的次数 n个元素第i趟比较n-i次 【2】
		for (int j = 0; j < len - 1 - i; j++) {
			//比较相邻的元素大小 目的：将最大的元素选出到移动到最后 
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
		while (low <= high)//折半查找
		{
			mid = (low + high) / 2;
			if (num[mid].score >= key.score)
				high = mid - 1;//如果大于key值，则查找范围缩小到左子序列
			else
				low = mid + 1;//如果小于key值，则查找范围缩小到右子序列
		}
		for (j = i - 1; j >= high + 1; j--)
			num[j + 1] = num[j];//将high之后的数据整体后移
		num[high + 1] = key;//将key值插入该位置
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

	//将基准temp放于自己的位置，（第i个位置）
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
	cout << "排序前的学生列表" << endl;
	for (int i = 0; i < N; i++) {
		cout << "姓名：" << num[i].name << " 学号：" << num[i].num << " 分数： " << num[i].score << endl;
	}


	cout << "选择排序方法：（输入序号）" << endl;
	cout << "1、直接插入排序 "<< endl;
	cout << "2、折半插入排序 "<< endl;
	cout << "3、冒泡排序 "<< endl;
	cout << "4、快速排序 "<< endl;
	cout << "5、简单选择排序 "<< endl;
	cout << "6、退出程序" << endl;
	while (true) {
		int sel;
		cin >> sel;
		switch (sel){
			case 1:
				cout << "进行直接插入排序" << endl;
				InsertSort(num, N);
				break;
			case 2:
				cout << "进行二分插入排序" << endl;
				BInsertSort(num, N);
				break;
			case 3:
				cout << "进行冒泡排序" << endl;
				BubbleSort(num, N);
				break;
			case 4:
				cout << "进行快速排序" << endl;
				QuickSort(num, 0, 4);
				break;
			case 5:
				cout << "进行简单选择排序" << endl;
				SelectSort(num, N);
				break;
			case 6:
				cout << "程序退出" << endl;
				exit(-1);
		}
		cout << "排序结果：" << endl;
		for (int i = 0; i < N; i++) {//打印排序结果
			cout << "姓名：" << num[i].name << " 学号：" << num[i].num << " 分数： " << num[i].score << endl;
		}
	}
	//InsertSort(num, N);
	//SelectSort(num, N);
	//BubbleSort(num, N);
	//BInsertSort(num, N);
	QuickSort(num, 0,4);

	for (int i = 0; i < N; i++) {
		cout << "姓名：" << num[i].name << " 学号：" << num[i].num << " 分数： " << num[i].score << endl;
	}
}
