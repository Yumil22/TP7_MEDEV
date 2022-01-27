# 1. Indicate the required version of CMake (we want version 3.0) :
# ...

CMAKE_MINIMUM_REQUIRED ( VERSION 3.0 )

# 2. Indicate the name of the project :
# ...

project ( JPEG )

# Binaries will be saved there
# ${PROJECT_SOURCE_DIR} is a variable, it is the top level source directory for the current project.

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

set(CMAKE_CXX_STANDARD 11) # set Cpp11

# Set coverage compilation option if in UNIX
if (UNIX)
    find_program(GCOV_PATH gcov REQUIRED)
    find_program(LCOV_PATH lcov REQUIRED)
    set(CMAKE_CXX_FLAGS "--coverage")
endif(UNIX)

# Allow include to use paths relative to project root

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/googletest/googletest/include) # add the include directory of google test
#TODO : update path



# create target
# 3. Uncomment these two next lines and complete them.
# The first executable is for running the tests, add all needed files for the tests.
# The second executable is for running the main code, add all needed files for the code to compile.
# Note : you can write all files by hand or use file(GLOB...) or file(GLOB_RECURSE...)

# Main project entry point
file(GLOB SRC_MAIN
    "src/main.cpp"
)

# Main project sources, without main
file(GLOB_RECURSE SRC_FILES
    "src/**.cpp"
)
list(REMOVE_ITEM SRC_FILES ${SRC_MAIN})

# Tests sources
file(GLOB GTESTS
    "tests/**.cpp"
)

# create target
add_executable(project ${SRC_MAIN} ${SRC_FILES})
add_executable(run_tests tests/tests.cpp ${GTESTS} ${SRC_FILES})

# link gtest (and pthread on Unix) to run_tests project
target_link_libraries(run_tests ${CMAKE_SOURCE_DIR}/build_gtest/lib/libgtest.a)
#TODO : update path