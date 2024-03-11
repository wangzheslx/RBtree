#pragma once
#include<iostream>
#include<string>
using namespace std;
#define RED true
#define BLACK false


//�ڵ㶨��
struct Node {
	string key;//Ψһ��ֵ����ʶ�ڵ��Ψһ��
	int val; //�ڵ��ֵ
	Node* left;//��ڵ�
	Node* right;//�ҽڵ�
	int N;//��¼��ǰ�ڵ�����ı�ʶ
	bool color;//��ʶ��ǰ�ڵ����ɫ  true RED  false BLACK
	//��ʼ�����幹��ṹ��
	Node(string key, int val, int N, bool color) {
		this->key = key;
		this->val = val;
		this->N = N;
		this->color = color;
		this->left = nullptr;
		this->right = nullptr;
	}
};

//�������
class RBtree
{
private:
	Node * root = nullptr;//��ʼ����ǰ���ڵ�Ϊ��
	bool isRed(Node* node);//�жϵ�ǰ�ڵ��Ƿ�Ϊ��
	int size(Node* node);//������nodeΪ���ڵ�����Ľڵ����

public:
	//�����ȡ˽�б����ķ����������Լ�����ĵ�ǰ�ڵ�
	Node* getroot();
	//����
	Node* rotateLeft(Node* h);
	//����
	Node* rotateRight(Node* h);
	//�ı���ɫ���������ӽڵ㶼Ϊ���ʱ�����
	void filpColors(Node* h);
	//��RB�����в���Ԫ��
	void put(string key, int val);
	//Ԫ�ز������������Ӱ�죬��������α�������
	Node* put(Node* h, string key, int val);
	//�������
	void Inorder(Node* h);
};

