cmake_minimum_required(VERSION 3.5.1)

project(my_project)

include_directories(inc)

set(SOURCES src/function.cpp)

add_executable(my_app ${SOURCES})
add_library(function-staticlib STATIC ${SOURCES})

target_link_libraries(my_app PUBLIC function-staticlib)
target_include_directories(my_app PUBLIC function-staticlib)

install(TARGETS function-staticlib DESTINATION ${CMAKE_CURRENT_SOURCES_DIR}/..)
