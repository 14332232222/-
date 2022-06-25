#include <iostream>
using namespace std;
#define maxsize 5
struct SeqStack{
	int data[maxsize];
	int top;
};

SeqStack S;

bool empty(SeqStack &S) {//判断栈指针是-1，如果是就是空栈
	return S.top == -1;
}

void Seqstack(SeqStack &S) {//传一个指针进去
	S.top = -1;//操纵堆区对象指针指向-1
	cout << "已建新栈" << endl;
}

void Push(SeqStack &S, int value) {//传入一个指针和一个数值
	if (S.top == maxsize - 1) {
		cout << "本栈已满，数据不予压入" << endl;
		return;
	}
	cout << "压入 " << value;
	S.data[++S.top] = value;//先加加在赋值
	cout << "  当前指针为"<<S.top << " " << endl;
}

int  Pop(SeqStack &S) {//传入一个引用
	if (empty(S)) {//判断是否空栈
		cout << "栈空，无数据" << endl;
		return 0;
	}
	cout << "弹出 " << S.data[S.top];
	cout << "  当前指针为 " << S.top-1 << endl;
	return S.data[S.top--];//先传值再减减
}

int GetTop(SeqStack &S) {//得到栈顶指针指向的值
	if (empty(S)) {//判断是否空栈
		cout << "栈空，无数据" << endl;
		return 0;
	}
	cout << "栈顶数据为 "<<S.data[S.top] << endl;;
	return S.data[S.top];//得到当前指针指向的值
}

void test() {
	cout << "1.元素入栈" << endl;
	cout << "2.元素出栈" << endl;
	cout << "3.查询栈顶元素值" << endl;
	cout << "4.初始化顺序栈" << endl;

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
			cout << "输入的数据有误请重新输入" << endl;
			break;
		}
	}
}

int main() {
	test();
}