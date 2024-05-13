/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

struct NODE{
    int value;
    NODE *pNext;
};

struct stack{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNode(int value){
    NODE *n = new NODE();
    n->value = value;
    n->pNext = NULL;
    return n;
}

void pop(stack &s){
    NODE *p;
    if (s.pHead != NULL){
        cout << s.pHead->value << " ";
        p = s.pHead;
        s.pHead = s.pHead->pNext;
        if (s.pHead == NULL) s.pTail = NULL;
        delete p;
    }
}

void push(stack &s, int value){
    NODE *n = CreateNode(value);
    if (s.pHead == NULL){
        s.pHead = n;
        s.pTail = n;
    }
    else{
        n->pNext = s.pHead;
        s.pHead = n;
    }
}

void Testing_Push_Pop_Top_Stack(stack &s){
    cout << "output: ";
    int i; 
    while (cin >> i){
        if (i == -1){
            cout << endl << "top: ";
            if (s.pHead != NULL) cout << s.pHead->value;
            return;
        }
        else if (i == 0) pop(s);
        else push(s, i);
    }
}

//###INSERT CODE HERE -

int main() {
    stack s;
	Testing_Push_Pop_Top_Stack(s);
    return 0;
}
