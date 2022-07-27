cmake_minimum_required(VERSION 3.15)

project("Qubit Simulator" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable("QubitSim" source.cpp Qubit.cpp Qubit.h)