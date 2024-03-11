#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct  Node {
	int key;
	Node* left = NULL;
	Node* right = NULL;
	Node(int k) {
		key = k;
	}
};
class tree
{
	Node* root = NULL;
public:
	tree(vector<int>vec);

	void LevelOrder();
	void PreOrder();
	void PostOrder();
	void InOrder();

	void Pre_Order(Node* root) {
		if (root == NULL)return;
		cout << root << " ";
		Pre_Order(root->left);
		Pre_Order(root->right);
	}
	void In_Order(Node* root) {
		if (root == NULL)return;
		In_Order(root->left);
		cout << root << " ";
		In_Order(root->right);
	}
	void Post_Order(Node* root) {
		if (root == NULL)return;
		Post_Order(root->left);
		Post_Order(root->right);
		cout << root << " ";
	}

	Node* getroot() { return root; }
};

