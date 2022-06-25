#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct BtNode {
	int data;
	BtNode* left;
	BtNode* right;
};
//��������
BtNode* preCreateBiTree();
void preOrderTraversal();
void inOrderTraversal();
void postOrderTraversal();
void preOrderTraversal_stack();
void inOrderTraversal_stack();
void postOrderTraversal_stack();
void levelOrderTraversal();

//�ݹ�����
void preOrderTraversal(BtNode*root) {//�������
	if (root == NULL) {
		return;
	}
	cout << root->data << ' ';
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
//�ݹ�����
void inOrderTraversal(BtNode* root) {//�������
	if (root == NULL) {
		return;
	}
	inOrderTraversal(root->left);
	cout << root->data << ' ';
	inOrderTraversal(root->right);
}
//�ݹ����
void postOrderTraversal(BtNode* root) {//��������
	if (root == NULL) {
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << ' ';
}
//ջ����
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
//ջ����
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
//ջ����
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
//����
void levelOrderTraversal(BtNode* root) {//�������
	if (root == NULL) {
		cout << "��Ϊ�գ�������" << endl;
		return;
	}
	queue<BtNode*>Q;
	BtNode* p = root;//��ʱָ��pָ����ڵ�
	if (p != NULL) Q.push(p);//ָ��p���
	while (!Q.empty()) {
		BtNode* current = Q.front();//����Ԫ��Ϊָ��p��ָ��currentҲָ���˸��ڵ�
		cout << current->data << " ";
		Q.pop();//�����꼴����
		if (current->left != NULL) Q.push(current->left);//��ڵ㲻Ϊ������ڵ����
		if (current->right != NULL) Q.push(current->right);//�ҽڵ�ͬ��
	}
}
//����
BtNode* preCreateBiTree() {//���򴴽�������
	int value;
	cin >> value;
	BtNode* p;
	if (value == -1) {//�˳��ݹ�����,����-1���˳�
		return NULL;//���ؿ�ָ��
	}
	else{
		p = new BtNode();
		p->data = value;//��ֵ

		cout << "��������������" << endl;
		p->left = preCreateBiTree();
		cout << "��������������" << endl;
		p->right = preCreateBiTree();
		return p;//���ظ��ڵ�
	}
}

int main() {
	BtNode* s = NULL;//������ָ��
	while (true) {
		cout << "1�����򴴽�������" << endl;
		cout << "2���������������" << endl;
		cout << "3���������������" << endl;
		cout << "4���������������" << endl;
		cout << "5���ǵݹ��������������" << endl;
		cout << "6���ǵݹ��������������" << endl;
		cout << "7���ǵݹ�������������" << endl;
		cout << "8���������������" << endl;
		cout << "-1���˳�����" << endl;
		cout << "��ѡ��������ͣ�" << endl;
		int sel;
		cin >> sel;
		switch (sel) {
		case 1:
			cout << "������ڵ�ֵ��" << endl;
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
			exit(-1);//�˳�����
		}
	}
}