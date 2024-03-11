#include "tree.h"

tree::tree(vector<int>vec) {
	if (vec.size() == 0)return;
	root = new Node(vec[0]);
	for (int i = 1; i < vec.size(); i++) {
		Node*p = root;
		Node*newNode = new Node(vec[i]);
		while (1) {
			if (p->key < vec[i]) {
				if (p->right == NULL) {
					p->right = newNode;
					break;
				}
				p = p->right;
			}
			if (p->key > vec[i]) {
				if (p->left == NULL) {
					p->left = newNode;
					break;
				}
				p = p->left;
			}
			if (p->key == vec[i]) {
				return;
			}
		}
	}
}
void tree::LevelOrder() {
	if (root == NULL)return;
	queue<Node*>que;
	que.push(root);
	while (!que.empty()) {
		int n = que.size();
		for (int i = 0; i < n; i++) {
			Node* front = que.front();
			cout << front->key<<" ";
			que.pop();
			if (front->left)que.push(front->left);
			if (front->right)que.push(front->right);
		}
		cout << endl;
	}
}
void tree::PreOrder() {
	if (root == NULL)return;
	stack<Node*>stk;
	stk.push(root);
	while (!stk.empty()) {
		Node*nop = stk.top();
		stk.pop();
		cout << nop->key << " ";
		if (nop->right)stk.push(nop->right);
		if (nop->left)stk.push(nop->left);
	}
	}
void tree::PostOrder() {
		if (root == NULL) return;
		stack<Node*>s1, s2;
		s1.push(root);
		while (!s1.empty()) {
			Node*p = s1.top();
			s1.pop();
			s2.push(p);
			if (p->left)s1.push(p->left);
			if (p->right)s1.push(p->right);
		}
		while (s2.size()) {
			cout << s2.top()->key << " ";
			s2.pop();
		}

	}
void tree::InOrder() {
	if (root == NULL)return;
	stack <Node*>stk;
	Node* cur = root;
	while (!stk.empty() || cur) {
		while (cur) {
			stk.push(cur);
			cur = cur->left;
		}
		Node* top = stk.top();
		cout << stk.top()->key << " ";
		stk.pop();
		cur = top->right;
	}
}
