#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class STUDENT {
private:
	string fio;       //ФИО
	string group;     //Группа
	string subject1;  //Предмет1
	string subject2;  //Предмет2
	string subject3;  //Предмет3
	double mark1;     //Оценка
	double mark2;     //Оценка
	double mark3;     //Оценка
	double ball;      //Средний балл
	int a;
	STUDENT* ptr;
	int size;
public:
	STUDENT();
	STUDENT(int x);
	STUDENT(const STUDENT&);
	~STUDENT();

	void push();  //Добавление студента
	void pop(int);
	void show();  //Вывод
	void show_increase_ball(); //Вывод студентов по возрастанию среднего балла
	void show_students_have_mark_2(); //Вывод студентов, имеющих хотя бы одну оценку 2
	void edit(int);


	friend ostream& operator << (ostream& out, STUDENT& obj); //Перегрузка вывода
	friend istream& operator >> (istream& in, STUDENT& obj);  //Перегрузка ввода




};