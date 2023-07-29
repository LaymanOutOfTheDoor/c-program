cmake_minimum_required(VERSION 3.25)
file(GLOB SRC_FILES *.c)

project(sub_projcet)

include_directories(${PROJECT_BINARY_DIR})# 自己后加的



if (${POOL_SIZE})
    set(WORKER_POOL_SIZE ${POOL_SIZE})
endif ()
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/aaa)
# set_target_properties(mylib PROPERTIES PREFIX "lib/")

configure_file(config.h.cmake config.h)# Error---->configure_file(${PROJECT_SOURCE_DIR}/config.h.cmake ${PROJECT_BINARY_DIR}/config.h)

add_library(mylib SHARED ${SRC_FILES})
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    # Windows下的定义
    add_definitions(-DWINDOWS_DEFINITION)
    # 使用target_link_libraries命令将库mylib与pthread库进行链接。pthread库用于支持多线程编程。可以带-l也可以不带。
    target_link_libraries(mylib # windows 下
            PUBLIC -lpthread    # windows 下
            PRIVATE             # windows 下
            ws2_32)             # windows 下
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    # Linux下的定义
    add_definitions(-DLINUX_DEFINITION)
    target_link_libraries(mylib pthread)
endif ()
message(lib：CMAKE_SOURCE_DIR:----> ${CMAKE_SOURCE_DIR})
message(lib：CMAKE_BINARY_DIR:----> ${CMAKE_BINARY_DIR})
message(lib：CMAKE_CURRENT_SOURCE_DIR:----> ${CMAKE_CURRENT_SOURCE_DIR})
message(lib：CMAKE_BINARY_DIR:----> ${CMAKE_BINARY_DIR})
message(lib：CMAKE_CURRENT_BINARY_DIR:----> ${CMAKE_BINARY_DIR})
message(lib：PROJECT_BINARY_DIR:----> ${PROJECT_BINARY_DIR})
message(lib：PROJECT_SOURCE_DIR:----> ${PROJECT_SOURCE_DIR})