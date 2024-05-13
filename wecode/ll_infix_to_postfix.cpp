#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};

NODE *CreateNode(char x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}
struct stack{
    NODE *top;
};
bool empty(const stack &s){
    return (s.top==NULL);
}
void CreateEmptyStack(stack &s){
    s.top=NULL;
}
void push(stack &s, char x){
    NODE *p=CreateNode(x);
    if(s.top==NULL) s.top= p;
    else {
        p->pNext=s.top;
        s.top=p;
    }
}
void pop (stack &s) {
    if(s.top==NULL) return;
    NODE *p= s.top;
    s.top=p->pNext;
    delete p;
}
char& top(stack s) {
    return s.top->info;
}

void printStack(stack s) {
    NODE* temp = s.top;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->pNext;
    }
    cout << endl;
}

void Input_infix(char *infix, int &ni){
    ni = 0;
    while (true){
        char c; cin >> c;
        if (c == '#') break;
        infix[ni++] = c;
    }
}

bool precedence(char a, char b){
    int precA = (a == '^') ? 3 : (a == '*' || a == '/' || a == '%') ? 2 : (a == '+' || a == '-') ? 1 : 0;
    int precB = (b == '^') ? 3 : (b == '*' || b == '/' || b == '%') ? 2 : (b == '+' || a == '-') ? 1 : 0;
    if (a == '(') precA = -1;
    if (b == '(') precB = -1;
    return (precA >= precB);
}

void infix_to_postfix(char *infix, int ni, char* postfix, int &np){
    np = 0;
    stack s;
    CreateEmptyStack(s);
    for (int i = 0; i < ni; i++){
        if (isdigit(infix[i])) {
            postfix[np++] = infix[i];
        } 
        else if (infix[i] == '(') {
            push(s, infix[i]);
        } 
        else if (infix[i] == ')'){
            while (!empty(s) && top(s) != '('){
                postfix[np++] = top(s);
                pop(s);
            }
            if (!empty(s)) pop(s); 
        } 
        else {
            while (!empty(s) && precedence(top(s), infix[i])){
                postfix[np++] = top(s);
                pop(s);
            }
            push(s, infix[i]);
        }
    }
    while (!empty(s)) { 
        postfix[np++] = top(s);
        pop(s);
    }
}

void Output(char *postfix, int np){ 
    for (int i = 0; i < np; i++) cout << postfix[i] << " ";
}
//###INSERT CODE HERE -

int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
