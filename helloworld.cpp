#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

bool ktrSHH(int x){
    int tong = 0;
    for(int i = 1; i < sqrt(x); i++){
        if(x % i == 0){
            tong += i;
        }
        while(i != (x%i)){
            tong += x%i;
            x /= i;
        }
    }
    return tong == x;
}
int main(){
    int x; cin >> x;
    if(ktrSHH(x)){
        cout << "YES";
    }
    else cout << "NO";
}