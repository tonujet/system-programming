cmake_minimum_required(VERSION 3.26)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab2 main.cpp
        Car.cpp
        TaxiCompany.cpp
        Owner.cpp
        CarView.cpp
        UserInterface.cpp
        OwnerView.h
        OwnerView.cpp)
