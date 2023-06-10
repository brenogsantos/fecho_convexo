#include <iostream>

#include "../include/manager.h"

int main() {
  std::cout << "bbbb\n";
  managerInit();
  readFile("ENTRADA100.txt");
  managerFinish();
  return 0;
}
