add_executable(countingsort
    countingsort.cpp
    )

add_executable(tests
    tests.cpp
    io.hpp
    )

# generate compile_commands.json
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
