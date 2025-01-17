#include <iostream>
#include <fstream>
using namespace std;
struct SinhVien{
    string hoVaTen;
    string maSo;
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
    Node *p = new Node();
    p->link = NULL;
    p->sv =x;
    return p;    
}
void themDau(SinhVien x){
    Node *p = taoNode(x);
    if(first == NULL){
        first = p;
    }
    else{
        p->link =first;
        first = p;
    }
    
}
void docFile(){
    ifstream inputFile("C:\\Users\\DatVo\\.vscode\\TuTienGioi\\Vo Tri Dat.txt");
    if(!inputFile){
        cout << "NOPE!";
    }
    else{
        SinhVien x;
        while(getline(inputFile, x.hoVaTen)){
        getline(inputFile, x.maSo);
        inputFile>>x.tuoi;
        inputFile.ignore();
        themDau(x);
        }
        inputFile.close();
    }
}
void xuatSv(SinhVien x){
    cout <<"Ho va ten: " << x.hoVaTen << endl;
    cout << "Ma so: " << x.maSo << endl;
    cout << "Tuoi: " << x.tuoi << endl;
}
void in(){
    Node *p = first;
    while(p != NULL){
        xuatSv(p->sv);
        p = p->link;
    }
}
int main(){
    init();
    docFile();
    in();
}