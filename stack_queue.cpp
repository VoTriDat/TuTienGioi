#include <iostream>
using namespace std;
struct Node{
    int info;
    Node *link;
};
struct Stack{
    Node *head;
};
void init(Stack &s){
    s.head = NULL;
}
Node *taoNode(int x){
    Node *p = new Node();
    if(p ==NULL) return NULL;
    p ->info = x;
    p->link = NULL;
    return p;
}
bool isEmpty(Stack s){
    return s.head == NULL;
}
void push(Stack &s, int x){
    Node *p = taoNode(x);
    if(p == NULL) return;
    else{
        p->link = s.head;
        s.head = p;
    }
}
void pop(Stack &s){
    if(s.head == NULL) return;
    else{
        Node *p = s.head;
        s.head = s.head -> link;
        delete p;
    }
}
void display(Stack s){
    if (isEmpty(s)){
        cout << "Stack rong";
    } 
    else {
        Node *p = s.head;
        while(p != NULL){
            cout << p->info << " ";
            p = p->link;
        }
    }
}
int main(){
    Stack s;
    init(s);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    cout << "Cac phan tu trong Stack: ";
    display(s);

    pop(s);
    cout << "Stack sau khi pop: ";
    display(s);
}