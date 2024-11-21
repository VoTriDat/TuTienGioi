#include <iostream>
using namespace std;
struct SinhVien{
    string maSV;
    string hoVaTen;
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
    p ->link = NULL;
    p ->sv = x;
    return p;
}
void themDau(SinhVien x){
    Node *p = taoNode(x);
    p ->link = first;
    first = p;
}
int main(){

}