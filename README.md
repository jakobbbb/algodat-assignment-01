# Algorithms and Data Structure Assignment 01

First assignment for AlgoDat, Summer Semester 2020.

Task:  Implement **quicksort** and **countingsort**.

## Building
```sh
mkdir build
cd build
cmake ..
make
```
Executables will be in `build/source`.

## Running Tests

`catch.hpp` is used for the unit tests.  They can be run from the
`build/source` directory as `./tests` and are also automatically run
on [GitHub](https://github.com/jakobbbb/algodat-assignment-01).

## Running With Custom Inuput

Within `build/source`, executables are provided that sort
space-separated lists of numbers:

### Countingsort

```sh
[jakob@neon source]$ ./count 6 1 2 4 1 3 4 6 1 3 2
1 1 1 2 2 3 3 4 4 6 6
```

Note that the algorithm will only work on positive integers.

```sh
[jakob@neon source]$ ./count
(empty)
[jakob@neon source]$ ./count 1 2 0 3
elements must be positive!
[jakob@neon source]$ ./count 1 2 -1 3
elements must be positive!
[jakob@neon source]$ ./count 3 1 a 2
Warning: ignoring invalid argument 'a'.
1 2 3
```
