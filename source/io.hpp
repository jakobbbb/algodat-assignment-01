#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include <vector>

template<typename T>
void print(std::vector<T> const& xs) {
  int n = xs.size();
  for (int i = 0; i < n - 1; ++i) {
    std::cout << xs[i] << ' ';
  }
  if (n == 0) {
    std::cout << "(empty)";
  } else {
    std::cout << xs[n - 1];
  }
  std::cout << '\n';
}

template<typename T>
std::vector<T> to_vector(int argc, char *argv[]) {
  std::vector<T> xs;
  for (int i = 1; i < argc; ++i) {
    try {
      xs.push_back((T) std::stod(argv[i]));
    } catch (std::invalid_argument const& e) {
      std::cerr << "Warning: ignoring invalid argument '" << argv[i] << "'.\n";
    } catch (std::out_of_range const& e) {
      std::cerr << "Warning: ignoring out-of-range '" << argv[i] << "'.\n";
    }
  }
  return xs;
}
#endif  // IO_HPP
