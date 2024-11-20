#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int a[MAX][MAX];
int n;
int C[MAX];
int bfs[MAX];
int nbfs = 0;

struct Queue_09_Dat {
	int data[MAX];
	int front = -1, rear = -1;

	bool isEmpty_09_Dat() {
		return front == -1;
	}

	void push_09_Dat(int value) {
		if (rear == MAX - 1) {
			cout << "Queue day!" << endl;
			return;
		}
		if (front == -1) front = 0;
		data[++rear] = value;
	}

	int pop_09_Dat() {
		if (isEmpty_09_Dat()) {
			cout << "Queue rong!" << endl;
			return -1;
		}
		int value = data[front];
		if (front == rear) {
			front = rear = -1;
		}
		else {
			front++;
		}
		return value;
	}
};

Queue_09_Dat Q;

void nhapMatran_09_Dat() {
	ifstream inputFile("C:\\Users\\DatVo\\.vscode\\TuTienGioi\\09_Dat_b5_Bai_3.txt");
	if (!inputFile) {
		cout << "Khong the mo file!" << endl;
		return;
	}

	inputFile >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			inputFile >> a[i][j];
		}
	}
	inputFile.close();
}

void xuatMatran_09_Dat() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void khoitaochuaxet_09_Dat() {
	for (int i = 0; i < n; i++) {
		C[i] = 1;
	}
}

void BFS_09_Dat(int v) {
	int w, p;
	Q.push_09_Dat(v);
	C[v] = 0;

	while (!Q.isEmpty_09_Dat()) {
		p = Q.pop_09_Dat();
		bfs[nbfs++] = p;

		for (w = 0; w < n; w++) {
			if (C[w] && a[p][w] == 1) {
				Q.push_09_Dat(w);
				C[w] = 0;
			}
		}
	}
}

int main() {
	nhapMatran_09_Dat();
	cout << "Ma tran da doc tu file:" << endl;
	xuatMatran_09_Dat();

	khoitaochuaxet_09_Dat();

	int start;
	cout << "Nhap dinh bat dau duyet: ";
	cin >> start;

	BFS_09_Dat(start);

	cout << "Thu tu duyet: ";
	for (int i = 0; i < nbfs; i++) {
		cout << bfs[i] << " ";
	}
	cout << endl;

	return 0;
}
