#include "pch.h"
#include"Test.h"
#include <iostream>
#include <cassert>

using namespace std;

void test_Time_Consturctor()
{
	{
		Time a;
		assert(a.seconds() == 0);
	}
	{
		Time a;
		assert(a.minutes() == 0);
	}
	{
		Time a;
		assert(a.hours() == 0);
	}
	cout << "test_Time_Consturctor OK" << endl;
}

void test_Time_setTime()
{
	{
		Time a;
		a.setSeconds(20);
		assert(a.seconds() == 20);
	}

	{
		Time a;
		a.setMinutes(10);
		assert(a.minutes() == 10);
	}	
	
	{
		Time a;
		a.setHours(8);
		assert(a.hours() ==8);
	}
	cout << "test_Time_setTime OK" << endl;
}

void test_Time_AddTime()
{
	{
		Time a(0, 0, 30);
		a.addSeconds(100);
		assert(a.minutes() == 2 && a.seconds() == 10);
	}
	{
		Time a(0, 50, 0);
		a.addMinutes(30);
		assert(a.hours() == 1 && a.minutes() == 20);
	}
	
	{
		Time a(3, 0, 0);
		a.addHours(34);
		assert(a.hours() == 13);
	}
	cout << "test_Time_AddTime OK" << endl;
}

void test_Time_TransferTime()
{
	{
		Time a(0, 40, 0);
		assert(a.timeTosecond() == 2400);
	}
	{
		Time a(2, 30, 0);
		assert(a.timeTominute() == 150);
	}
	
	{
		Time a(8, 15, 0);
		assert(a.timeTohour() == 8.25);
	}
	cout << "test_Time_TransferTime OK" << endl;
}

void test_Time_opr()
{
	{
		Time a(12, 0, 0);
		Time b(10, 0, 0);
		Time c = a + b;
		assert(c.hours() == 22 && c.minutes() == 0 && c.seconds() == 0);
	}
	
	{
		Time a(0, 45, 0);
		Time b(13, 30, 0);
		Time c = a + b;
		assert(c.hours() == 14 && c.minutes() == 15 && c.seconds() == 0);
	}
	{
		Time a(0, 0, 20);
		Time b(0, 20, 50);
		Time c = a + b;
		assert(c.hours() == 0 && c.minutes() == 21 && c.seconds() == 10);
	}


	{
		Time a(0, 0, 15);
		Time b(0, 1, 25);
		Time c = a - b;
		assert(c.hours() == 23 && c.minutes() == 58 && c.seconds() == 50);
	}
	{
		Time a(22, 0, 30);
		Time b(0, 1, 30);
		Time c = a - b;
		assert(c.hours() == 21 && c.minutes() == 59 && c.seconds() == 0);
	}
	{
		Time a(10, 20, 15);
		Time b(22, 0, 30);
		Time c = a - b;
		assert(c.hours() == 12 && c.minutes() == 19 && c.seconds() == 45);
	}
	
	
	cout << "test_Time_opr OK" << endl;
}


void test_Time_AllCheck()
{
 test_Time_Consturctor();
 test_Time_setTime();
 test_Time_AddTime();
 test_Time_TransferTime();
 test_Time_opr();
}