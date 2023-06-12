#ifndef SORTERS_H
#define SORTERS_H
#include "manager.h"

typedef int (*CompareFunction)(const void*, const void*);
void merge(Point* arr, int left, int mid, int right, CompareFunction compare);
void mergeSort(Point* arr, int left, int right, CompareFunction compare);
void insertionSort(Point* points, int n, CompareFunction compare);
void countingSort(Point* points, int n, CompareFunction compare);
#endif  // !

