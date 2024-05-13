/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

void CreateEmptyList(LIST &L){
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int n)
{
    NODE *p = new NODE();
    p->info = n;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &L, int n){
    NODE *p = CreateNode(n);
    if (L.pHead == NULL){
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else{
        L.pTail->pNext = p;
		p->pNext = L.pTail;
    }
}

void CreateList(LIST &L){
	int n;
    while (cin >> n){
		AddHead(L, n);
	}
}

void PrintList(LIST &L){
    NODE *curNode = L.pHead;
    if (curNode == NULL) cout << "Empty List.";
    while (curNode != NULL){
        cout << curNode->info << " ";
        curNode = curNode->pNext;
    }
	cout << endl;
}

bool isSorted(NODE* head) {
    NODE *curNode = head;
    while (curNode != NULL && curNode->pNext != NULL) {
        if (curNode->info > curNode->pNext->info) {
            return false;
        }
        curNode = curNode->pNext;
    }
    return true;
}
//###INSERT CODE HERE -

int main() {
    LIST *L=new LIST;

	CreateEmptyList(*L);
	CreateList(*L);
	PrintList(*L);
	cout << boolalpha << isSorted(L->pHead);

    return 0;
}