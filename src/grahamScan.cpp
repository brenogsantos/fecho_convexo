#include "../include/grahamScan.h"

#include "../include/sorters.h"
template class Stack<Point>;

Point p0;

Point secondTop(Stack<Point>& stack) {
  Point tempPoint = stack.getTop();
  stack.pop();
  Point res = stack.getTop();
  stack.push(tempPoint);
  return res;
}

int orientation(Point p, Point q, Point r) {
  int val = (q.beta - p.beta) * (r.alfa - q.alfa) -
            (q.alfa - p.alfa) * (r.beta - q.beta);
  if (val == 0)
    return 0;
  else if (val > 0)
    return 1;
  else
    return 2;
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

  if (orientation(p0, *p1, *p2) == 0) {
    if (distSq(p0, *p2) >= distSq(Point{0, 0}, *p1))
      return -1;
    else
      return 1;
  }

  else if (orientation(p0, *p1, *p2) == 2)
    return -1;
  else
    return 1;
}
void grahamScan(Point* points, int n, TIPO_SORT tipo_sort, int print_flag) {
  if (n < 3) {
    std::cout << "Fecho Convexo não é possível\n";
    return;
  }

  Point* pointsCopy = new Point[n];
  std::copy(points, points + n, pointsCopy);

  int beta_min = pointsCopy[0].beta;
  int minIdx = 0;
  for (int i = 1; i < n; i++) {
    int beta = pointsCopy[i].beta;

    if ((beta < beta_min) ||
        (beta_min == beta && pointsCopy[i].alfa < pointsCopy[minIdx].alfa)) {
      beta_min = pointsCopy[i].beta;
      minIdx = i;
    }
  }

  swap(pointsCopy[0], pointsCopy[minIdx]);

  p0 = pointsCopy[0];
  switch (tipo_sort) {
    case MERGE_SORT:
      mergeSort(&pointsCopy[1], 0, n - 2, compare);
      break;
    case INSERTION_SORT:
      insertionSort(pointsCopy, n, compare);
      break;
    case COUNTING_SORT:
      countingSort(pointsCopy, n, compare);
      break;
    default:
      break;
  }

  int arrSize = 1;
  for (int i = 1; i < n; i++) {
    while (i < n - 1 && orientation(p0, pointsCopy[i], pointsCopy[i + 1]) == 0)
      i++;
    pointsCopy[arrSize] = pointsCopy[i];
    arrSize++;
  }

  Stack<Point> stack(n);

  stack.push(pointsCopy[0]);
  stack.push(pointsCopy[1]);
  stack.push(pointsCopy[2]);

  for (int i = 3; i < n; i++) {
    while (orientation(secondTop(stack), stack.getTop(), pointsCopy[i]) != 2)
      stack.pop();

    stack.push(pointsCopy[i]);
  }

  stack.invert();
  if (print_flag) std::cout << "FECHO CONVEXO:\n";
  const int numRetas = n - 1;
  Reta retas[numRetas];
  int retaIndex = 0;

  Point prevPoint = stack.pop();
  if (print_flag) std::cout << prevPoint.alfa << " " << prevPoint.beta << "\n";
  while (!stack.isEmpty()) {
    Point currentPoint = stack.pop();

    if (print_flag)
      std::cout << currentPoint.alfa << " " << currentPoint.beta << "\n";
    Reta reta;
    reta.p1 = prevPoint;
    reta.p2 = currentPoint;
    retas[retaIndex++] = reta;
    prevPoint = currentPoint;
  }
  delete[] pointsCopy;
}

