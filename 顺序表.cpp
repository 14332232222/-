#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int Elemtype;
struct linearlist {//直接在栈区创建对象
	int curlength;
	int data[MAXSIZE];
};
linearlist list1;//全局变量list1
bool Empty() {
	return list1.curlength == 0;//判断顺序表元素长度是否为0
}

void Traverse() {
	if (Empty()) {//使用Empty函数判断是否空表
		cout << "Sequence list is empty";
	}
	else {//不是空表的时候执行以下代码
		cout << "result:";
		for (int i = 0; i < list1.curlength; ++i) {//for循环打印data[]的所有元素
			cout << list1.data[i] << " ";
		}
		cout << endl;
	}
}

int Search(int value) {//输入要查找的数值
	for (int i = 0; i < list1.curlength; ++i) {//遍历data[]
		if (value == list1.data[i])//若数值等于其中一个元素值
			return i;//返回这个元素的下标
	}
	return -1;
}

void Insert(int value, int i) {
	if (i < 0 || i>list1.curlength) {
		cout << "this Sequence is full" << endl;
		return;
	}
	if (list1.curlength == MAXSIZE)//若顺序表已满
		//Resize();//则扩大存储空间
	for (int j = list1.curlength; j >= i; j--) {//把即将插入的下标元素以及后面的元素向后推一位
		list1.data[j] = list1.data[j - 1];
	}
	list1.data[i] = value;//将value写入data[i]
	list1.curlength++;//元素实际长度+1
}

void Delete(int i) {
	if (i < 0 || i > list1.curlength)
		return ;
	for (int j = i; j < list1.curlength; j++)
		list1.data[j - 1] = list1.data[j];
	list1.curlength--;
}

void Inverse() {
	int tmp;//临时变量
	for (int i = 0; i < list1.curlength / 2; i++) {
		tmp = list1.data[i];//临时变量暂存元素值
		list1.data[i] = list1.data[list1.curlength - 1 - i];//将最后一位元素拷贝到第一个下标处
		list1.data[list1.curlength - 1 - i] = tmp;//临时变量暂存值拷贝到最后一个元素处，完成交换
	}
}

void Resize() {//Resize用于扩容顺序表，但这个函数只能用于在堆区创建的顺序表，在栈区创建的表无法使用
	Elemtype * p = list1.data;
	int a = MAXSIZE * 2;
	list1.data = new Elemtype[a];
	for (int i = 0; i < list1.curlength; i++)//核心代码，将原来的旧表拷贝到新表里面
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