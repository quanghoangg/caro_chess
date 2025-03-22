#include "CaroTable.h"



CaroTable::CaroTable()
{	//Hàm khởi tạo mảng vector 2 chiều 10x10 và số lượt = 0
	Table.resize(SIZE, vector<char>(SIZE, ' '));
	turn = 0;
}

void CaroTable::createTable()
{//Tạo bàn cờ để nhập X/O
	system("cls");
	cout << "    ";
	for (int i = 0;i < SIZE;i++) cout <<YELLOW<< i << "   ";
	cout << endl;
	cout << "  ";
	for (int j = 0;j < SIZE;j++) cout <<GRAY<< "|---";
	cout <<GRAY<< "|" << endl;
	for (int i = 0;i < SIZE;i++) {
		cout << YELLOW<<i << " ";
		for (int j = 0;j < SIZE;j++) {
			if(Table[i][j]=='X') cout << GRAY << "|" << " " << RED << Table[i][j] << " ";
			else if(Table[i][j] == 'O') cout << GRAY << "|" << " " << GREEN << Table[i][j] << " ";
			else cout << GRAY << "|" << " "  << Table[i][j] << " ";
		}
		cout << GRAY<<"|" << endl;
		cout << "  ";
		for (int j = 0;j < SIZE;j++) cout <<GRAY<< "|---";
		cout <<GRAY<<"|" << endl;
	}
}

void CaroTable::insertMove(char tick)
{	//Nhập nước đi theo hàng và cột, nếu nhập sai sẽ nhập lại.
	int hang, cot;
	cout << "Nhap nuoc di: ";
	do {
		cin >> hang >> cot;
		if (hang < 0 || hang >= SIZE || cot < 0 || cot >= SIZE || !checkEmpty(hang, cot))
			cout << "Nhap sai, moi nhap lai: ";
	} while (hang<0||hang>=SIZE||cot<0||cot>=SIZE||!checkEmpty(hang,cot));
	Table[hang][cot] = tick;
}

bool CaroTable::checkWin(char tick)
{	//Hàm kiểm tra nếu có 4 ký tự thẳng hàng
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j < SIZE;j++) {
			//Check theo đường ngang
			if (Table[i][j] == tick && Table[i][j + 1] == tick && Table[i][j + 2] 
				&& Table[i][j + 3]==tick&& j < SIZE - 3)
				return true;
			//Check theo đường thẳng
			else if (Table[i][j] == tick && Table[i + 1][j] == tick && Table[i + 2][j]==tick 
				&& Table[i + 3][j] == tick && i < SIZE - 3)
				return true;
			//Check theo đường chéo "\"
			else if (Table[i][j] == tick && Table[i + 1][j + 1] == tick 
				&& Table[i + 2][j + 2] == tick && Table[i + 3][j + 3] == tick && j < SIZE - 3 && i < SIZE - 3)
				return true;
			//Check theo đường chéo "/"
			else if (Table[i][j] == tick && Table[i + 1][j - 1] == tick 
				&& Table[i + 2][j - 2] == tick && Table[i + 3][j - 3] == tick && i < SIZE - 3 && j >= 3)
				return true;
		}
	}
	return false;
}

void CaroTable::LetPlay(string name1,string name2)
{
	char Player1 = 'X',Player2='O';
	while (true) {
		createTable();
		if (turn % 2 == 0) {
			cout << "Luot cua "<<name1<<" :" << endl;
			insertMove(Player1);
			if (checkWin(Player1)) {
				createTable();
				cout <<"==> Chuc mung " << name1 << " da chien thang!!" << endl;
				break;
			}
		}
		else {
			cout << "Luot cua " << name2 << " :" << endl;
			insertMove(Player2);
			if (checkWin(Player2)) {
				createTable();
				cout << "==> Chuc mung " << name2 << " da chien thang!!" << endl;
				break;
			}
		}
		turn++;
		if (turn == SIZE*SIZE) {
			createTable();
			cout << "==> Ket Qua Hoa!" << endl;
			return;
		}
	}
}
