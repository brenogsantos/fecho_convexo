#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/Stack.h"

struct Point {
  int alfa;
  int beta;
};

extern Point* points;

void managerInit();
void managerFinish();
void readFile(const std::string);
void printPoints(int);
