CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(PX4-EKF2-Standalone C CXX ASM)

SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(
        custom
        .
)

ADD_DEFINITIONS(
        -D__STDC_FORMAT_MACROS
)

SET(
        PROJECT_SOURCES
        main.cpp
        custom/defines.cpp
)

add_definitions(-DCONFIG_EKF2_GNSS)
add_definitions(-DCONFIG_EKF2_MAGNETOMETER)
add_definitions(-DCONFIG_EKF2_BAROMETER)

ADD_SUBDIRECTORY(ekf2)
ADD_SUBDIRECTORY(mathlib)
ADD_SUBDIRECTORY(geo)

LINK_DIRECTORIES(
)

LINK_LIBRARIES(
        ecl_EKF
        mathlib
        geo
)

ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})
