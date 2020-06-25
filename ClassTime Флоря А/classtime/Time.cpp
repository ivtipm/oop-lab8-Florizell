#include "pch.h"
#include "Time.h"
#include <string>


using namespace std;

Time::Time() {
	sec = 0;
	min = 0;
	hour = 0;
}

Time::Time(unsigned h, unsigned m, unsigned s) {
	hour = h;
	min = m;
	sec = s;
}


void Time::setHours(unsigned h)
{
	if (h >= 0 && h < 24)
		hour = h;
}

void Time::setMinutes(unsigned m)
{
	if (m >= 0 && m < 60)
		min = m;
}

void Time::setSeconds(unsigned s)
{
	if (s >= 0 && s < 60)
		sec = s;
}

void Time::setTime(unsigned h, unsigned m, unsigned s)
{
	setHours(h);
	setMinutes(m);
	setSeconds(s);
}


float Time::hours() const
{
	return hour;
}

float Time::minutes() const
{
	return min;
}

float Time::seconds() const
{
	return sec;
}

float Time::timeTosecond()
{
	float temp;
	temp = hour * 60 * 60 + min * 60 + sec;
	return temp;
}

float Time::timeTominute()
{
	float temp;
	temp = hour * 60 + min + sec / 60;
	return temp;
}

float Time::timeTohour()
{
	float temp = 0;
	temp = hour + min / 60 + sec / (60 * 60);
	return temp;
}

void Time::addSeconds(float number)
{
	int s, m;
	s = sec + number;
	sec = s;
	if (sec > 60)
	{
		sec = (int)sec % 60;
		min = min + (s / 60);
		m = min;
		if (min > 60) {
			min = (int)min % 60;
			hour = hour + (m / 60);
			if (hour > 24) {
				hour = (int)hour % 24;

			}

		}

	}

}

void Time::addMinutes(float number)
{
	int m;
	this->sec = sec;
	min = min + number;
	m = min;
	if (min > 60) {
		min = (int)min % 60;
		hour = hour + (m / 60);
		if (hour > 24) {
			hour = (int)hour % 24;

		}
	}

}

void Time::addHours(float number)
{
	this->sec = sec;
	min = min;
	hour = hour + number;
	if (hour > 24) {
		hour = (int)hour % 24;

	}
}

Time Time::operator +(const Time& other)
{
	Time temp;
	temp.sec = sec + other.sec;
	temp.min = min + other.min;
	temp.hour = hour + other.hour;

	if (temp.sec > 60)
	{
		temp.sec = sec + other.sec - 60;
		temp.min++;
		if (temp.min == 60)
		{
			temp.hour++;
			temp.min = 0;
		}
		if (temp.hour == 24)
			temp.hour = 0;
	}

	if (temp.min > 60)
	{
		temp.min -= 60;
		temp.hour++;
		if (temp.hour == 24)
			temp.hour = 0;
	}

	if (temp.hour > 24)
		temp.hour -= 24;
	return temp;
}

Time Time::operator -(const Time& other)
{
	Time temp;
	temp.sec = this->sec - other.sec;
	temp.min = this->min - other.min;
	temp.hour = this->hour - other.hour;
	if (temp.sec < 0)
	{
		temp.sec += 60;
		temp.min--;
		if (temp.min < 0)
		{
			temp.min += 60;
			temp.hour--;
		}
		if (temp.hour < 0)
			temp.hour += 24;
	}
	if (temp.min < 0)
	{
		temp.min += 60;
		temp.hour--;
		if (temp.hour < 0)
			temp.hour += 24;
	}
	if (temp.hour < 0)
		temp.hour += 24;

	return temp;
}

string Time::toString()
{
	string str, str2;
	int a;
	a = hour;
	str = to_string(a);
	str += ".";
	a = min;
	str2 = to_string(a);
	str += str2 + ".";
	a = sec;
	str2 = to_string(a);
	str += str2;
	return str;
}
