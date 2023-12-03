#include "train.h"
#include <iostream>
#include <string>
using namespace std;

TRAIN::TRAIN() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора по умолчанию для класса TRAIN" << endl << endl;
	destination = "";
	train_number = "";
	departure_time_minutes = 0;
	departure_time_hours = 0;

	size = 0;
}

TRAIN::TRAIN(int x) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора с параметром для класса TRAIN" << endl << endl;
}

TRAIN::TRAIN(const TRAIN&) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора копирования для класса TRAIN" << endl << endl;
}

TRAIN::~TRAIN() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов диструктора для класса TRAIN" << endl << endl;
}

void TRAIN::push() { 
	TRAIN* temp = new TRAIN[size + 1];
	for (int i = 0; i < size; ++i) {
		temp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = temp;
	cin >> ptr[size];
	++size;
	cout << endl << endl << "Новый объект добавлен" << endl << endl;
}


//string getDestination();
//string getTrain_number();
//int getDeparture_time_hours();
//int getDeparture_time_minutes();
//
//void setDestination(string destination);
//void setTrain_number(string train_number);
//void setDeparture_time_hours(int departure_time_hours);
//void setDeparture_time_minutes(int departure_time_minutes);


string TRAIN::getDestination() {
	return this->destination;
}

string TRAIN::getTrain_number() {
	return this->train_number;
}

int TRAIN::getDeparture_time_hours() {
	return this->departure_time_hours;
}

int TRAIN::getDeparture_time_minutes() {
	return this->departure_time_minutes;
}

void TRAIN::setDestination(string destination) {
	this->destination = destination;
}

void TRAIN::setTrain_number(string train_number) {
	this->train_number = train_number;
}

void TRAIN::setDeparture_time_hours(int departure_time_hours) {
	this->departure_time_hours = departure_time_hours;
}

void TRAIN::setDeparture_time_minutes(int departure_time_minutes) {
	this->departure_time_minutes = departure_time_minutes;
}

void TRAIN::pop(int num) {
	try {
		if (size == 0) {
			exception error("Пусто");
			throw error;
		}
		if (num < 0 || num >= size) {
			exception bug("Неверный номер");
			throw bug;
		}
		TRAIN* temp = new TRAIN[size - 1];
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

void TRAIN::show() {
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

void TRAIN::destination_after_time() {
	setlocale(LC_ALL, "Russian");
	int person_time_hours = 0;
	int person_time_minutes = 0;
	cout << "Введите интересующее вас время:" << endl;
	cout << "Сначала введите часы -> " ;
	
	while (true) {
		cin >> person_time_hours; 
		if (person_time_hours < 24 && person_time_hours >= 0) {
			break;
		}
		else {
			cout << "Введите значение от 0 до 23" << endl;
		}
	}
	cout << "Введите минуты -> ";
	cin >> person_time_minutes;

	while (true) {
		cin >> person_time_minutes;
		if (person_time_minutes < 60 && person_time_minutes >= 0) {
			break;
		}
		else {
			cout << "Введите значение от 0 до 59" << endl;
		}
	}
	cout << "Ваше время: " << person_time_hours << ":" << person_time_minutes << endl;

	int proverka = 0;


	if (size == 0) {
		cout << "Пусто" << endl << endl;
	}
	else {
		for (int i = 0; i < size; ++i) {
			if (ptr[i].departure_time_hours > person_time_hours) {
				cout << ptr[i] << endl;
				proverka++;
			}
			if (ptr[i].departure_time_hours == person_time_hours) {
				if (ptr[i].departure_time_minutes > person_time_minutes) {
					cout << ptr[i] << endl;
					proverka++;
				}
			}
		}
		if (proverka == 0) {
			cout << "Пусто" << endl;
		}
	}

}

void TRAIN::destination_in_vocabulary() {
	setlocale(LC_ALL, "Russian");
	TRAIN* temp = new TRAIN[size + 1];

	if (size == 0) {
		cout << "Пусто" << endl << endl;
	}

	else {
		for (int i = 0; i < size - 1; ++i)
		{
			for (int j = 0; j < size - i - 1; ++j)
			{
				if (ptr[j].destination > ptr[j + 1].destination)
				{
					temp[j] = ptr[j];
					ptr[j] = ptr[j + 1];
					ptr[j + 1] = temp[j];
				}
			}
		}
	}
}

void TRAIN::edit(int change) {
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
//Определить класс с именем TRAIN, содержащий следующие поля : ● название пункта назначения; ● номер поезда; ● время отправления.

ostream& operator<<(ostream& out, TRAIN& obj) {   //Вывод данных
	setlocale(LC_ALL, "Russian");
	out << "Название пункта назначения: " << obj.destination << endl;
	out << "Номер поезда: " << obj.train_number << endl;
	out << "Время отправления: " << obj.departure_time_hours << ":" << obj.departure_time_minutes << endl;
	return out;
}

istream& operator>>(istream& in, TRAIN& obj) {   //Ввод данных
	setlocale(LC_ALL, "Russian");
	int time_hours;
	int time_minutes;
	cout << "Введите данные:" << endl << endl;
	cout << "Название пункта назначения: ";
	getchar();
	getline(cin, obj.destination);
	cout << "Номер отправления: ";
	cin >> obj.train_number;
	cout << "Время отправления (часы): ";	
	while (true) {
		cin >> time_hours;
		if (time_hours < 24 && time_hours >= 0) {
			obj.departure_time_hours = time_hours;
			break;
		}
		else {
			cout << "Введите значение от 0 до 23" << endl;
		}
	}

	cout << "Время отправления (минуты): ";	
	while (true) {
		cin >> time_minutes;
		if (time_minutes < 60 && time_minutes >= 0 ) {
			obj.departure_time_minutes = time_minutes;
			break;
		}
		else {
			cout << "Введите значение от 0 до 59" << endl;
		}
	}
	cout << "Время отправления:" << obj.departure_time_hours <<":"<< obj.departure_time_minutes << endl;
	
	return in;
}

