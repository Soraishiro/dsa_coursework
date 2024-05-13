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

TNODE* minValueNode(TREE node) {
    TNODE* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->pLeft != NULL)
        current = current->pLeft;

    return current;
}

void DeleteNode(TREE& T, int x){
    if (T == NULL) return;
    if (x < T->key) DeleteNode(T->pLeft, x);
    else if (x > T->key) DeleteNode(T->pRight, x);
    else {
        if (T->pLeft == NULL) {
            TNODE *temp = T->pRight;
            delete T;
            T = temp;  
        } 
		else if (T->pRight == NULL) {
            TNODE *temp = T->pLeft;
            delete T;
            T = temp;  
        } 
		else {   
            TNODE* temp = minValueNode(T->pRight);
            T->key = temp->key;
            DeleteNode(T->pRight, temp->key);
        }
    }
}

void PrintTREE(TREE T){
	if (T){
		cout << T->key << " ";
		PrintTREE(T->pLeft);
		PrintTREE(T->pRight);
	}
}

void PrintTree(TREE T){
	if (T == NULL) cout << "Empty Tree.";
	else PrintTREE(T);
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	DeleteNode(T, x);

	PrintTree(T);
	return 0;
}
