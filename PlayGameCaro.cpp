#include "CaroTable.h"

void playWithPlayer();

int main() {
	int choice;
	CaroTable a;
	a.LetPlay("co", "Bi");
	do {
		cout << "*-------MAIN MENU-------*" << endl;
		cout << " Danh sach lua chon:" << endl;
		cout << "1. Choi voi nguoi choi khac." << endl;
		cout << "2. Choi voi BOT" << endl;
		cout << "3. Replay" << endl;
		cout << "4. Thong tin nguoi choi" << endl;
		cout << "5. Thoat!" << endl;
		cout << " ==> Nhap lua chon cua ban: "; cin >> choice;

	} while (choice != 5);
	return 0;
}

void playWithPlayer() {
	int choice;
	do {
		cout << "*-------Play With Other-------*" << endl;
		cout << "1. Dau thuong." << endl;
		cout << "2. Dau voi nguoi choi cung xep hang." << endl;
		cout << "3. Quay lai man hinh chinh." << endl;
		cout << " ==> Nhap lua chon: ";cin >> choice;
	} while (choice != 3);
}