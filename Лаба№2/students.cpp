#include "student.h"
#include <iostream>
#include <string>
using namespace std;

STUDENT::STUDENT() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора по умолчанию для класса STUDENT" << endl << endl;
	fio = "";
	group = "";
	subject1 = "";
	subject2 = "";
	subject3 = "";
	mark1 = 0;
	mark2 = 0;
	mark3 = 0;
	a = 0;
	ball = 0;
	size = 0;
}

STUDENT::STUDENT(int x) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора с параметром для класса STUDENT" << endl << endl;
}

STUDENT::STUDENT(const STUDENT&) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора копирования для класса STUDENT" << endl << endl;
}

STUDENT::~STUDENT() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов диструктора для класса STUDENT" << endl << endl;
}

void STUDENT::push() {
	STUDENT* temp = new STUDENT[size + 1];
	for (int i = 0; i < size; ++i) {
		temp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = temp;
	cin >> ptr[size];
	++size;
	cout << endl << endl << "Новый объект добавлен" << endl << endl;
}

void STUDENT::pop(int num) {
	try {
		if (size == 0) {
			exception error("Пусто");
			throw error;
		}
		if (num < 0 || num >= size) {
			exception bug("Неверный номер");
			throw bug;
		}
		STUDENT* temp = new STUDENT[size - 1];
		ptr[num] = ptr[size - 1];
		for (int i = 0; i < size - 1; ++i) {
			temp[i] = ptr[i];
		}
		delete[] ptr;
		ptr = temp;
		--size;
		cout << endl << endl << "Объект добавлен" << endl << endl;
	}
	catch (exception& error) {
		cout << error.what() << endl << endl;
	}
}

void STUDENT::show() {
	setlocale(LC_ALL, "Russian");


	if (size == 0) {
		cout << "Пусто" << endl << endl;
	}
	else {
		for (int i = 0; i < size; ++i) {
			cout << ptr[i] << endl;
		}
	}
}

void STUDENT::show_students_have_mark_2() {
	setlocale(LC_ALL, "Russian");

	if (size == 0) {
	cout << "Пусто" << endl << endl;
	}

	else {
		for (int i = 0; i < size; ++i) {
			if (ptr[i].mark1 == 2 || ptr[i].mark2 == 2 || ptr[i].mark3 == 2) {
				cout << ptr[i] << endl;
			}
			else
				cout << "Таких студентов нет" << endl << endl;
		}
	}

}

void STUDENT::show_increase_ball() {
	setlocale(LC_ALL, "Russian");
	STUDENT* temp = new STUDENT[size + 1];

	if (size == 0) {
		cout << "Пусто" << endl << endl;
	}

	else {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size - 1; ++j) {
				if (ptr[j].ball > ptr[j + 1].ball) {
					temp[j] = ptr[j];
					ptr[j] = ptr[j + 1];
					ptr[j + 1] = temp[j];
				}
			}
		}

		for (int i = 0; i < size; ++i) {
			cout << ptr[i] << endl;
		}
	}

}

void STUDENT::edit(int change) {
	try {
		if (size == 0) {
			exception error("Пусто");
			throw error;
		}
		if (change < 0 || change >= size) {
			exception bug("Неверный номер");
			throw bug;
		}
		cin >> ptr[change];
	}
	catch (exception& bug) {
		cout << bug.what() << endl << endl;
	}
}

ostream& operator<<(ostream& out, STUDENT& obj) {   //Вывод данных
	setlocale(LC_ALL, "Russian");
	out << "Фамилия и инициалы: " << obj.fio << endl;
	out << "Номер группы: " << obj.group << endl;
	//int a;
	//a = obj.a;
	//for (int i = 0; i < a; i++) {
	out << "Предмет: " << obj.subject1 << endl;
	out << "Оценка: " << obj.mark1 << endl;
	//out << "Предмет: " << obj.subject2 << endl;
	//out << "Оценка: " << obj.mark2 << endl;
	//out << "Предмет: " << obj.subject3 << endl;
	//out << "Оценка: " << obj.mark3 << endl;
	//}
	out << "Средний балл: " << obj.ball << endl;
	return out;
}

istream& operator>>(istream& in, STUDENT& obj) {   //Ввод данных
	setlocale(LC_ALL, "Russian");
	cout << "Введите данные:" << endl << endl;
	cout << "Фамилия и инициалы: ";
	getchar();
	getline(cin, obj.fio);
	cout << "Номер группы: ";
	getchar();
	getline(cin, obj.group);
	double s = 0;
	//cout << "Введите количество предметов:";
	//cin >> obj.a;
	//for (int i = 0; i < obj.a; i++) {
	cout << "Предмет: ";
	getchar();
	getline(cin, obj.subject1);
	cout << "Оценка: ";
	cin >> obj.mark1;

	//cout << "Предмет: ";
	//getchar();
	//getline(cin, obj.subject2);
	//cout << "Оценка: ";
	//cin >> obj.mark2;


	//cout << "Предмет: ";
	//getchar();
	//getline(cin, obj.subject3);
	//cout << "Оценка: ";
	//cin >> obj.mark3;

	s = obj.mark1;
		//+ obj.mark2 + obj.mark3;
	//}
	//obj.ball = s/obj.a;
	obj.ball = s / 3;
	return in;
}