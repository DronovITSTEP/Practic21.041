#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Man
{
	int age;
	char* name;
	char* surname;

public:
	Man(char* n, char* s, int a);
	Man();
	~Man();

	void Put(); // ���� ������
	void Show(); // �������� ������
	void SaveToFile(); // ���������� � ����
	static void LoadFromFile(); // �������� �� �����
};

