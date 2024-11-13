#include <bits/stdc++.h>
using namespace std;
struct Node //khai báo 1 node
{
    int info; //khai báo giá trị của node
    Node *link; // địa chỉ của node tiếp thep trong dslk
};
Node * first; //con trỏ Node tên first

void init() //khởi tạo node
{
    first = NULL;
}
Node *taoNode(int x){
    Node *p = new Node; //tạo con trỏ Node mới có tên là p// cấp phát bộ nhớ mới
    p ->info = x; //trỏ p tới info và gán là x
    p ->link = NULL; //trỏ p tới link và gán là NULL
    return p; //trả p(địa chỉ của node mới)
}
void themDau( int x)//them dau vao ds lien ket// truyen con tro va thay doi gia tri/ truyen x
{
    Node *p = taoNode(x); // tao 1 node moi
    p -> link = first;
    first = p;
}
void themCuoi( int x){
    Node *p = taoNode(x); //p la node muon duoc them vao cuoi dslk
    if(first == NULL)//neu kco node nao 
    {
        first = p;//p se duoc them vo
    }
    else
    {
        Node * q = first;//ktao q de duyet tu dau ds
        while(q -> link != NULL)//duyet tu dau ds toi cuoi ds
        {
            q = q ->link;//duyet cac node
        }
        q->link = p;//cap nhat node cuoi
    }
}
    
int size(Node *first)//dem so luong node
{
    int cnt = 0;//bat dau dem tu 0
    while(first != NULL)//neu con node
    {
        cnt++;//cong truoc khi tro den ptu tiep theo
        first = first-> link;//tro toi ptu tiep theo
    }
    return cnt;//tra ra slg node
}
void chenGiua( int x, int pos)
{
    int n = size(first);//so luong node cua dslk
    if(pos <= 0 || pos > n + 1)//neu vi tri khong hop le
    {
        cout << "Vi tri nhap kh hop le";//in ra thong bao
    }
    if(pos == 1)//neu vtri muon them la vi tri dau tien
    {
        themDau( x);//them dau dslk
        return;//dung lai
    }
    if(pos == n + 1)//neu vtri them la cuoi ds
    {
        themCuoi( x); //them cuoi
        return;//dung
    }
    Node *p = first;//tao 1 node 
    for(int i = 1; i < pos -1; ++i)//duyet toi truoc vi tri muon chen 1 node
    {
        p = p ->link;//tro toi node tiep theo
    }
    Node *tmp = taoNode(x);//ktao node muon them
    tmp ->link = p -> link;// node tmp -> link se tro toi p-> link /nghia la se tro toi o sau vi tri muon tro
    p ->link = tmp;//node truoc vi tri muon tro se lien ket voi node o vi tri muon tro

}
void inDS(Node *first){
    Node *p = first;
    while(p != NULL){
        cout << p -> info << " ";
        p = p -> link;
    }
}
void xoaDau()//xoa ptu dau ds
{
    if(first == NULL)//neu ds rong
    return;//khong lam gi ca
    first = first -> link;//neu ds khong rong thi tro ptu dau tien toi ptu thu 2
}
void xoaCuoi(Node *& first){
    if(first == NULL) return;
    if(first -> link == NULL){
        delete first;
        first = NULL;
    }
    else{
        Node *p = first;
        while(p->link->link != NULL){
            p = p-> link;
        }
        delete p ->link;
        p->link = NULL;
    }
}
void xoaViTri( int pos) {  
    int n = size(first); // Số lượng node hiện tại trong danh sách  

    // Kiểm tra xem vị trí có hợp lệ không  
    if (pos <= 0 || pos > n) {  
        cout << "Vi tri nhap khong hop le" << endl;  
        return; // Nếu không hợp lệ, thoát hàm  
    }  

    // Xử lý trường hợp vị trí cần xóa là vị trí đầu tiên  
    if (pos == 1) {  
        xoaDau(); // Sử dụng hàm xóa đầu  
        return;  
    }  

    // Tìm node đứng trước vị trí cần xóa  
    Node *p = first;  
    for (int i = 1; i < pos - 1; ++i) {  
        p = p->link; // Duyệt đến node trước vị trí cần xóa  
    }  

    // Xóa node tại vị trí pos  
    Node *temp = p->link; // Lưu node sẽ xóa  
    p->link = temp->link; // Cập nhật link của node trước  
    delete temp; // Giải phóng bộ nhớ của node đã xóa  
}
int main(){
    init();
    themDau( 3);
    themCuoi( 4);
    themCuoi( 6);
    chenGiua( 9, 1);
    inDS(first);
    cout << endl;
    xoaDau();
    inDS(first);
    cout << endl;
    xoaViTri( 2);
    inDS(first);

}