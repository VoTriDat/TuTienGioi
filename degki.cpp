#include <iostream>
#include <string>
using namespace std;
struct Phim{
    string tenPhim;
    int maPhim;
    int nam;
};
struct Node{
    Phim info;
    Node *link;
};
Node *first;
void init(){
    first = NULL;
}
Node *taoNode(Phim x){
    Node *p = new Node();
    p->info =x;
    p->link= NULL;
    return p;
}
void themCuoi(Phim x){
    Node *p = taoNode(x);
    if(first == NULL){
        first = p;
    }
    else{
        Node *q = first;
        while(q->link!=NULL){
            q = q->link;
        }
        q->link=p;
    }
}
void nhap(Phim &x) {
    cout << "Nhap ten phim: ";
    getline(cin, x.tenPhim); 
    cout << "Nhap ma phim: ";
    cin >> x.maPhim;
    cout << "Nhap nam: ";
    cin >> x.nam;
    cin.ignore(); 
    cout << endl;
}

void xuat(Phim x){
    cout << "Ten phim: " << x.tenPhim << endl;
    cout << "Ma phim: " << x.maPhim << endl;
    cout << "Nam: " << x.nam;
}
void duyet(){
    Node *p = first;
    while(p!=NULL){
        xuat(p->info);
        p = p->link;
    }
}
int main(){
    Phim x;
    init(); 

    cout << "Nhap thong tin phim thu nhat:\n";
    nhap(x);
    themCuoi(x);

    cout << "Nhap thong tin phim thu hai:\n";
    nhap(x);
    themCuoi(x);

    cout << "\nDanh sach phim:\n";
    duyet();
}