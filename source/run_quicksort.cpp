#include <iostream>
#include "io.hpp"
#include "quicksort.hpp"

bool use_double(int argc, char* argv[]) {
  char c = '\0';
  for (int i = 0; i < argc; ++i) {
    int j = 0;
    while((c = argv[i][++j]) != '\0') {
      if (c == '.')
        return true;
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  try {
    if (use_double(argc, argv)) {
      auto a = to_vector<double>(argc, argv);
      print(quicksort(a));
    }
    else {
      a = to_vector<int>(argc, argv);
      print(quicksort(a));
    }
  } catch (std::invalid_argument const& e) {
    std::cout << e.what();
  }
}
