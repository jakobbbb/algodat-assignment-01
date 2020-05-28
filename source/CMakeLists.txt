add_library(sort
    countingsort.cpp
    quicksort.hpp
    )

add_executable(count run_countingsort.cpp)
target_link_libraries(count sort)
add_executable(quick run_quicksort.cpp)
target_link_libraries(quick sort)

add_executable(tests tests.cpp)
target_link_libraries(tests sort)

# generate compile_commands.json
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
