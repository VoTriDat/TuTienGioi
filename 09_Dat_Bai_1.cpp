#include <iostream>  // Them thu vien iostream de su dung cout va cin
#include <cstdlib>   // Them thu vien cstdlib de su dung rand() va srand()
#include <ctime>     // Them thu vien ctime de su dung time(NULL)
using namespace std; 
#define MAX 100       // Dinh nghia hang so MAX la 100, tuc la kich thuoc toi da cua mang
void nhapMang_09_Dat(int a[], int &x) // Nhap mang
{
	cout << "Nhap slg ptu: "; cin >> x; // Nhap so luong phan tu vao x
	srand(time(NULL)); // Khoi tao bo sinh so ngau nhien voi time(NULL) de lay gia tri thoi gian hien tai
	for (int i = 0; i < x; i++) { // Duyet mang tu i = 0 den i = x-1
		a[i] = rand() % (100 + 100 + 1) - 100; //random [-100, 100]
	}
}

void xuatMang_09_Dat(int a[], int x)//xuat mang
{
	for (int i = 0; i < x; i++) { // Duyet mang tu i = 0 den i = x-1
		cout << a[i] << " "; // In gia tri cua phan tu thu i
	}
}

void swap_09_Dat(int &a, int &b) // Hoan doi vi tri 2 ptu
{
	int c; // Khai bao bien tam c
	c = a; // Luu gia tri a vao c
	a = b; // Gan gia tri b vao a
	b = c; // Gan gia tri c (truoc la a) vao b
}

void SelectionSort_09_Dat(int a[], int n) // Sap xep chon
{
	int min_pos; // Khai bao bien min_pos de luu vi tri phan tu nho nhat
	for (int i = 0; i < n - 1; i++) // Duyet mang tu i = 0 den i = n-2
	{
		min_pos = i; // Khoi tao min_pos la i
		for (int j = i + 1; j < n; j++) // Duyet mang tu j = i+1 den j = n-1
			if (a[j] < a[min_pos]) // Neu a[j] nho hon a[min_pos], cap nhat min_pos
				min_pos = j; // Cap nhat min_pos
		swap_09_Dat(a[min_pos], a[i]); // Hoan doi gia tri a[i] va a[min_pos]
	}
}

void InsertionSort_09_Dat(int a[], int n) // Sap xep chen
{
	int x, i, j; // Khai bao  x, i, j
	for (int i = 1; i < n; i++) { // Duyet mang tu i = 1 den i = n-1
		x = a[i]; // Luu gia tri a[i] vao x
		j = i - 1; // Khoi tao j la i-1 (vi tri phan tu truoc do)
		while (0 <= j && x < a[j]) { // Neu x nho hon a[j] va j >= 0
			a[j + 1] = a[j]; // Di chuyen phan tu a[j] sang phai
			j--; // Giam j xuong de so sanh voi phan tu truoc do
		}
		a[j + 1] = x; // Chen gia tri x vao vi tri j+1
	}
}

void BubbleSort_09_Dat(int a[], int n) // Sap xep noi bot
{
	for (int i = 0; i < n - 1; i++) // Duyet mang tu i = 0 den i = n-2
		for (int j = n - 1; j > i; j--) // Duyet mang tu j = n-1 den j = i+1
			if (a[j - 1] > a[j]) { // Neu a[j-1] lon hon a[j], hoan doi
				swap_09_Dat(a[j], a[j - 1]); // Hoan doi a[j] va a[j-1]
			}
}

void InterchangeSort_09_Dat(int a[], int n) // Sap xep interchange
{
	for (int i = 0; i < n - 1; i++) // Duyet mang tu i = 0 den i = n-2
		for (int j = i + 1; j < n; j++) // Duyet mang tu j = i+1 den j = n-1
			if (a[i] > a[j]) // Neu a[i] lon hon a[j], hoan doi
				swap_09_Dat(a[i], a[j]); // Hoan doi a[i] va a[j]
}
int binarySearch_09_Dat(int a[], int n, int x)//tim kiem nhi phan 
{
	int left = 0;//duyet tu dau 
	int right = n - 1;//khoi tao bien cuoi cuoi
	while (left <= right) //dieu kien dung
	{
		int mid = left + (right - left) / 2; //gia tri o giua 
		if (a[mid] == x)//neu x o vi tri mid 
		{
			return mid; //tra ve index 
		}
		if (a[mid] > x) //neu gia tri tai index mid lon hon x 
		{
			right = mid - 1; //right se thanh mid - 1  
		}
		else {
			left = mid + 1; //left se thanh mid + 1   
		}
	}
	return -1; //neu kong tim thay
}


int main() {
	int a[MAX]; // Khai báo mảng a với kích thước tối đa là MAX
	int n; // Khai báo biến n để lưu số phần tử mảng
	nhapMang_09_Dat(a, n); // Gọi hàm nhapMang_09_Dat để nhập mảng a
	cout << "Mang : "; // In ra thông báo "Mảng trước khi sắp xếp"
	xuatMang_09_Dat(a, n); // In mảng trước khi sắp xếp
	cout << endl; // In xuống dòng
	int x;
	
	SelectionSort_09_Dat(a, n);
	cout << "Mang sau khi sap xep : "; // In ra thông báo "Mảng sau khi sắp xếp bằng SelectionSort"
	xuatMang_09_Dat(a, n); // In mảng sau khi sắp xếp
	cout << "\nNhap gia tri can tim: ";
	cin >> x;  // Nhập giá trị cần tìm
	int result = binarySearch_09_Dat(a, n, x);  // Tìm kiếm trong mảng đã sắp xếp
	if (result != -1) {
		cout << "Phan tu " << x << " duoc tim thay tai chi so " << result << endl;
	}
	else {
		cout << "Phan tu " << x << " khong ton tai trong mang." << endl;
	}
	
	cout << "Mang sau khi sap xep bang SelectionSort: "; // In ra thông báo "Mảng sau khi sắp xếp bằng SelectionSort"
	xuatMang_09_Dat(a, n); // In mảng sau khi sắp xếp

	cout << endl;
	InterchangeSort_09_Dat(a, n); // Gọi hàm InterchangeSort_09_Dat để sắp xếp mảng a bằng Interchange Sort
	cout << "Mang sau khi sap xep bang InterchangeSort: "; // In ra thông báo "Mảng sau khi sắp xếp bằng InterchangeSort"
	xuatMang_09_Dat(a, n); // In mảng sau khi sắp xếp

	cout << endl;
	BubbleSort_09_Dat(a, n); // Gọi hàm BubbleSort_09_Dat để sắp xếp mảng a bằng Bubble Sort
	cout << "Mang sau khi sap xep bang BubbleSort: "; // In ra thông báo "Mảng sau khi sắp xếp bằng BubbleSort"
	xuatMang_09_Dat(a, n); // In mảng sau khi sắp xếp

	cout << endl;
	InsertionSort_09_Dat(a, n); // Gọi hàm InsertionSort_09_Dat để sắp xếp mảng a bằng Insertion Sort
	cout << "Mang sau khi sap xep bang InsertionSort: "; // In ra thông báo "Mảng sau khi sắp xếp bằng InsertionSort"
	xuatMang_09_Dat(a, n); // In mảng sau khi sắp xếp
}
