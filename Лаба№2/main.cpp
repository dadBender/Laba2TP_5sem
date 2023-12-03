#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "train.h"
using namespace std;

//1. Стандартные потоки
//Определить класс с именем TRAIN, содержащий следующие поля : ● название пункта назначения; ● номер поезда; ● время отправления.
//Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа TRAIN.
//Заранее число объектов не известно.Написать программу, выполняющую следующие действия :
//● записи должны быть размещены в алфавитном порядке по названиям пунктов назначения;
//● вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени;
//● если таких поездов нет, выдать на дисплей соответствующее сообщение.
//2. Файловые и строковые потоки 
//С использованием файловых и строковых потоков написать программу,
//которая считывает текст из файла и определяет,
//сколько в нем слов, состоящих не более чем из четырех букв.

void task1() {
	TRAIN s;
	int button;
	bool flag = true;
	int i;
	//system("cls");
	while (flag) {
		cout << "Меню: " << endl << endl;
		cout << "1 - Добавить отправление" << endl;
		cout << "2 - Удаление отправления" << endl;
		cout << "3 - Вывод отправлений" << endl;
		cout << "4 - Вывод отправлений в алфавитном порядке по названиям пунктов назначения" << endl;
		cout << "5 - Вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени" << endl;
		cout << "6 - Редактирование данных отправлений" << endl;
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
			s.destination_in_vocabulary();
			system("pause");
			break;
		case 5:
			s.destination_after_time();
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





int task2() {

	// Открываем файл для чтения
	ifstream inputFile("input.txt");

	// Проверяем, открылся ли файл успешно
	if (!inputFile) {
		cout << "Ошибка открытия файла." << endl;
		return 1;
	}

	string word;
	int count = 0;

	// Считываем текст из файла по словам
	while (inputFile >> word) {
		// Проверяем, состоит ли слово не более чем из четырех букв
		if (word.length() <= 4) {
			count++;
		}
	}

	// Закрываем файл
	inputFile.close();

	cout << "Количество слов, состоящих не более чем из четырех букв: " << count << endl;

	return 0;
	
}


int main() {
	setlocale(LC_ALL, "Russian");
	string filename;
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