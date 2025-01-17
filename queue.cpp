#include <iostream>
using namespace std;
struct Node{
    int info;
    Node *link;
};
struct Queue{
    Node *front;
    Node *rear;
};
void init(Queue &q){
    q.front = q.rear = NULL;
}
Node *taoNode(int x){
    Node *p = new Node();
    if(p == NULL) return NULL;
    p ->info = x;
    p->link =NULL;
    return p;
}
bool isEmpty(Queue q){
    return q.front == NULL;
}
void enqueue(Queue &q, int x){
    Node *p =taoNode(x);
    if(p==NULL) return;
    if(isEmpty(q)){
        q.front =q.rear =p;
    }
    else{
        q.rear ->link = p;
        q.rear = p;
    }

}
void dequeue(Queue &q){
if (isEmpty(q)) return;
    Node* p = q.front;       // Lấy phần tử đầu
    q.front = q.front->link; // Cập nhật front
    if (q.front == NULL) {   // Nếu sau khi xóa hàng đợi rỗng
        q.rear = NULL;
    }
    delete p;
}
void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue rong";
    } else {
        Node* p = q.front;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->link;
        }
        cout << endl;
    }
}
int main(){
 Queue q;
    init(q);

    // Thêm phần tử vào hàng đợi
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    cout << "Cac phan tu trong Queue: ";
    display(q);

    // Xóa phần tử khỏi hàng đợi
    dequeue(q);
    cout << "Queue sau khi dequeue: ";
    display(q);

}