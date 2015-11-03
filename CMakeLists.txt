CMAKE_MINIMUM_REQUIRED( VERSION 2.8)

PROJECT(calculator-server)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(LWAN_JSON_NAME  "lwan_json")

find_package(ZLIB REQUIRED)

set(SOURCES src/calculator.cpp src/main.cpp)

file(GLOB_RECURSE HEADERS include/ *.h*)

include_directories(include/)
include_directories(include/3rdparty/)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})

add_library(${LWAN_JSON_NAME} SHARED src/3rdparty/json.c)

add_dependencies(${CMAKE_PROJECT_NAME} ${LWAN_JSON_NAME})

set_property(TARGET ${CMAKE_PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS "-std=c++11 -Wall -pedantic -Wextra -Weffc++ -Werror -O3 -finline-functions -finline-limit=64")

target_link_libraries(${CMAKE_PROJECT_NAME} lwan-common.a ${ZLIB_LIBRARIES} pthread dl ${LWAN_JSON_NAME})
