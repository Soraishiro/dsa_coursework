/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//###INSERT CODE HERE -

TNODE* CreateNode(int x){
	TNODE *newNode = new TNODE;
	newNode->key = x;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;
}

int Insert(TREE& T, int tmp){
	if (T){
		if (tmp == T->key) return 0;
		else if (tmp > T->key) return Insert(T->pRight, tmp);
		else return Insert(T->pLeft, tmp);
	}
	T = CreateNode(tmp);
	return 1;
}

void CreateTree(TREE& T){
	int tmp;
	while(true){
		cin >> tmp;
		if (tmp == -1) break;
		Insert(T, tmp);
	}
}

void SumNODE(TREE T, int& sum){
	if (T){
		SumNODE(T->pLeft, sum);
		sum = sum + T->key;
		SumNODE(T->pRight, sum);
	}
}

int SumNode(TREE T){
	int sum = 0; 
	SumNODE(T, sum);
	return sum;
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << SumNode(T);
	return 0;
}

