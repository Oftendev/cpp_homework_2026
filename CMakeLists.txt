cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-Wall)
add_definitions(-DPATH_TO_DATA="${CMAKE_CURRENT_SOURCE_DIR}/")

set(SOURCES 
    main.cpp 
    QuadEquation.cpp 
    Student.cpp 
    Email.cpp 
    Teacher.cpp
)

add_executable(program ${SOURCES})
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/equations.txt"
    "${CMAKE_CURRENT_BINARY_DIR}/equations.txt"
    COPYONLY
)
