#include <iostream>
#include "countingsort.hpp"
#include "io.hpp"

int main(int argc, char* argv[]) {
  auto a = to_vector<unsigned>(argc, argv);
  try {
    print(countingsort(a));
  } catch (std::invalid_argument const& e) {
    std::cout << e.what();
  }
}
