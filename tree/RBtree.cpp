#include "RBtree.h"

bool RBtree::isRed(Node * node)
{
	//Ϊ�յ�ʱ��Ż�false����Ӱ������ж�
	//��Ϊ��ɫ�ڵ㲻��Ӱ�������ת
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
	x->color = h->color;//����ԭ��λ�õĽڵ����ɫ����
	h->color = RED;//��ɫҲ��ת��һ��
	x->N = h->N;
	h->N = 1 + size(h->right) + size(h->right);
	return x;
}

Node * RBtree::rotateRight(Node * h)
{
	Node * x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;//����ԭ��λ�õĽڵ����ɫ����
	h->color = RED;//��ɫҲ��ת��һ��
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
	//���ҽڵ���õ�λ�ã�������
	root = put(root, key, val);//��ͷ��root����ʼ��
	//�����ܸ��µ����ڵ㣬���Կ��ܸ���root
	root->color = BLACK;
}

Node * RBtree::put(Node * h, string key, int val)
{
	//�ߵ�Ҷ�ӽڵ㣬���Ԫ��
	if (h == nullptr) {
		return new Node(key,val,1,RED);
	}
	//ͨ���Ƚϵ�ǰ�ڵ��keyֵ��ѡ����õ�λ��
	int cmp = key.compare(h->key);
	//����ڵ�С����һ���ڵ㣬�Ͳ�����ڵ㣬֮����к����ĸ��²���
	if (cmp < 0) {
		h->left = put(h->left, key, val);
	}
	//����ڵ������һ���ڵ㣬�Ͳ����ҽڵ㣬��������и��²���
	else if (cmp > 0) {
		h->right = put(h->right, key, val);
	}
	//�����Ⱦ͸���ֵ
	else {
		h->val = val;
	}
	//�������Ǻ�ɫ�����������Ǻ�ɫ��Ҫ����
	//��ɫ�ڵ��Ǹ��׽ڵ��ɫ�ڵ������ӽڵ�
	if (isRed(h->right) && !isRed(h->left)) {
		//��ת����Ľڵ�������һ���ڵ�
		h = rotateLeft(h);
	}
	//ת����֮����ܻ����������ɫ���������������
	//�������ж�
	if (isRed(h->left) && isRed(h->left->left)) {
		//���������Ҫ����
		h = rotateRight(h);
		//����֮����ܻ������Ҫ��ɫת�������
	}
	//������߶��Ǻ�ɫ����Ҫ������ɫת��
	if (isRed(h->left) && isRed(h->right)) {
		filpColors(h);
	}
	h->N = size(h->left) + size(h->right) + 1;
	return h;
}

void RBtree::Inorder(Node * h)
{//�������
	if (h == nullptr)return;
	Inorder(h->left);
	cout << h->key << "	" 
		<< h->val << "	"
		<< (h->color == 1 ? "��" : "��") << endl;
	Inorder(h->right);
}
