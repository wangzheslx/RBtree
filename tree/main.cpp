//#include"tree.h"
#include "RBtree.h"
int main() {

	/*vector<int> vec = { 7,5,4,6,11,9,10 };
	tree *t = new tree(vec); 
	t->LevelOrder();
	t->PreOrder();
	t->PostOrder();
	t->InOrder();*/
	RBtree b;
	b.put("s", 1);
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;

	b.put("e", 2);
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;

	b.put("a",2 );
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;

	b.put("r",3 );
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;

	b.put("c",4 );
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;

	b.put("h",5 );
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;

	b.put("x",6 );
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;

	b.put("m",7 );
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;

	b.put("p",8 );
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;

	b.put("l", 9);
	b.Inorder(b.getroot());
	cout << endl;
	cout << endl;


	return 0;
}