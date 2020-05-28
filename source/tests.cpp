#define CATCH_CONFIG_MAIN
#include "io.hpp"
#include "countingsort.hpp"
#include <catch2/catch.hpp>
#include <array>
#include <iostream>


SCENARIO("countingsort", "[countingsort]") {

  const std::vector<unsigned> a_sorted{1, 1, 2, 4, 4, 5, 6, 7, 9, 13};
  const std::vector<unsigned> a_unsorted{4, 2, 6, 1, 5, 13, 4, 1, 7, 9};
  const std::vector<unsigned> b_sorted{1, 1, 1, 2, 2, 3, 3, 4, 4, 6, 6};
  const std::vector<unsigned> b_unsorted{6, 1, 2, 4, 1, 3, 4, 6, 1 , 3, 2};
  GIVEN("sorted vectors of unsigned") {
    REQUIRE(countingsort(a_sorted) == a_sorted);
    REQUIRE(countingsort(b_sorted) == b_sorted);
  }
  GIVEN("unsorted vectors of unsigned") {
    REQUIRE(countingsort(a_unsorted) == a_sorted);
    REQUIRE(countingsort(b_unsorted) == b_sorted);
  }

  const std::vector<unsigned> empty{};
  GIVEN("an empty vector of unsigned") {
    REQUIRE(countingsort(empty) == empty);
  }

  const std::vector<unsigned> one{1};
  GIVEN("a one-element vector of unsigned") {
    REQUIRE(countingsort(one) == one);
  }

  const std::vector<unsigned> two_sorted{2, 4};
  const std::vector<unsigned> two_unsorted{4, 2};
  GIVEN("two-element vectors of unsigned") {
    REQUIRE(countingsort(two_sorted) == two_sorted);
    REQUIRE(countingsort(two_unsorted) == two_sorted);
  }

  const std::vector<unsigned> one_zero{0};
  std::vector<unsigned> has_zero{a_unsorted};
  has_zero[has_zero.size() - 1] = 0;
  GIVEN("vectors containing zeroes") {
    REQUIRE_THROWS(countingsort(one_zero));
    REQUIRE_THROWS(countingsort(has_zero));
  }
}

SCENARIO("quicksort", "[quicksort]") {
}

SCENARIO("print", "[print]") {
  GIVEN("an empty vector of integers") {
    std::vector<int> a{};
    THEN("print it") {
      CHECK_NOTHROW(print(a));
    }
  }
  GIVEN("an non-empty vector of integers") {
    std::vector<int> a{-1, 0, 1, 2, 3, 42, 1, 3, 4};
    THEN("print it") {
      CHECK_NOTHROW(print(a));
    }
  }
  GIVEN("an non-empty vector of doubles") {
    std::vector<double> a{-1.2, 0.5, 1.12, 2.534, 1.234, 42.2, 1.4, 3.61, 4.0};
    THEN("print it") {
      CHECK_NOTHROW(print(a));
    }
  }
}

SCENARIO("read input", "[read]") {
  GIVEN("no input") {
    int argc = 1;
    char* argv[] = {(char*)""};
    auto xs = to_vector<int>(argc, argv);
    REQUIRE(xs.empty());
  }
  GIVEN("invalid input") {
    int argc = 4;
    char* argv[] = {(char*)"", (char*)"X", (char*)"Y", (char*)"Z"};
    auto xs = to_vector<double>(argc, argv);
    REQUIRE(xs.empty());
  }
  GIVEN("valid integer input") {
    int argc = 5;
    char* argv[] = {(char*)"", (char*)"-1", (char*)"0", (char*)"42", (char*)"1"};
    auto xs = to_vector<int>(argc, argv);
    REQUIRE(xs == std::vector<int>{-1, 0, 42, 1});
  }
  GIVEN("valid double input") {
    int argc = 4;
    char* argv[] = {(char*)"", (char*)"-1", (char*)"0.4", (char*)"-4.2"};
    auto xs = to_vector<double>(argc, argv);
    REQUIRE(xs[0] == Approx(-1));
    REQUIRE(xs[1] == Approx(0.4));
    REQUIRE(xs[2] == Approx(-4.2));
    REQUIRE(xs.size() == 3);
  }
  GIVEN("partially valid integer input") {
    int argc = 5;
    char* argv[] = {(char*)"", (char*)"-1", (char*)"0", (char*)"X", (char*)"1"};
    auto xs = to_vector<int>(argc, argv);
    REQUIRE(xs == std::vector<int>{-1, 0, 1});
  }
  GIVEN("partially valid double input") {
    int argc = 4;
    char* argv[] = {(char*)"", (char*)"-1", (char*)"0.4", (char*)"X"};
    auto xs = to_vector<double>(argc, argv);
    REQUIRE(xs[0] == Approx(-1));
    REQUIRE(xs[1] == Approx(0.4));
    REQUIRE(xs.size() == 2);
  }
}
