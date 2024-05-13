#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};

struct Stack{
    NODE *pTop;
};

void Initialize(Stack &s){
    s.pTop = NULL;
}

bool isEmpty(Stack s){
    return s.pTop == NULL;
}

void Push(Stack &s, char x){
    NODE *p = new NODE;
    if(p == NULL) exit(1);
    p->info = x;
    p->pNext = s.pTop;
    s.pTop = p;
}

char Pop(Stack &s){
    if(isEmpty(s)) return '#';
    NODE *p = s.pTop;
    char x = p->info;
    s.pTop = p->pNext;
    delete p;
    return x;
}

bool precedence(char a, char b){
    int precA = (a == '^') ? 3 : (a == '*' || a == '/' || a == '%') ? 2 : (a == '+' || a == '-') ? 1 : 0;
    int precB = (b == '^') ? 3 : (b == '*' || b == '/' || b == '%') ? 2 : (b == '+' || b == '-') ? 1 : 0;
    return precA >= precB;
}

void Input_infix(char *infix, int &ni){
    ni = 0;
    while (true){
        char c; cin >> c;
        if (c == '#') break;
        infix[ni++] = c;
    }
}

void infix_to_postfix(char *infix, int ni, char* postfix, int &np){
    np = 0;
    Stack s;
    Initialize(s);
    for (int i = 0; i < ni; i++){
        if (isdigit(infix[i])) {
            postfix[np++] = infix[i];
        } 
        else if (infix[i] == '(') {
            Push(s, infix[i]);
        } 
        else if (infix[i] == ')'){
            while (!isEmpty(s) && s.pTop->info != '('){
                postfix[np++] = Pop(s);
            }
            if (!isEmpty(s)) Pop(s);
        } 
        else {
            while (!isEmpty(s) && precedence(s.pTop->info, infix[i])){
                postfix[np++] = Pop(s);
            }
            Push(s, infix[i]);
        }
    }
    while (!isEmpty(s)) { 
        postfix[np++] = Pop(s);
    }
}

void Output(char *postfix, int np){ 
    for (int i = 0; i < np; i++) cout << postfix[i] << " ";
}

int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
