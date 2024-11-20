#include <iostream> 
#define MAX 20 
int a[MAX][MAX]; 
int x; 
using namespace std;

// Dinh nghia kich thuoc toi da cua ma tran la 20
// Khai bao ma tran a kich thuoc MAX x MAX
// Khai bao bien x de luu so dinh cua do thi
// Su dung namespace std de su dung cac ham cua thu vien iostream

void nhapMaTran_09_Dat(){
    cout << "Nhap so dinh cua do thi: "; cin >> x;
    // In ra thong bao nhap so dinh cua do thi va luu gia tri vao bien x

    for(int i = 0; i < x; ++i){
        cout << "Nhap dong " << i + 1 << ": ";
        // Lap qua cac dong cua ma tran (so dong bang x)
        // In ra thong bao nhap gia tri cho dong thu i+1

        for(int j = 0; j < x; ++j){
            cin >> a[i][j];
            // Lap qua cac cot cua dong hien tai va nhap gia tri vao ma tran a
        }
    }
}

void xuatMaTran_09_Dat(){
    for(int i = 0; i < x; ++i){
        for(int j = 0; j < x; ++j){
            cout << a[i][j] << " ";
            // Lap qua tung phan tu cua ma tran va in ra gia tri, cach nhau mot khoang trang
        }
        cout << endl;
        // Ket thuc mot dong thi xuong dong moi
    }
}

int main(){
    nhapMaTran_09_Dat();
    // Goi ham nhap gia tri ma tran

    xuatMaTran_09_Dat();
    // Goi ham xuat ma tran ra man hinh
}
