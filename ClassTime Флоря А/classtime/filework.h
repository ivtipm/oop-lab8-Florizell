#pragma once
#include "Time.h"
#include <string>
#include <vector>

using namespace std;

unsigned countObj(string filename); // ������� �������� � �����
void objTofile(Time obj, string filename); // ������ ������� � ����
vector <Time> fileToobj(string filename); // ������ ������� � ����