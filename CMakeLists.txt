cmake_minimum_required(VERSION 3.10)
project(ProyectoFinalAlgoritmos)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProyectoFinalAlgoritmos main.cpp)
add_executable(radixSort radixSort.cpp)
add_executable(mergeSort mergeSort.cpp)
add_executable(quickSort quickSort.cpp)
add_executable(bubbleSort bubbleSort.cpp)