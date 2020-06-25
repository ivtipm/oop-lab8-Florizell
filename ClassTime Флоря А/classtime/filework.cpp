#include "pch.h"
#include "Time.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

unsigned countObj(string filename)
{
	unsigned count=0;
	Time obj;
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "Файл не открылся" << endl;
	}
	else
	{
		while (file.read((char*)&obj, sizeof(Time)))
		{
			count++;
		}
	}
	file.close();
	return count;
}

void objTofile(Time obj, string filename) 
{
	ofstream file;
	file.open(filename, ofstream::app);
	if (!file.is_open())
	{
		cout << "Файл не открылся" << endl;
	}
	else
	{
		file.write((char*)&obj, sizeof(Time));
	}
	file.close();
}

vector <Time> fileToobj(string filename)
{
	unsigned count = countObj(filename);
	vector <Time> array_obj;
	array_obj.resize(count);
	unsigned i = 0;
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		cout << "Файл не открылся" << endl;
	}
	else
	{
		while (file.read((char*)&array_obj[i], sizeof(Time)))
		{
			i++;
			if (i == count)
				break;
		}
	}
	file.close();
	return array_obj;
}