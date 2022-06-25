#include <iostream>
using namespace std;

struct Node {
	Node* next;
	int data;
};

Node* top;//栈顶指针

bool empty() {
	return top == NULL;//栈一般没有头节点
}//当top指针为空时表示空栈

void Clear() {
	Node* p;
	while (top != NULL) {
		p = top;//p首先指向top所指
		top = top->next;//top移向下一节点
		delete p;//p将原节点删除
	}
	cout << "链栈已清空" << endl;
}

int Size() {//获取栈长度的函数
	Node* p = top;//临时指针p指向top所指
	int count = 0;//用于计数的变量
	while (p!=NULL) {//只要p不指向空，就继续循环
		count++;
		p = p->next;//指针p移动到下一个节点
	}
	cout << "栈长度为: " <<count<< endl;
	return count;//返回最终计数值
}

void Push(int value) {//传入一个值
	Node* p = new Node();//用p接受新开辟的堆区内存
	cout << "压入 " << value << endl;
	p->data = value;//传入的值赋给新节点
	p->next = top;//p指向节点的next指向top所指
	top = p;
}

int Pop() {
	if (empty()) {//空栈检测
		cout << "栈空，无数据可弹出" << endl;
		return 0;
	}
	Node* p = top;//临时指针p指向top所指
	int value = p->data;
	top = top->next;//top指针移至下一位
	delete p;//用临时指针删除对象
	cout << "弹出 " << value << endl;
	return value;//返回节点值
}

int GetTop() {
	if (empty()) {//空栈检测
		cout << "栈空，无数据" << endl;
		return 0;
	}
	cout << "栈顶元素值为 " <<top->data<<endl;
	return top->data;//返回top指向的节点值
}

void test() {
	cout << "1.元素入栈" << endl;
	cout << "2.元素出栈" << endl;
	cout << "3.查询栈顶元素值" << endl;
	cout << "4.清空链栈" << endl;
	cout << "5.结束操作" << endl;
	cout << endl;

	bool j = true;
	while (j) {
		cout << "请输入操作序号：";
		int in;
		cin >> in;
		switch (in) {
		case 1:
			int data;
			cout << "请输入入列元素值：";
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
			cout << "输入的数据有误请重新输入" << endl;
			break;
		}
	}
}

int main() {
	test();
}
