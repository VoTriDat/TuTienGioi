#include <iostream>
#include <cmath>
using namespace std;
int ucln(int x, int y){
    x = abs(x);
    y = abs(y);
    while(y!=0){
        int tmp = y;
        y = x % y;
        x = tmp; 
    }
    return x;
}
void rutGon(int x, int y){
    if(y == 0){
        cout << "INVALID";
    }
    else if(y == 1){
        cout << x;
    }
    else{
        if(y < 0){
            x = -x;
            y = -y;
        }
        int uoc = ucln(x, y);
        x /= uoc;
        y /= uoc;
        cout << x<< " " << y;
    }
}
int main(){
    int x;
    int y;
    cout << "Nhap 2 so: ";
    cin >> x >> y;
    rutGon(x, y);    
}