#include <iostream>
using namespace std;
struct Node {//元素内的数据域和指针域
	Node* next;
	int data;
};

Node* head; Node* tail;
int curlength;

bool empty() {//判断链表是否为空
	return head->next == NULL;//头节点指针指向NULL
}

void CreateList() {//创建一个只有头节点的链表
	Node* p = new Node();
	p->data = 0;
	p->next = NULL;
	head = p;
	tail = p;
	cout << "已创建新表" << endl;
}

void tailinsert() {//尾插法
	Node* tmp = new Node();
	cout << "输入新节点data: ";
	cin >> tmp->data;//给新节点的数据赋值
	tmp->next = NULL;//给新节点的指针赋值
	tail->next = tmp;//尾指针的节点next指向新节点
	tail = tmp;//尾指针迁移
}
void Clear() {
	Node* p, * tmp;//两个临时指针，tmp用于删节点
	p = head->next;//p指向头节点下一位节点
	while(p != NULL) {//tmp和p通过反复迭代将节点全部删除，最后只剩头节点
		tmp = p;
		p = p->next;
		delete tmp;
	}
	head->next = NULL;//头节点next指针指向NULL
	tail = head;//tail指向head的箭头指向
	curlength = 0;
	cout << "链表已清空" << endl;
}

void Traverse(){
	if (empty()) {
		cout << "链表为空，无数据" << endl;
		return;
	}
	Node* p = head->next;//p指向1号节点
	cout << "result: ";
	while (p != NULL) {//遍历所有节点并打印数据
		cout <<"此链表数据为: " << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

Node* Getposition(int i){
	if ( i < -1 || i > curlength - 1)//判定参数是否合法 
		return NULL;
	Node* p = head;//p指向head所指（头节点）
	int count = 0;
	while (count < i) {//当count递增至i的值时，函数返回p指向的地址（或者说返回p指针）
		p = p->next;
		count++;
	}
	return p;
}

int Search(int value) {
	Node* p = head->next;//指针p指向1号节点
	int count = 0;
	while(p != NULL && p->data != value) {//当p既不指向NULL，p指向的节点data也不是要搜索的参数
		p = p->next;//p移动至下一个节点
		count++;//计数+1
	}
	if(p == NULL)
		return - 1;
	else
		return count;//返回计数值
}

void Insert(int i,int value) {
	Node* p, * q;
	if (i < 0 || i > curlength)//判定参数值在合法范围内
		return ;
	p = Getposition(i - 1);
	q = new Node();
	q->data = value; 
	q->next = p->next;
	p->next = q;
	if (p == tail) 
		tail = q;
	curlength++;//链表长度+1
}

void Delete(int i) {
	Node* pre, * p;
	if (i < 0 || i > curlength)//判定参数值在合法范围内
		return ;
	pre = Getposition(i );//pre指向i号节点
	p = pre->next;//p指向pre所指节点下一个节点
	if(p == tail) {
		tail = pre;
		pre->next = NULL;
		delete p;
	}
	else{
		pre->next = p->next;
		delete p;
	}
	curlength--;//实际长度-1
}

void Inverse() {
	Node* p, * tmp;
	p = head->next;
	head->next = NULL;
	if(p != NULL)
		tail = p;
	while(p != NULL) {
		tmp = p->next;
		p->next = head->next;
		head->next = p;
		p = tmp;
	}
}

int Visit(int i) {
	Node* p = head->next;//p指针指向头节点下一个节点
	int count = 0;
	if (i < 0 || i > curlength-1)//判定参数值在合法范围内
		return 0;
	while(count < i) {
		p = p->next;//p指针移动至下一个节点
		count++;//计数增加
	}
	return p->data;
}
