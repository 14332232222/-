#include <iostream>
using namespace std;

struct Node;
struct LinkQueue{//封装一个链队列结构体
	Node* front;
	Node* rear;
};

struct Node {//封装一个节点结构体
	Node* next;//元素指针域
	int data;//元素数据域
};

bool empty(LinkQueue*tmp) {
	return tmp->front == NULL;//头指针指向空时可认为是空列表
}

void Clear(LinkQueue*tmp) {//清空链队列函数
	Node* p;
	while (tmp->front != NULL) {
		p = tmp->front;
		tmp->front = tmp->front->next;
		delete p;
	}
	tmp->rear = NULL;
	cout << "队列已清空" << endl;
}

int Size(LinkQueue*tmp) {//查询链队列长度
	Node* p = tmp->front;
	int count = 0;//计数变量初始化为0
	while (p) {
		count++;//计数值增加
		p = p->next;//临时指针向下一个节点位移
	}
	cout << "队列长度为 " << count << endl;
	return count;
}
void EnQueue(LinkQueue*tmp,int x) {//入列函数
	if (tmp->rear == NULL) {//当rear指针置空时（队列没元素时）
		tmp->front = tmp->rear = new Node();//front和rear指向新节点
		tmp->front->data = x;
		cout << x << " 入列" << endl;
	}
	else {//此时队列有元素
		tmp->rear->next = new Node();//尾指针指向节点的next指针指向新节点
		tmp->rear->next->data = x;
		tmp->rear = tmp->rear->next;
		cout << x << " 入列" << endl;
	}
}

int  DeQueue(LinkQueue*tmp) {//出列函数
	if (empty(tmp)) {
		cout << "队列为空，无元素可出列" << endl;
		return 0;
	}
	Node* p = tmp->front;
	int value = tmp->front->data;
	tmp->front = tmp->front->next;
	if (tmp->front == NULL)//当唯一元素出列后，队列无元素，首节点和尾节点都置空
		tmp->rear == NULL;
	delete p;
	cout << value << " 出列" << endl;
	return value;
}

int GetHead(LinkQueue* tmp) {//得到队首元素值
	if (empty(tmp)) {
		cout << "队列为空，无元素" << endl;
		return 0;
	}
	cout << "队首元素值为 " << tmp->front->data<<endl;
	return tmp->front->data;
}

LinkQueue* CreateLinkQueue() {//初始化链式队列
	LinkQueue* tmp = new LinkQueue();//分配空间
	tmp->front == NULL;//头指针置空
	tmp->rear == NULL;//尾指针置空
	cout << "已创建新队列" << endl;
	return tmp;
}

void test() {
	LinkQueue* lq1=NULL;
	cout << "1.创建新链式队列" << endl;
	cout << "2.元素入列" << endl;
	cout << "3.元素出列" << endl;
	cout << "4.查询链式队列长度" << endl;
	cout << "5.查询队首元素值" << endl;
	cout << "6.清空链式队列" << endl;
	cout << "7.结束操作" << endl;
	cout << endl;

	bool j = true;
	while (j) {
		cout << "请输入操作序号：";
		int in;
		cin >> in;
		switch (in) {
			case 1:
				lq1 = CreateLinkQueue();
				break;
			case 2:
				int data;
				cout << "请输入入列元素值：";
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
				cout << "输入的数据有误请重新输入" << endl;
				break;
		}
	}
}

int main() {
	test();
}
