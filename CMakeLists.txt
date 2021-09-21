cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

project(client_ras VERSION 0.1.0)

set(CMAKE_PREFIX_PATH E:/solomatin/boost/)
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(agent_ras)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC agent_ras)

target_link_libraries(${PROJECT_NAME} agent_ras)

set(CMAKE_CXX_FLAGS "-municode")