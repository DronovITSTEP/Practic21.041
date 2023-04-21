#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

/*
	fstream();
	fstream(const char* name,
		int mode,
		int = filebuf:openprot);
	fstream(int f);
	fstream(int f, char* buf, int len);
mode :
	in
		out
		ate
		app
		trunc
		_Nocreate
		_Noreplace
		binary
*/

//open(const char* fileName, int mode, int protection);
//close();
//
//read(char* buf, int len);
//write(const char* buf, int len);
//
//get(); get(char&);
//put(char);
//
//getline(char* buf, int n, char c = '\n');
//ignore(int n = 1, int d = EOF);
//gcount();
//
//peek();
//putback(char c);
//
//seekg(long pos);
//seekp(long pos);
//
//tellg();
//tellp();
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char answer;
	const int messageCount = 8;
	int i, j;

	enum {CHOICE = 3, INPUT_FILENAME, INPUT_DIMENSIONS, INPUT_ELEMENTS, FILE_ERROR};
	char Msg[messageCount][50] =
	{
		"1. Вывести данные из файла\n",
		"2. Записать данные в файл\n",
		"3. Выход из программы\n",
		"\nВаш выбор -> ",
		"Введите имя файла -> ",
		"Введите размерность матрицы -> ",
		"Введите элементы матрицы -> ",
		"Невозможно открыть файл\n",
	};

	do {
		for (i = 0; i < 4; i++)
			cout << Msg[i];
		cin >> answer;
	} while (answer < '1' || answer > '3');

	if (answer == '3') exit(0);

	char fileName[50];
	int M, N;
	int num;
	cout << "\n" << Msg[INPUT_FILENAME];
	cin >> fileName;

	if (answer == '1') {
		ifstream inF(fileName, ios::in | ios::_Nocreate);
		if (!inF) {
			cout << Msg[FILE_ERROR];
			exit(0);
		}
		inF >> M;
		inF >> N;

		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				inF >> num;
				cout << num << " ";
			}
			cout << endl;
		}
		inF.close();
	}
	else {
		ofstream outF(fileName, ios::out);
		if (!outF) {
			cout << Msg[FILE_ERROR];
			exit(0);
		}

		cout << Msg[INPUT_DIMENSIONS];
		cout << "M = "; cin >> M;
		cout << "N = "; cin >> N;
		outF << M << ' ' << N << '\n';

		cout << Msg[INPUT_ELEMENTS];
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				cout << "arr[" << i << "][" << j << "] = ";
				cin >> num;
				outF << num << " ";
			}
			outF << "\n";
		}
		outF.close();
	}
}
