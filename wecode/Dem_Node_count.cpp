/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
static
###End banned keyword*/
#include <bits/stdc++.h>

using namespace std;
struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

void CreateEmptyTree(TREE &T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}
void CreateTree(TREE &T){
	int x;
	do {
		cin >> x;
		if(x==-1) break;
		Insert(T, CreateTNode(x));
	}while(true);
}

//###INSERT CODE HERE -
void Count(TREE T, int &count){
	if (T){
		if (T->pLeft != NULL) Count(T->pLeft, count);
		if (T->pRight != NULL) Count(T->pRight, count);
		count++;
	}
}

void CountNode(TREE T, int &count){
	Count(T, count);
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int count=0;
	CountNode(T, count);
	cout << count;
	return 0;
}
