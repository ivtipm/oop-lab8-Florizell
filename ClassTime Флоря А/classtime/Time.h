#pragma once
 
#include <string>
using namespace std;

class Time
{
	float hour; // ����
	float min; // ������
	float sec; // �������

public:
	Time(); // ����������� �� ���������
	Time(unsigned h, unsigned m, unsigned s); // ����������� � ����� �����������
	void setHours(unsigned h); // ������ ��� ����
	void setMinutes(unsigned m); // ������ ��� �����
	void setSeconds(unsigned s); // ������ ��� ������
	void setTime(unsigned h, unsigned m, unsigned s); // ������ �/�/c
	float hours() const; // ������ ��� �����
	float minutes() const; // ������ ��� �����
	float seconds() const; // ������ ��� ������
	float timeTosecond(); // ������� ������� � �������
	float timeTominute(); // ������� ������� � ������
	float timeTohour(); // ������� ������� � ����
	void addSeconds(float number); // ���������� ������
	void addMinutes(float number); // ���������� �����
	void addHours(float number); // ���������� �����
	Time operator +(const Time & other); // �������� ��������
	Time operator -(const Time &other); // �������� ���������
	string toString(); // �������������� � ������
};

