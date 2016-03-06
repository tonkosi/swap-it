cmake_minimum_required(VERSION 3.0)
project(SwapIt)

include_directories("include")

set(MAIN_EXECUTABLE "swapit")

file(GLOB PROJ_SOURCES src/*.cc src/*/*.cc src/*/*/*.cc)
set(SOURCES ${PROJ_SOURCES})

add_executable(
  ${MAIN_EXECUTABLE}
  ${SOURCES}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(SFML 2 REQUIRED graphics window system)
include_directories(${SFML_INCLUDE_DIR})

find_package(EntityX REQUIRED)
include_directories(${ENTITYX_INCLUDE_DIR})

target_link_libraries(
  ${MAIN_EXECUTABLE}
  ${OPENGL_LIBRARIES}
  ${SFML_LIBRARIES}
  ${ENTITYX_LIBRARY}
)

