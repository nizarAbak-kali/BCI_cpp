cmake_minimum_required(VERSION 3.9)
project(BCI2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS -lpthread)

add_executable(BCI2 main.cpp InternalConfig.h TrainingData.cpp TrainingData.h Neuron.cpp Neuron.h Connection.h Net.cpp Net.h csv.h)