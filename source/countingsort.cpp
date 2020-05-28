#include "countingsort.hpp"
#include <vector>
#include <iostream>

/**
 * Sort a vector of positive integers <= k using countingsort.
 */
std::vector<unsigned> countingsort(std::vector<unsigned> const& a, unsigned k) {
  unsigned n = a.size();
  auto b = std::vector<unsigned>(n, 0);
  auto c = std::vector<unsigned>(k, 0);

  // count occurences at i-1, also check if all emenents are positive
  for (unsigned i = 0; i < n; ++i) {
    if (a[i] == 0)
      throw std::invalid_argument("elements must be positive!");
    c[a[i] - 1]++;
  }

  // count total number of elements less or equal than i-1
  for (unsigned i = 1; i < k; ++i)
    c[i] += c[i-1];

  // put elements from a in correct place in c
  for (int i = n - 1; i >= 0; --i) {
    b[c[a[i]-1]-1] = a[i];
    --c[a[i]-1];
  }

  return b;
}


/**
 * Sort a vector of positive integers using countingsort.
 */
std::vector<unsigned> countingsort(std::vector<unsigned> const& a) {
  unsigned k = 0;
  for (unsigned x : a) {
    if (x > k)
      k = x;
  }
  return countingsort(a, k);
}
