#include <iostream>
using namespace std;
#define maxsize 10

struct Queue {
	int* base; // 初始化的动态分配存储空间
	int front; // 头指针，若队列不空，指向队列头元素
	int rear; // 尾指针，若队列不空，指向队列尾元素的下一个位置
};

bool empty(Queue*tmp) {
	return tmp->front == tmp->rear;
}

Queue* SeqQueue() {//用于构造新队列
	Queue* q = new Queue();//q指向堆区的quene实例对象
	q->base = new int[maxsize];//base指针指向数组
	q->front = q->rear = 0;//front和rear都置为0
	cout << "新队列已构造" << endl;
	return q;//返回一个q指针
}

void EnQueue(Queue* tmp,int x) {
	if ((tmp->rear + 1) % maxsize == tmp->front) {//若rear+1后与front相同就返回
		cout << "队列已满，无法入队" << endl;
		return;
	}
	tmp->rear = (tmp->rear + 1) % maxsize;//尾指针+1
	tmp->base[tmp->rear] = x;//参数值赋给rear所在下标
	cout << x << " 入队" << endl;
}

int DeQueue(Queue* tmp) {
	if (empty(tmp)) {//判断是否空队，空队则返回
		cout<<"队列为空，无数据" << endl;
		return 0;
	}
	tmp->front = (tmp->front + 1) % maxsize;//front指针+1
	cout << tmp->base[tmp->front]<<" 出队" << endl;
	return tmp->base[tmp->front];

}

int GetHead(Queue* tmp) {
	if (empty(tmp)) {//空队判断
		cout << "队列为空，无数据" << endl;
		return 0;
	}
	cout << "队列首元素为 " << tmp->base[(tmp->front + 1) % maxsize] << endl;
	return tmp->base[(tmp->front + 1) % maxsize];//返回front指针+1后的下标元素值
}

void PrintQueue(Queue*tmp) {
	int p = tmp->front;//创建一个变量p接收front指针值
	cout << "队列中元素为：";
	while (tmp->rear != p) {//循环条件：p不等于rear指针
		p = (p + 1) % maxsize;//指针p+1
		cout<< tmp->base[p] << " ";//打印p指向的数组下标
	}
	cout << endl;
}

void Clear(Queue*tmp) {
	delete tmp->base;
	delete tmp;
	cout << "顺序队列已清空" << endl;
}
void test() {
	Queue* lq2 = NULL;
	cout << "1.创建新顺序队列" << endl;
	cout << "2.元素入列" << endl;
	cout << "3.元素出列" << endl;
	cout << "4.查询队首元素值" << endl;
	cout << "5.清空顺序队列" << endl;
	cout << "6.打印顺序队列" << endl;
	cout << "7.结束操作" << endl;

	cout << endl;

	bool j = true;
	while (j) {
		cout << "请输入操作序号：";
		int in;
		cin >> in;
		switch (in) {
		case 1:
			lq2 = SeqQueue();
			break;
		case 2:
			int data;
			cout << "请输入入列元素值：";
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
			cout << "输入的数据有误请重新输入" << endl;
			break;
		}
	}
}

int main() {
	test();
}
