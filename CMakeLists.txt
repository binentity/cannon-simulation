cmake_minimum_required(VERSION 3.10)
project(CannonSimulation)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(
    CannonSimulation 
    main.cpp 
    ball.h 
    ball.cpp 
    simulation.h 
    simulation.cpp 
    cannon.h 
    cannon.cpp
)

target_link_libraries(CannonSimulation sfml-graphics sfml-window sfml-system)