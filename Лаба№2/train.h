#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//Определить класс с именем TRAIN, содержащий следующие поля : ● название пункта назначения; ● номер поезда; ● время отправления.

//Заранее число объектов не известно.Написать программу, выполняющую следующие действия :
//● записи должны быть размещены в алфавитном порядке по названиям пунктов назначения;
//● вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени;
//● если таких поездов нет, выдать на дисплей соответствующее сообщение.
class TRAIN {
private:
	int a;
	TRAIN* ptr;
	int size;

	string destination;       //название пункта назначения
	string train_number;     //номер поезда

	int departure_time_hours;  //время отправления
	int departure_time_minutes;
	
public:
	TRAIN();
	TRAIN(int x);
	TRAIN(const TRAIN&);
	~TRAIN();

	void push();  //Добавление отправления
	void pop(int);
	void show();  //Вывод на экран
	void destination_in_vocabulary(); //записи должны быть размещены в алфавитном порядке по названиям пунктов назначения
	void destination_after_time(); //вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени
	void edit(int);


	friend ostream& operator << (ostream& out, TRAIN& obj); //Перегрузка вывода
	friend istream& operator >> (istream& in, TRAIN& obj);  //Перегрузка ввода

	string getDestination();
	string getTrain_number();
	int getDeparture_time_hours();
	int getDeparture_time_minutes();

	void setDestination(string destination);
	void setTrain_number(string train_number);
	void setDeparture_time_hours(int departure_time_hours);
	void setDeparture_time_minutes(int departure_time_minutes);
};