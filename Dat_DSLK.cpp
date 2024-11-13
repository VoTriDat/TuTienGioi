#include <iostream>
#include <string>
using namespace std;
struct SinhVien{
    string hoVaTen;
    string maSV;
    int tuoi;
};

struct Node{
    SinhVien sv;
    Node *link;
};

Node *first;
void init(){
    first = NULL;
}
Node *taoNode(SinhVien x){
    Node *p = new Node;
    p -> link = NULL;
    p ->sv = x;
    return p;
}
void themDau(SinhVien x){
    Node *p = taoNode(x);
    p ->link = first;
    first = p;
}
void xuat(SinhVien hv){
        cout << "Ten: " << hv.hoVaTen << endl;
        cout << "MSSV " << hv.maSV << endl;
        cout << "Tuoi: " << hv.tuoi <<endl;
}
void output(){
    Node *p = first;
    while(p!=NULL){
        xuat(p->sv);
        p = p->link;
    }
}
int main(){
    init();
    SinhVien sv1;
    sv1.hoVaTen = "VoTriDat";
    sv1.maSV ="abc";
    sv1.tuoi = 19;
    
    SinhVien sv2;
    sv2.hoVaTen = "DAtVo";
    sv2.maSV ="def";
    sv2.tuoi = 120;
    
    themDau(sv1);
    themDau(sv2);
    output();
}