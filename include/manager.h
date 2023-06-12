#pragma once

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Stack.h"

enum TIPO_SORT { MERGE_SORT, INSERTION_SORT, COUNTING_SORT };

struct Point {
  int alfa;
  int beta;
};

#include "grahamScan.h"
#include "jarvisMarch.h"

extern Point* points;

void managerInit();
void managerFinish();
void readFile(const std::string);
void printPoints(int);
