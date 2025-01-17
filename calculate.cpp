#include <iostream>
#include <cctype>
using namespace std;

double calculate() {
    double kq = 0.0;
    double nhap = 0.0;
    char input;
    char dau = '+';

    while (true) {
        cin >> input;

        if (input == '=') {
            switch (dau) {
                case '+': kq += nhap; break;
                case '-': kq -= nhap; break;
                case '*': kq *= nhap; break;
                case '/': 
                    if (nhap != 0) {
                        kq /= nhap;
                    } else {
                        cout << "Lỗi: Chia cho 0!" << endl;
                        return kq;
                    }
                    break;
            }
            return kq;
        } 
        else if (isdigit(input)) {
            nhap = nhap * 10 + (input - '0');
        } 
        else {
            switch (dau) {
                case '+': kq += nhap; break;
                case '-': kq -= nhap; break;
                case '*': kq *= nhap; break;
                case '/': 
                    if (nhap != 0) {
                        kq /= nhap;
                    } else {
                        cout << "Lỗi: Chia cho 0!" << endl;
                        return kq;
                    }
                    break;
            }
            nhap = 0.0;
            dau = input;
        }
    }
    return kq;
}

int main() {
    cout << calculate() << endl;
}
