# to execute, be in root folder (NOT build)
#  cmake -S . -B build
#  cmake --build build
#
# to run tests go in build : cd build
# then run test by typing : ctest
#
#



# updated from https://google.github.io/googletest/quickstart-cmake.html

cmake_minimum_required(VERSION 3.14)
project(jpeg)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

# directly fetch google test from github
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


file(GLOB_RECURSE TESTS_FILES
    "tests/**.cc"
)

enable_testing()

# testing
add_executable(
  tests
  ${TESTS_FILES}
)
# link google test to the executable
target_link_libraries(
  tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)


# main program part
# Main project entry point
file(GLOB SRC_MAIN
    "src/JPEG.cpp"
)

# Main project sources, without main
file(GLOB_RECURSE SRC_FILES
    "src/**.cpp"
)
list(REMOVE_ITEM SRC_FILES ${SRC_MAIN})

file(GLOB_RECURSE HEADER_FILES
    "src/**.h"
)


# Allow include to use paths relative to projct root
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)



add_executable(jpeg ${SRC_MAIN} ${SRC_FILES} ${HEADER_FILES})

find_package( OpenCV REQUIRED )
MESSAGE(STATUS "Include dirs ${OpenCV_INCLUDE_DIRS}")
MESSAGE(STATUS "LINK LIBRARIES ${OpenCV_LIBS}")
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(jpeg ${OpenCV_LIBS})
