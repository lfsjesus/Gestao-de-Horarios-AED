cmake_minimum_required(VERSION 3.23)
project(AED)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Classes)

add_executable(AED
        Classes/Class.cpp
        Classes/Class.h
        Classes/Dados.cpp
        Classes/Dados.h
        Classes/Enrollment.cpp
        Classes/Enrollment.h
        Classes/Lecture.cpp
        Classes/Lecture.h
        Classes/Schedule.cpp
        Classes/Schedule.h
        Classes/Student.cpp
        Classes/Student.h
        main.cpp
        menu.cpp
        menu.h)
