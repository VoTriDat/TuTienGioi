#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX 20
void nhapMang(int a[], int &x){
    cout << "Nhập số lượng phần tử: ";
    srand(time(NULL));
    cin >> x;
    for(int i = 0; i < x; ++i){
        a[i] = rand() % (100+100-1) -100;
    }
}
void xuatMang(int a[], int &x){
    for(int i = 0; i < x; i++){
        cout << a[i] << " ";
    }
}
void swap(int &a, int &b){
    int x = a;
    a = b;
    b = x;
}
void interchangeSort(int a[], int x){
    for(int i = 0; i < x-1; ++i){
        for(int j = i+1; j< x;++j){
            if(a[j]<a[i]){
                swap(a[i], a[j]);
            }
        }
    }
}
void bubbleSort(int a[], int x){
    for(int i = 0; i < x -1;++i){
        for(int j = x-1; j>i; --j){
            if(a[j-1] > a[j]){
                swap(a[j-1], a[j]);
            }
        }
    }
}
void selectionSort(int a[], int x){
    int i, key, j;
    for(int i = 0; i < x-1; ++i){
        key = i;
        for(int j = i+1; j<x; ++j){
            if(a[key] > a[j]){
                swap(a[key], a[j]);
            }
        }
    }
}
void insertionSort(int a[], int x){
    int i, key, j;
    for(int i = 1; i < x; ++i){
        key = a[i];
        j = i-1;
        while(j >= 0 && a[j] >= key){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}
void menu(){
    int n, choice;
    int a[MAX];
    do{
    cout << "\n----- Chuong 3: XEP THU TU va TIM KIEM -----" <<endl;
    cout << "   0. Nhập mảng: " << endl;
    cout << "   1. Xuất mảng: "<<endl;
    cout << "   2. Xếp thứ tự bằng SELECTION SORT"<<endl;
    cout << "   3. Xếp thứ tự bằng BUBBLE SORT"<<endl;
    cout << "   4. Xếp thứ tự bằng INTERCHANGE SORT"<<endl;
    cout << "   5. Xếp thứ tự bằng INSERT SORT"<<endl;
    cout << "   6.Thoát"<<endl;
    cout << " Vui lòng chọn số để thực hiện: ";
    cin >> choice;
    switch(choice){
            case 0:
                nhapMang(a, n);
                break;
            case 1:
                cout << "Mảng ban đầu là: ";
                xuatMang(a, n);
                break;
            case 2:
                selectionSort(a, n);
                cout << "Mảng sau khi sắp xếp bằng SELECTION SORT: ";
                xuatMang(a, n);
                break;
            case 3:
                bubbleSort(a, n);
                cout << "Mảng sau khi sắp xếp bằng BUBBLE SORT: ";
                xuatMang(a, n);
                break;
            case 4:
                interchangeSort(a, n);
                cout << "Mảng sau khi sắp xếp bằng INTERCHANGE SORT: ";
                xuatMang(a, n);
                break;
            case 5:
                insertionSort(a, n);
                cout << "Mảng sau khi sắp xếp bằng INSERTION SORT: ";
                xuatMang(a, n);
                break;
            case 6:
                cout << "Thoát chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ, vui lòng chọn lại." << endl;
    } 
    }
    while(choice != 6);


}
int main(){
    menu();
    
}