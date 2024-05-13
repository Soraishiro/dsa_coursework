/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <queue>
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

void PrintLevel(TREE T, int level) {
    if (T == NULL) return;
    if (level == 0) {
        cout << T->key << " ";
    } else if (level > 0) {
        PrintLevel(T->pLeft, level-1);
        PrintLevel(T->pRight, level-1);
    }
}

int main() {
	TNODE* T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	int level;
	cin >> level;
	CreateTree(T);
	PrintLevel(T, level);
	return 0;
}
