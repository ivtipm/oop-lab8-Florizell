#pragma once
#include "Time.h"
#include <string>
#include <vector>

using namespace std;

unsigned countObj(string filename); // Счетчик объектов в файле
void objTofile(Time obj, string filename); // Запись объекта в файл
vector <Time> fileToobj(string filename); // Запись объекта в файл