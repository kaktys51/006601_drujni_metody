#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

using std::cout;
using std::cin;

class DisplayBoard;



class ChessBorad
{
private:
	char peshka = 'П';
	char kin = 'к';
	char slon = 'С';
	char tura = 'Т';
	char ferz = 'Ф';
	char korol = 'К';
	std::vector<std::vector<char*>>bottomSideFormation;  //формат фигур на доске
public:
	ChessBorad() {};

	friend class DisplayBoard;
	void buildFigures(); //сборка фигур 
	void defaultBlackFormation() //подготовка к сборке
	{
		bottomSideFormation =
		{
			{&peshka, &peshka, &peshka, &peshka, &peshka, &peshka, &peshka, &peshka},
			{&tura, &kin, &slon, &ferz, &korol, &slon, &kin, &tura}
		};
	}

	void printBottomSide() //просто функция вывода фигур (не преминяется в выводе на доску)
	{
		system("chcp 1251");
		defaultBlackFormation();
		for (int i = 0; i < bottomSideFormation.size(); ++i) {
			for (int j = 0; j < bottomSideFormation[i].size(); ++j)
			{
				cout << *(bottomSideFormation[i][j]) << " ";
			}
			cout << std::endl;
		}
	}

	std::vector<std::vector<char*>> getBottomArray() // передача массива фигур в массив доски 
	{
		return bottomSideFormation;
	}

};

void ChessBorad::buildFigures()  //сборка фигур
{
	defaultBlackFormation();

}

class DisplayBoard
{
private:
	char empt = ' ';

	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char e = 'e';
	char f = 'f';
	char g = 'g';
	char h = 'h';

	char n0 = '0';
	char n1 = '1';
	char n2 = '2';
	char n3 = '3';
	char n4 = '4';
	char n5 = '5';
	char n6 = '6';
	char n7 = '7';
	char n8 = '8';
	char board[9][9]; //дополнитильные поля для обозначения строк, столбцов

public:

	DisplayBoard() {};
	friend void ChessBorad::buildFigures();
	void defaultCordinatesDispaly() //черные снизу подготовка к сборке     
	{
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
			{
				board[i][j] = empt;
			}

		board[8][0] = h;
		board[8][1] = g;
		board[8][2] = f;
		board[8][3] = e;
		board[8][4] = d;
		board[8][5] = c;
		board[8][6] = b;
		board[8][7] = a;
		board[8][8] = empt;

		board[0][8] = n1;
		board[1][8] = n2;
		board[2][8] = n3;
		board[3][8] = n4;
		board[4][8] = n5;
		board[5][8] = n6;
		board[6][8] = n7;
		board[7][8] = n8;
		board[8][8] = empt;
	}

	void reverceCordinatesDispaly() //черные сверху подготовка к сборке     
	{
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
			{
				board[i][j] = empt;
			}

		board[8][0] = a;
		board[8][1] = b;
		board[8][2] = c;
		board[8][3] = d;
		board[8][4] = e;
		board[8][5] = f;
		board[8][6] = g;
		board[8][7] = h;
		board[8][8] = empt;

		board[0][8] = n8;
		board[1][8] = n7;
		board[2][8] = n6;
		board[3][8] = n5;
		board[4][8] = n4;
		board[5][8] = n3;
		board[6][8] = n2;
		board[7][8] = n1;
		board[8][8] = empt;
	}

	void blidBoard(int ch);
};

void DisplayBoard::blidBoard(int ch) //окончательная сборка доски с выбором отображения
{
	int choice = ch;
	int topColor = 0;
	int bottomColor = 0;

	switch (choice)  // от выбора зависит как будут собраны поля с координатами и цвет верхних\нижних фигур
	{
	case 0:
	{
		defaultCordinatesDispaly(); //черные снизу
		topColor = 7;
		bottomColor = 1;
		break;
	}
	case 1:
	{
		reverceCordinatesDispaly(); //черные сверху
		topColor = 1;
		bottomColor = 7;
		break;
	}
	default:
		break;
	}
	ChessBorad figures;
	figures.buildFigures();
	figures.getBottomArray();     // передача массива фигур в массив доски 

	std::vector<std::vector<char*>>tempBottomBuild = figures.getBottomArray();

	//верхний ряд фигур
	board[0][0] = *tempBottomBuild[1][0];
	board[0][1] = *tempBottomBuild[1][1];
	board[0][2] = *tempBottomBuild[1][2];
	board[0][3] = *tempBottomBuild[1][4];
	board[0][4] = *tempBottomBuild[1][3];
	board[0][5] = *tempBottomBuild[1][5];
	board[0][6] = *tempBottomBuild[1][6];
	board[0][7] = *tempBottomBuild[1][7];

	board[1][0] = *tempBottomBuild[0][0];
	board[1][1] = *tempBottomBuild[0][0];
	board[1][2] = *tempBottomBuild[0][0];
	board[1][2] = *tempBottomBuild[0][0];
	board[1][3] = *tempBottomBuild[0][0];
	board[1][4] = *tempBottomBuild[0][0];
	board[1][5] = *tempBottomBuild[0][0];
	board[1][6] = *tempBottomBuild[0][0];
	board[1][7] = *tempBottomBuild[0][0];

	//нижний ряд фигур
	board[6][0] = *tempBottomBuild[0][0];
	board[6][1] = *tempBottomBuild[0][0];
	board[6][2] = *tempBottomBuild[0][0];
	board[6][2] = *tempBottomBuild[0][0];
	board[6][3] = *tempBottomBuild[0][0];
	board[6][4] = *tempBottomBuild[0][0];
	board[6][5] = *tempBottomBuild[0][0];
	board[6][6] = *tempBottomBuild[0][0];
	board[6][7] = *tempBottomBuild[0][0];

	board[7][0] = *tempBottomBuild[1][0];
	board[7][1] = *tempBottomBuild[1][1];
	board[7][2] = *tempBottomBuild[1][2];
	board[7][3] = *tempBottomBuild[1][3];
	board[7][4] = *tempBottomBuild[1][4];
	board[7][5] = *tempBottomBuild[1][5];
	board[7][6] = *tempBottomBuild[1][6];
	board[7][7] = *tempBottomBuild[1][7];

	if (choice == 1) //поправка на положение ферзя при разном выборе отображения
	{
		board[0][3] = *tempBottomBuild[1][3];
		board[0][4] = *tempBottomBuild[1][4];
	}

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (i == 8 || j == 8)  //поправка на цвета для координат доски 
			{
				SetConsoleTextAttribute(hConsole, 7);
				cout << " " << board[i][j] << " ";
			}
			else
			{
				if (i < 6 && (i % 2 == 0 && j % 2 == 0)) // первый ряд 
				{
					SetConsoleTextAttribute(hConsole, (((8 << 4) | topColor)));
					cout << " " << board[i][j] << " ";
				}
				else if (i < 6 && (i % 2 == 0 && j % 2 == 1)) // первый ряд 
				{
					SetConsoleTextAttribute(hConsole, (((0 << 4) | topColor)));
					cout << " " << board[i][j] << " ";
				}
				else if (i < 6 && (i % 2 == 1 && j % 2 == 0)) // второй ряд 
				{
					SetConsoleTextAttribute(hConsole, (((0 << 4) | topColor)));
					cout << " " << board[i][j] << " ";
				}
				else if (i < 6 && (i % 2 == 1 && j % 2 == 1)) // второй ряд 
				{
					SetConsoleTextAttribute(hConsole, (((8 << 4) | topColor)));
					cout << " " << board[i][j] << " ";
				}
				else if (i >= 6 && (i % 2 == 0 && j % 2 == 0)) // первый ряд нижние фигуры
				{
					SetConsoleTextAttribute(hConsole, (((8 << 4) | bottomColor)));
					cout << " " << board[i][j] << " ";
				}
				else if (i >= 6 && (i % 2 == 0 && j % 2 == 1)) // первый ряд нижние фигуры
				{
					SetConsoleTextAttribute(hConsole, (((0 << 4) | bottomColor)));
					cout << " " << board[i][j] << " ";
				}
				else if (i >= 6 && (i % 2 == 1 && j % 2 == 0)) // второй ряд нижние фигуры
				{
					SetConsoleTextAttribute(hConsole, (((0 << 4) | bottomColor)));
					cout << " " << board[i][j] << " ";
				}
				else if (i >= 6 && (i % 2 == 1 && j % 2 == 1)) // второй ряд нижние фигуры
				{
					SetConsoleTextAttribute(hConsole, (((8 << 4) | bottomColor)));
					cout << " " << board[i][j] << " ";
				}
			}
		}
		cout << std::endl;
	}

}

int main()
{
	system("chcp 1251");


	DisplayBoard b1;

	// синий = черный
	// для расположения доски белыми фигурами к игроку фнкции нужно передать 1
	// для расположения доски черными фигурами к игроку фнкции нужно передать 0

	b1.blidBoard(0);

	return 0;
}