#include <iostream>

#include "../include/manager.h"

int main() {
  managerInit();
  readFile("ENTRADA1000.txt");
  managerFinish();
  return 0;
}
