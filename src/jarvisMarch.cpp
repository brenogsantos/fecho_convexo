#include "../include/jarvisMarch.h"

template class Stack<Point>;

/*int orientation(Point p, Point q, Point r) {
  int val = (q.beta - p.beta) * (r.alfa - q.alfa) -
            (q.alfa - p.alfa) * (r.beta - q.beta);
  if (val == 0) return 0;    // collinear
  return (val > 0) ? 1 : 2;  // clockwise or counterclockwise
}*/

void jarvisMarch(Point points[], int n) {
  if (n < 3) {
    std::cout << "Fecho Convexo não é possível";
    return;
  }

  Stack<Point> fecho_convexo(n);

  // Find the leftmost point
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

  // Print the convex fecho_convexo points
  // while (!fecho_convexo.isEmpty()) {
  // Point point = fecho_convexo.pop();
  // std::cout << "(" << point.alfa << ", " << point.beta << ")\n";
  //}
}

