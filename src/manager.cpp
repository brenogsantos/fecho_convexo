#include "../include/manager.h"

Point* points = nullptr;

void managerInit() { points = nullptr; }

void readFile(const std::string filename) {
  int point_counter = 0;

  std::string line;

  std::ifstream file(filename);

  if (file.is_open()) {
    std::cout << "aaaa\n";
    while (std::getline(file, line)) {
      std::istringstream iss(line);

      Point new_point;
      iss >> new_point.alfa;
      iss >> new_point.beta;

      Point* new_array = new Point[point_counter + 1];

      for (int i = 0; i < point_counter; i++) {
        new_array[i] = points[i];
      }

      new_array[point_counter] = new_point;

      delete[] points;

      points = new_array;

      point_counter++;
    }
    file.close();

    printPoints(point_counter);
  }
}

void managerFinish() { delete[] points; }

void printPoints(int counter) {
  std::cout << "aaaaaaaa\n";
  for (int i = 0; i < counter; i++) {
    std::cout << "Point " << i + 1 << ": alfa = " << points[i].alfa
              << ", beta = " << points[i].beta << std::endl;
  }
}

