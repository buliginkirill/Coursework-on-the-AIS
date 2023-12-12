cmake_minimum_required(VERSION 3.2)
project(writer)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenSSL)
find_package(Threads)
find_package(ZLIB)
find_package(CppKafka REQUIRED)
find_package(Poco REQUIRED COMPONENTS Foundation Util Net XML JSON Crypto NetSSL)


include_directories(config)
include_directories(database)

set (STD_CXX "c++17")
set (REDISCPP_FLAGS "-DREDISCPP_HEADER_ONLY=ON")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -std=${STD_CXX} ${REDISCPP_FLAGS}")
set (CMAKE_CXX_FLAGS_RELEASE "-O3 -g0 -std=${STD_CXX} -Wall -DNDEBUG ${REDISCPP_FLAGS}")
set (RUNTIME_OUTPUT_DIRECTORY "./build")

add_executable(writer
        config/config.cpp
        config/config.h
        database/database.cpp
        database/database.h
        database/user.cpp
        database/user.h
        writer_main.cpp
        database/user.cpp
)

set_target_properties(writer PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(writer PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

target_link_libraries(writer PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
        ${Poco_LIBRARIES}
        "PocoData"
        "PocoDataMySQL"
        "rdkafka++"
        CppKafka::cppkafka
        ZLIB::ZLIB)

