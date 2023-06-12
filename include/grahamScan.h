#ifndef GRAHAMSCAN_H
#define GRAHAMSCAN_H
#include "manager.h"

int orientation(Point p, Point q, Point r);
void swap(Point& p1, Point& p2);
int distSq(Point p1, Point p2);
int compare(const Point* vp1, const Point* vp2);
void grahamScan(Point points[], int n, TIPO_SORT, int print_flag);

#endif  // GRAHAMSCAN_H
