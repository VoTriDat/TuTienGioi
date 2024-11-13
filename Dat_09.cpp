#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MAX 20
void swap(int &a,int &b){
    int c = a; 
    a = b;
    b = c;

}
void taoMang(int a[], int &x){
    cout << "Nhập slg ptu: "; cin >> x;
    srand(time(NULL));
    for(int i = 0; i < x; ++i){
        a[i] = rand() % (100 + 100 - 1) - 100;
    }
}
void xuatMang(int a[], int &x){
    for(int i = 0; i < x; ++i){
        cout << a[i] << " ";
    }
}
void bubbleSort(int a[], int x){
    for(int i = 0; i < x -1; ++i){
        for(int j = x - 1; j > x; --j){
            if(a[j-1] > a[j]){
                swap (a[j], a[j-1]);
            }
        }
    }
}
void selectionSort(int a[], int x){
    int i, key, j;
    for(int i = 0; i < x-1; ++i){
        key = i;
        for(int j = i+1; j < x; ++j){
            if(a[j] < a[key]){
                swap(a[j], a[key]);
            }
        }
    }
}
void interchangeSort(int a[], int x){
    for(int i = 0; i < x - 1; ++i){
        for(int j = i+1; j < x; ++j){
            if(a[i] > a[j]){
                swap(a[j], a[i]);
            }
        }
    }
}
void insertionSort(int a[], int x){
    int i, j, key;
    for(int i = 1; i < x; ++i){
        key = a[i];
        j = i -1;
        while(0<=j && key < a[j]){
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = key;
    }
}
int main(){
    int n;
    int a[MAX];
    taoMang(a, n);
    interchangeSort(a, n);
    cout << "inter: ";
    xuatMang(a, n);
    bubbleSort(a, n);
    cout << "bubble: "; 
    xuatMang(a, n);
    selectionSort(a, n);
    cout << "selectionsort: ";
    xuatMang(a, n);
    insertionSort(a, n);
    cout << "in: ";
    xuatMang(a, n);
}