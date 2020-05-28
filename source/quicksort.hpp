#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

template<typename T>
void swap(std::vector<T>& a, int i, int j) {
  T tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

template<typename T>
int partition(std::vector<T>& a, int p, int r) {
  T x = a[r];
  int i = p - 1;
  for (int j = p; j < r; ++j) {
    if (a[j] <= x) {
      ++i;
      swap(a, i, j);
    }
  }
  swap(a, i + 1, r);
  return i + 1;
}


template<typename T>
std::vector<T>& quicksort(std::vector<T>& a, int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quicksort(a, p, q-1);
    quicksort(a, q+1, r);
  }
  return a;
}


template<typename T>
std::vector<T>& quicksort(std::vector<T>& a) {
  return quicksort(a, 0, a.size() - 1);
}

#endif  // QUICKSORT_HPP
