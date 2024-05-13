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

TNODE* FindMin(TREE T){
	if (T == NULL) return NULL;
	while (T->pLeft != NULL){
		T = T->pLeft;
	}
	return T;
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << FindMax(T)->key;
	return 0;
}
