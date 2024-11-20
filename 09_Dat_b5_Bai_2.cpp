#include <iostream>  // Thu vien ho tro nhap xuat du lieu
#include <fstream>   // Thu vien ho tro lam viec voi file
#define MAX 20       // Dinh nghia hang so MAX la 20, gioi han kich thuoc ma tran
int A[MAX][MAX];     // Khai bao ma tran A co kich thuoc toi da 20x20
int x;               // Bien luu so dinh (kich thuoc ma tran)
using namespace std; // Su dung khong gian ten std de khong can viet std:: truoc cac ham nhu cin, cout

// Ham nhap ma tran tu file
void nhapMaTran_09_Dat() {
    // Mo file voi duong dan cu the
    ifstream inputfile("C:\\Users\\DatVo\\.vscode\\TuTienGioi\\09_Dat_b5_Bai_2.txt");
    
    // Kiem tra neu khong mo duoc file, in thong bao loi va thoat khoi ham
    if (!inputfile) {
        cout << "Khong the mo file!";  // Thong bao loi khong mo duoc file
        return;                       // Thoat khoi ham
    }
    
    inputfile >> x; // Doc so dinh  tu file
    
    // Duyet qua tung phan tu cua ma tran va doc du lieu tu file
    for (int i = 0; i < x; ++i) {        // Lap qua cac hang cua ma tran
        for (int j = 0; j < x; ++j) {    // Lap qua cac cot cua ma tran
            inputfile >> A[i][j];        // Doc gia tri tai hang i, cot j
        }
    }
    
    inputfile.close(); // Dong file sau khi doc xong
}

// Ham xuat ma tran ra man hinh
void xuatMaTran_09_Dat() {
    // Lap qua tung phan tu cua ma tran de xuat ra man hinh
    for (int i = 0; i < x; ++i) {        // Lap qua cac hang
        for (int j = 0; j < x; ++j) {    // Lap qua cac cot
            cout << A[i][j] << " ";      // Xuat gia tri tai hang i, cot j, cach nhau dau cach
        }
        cout << endl;                    // Xuat xuong dong sau khi het mot hang
    }
}

int main() {
    nhapMaTran_09_Dat(); // Goi ham nhap ma tran
    xuatMaTran_09_Dat(); // Goi ham xuat ma tran
}
