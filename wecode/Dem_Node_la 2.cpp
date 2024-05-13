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

void Count(TREE T, int& count){
    if (T == NULL) return; // If T is NULL, return without doing anything
    if (T->pLeft == NULL && T->pRight == NULL){
        count++;
    }
    else{
        Count(T->pLeft, count);
        Count(T->pRight, count);
    }
}

int CountLeaf(TREE T){
    int count = 0;
    if (T){
        Count(T, count);
    }
    return count; 
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	cout << CountLeaf(T);
	return 0;
}
