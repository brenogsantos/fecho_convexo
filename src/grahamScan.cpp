#include "../include/grahamScan.h"

template class Stack<Point>;
Point p0;

Point secondTop(Stack<Point>& stk) {
  Point tempPoint = stk.getTop();
  stk.pop();
  Point res = stk.getTop();  // get the second top element
  stk.push(tempPoint);       // push previous top again
  return res;
}

int orientation(Point p, Point q, Point r) {
  int val = (q.beta - p.beta) * (r.alfa - q.alfa) -
            (q.alfa - p.alfa) * (r.beta - q.beta);
  if (val == 0) return 0;    // collinear
  return (val > 0) ? 1 : 2;  // clockwise or counterclockwise
}
void swap(Point& p1, Point& p2) {
  Point temp = p1;
  p1 = p2;
  p2 = temp;
}
int distSq(Point p1, Point p2) {
  return ((p2.alfa - p1.alfa) * (p2.alfa - p1.alfa)) +
         ((p2.beta - p1.beta) * (p2.beta - p1.beta));
}
int compare(const void* vp1, const void* vp2) {
  Point* p1 = (Point*)vp1;
  Point* p2 = (Point*)vp2;

  int o = orientation(p0, *p1, *p2);
  if (o == 0) return (distSq(p0, *p2) >= distSq(Point{0, 0}, *p1)) ? -1 : 1;

  return (o == 2) ? -1 : 1;
}
void grahamScan(Point points[], int n) {
  if (n < 3) {
    std::cout << "Convex hull not possible" << std::endl;
    return;
  }

  int beta_min = points[0].beta;
  int minIdx = 0;
  for (int i = 1; i < n; i++) {
    int beta = points[i].beta;

    if ((beta < beta_min) ||
        (beta_min == beta && points[i].alfa < points[minIdx].alfa)) {
      beta_min = points[i].beta;
      minIdx = i;
    }
  }

  swap(points[0], points[minIdx]);

  p0 = points[0];

  std::qsort(&points[1], n - 1, sizeof(Point), compare);

  int arrSize = 1;  // used to locate items in modified array
  for (int i = 1; i < n; i++) {
    // when the angle of ith and (i+1)th elements are same, remove points
    while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0) i++;
    points[arrSize] = points[i];
    arrSize++;
  }

  Stack<Point> stack(n);

  stack.push(points[0]);
  stack.push(points[1]);
  stack.push(points[2]);

  for (int i = 3; i < n; i++) {
    while (orientation(secondTop(stack), stack.getTop(), points[i]) != 2)
      stack.pop();

    stack.push(points[i]);
  }

  stack.invert();

  std::cout << "Convex Hull points:" << std::endl;
  while (!stack.isEmpty()) {
    Point p = stack.pop();
    std::cout << "(" << p.alfa << ", " << p.beta << ")" << std::endl;
  }
}

