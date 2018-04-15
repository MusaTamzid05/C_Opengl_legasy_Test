cmake_minimum_required(VERSION 2.8)

project(testas)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


file(GLOB SOURCES "src/*c")
add_executable(testas ${SOURCES})
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} include )

target_link_libraries(testas ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} GL GLU dl  m)
