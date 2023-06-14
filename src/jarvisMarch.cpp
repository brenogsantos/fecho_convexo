#include "../include/jarvisMarch.h"

template class Stack<Point>;
void jarvisMarch(Point points[], int n) {
  if (n < 3) {
    std::cout << "Fecho Convexo não é possível\n";
    return;
  }

  Stack<Point> fecho_convexo(n);

  int leftmostIdx = 0;
  for (int i = 1; i < n; i++) {
    if (points[i].alfa < points[leftmostIdx].alfa) {
      leftmostIdx = i;
    }
  }

  int p = leftmostIdx;
  int q;
  do {
    fecho_convexo.push(points[p]);
    q = (p + 1) % n;
    for (int i = 0; i < n; i++) {
      if (orientation(points[p], points[i], points[q]) == 2) {
        q = i;
      }
    }
    p = q;
  } while (p != leftmostIdx);
}

