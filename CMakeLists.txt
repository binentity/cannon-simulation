cmake_minimum_required(VERSION 3.10)
project(CannonSimulation)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Windows path to your sfml lib folder.
if (WIN32)
    set(CMAKE_MODULE_PATH "C:/party/SFML/lib")
    set(SFML_DIR "C:/party/SFML/lib/cmake/SFML")
    include_directories("C:/party/SFML/include")
endif ()

find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

add_executable(
    CannonSimulation 
    main.cpp 
    ball.h 
    ball.cpp 
    simulation.h 
    simulation.cpp 
    cannon.h 
    cannon.cpp
    platform.cpp
    platform.h
)

target_link_libraries(CannonSimulation sfml-graphics sfml-window sfml-system)