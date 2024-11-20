#include <iostream>
#include<string>
using namespace std;
struct hocVien_09_Dat //dinh nghia cau truc hoc vien de luu thong tin hoc vien
{
    string maHV_09_Dat; //ma hoc vien
    string hoVaTen_09_Dat; // ho va ten hoc vien
    int namSinh_09_Dat; // nam sinh hoc vien
};
struct Node //dinh nghia cau truc node de xay dung dslk
{
    hocVien_09_Dat info; //chua thong tin hoc vien
    Node *link; //con tro den node tiep theo trong dslk
};
Node *first; //khai bao con tro dau tien cua dslk co thuoc tinh Node co ten la first
void init_09_Dat() // ham khoi tao dslk
{
    first = NULL; // gan con tro dau tien la NULL, tuc la dslk dang rong
}
Node *taoHocVien_09_Dat(string maHV, string hoVaTen, int namSinh) //tao 1 node moi voi thong tin cua hoc vien
{
    hocVien_09_Dat hv; //tao doi tuong hv // giong nhu cau lenh "hocVien hv = new hocVien();" trong java
    hv.maHV_09_Dat = maHV; //
    hv.hoVaTen_09_Dat = hoVaTen; //gan ho va ten hoc vien
    hv.namSinh_09_Dat = namSinh; // gan nam sinh hoc vien
    Node *p = new Node;//tao node moi
    p -> link = NULL;//gan link cua node moi la NULL
    p -> info = hv;//gan thong tin cua hv vao node
    return p;//tra thong tin node moi duoc tao
}
void themHocVien_09_Dat(Node *p)//them 1 node hoc vien vao dslk
{
    if(first == NULL){//neu dslk dang rong
        first =     p;//gan node p lam node dau tien
    }
    else{//neu dslk khong rong
        p -> link = first;//gan link cua con tro p den nut dau
        first = p;//cap nhat p lam node dau tien
    }
}
void nhapDS_09_Dat()//ham nhap ds hoc vien lien tuc cho toi khi nhap 0 thi dung
{
    string maHV_09_Dat, hoVaTen_09_Dat;//khai bao ma hoc vien va ho ve ten kieu string
    int namSinh_09_Dat;//khai bao nam sinh hoc vien 
    while(1)//chay lien tuc 
    {
        cout << "Nhap Ma Hoc Vien (Nhap 0 de dung): ";//dung lai khi nhap 0
        cin >> maHV_09_Dat;//nhap ma hoc vien
        if(maHV_09_Dat == "0")// neu ma hoc vien = 0 thi dung
        {
            break;//dung vong while
        }
        cin.ignore();//giup minh loai bo dc \n 
        cout << "Ho Va Ten Hoc Vien: "; getline(cin, hoVaTen_09_Dat); //nhap ho va ten // sai getline de co the nhap khoang cach 
        cout << "Nam Sinh Hoc Vien: "; cin >> namSinh_09_Dat;//nhap nam sinh
        Node *p = taoHocVien_09_Dat(maHV_09_Dat, hoVaTen_09_Dat, namSinh_09_Dat);//tao node p de them hoc vien vao danh sach
        themHocVien_09_Dat(p);//them hoc vien vao danh sach
    }
}
void inDS_09_Dat()//in dslk
{
    Node *p = first;//con tro p tu first de khi lap first van la first 
    while(p != NULL)// lap qua dslk cho toi khi p la NULL
    {
        cout << "Ma hoc vien: " << p->info.maHV_09_Dat //in ma hoc vien
             << ", Ten hoc vien: " << p->info.hoVaTen_09_Dat //in ho va ten 
             << ", Nam sinh: " << p->info.namSinh_09_Dat << endl;//in nam sinh
        p = p -> link;//tro toi con tro tiep theo
    }
}
int main(){
    init_09_Dat();//khoi tao dslk
    nhapDS_09_Dat();//nhap
    inDS_09_Dat();//in
}