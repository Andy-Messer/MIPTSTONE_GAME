cmake_minimum_required(VERSION 3.16)

project(MIPTSTONE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

configure_file("src/Units/prepods.txt" "${PROJECT_SOURCE_DIR}/bin/prepods.txt")

set(CMAKE_CXX_STANDARD 20)

include_directories(include/Units)
include_directories(include/menu)
include_directories(include/Stub)
include_directories(include/Card)
include_directories(include/Interaction)

add_executable(MIPTSTONE home/main.cpp)



add_subdirectory(src)

target_link_libraries(MIPTSTONE CardsLib Comm_wth_user CardPrintLib LogosLib StubLib)
