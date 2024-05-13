/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
using namespace std;

struct NODE{
	int value;
	NODE *pNext;
};

NODE* CreateNode(int value){
	NODE *n = new NODE();
	n->value = value;
	n->pNext = NULL;
	return n;
}

void AddHead(NODE *&head, NODE *n){
	if (head == NULL) head = n;
	else{
		n->pNext = head;
		head = n;
	}
}

void CreateList(NODE *&head){
    int i; 
    while (cin >> i && i != -1){
		AddHead(head, CreateNode(i));
    }
}

string searchX(NODE *head, int value){
    NODE *curNode = head;
    while (curNode != NULL){
        if (value == curNode->value) return "true";
        curNode = curNode->pNext;
    }
    return "false";
}

int main() {
    NODE* pHead;
	int X;
	pHead=NULL;

	CreateList(pHead);
	cin >> X;
	cout << searchX(pHead, X);

    return 0;
}
