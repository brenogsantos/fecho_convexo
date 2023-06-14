#include "../include/manager.h"

Point* points = nullptr;

void managerInit() { points = nullptr; }

void readFile(const std::string filename) {
  int point_counter = 0;

  std::string line;

  std::ifstream file(filename);

  if (file.is_open()) {
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
  }
  clock_t start = clock();
  grahamScan(points, point_counter, MERGE_SORT, 1);
  clock_t end = clock();
  double timeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "\nGRAHAM+MERGESORT: " << std::fixed << std::setprecision(3)
            << timeInSeconds << "s\n";

  start = clock();
  grahamScan(points, point_counter, INSERTION_SORT, 0);
  end = clock();
  timeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "GRAHAM+INSERTIONSORT: " << std::fixed << std::setprecision(3)
            << timeInSeconds << "s\n";

  start = clock();
  grahamScan(points, point_counter, COUNTING_SORT, 0);
  end = clock();
  timeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "GRAHAM+LINEAR: " << std::fixed << std::setprecision(3)
            << timeInSeconds << "s\n";

  start = clock();
  jarvisMarch(points, point_counter);
  end = clock();
  timeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "JARVIS: " << std::fixed << std::setprecision(3) << timeInSeconds
            << "s\n";
}

void managerFinish() { delete[] points; }

void printPoints(int counter) {
  for (int i = 0; i < counter; i++) {
    std::cout << "Point " << i + 1 << ": alfa = " << points[i].alfa
              << ", beta = " << points[i].beta;
  }
}

