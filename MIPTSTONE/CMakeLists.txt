cmake_minimum_required(VERSION 3.16)

project(MIPTSTONE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

set(CMAKE_CXX_STANDARD 17)

configure_file("card_database.txt" "${PROJECT_SOURCE_DIR}/bin/card_database.txt")

include_directories(src/Game-core)
include_directories(src/UI)
add_subdirectory(src/Game-core)
add_subdirectory(src/UI)
add_executable(MIPTSTONE src/main.cpp)

execute_process(COMMAND python3 base_parse.py WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

target_link_libraries(MIPTSTONE Menu Cards_lib game Card_structure Card_print)
