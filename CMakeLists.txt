cmake_minimum_required(VERSION 3.23)
project(AED)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Classes)

add_executable(AED
        Classes/Class.cpp
        Classes/Class.h
        Classes/Schedule.cpp
        Classes/Schedule.h
        Classes/Student.cpp
        Classes/Student.h
        main.cpp
        menu.cpp
        menu.h Classes/Managing.cpp Classes/Managing.h Classes/Request.cpp Classes/Request.h Classes/Slot.cpp Classes/Slot.h Classes/CourseUnit.cpp Classes/CourseUnit.h)
