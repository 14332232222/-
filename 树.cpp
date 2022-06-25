#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct BtNode {
	int data;
	BtNode* left;
	BtNode* right;
};
//函数声明
BtNode* preCreateBiTree();
void preOrderTraversal();
void inOrderTraversal();
void postOrderTraversal();
void preOrderTraversal_stack();
void inOrderTraversal_stack();
void postOrderTraversal_stack();
void levelOrderTraversal();

//递归先序
void preOrderTraversal(BtNode*root) {//先序遍历
	if (root == NULL) {
		return;
	}
	cout << root->data << ' ';
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
//递归中序
void inOrderTraversal(BtNode* root) {//中序遍历
	if (root == NULL) {
		return;
	}
	inOrderTraversal(root->left);
	cout << root->data << ' ';
	inOrderTraversal(root->right);
}
//递归后续
void postOrderTraversal(BtNode* root) {//后续遍历
	if (root == NULL) {
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << ' ';
}
//栈先序
void preOrderTraversal_stack(BtNode*root) {
	if (NULL == root)return;
	stack<BtNode*>s;
	s.push(root);
	BtNode *p = NULL;
	while (!s.empty()) {
		p = s.top();
		cout << p->data << " ";
		s.pop();
		if (p->right != NULL)s.push(p->right);
		if (p->left != NULL)s.push(p->left);
	}
	cout << endl;
}
//栈中序
void inOrderTraversal_stack(BtNode*root) {
	if (NULL == root)
		return;
	stack<BtNode*>s;
	BtNode *c = root;
	BtNode *p = NULL;
	while (!s.empty() || c) {
		while (c && c != p) {
			s.push(c);
			c = c->left;
		}
		if (s.empty())
			return;
		c = s.top();
		cout << c->data << " ";
		p = c;
		s.pop();
		c = c->right;
	}
	cout << endl;
}
//栈后序
void postOrderTraversal_stack(BtNode*root) {
	if (NULL == root)return;
	stack<BtNode*> s;
	s.push(root);
	BtNode *c = root->left;
	BtNode *p = NULL;
	while (!s.empty()) {
		while (c && c != p) {
			s.push(c);
			c = c->left;
		}
		if (s.empty())
			return;
		c = s.top();
		if (c->right && c->right != p) {
			c = c->right;
		}
		else {
			cout << c->data << " ";
			p = c;
			s.pop();
		}
	}
	cout << endl;
}
//层序
void levelOrderTraversal(BtNode* root) {//层序遍历
	if (root == NULL) {
		cout << "树为空，无数据" << endl;
		return;
	}
	queue<BtNode*>Q;
	BtNode* p = root;//临时指针p指向根节点
	if (p != NULL) Q.push(p);//指针p入队
	while (!Q.empty()) {
		BtNode* current = Q.front();//队首元素为指针p，指针current也指向了根节点
		cout << current->data << " ";
		Q.pop();//访问完即出队
		if (current->left != NULL) Q.push(current->left);//左节点不为空则将左节点入队
		if (current->right != NULL) Q.push(current->right);//右节点同理
	}
}
//创建
BtNode* preCreateBiTree() {//先序创建二叉树
	int value;
	cin >> value;
	BtNode* p;
	if (value == -1) {//退出递归条件,输入-1则退出
		return NULL;//返回空指针
	}
	else{
		p = new BtNode();
		p->data = value;//赋值

		cout << "请输入左子树：" << endl;
		p->left = preCreateBiTree();
		cout << "请输入右子树：" << endl;
		p->right = preCreateBiTree();
		return p;//返回根节点
	}
}

int main() {
	BtNode* s = NULL;//创建树指针
	while (true) {
		cout << "1、先序创建二叉树" << endl;
		cout << "2、先序遍历二叉树" << endl;
		cout << "3、中序遍历二叉树" << endl;
		cout << "4、后序遍历二叉树" << endl;
		cout << "5、非递归先序遍历二叉树" << endl;
		cout << "6、非递归中序遍历二叉树" << endl;
		cout << "7、非递归后序遍历二叉树" << endl;
		cout << "8、层序遍历二叉树" << endl;
		cout << "-1、退出程序" << endl;
		cout << "请选择操作类型：" << endl;
		int sel;
		cin >> sel;
		switch (sel) {
		case 1:
			cout << "输入根节点值：" << endl;
			s = preCreateBiTree();
			break;
		case 2:
			preOrderTraversal(s);
			cout << endl;
			break;
		case 3:
			inOrderTraversal(s);
			cout << endl;
			break;
		case 4:
			postOrderTraversal(s);
			cout << endl;
			break;
		case 5:
			preOrderTraversal_stack(s);
			cout << endl;
			break;
		case 6:
			inOrderTraversal_stack(s);
			cout << endl;
			break;
		case 7:
			postOrderTraversal_stack(s);
			cout << endl;
			break;
		case 8:
			levelOrderTraversal(s);
			cout << endl;
			break;
		case -1:
			exit(-1);//退出程序
		}
	}
}