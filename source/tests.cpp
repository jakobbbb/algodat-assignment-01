#define CATCH_CONFIG_MAIN
#include "io.hpp"
#include <catch2/catch.hpp>
#include <array>
#include <iostream>

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
