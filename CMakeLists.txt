cmake_minimum_required ( VERSION 2.8)
project ( MEDRV_TP7 )

# sources extension
set(SRCEXT "cpp")

# setting the compiler to c++11
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


file(
    GLOB_RECURSE
    source_files
    *.${SRCEXT}
)

# required packages
find_package ( OpenCV REQUIRED )

# adding the source files to the executable
add_executable(MEDRV_TP7  DTC_converter.cpp)

# linking other libraries
target_link_libraries(MEDRV_TP7   ${OpenCV_LIBS})
