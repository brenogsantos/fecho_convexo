#include "../include/sorters.h"

void merge(Point arr[], int left, int mid, int right, CompareFunction compare) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  Point* L = new Point[n1];
  Point* R = new Point[n2];

  for (int i = 0; i < n1; i++) L[i] = arr[left + i];
  for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (compare((const void*)&L[i], (const void*)&R[j]) <= 0) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  delete[] L;
  delete[] R;
}

void mergeSort(Point* arr, int left, int right, CompareFunction compare) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, compare);
    mergeSort(arr, mid + 1, right, compare);
    merge(arr, left, mid, right, compare);
  }
}

void insertionSort(Point* points, int n, CompareFunction compare) {
  for (int i = 1; i < n; i++) {
    Point key = points[i];
    int j = i - 1;

    while (j >= 0 && compare((const void*)&points[j], (const void*)&key) > 0) {
      points[j + 1] = points[j];
      j--;
    }

    points[j + 1] = key;
  }
}

void countingSort(Point* points, int n, CompareFunction compare) {
  int maxBeta = points[0].beta;
  for (int i = 1; i < n; i++) {
    if (points[i].beta > maxBeta) {
      maxBeta = points[i].beta;
    }
  }

  int* count = new int[maxBeta + 1]{0};

  for (int i = 0; i < n; i++) {
    count[points[i].beta]++;
  }

  for (int i = 1; i <= maxBeta; i++) {
    count[i] += count[i - 1];
  }

  Point* output = new Point[n];
  for (int i = n - 1; i >= 0; i--) {
    output[count[points[i].beta] - 1] = points[i];
    count[points[i].beta]--;
  }

  for (int i = 0; i < n; i++) {
    points[i] = output[i];
  }

  delete[] count;
  delete[] output;

  // Perform stable sorting of points using compare function
  for (int i = 1; i < n; i++) {
    Point key = points[i];
    int j = i - 1;
    while (j >= 0 && compare((const void*)&points[j], (const void*)&key) > 0) {
      points[j + 1] = points[j];
      j--;
    }
    points[j + 1] = key;
  }
}
