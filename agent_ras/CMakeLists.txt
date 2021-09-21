cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 17)

project(agent_ras)

set(CMAKE_PREFIX_PATH E:/solomatin/boost/)
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_library(${PROJECT_NAME}
    agent_ras.cpp
    package.cpp
    cluster.cpp
    varint.cpp
    connector.cpp
    i_communication.cpp
    session.cpp
    license.cpp
    cluster_objects.cpp
    info_base.cpp
    working_server.cpp
    port_range.cpp
    cluster_user.cpp
    cluster_manager.cpp
    working_process.cpp
    object_lock.cpp
    connection.cpp
    )