/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

struct Node{
    char info;
    Node *pNext;
};

struct LIST{
    Node *pHead;
    Node *pTail;
};

void CreateEmptyList(LIST &L){
    L.pHead = NULL;
    L.pTail = NULL;
}

Node* CreateNode(char c)
{
    Node *p = new Node;
    if (p == NULL) exit(1);
    p->info = c;
    p->pNext = NULL;
    return p;
}

void AddHead(LIST &L, char c){
    Node *p = CreateNode(c);
    if (L.pHead == NULL){
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else{
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

void CreateList(LIST &L){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        AddHead(L, c);
    }
}

void RemoveHead(LIST &L){
    if (L.pHead == NULL) return;
    else{
        Node *p;
        p = L.pHead;
        L.pHead = L.pHead->pNext;
        if (L.pHead == NULL) L.pTail = NULL;
        delete p;
    }   
}

void PrintList(LIST L){
    Node *curNode = L.pHead;
    if (curNode == NULL) cout << "Empty List.";
    while (curNode != NULL){
        cout << curNode->info << " ";
        curNode = curNode->pNext;
    }
}
//###INSERT CODE HERE -

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
	RemoveHead(L);
    PrintList(L);

    return 0;
}
