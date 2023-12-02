#include <iostream>
#include "student.h"
using namespace std;



void task1() {
	STUDENT s;
	int button;
	bool flag = true;
	int i;
	//system("cls");
	while (flag) {
		cout << "Меню: " << endl << endl;
		cout << "1 - Добавить студента" << endl;
		cout << "2 - Удаление студента" << endl;
		cout << "3 - Вывод студентов" << endl;
		cout << "4 - Вывод студентов в порядке возрастания среднего балла" << endl;
		cout << "5 - Вывод студентовв, имеющих хотя бы одну оценку 2" << endl;
		cout << "6 - Редактирование данных студента" << endl;
		cout << "0 - Вернуться к выбору задания" << endl << endl;
		cout << "Выберите пункт: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			s.push();
			system("pause");
			break;
		case 2:
			cout << "Выберите для удаления: ";
			cin >> i;
			s.pop(i);
			system("pause");
			break;
		case 3:
			s.show();
			system("pause");
			break;
		case 4:
			s.show_increase_ball();
			system("pause");
			break;
		case 5:
			s.show_students_have_mark_2();
			system("pause");
			break;
		case 6:
			s.show();
			cout << "Выберите для изменения: ";
			cin >> i;
			s.edit(i);
			system("pause");
			break;
		case 0:
			flag = false;
			cout << "\nЗавершение работы программы" << endl;
			break;
		default:
			cout << endl << "Введите другое число!" << endl
				<< endl;
			system("pause");
			break;
		}
	}
}





void task2() {


	ifstream in;       // поток для чтения
	in.open("task2.txt"); // окрываем файл для чтения
	
	char* ptr;
	bool flag = true;


	if (!in.is_open())
		cout << "Ошибка открытия файла!" << endl;
	else {
		cout << "Файл открыт" << endl << endl << endl;
		string str;
		while (!in.eof()) {


			str = "";
			getline(in, str);

			*ptr = &str;
			while (*ptr != '\0'){
				if (*ptr != ' ') {
					flag = false;
				}
				
				if (flag == false)
					break;
				ptr++;
			}

			if(flag == true)
				cout << str << endl;

		}
	}
	in.close();             // закрываем файл
}


int main() {
	setlocale(LC_ALL, "Russian");
	string menu = "Меню:\n1 - Первое задание\n2 - Второе задание\n0 - Завершение работы\n>";
	int knopka;
	bool mode = true;
	while (mode) {
		cout << menu;
		cin >> knopka;
		if (cin.fail()) {
			knopka = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (knopka){
		case 1:
			task1();
			system("pause");
			break;
		case 2:
			task2();
			system("pause");
			break;
		case 0:
			mode = false;
			cout << "\nЗавершение работы" << endl;
			break;
		default:
			cout << endl << "Введите другое число!" << endl
				<< endl;
			system("pause");
			break;
		}
	}
	return 0;
}