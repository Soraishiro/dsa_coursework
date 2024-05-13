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

TNODE* CreateTNode(int x){
	TNODE* newNode = new TNODE;
	newNode->key = x;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	return newNode;
}

int Insert(TREE& T, int x){
	if (T){
		if (x == T->key) return 0;
		else if (x > T->key) return Insert(T->pRight, x);
		else return Insert(T->pLeft, x);
	}
	T = CreateTNode(x);
	return 1;
}

void CreateTree(TREE& T){
	int tmp;
	while (true){
		cin >> tmp;
		if (tmp == -1) break;
		Insert(T, tmp);
	}
}

void CountLeaf(TREE T, int& count){
    if (T){
        if (T->pLeft == NULL && T->pRight == NULL) {
            count++;
        } else {
            CountLeaf(T->pLeft, count);
            CountLeaf(T->pRight, count);
        }
    }
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int count =0;
	CountLeaf(T, count);
	cout << count;
	return 0;
}
