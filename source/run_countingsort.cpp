#include <iostream>
#include "countingsort.hpp"
#include "io.hpp"

int main(int argc, char* argv[]) {
  try {
    auto a = to_vector<unsigned>(argc, argv);
    print(countingsort(a));
  } catch (std::bad_alloc const& e) {
    std::cout << "elements must be positive!" << '\n';
  } catch (std::exception const& e) {
    std::cout << e.what() << '\n';
  }
}
