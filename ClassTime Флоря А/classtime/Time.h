#pragma once
 
#include <string>
using namespace std;

class Time
{
	float hour; // Часы
	float min; // Минуты
	float sec; // Секунды

public:
	Time(); // Конструктор по умолчанию
	Time(unsigned h, unsigned m, unsigned s); // Конструктор с тремя параметрами
	void setHours(unsigned h); // Сеттер для часа
	void setMinutes(unsigned m); // Сеттер для минут
	void setSeconds(unsigned s); // Сеттер для секунд
	void setTime(unsigned h, unsigned m, unsigned s); // Сеттер ч/м/c
	float hours() const; // геттер для часов
	float minutes() const; // геттер для минут
	float seconds() const; // геттер для секунд
	float timeTosecond(); // Перевод времени в секунды
	float timeTominute(); // Перевод времени в минуты
	float timeTohour(); // Перевод времени в часы
	void addSeconds(float number); // Добавление секунд
	void addMinutes(float number); // Добавление минут
	void addHours(float number); // Добавление часов
	Time operator +(const Time & other); // Оператор сложения
	Time operator -(const Time &other); // Оператор вычитания
	string toString(); // Преобразование в строку
};

