#pragma once
#include<iostream>
#include<string>
using namespace std;
#define RED true
#define BLACK false


//节点定义
struct Node {
	string key;//唯一键值，标识节点的唯一性
	int val; //节点的值
	Node* left;//左节点
	Node* right;//右节点
	int N;//记录当前节点个数的标识
	bool color;//标识当前节点的颜色  true RED  false BLACK
	//初始化定义构造结构体
	Node(string key, int val, int N, bool color) {
		this->key = key;
		this->val = val;
		this->N = N;
		this->color = color;
		this->left = nullptr;
		this->right = nullptr;
	}
};

//红黑树类
class RBtree
{
private:
	Node * root = nullptr;//初始化当前根节点为空
	bool isRed(Node* node);//判断当前节点是否为空
	int size(Node* node);//计算以node为根节点的树的节点个数

public:
	//定义获取私有变量的方法，返回自己本身的当前节点
	Node* getroot();
	//左旋
	Node* rotateLeft(Node* h);
	//右旋
	Node* rotateRight(Node* h);
	//改变颜色，当左右子节点都为红的时候进行
	void filpColors(Node* h);
	//向RB树当中插入元素
	void put(string key, int val);
	//元素插入后会产生后续影响，继续向上伪插入操作
	Node* put(Node* h, string key, int val);
	//中序遍历
	void Inorder(Node* h);
};

