#include <iostream>

#include "../include/manager.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: make run filename=<filename>" << std::endl;
    return 1;
  }
  std::string filename = argv[1];
  managerInit();
  //  readFile("ENTRADA1000.txt");
  readFile(filename);
  managerFinish();
  return 0;
}
