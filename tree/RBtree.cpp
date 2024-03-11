#include "RBtree.h"

bool RBtree::isRed(Node * node)
{
	//为空的时候放回false不会影响后续判断
	//因为黑色节点不会影响如何旋转
	if (node == nullptr)return false;
	else return node->color == RED;
}

int RBtree::size(Node * node)
{
	if (node == nullptr)
		return 0;
	else if (node->left == nullptr && node->right == nullptr)
		return 1;
	else if (node->left == nullptr)
		node->N = node->right->N + 1;
	else if (node->right == nullptr)
		node->N = node->left->N + 1;
	else
		node->N = node->left->N + node->right->N + 1;
	return node->N;
}

Node * RBtree::getroot()
{
	return root;
}

Node * RBtree::rotateLeft(Node * h)
{
	Node* x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;//让它原来位置的节点的颜色不变
	h->color = RED;//颜色也旋转了一下
	x->N = h->N;
	h->N = 1 + size(h->right) + size(h->right);
	return x;
}

Node * RBtree::rotateRight(Node * h)
{
	Node * x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;//让它原来位置的节点的颜色不变
	h->color = RED;//颜色也旋转了一下
	x->N = h->N;
	h->N = 1 + size(h->left) + size(h->right);
	return x;
}

void RBtree::filpColors(Node * h)
{
	h->color = RED;
	h->left->color = BLACK;
	h->right->color = BLACK;
}

void RBtree::put(string key, int val)
{
	//查找节点放置的位置，并更新
	root = put(root, key, val);//从头（root）开始找
	//最后可能更新到根节点，所以可能更新root
	root->color = BLACK;
}

Node * RBtree::put(Node * h, string key, int val)
{
	//走到叶子节点，添加元素
	if (h == nullptr) {
		return new Node(key,val,1,RED);
	}
	//通过比较当前节点的key值来选择放置的位置
	int cmp = key.compare(h->key);
	//如果节点小于上一个节点，就插入左节点，之后进行后续的更新操作
	if (cmp < 0) {
		h->left = put(h->left, key, val);
	}
	//如果节点大于上一个节点，就插入右节点，后续会进行更新操作
	else if (cmp > 0) {
		h->right = put(h->right, key, val);
	}
	//如果相等就更新值
	else {
		h->val = val;
	}
	//右子树是红色但是左子树是黑色就要左旋
	//黑色节点是父亲节点红色节点是左子节点
	if (isRed(h->right) && !isRed(h->left)) {
		//将转换后的节点分配给上一个节点
		h = rotateLeft(h);
	}
	//转换完之后可能会出现两个红色子树相连的情况，
	//做如下判断
	if (isRed(h->left) && isRed(h->left->left)) {
		//这总情况就要右旋
		h = rotateRight(h);
		//右旋之后可能会出现需要颜色转换的情况
	}
	//如果两边都是红色，就要进行颜色转化
	if (isRed(h->left) && isRed(h->right)) {
		filpColors(h);
	}
	h->N = size(h->left) + size(h->right) + 1;
	return h;
}

void RBtree::Inorder(Node * h)
{//中序遍历
	if (h == nullptr)return;
	Inorder(h->left);
	cout << h->key << "	" 
		<< h->val << "	"
		<< (h->color == 1 ? "红" : "黑") << endl;
	Inorder(h->right);
}
