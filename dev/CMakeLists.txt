cmake_minimum_required(VERSION 3.25)

project(spherical_area)

add_executable(spherical_area spherical_area.cpp)

cmake_path(SET BOOST_DIR NORMALIZE ${CMAKE_SOURCE_DIR}/../../..)

target_include_directories(spherical_area 
    PRIVATE ${CMAKE_SOURCE_DIR}/../include
    PRIVATE ${BOOST_DIR}
)