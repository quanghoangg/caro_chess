#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include <windows.h> // Dùng để xóa màn hình mỗi khi có game mới với system("cls"), và thay màu chữ.
using namespace std;

#define RED      "\033[31m"
#define GREEN	 "\033[32m"
#define YELLOW	 "\033[93m"
#define GRAY	 "\033[37m"


 

class CaroTable
{
private:
	const int SIZE = 10;// Kích thước bàn cờ 10x10.
	vector<vector<char>> Table;
	int turn;
	bool checkEmpty(int hang, int cot) {
		Table[hang][cot] = ' ';
		return Table[hang][cot] = ' ';
	}
public:
	CaroTable();
	void createTable();
	void insertMove(char tick);
	bool checkWin(char tick);
	void LetPlay(string,string);
};



