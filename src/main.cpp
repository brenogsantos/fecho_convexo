#include <iostream>

#include "../include/manager.h"

int main() {
  std::cout << "bbbb\n";
  managerInit();
  readFile("entrada10.txt");
  managerFinish();
  return 0;
}
