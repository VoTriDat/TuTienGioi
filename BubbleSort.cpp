#include <iostream>
using namespace std;
int main(){
    int a[] = {8, 6, 9, 2, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j > i; j--){
            if(a[j-1] > a[j]){
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
            }
        }
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j > i; j--){
            if(a[j-1] < a[j]){
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
            }
        }
    }
     for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

}