cmake_minimum_required(VERSION 3.2)
project(app VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PQXX)
find_path(LIBPQXX_INCLUDE_DIR pqxx)
find_library(LIBPQXX_LIBRARY liblibpqxx_static.a)
#include_directories(${LIBPQXX_INCLUDE_DIR})

find_package (Threads)

add_executable(app 
    main.cpp
    address.cpp
    db/postgres.cpp
    db/require/requireDb.cpp
    connectedIp/runConnected.cpp
)

target_link_libraries(app Threads::Threads pqxx)
