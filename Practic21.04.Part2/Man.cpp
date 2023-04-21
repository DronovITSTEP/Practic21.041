#include "Man.h"


Man::Man(char* n, char* s, int a) : name{ new char[strlen(n) + 1] },
surname{ new char[strlen(s) + 1] },
age{ a }
{
	strcpy_s(name, strlen(n) + 1, n);
	strcpy_s(surname, strlen(s) + 1, s);
}
Man::Man() :name{ nullptr }, surname{ nullptr }, age{ 0 } {}
Man::~Man() {
	delete[]name;
	delete[]surname;
}

void Man::Put() {
	char temp[1024];
	cout << "Введите имя -> "; cin >> temp;
	if (name) delete[]name;
	name = new char[strlen(temp) + 1];
	strcpy_s(name, strlen(temp) + 1, temp);

	cout << "Введите фамилию -> "; cin >> temp;
	if (surname) delete[]surname;
	surname = new char[strlen(temp) + 1];
	strcpy_s(surname, strlen(temp) + 1, temp);

	cout << "введите возраст -> "; cin >> age;
}

void Man::Show() {
	cout << "Имя: " << name << endl
		<< "Фамилия: " << surname << endl
		<< "Возраст: " << age << endl;
}

void Man::SaveToFile() {
	int size;
	fstream f{ "man.txt", ios::out | ios::binary | ios::app };
	if (!f)
	{
		cout << "Ошибка открытия файла\n";
		exit(1);
	}

	f.write((char*)&age, sizeof(int));
	size = strlen(name);
	f.write((char*)&size, sizeof(int));
	f.write(name, size * sizeof(char));

	size = strlen(surname);
	f.write((char*)&size, sizeof(int));
	f.write(surname, size * sizeof(char));

	f.close();
}

void Man::LoadFromFile() {
	fstream f{ "man.txt", ios::in | ios::binary };

	if (!f)
	{
		cout << "Ошибка открытия файла\n";
		exit(1);
	}

	char* n, * s;
	int a;
	int temp;

	while (f.read((char*)&a, sizeof(int))) {
		cout << "Имя: ";
		f.read((char*)&temp, sizeof(int));
		n = new char[temp + 1];
		f.read(n, temp * sizeof(char));
		n[temp] = '\0';
		cout << n << endl;

		cout << "Фамилия: ";
		f.read((char*)&temp, sizeof(int));
		s = new char[temp + 1];
		f.read(s, temp * sizeof(char));
		s[temp] = '\0';
		cout << s << endl;

		cout << "Возраст: " << a << endl;

		delete[]n;
		delete[]s;
	}
}