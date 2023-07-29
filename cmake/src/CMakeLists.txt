cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 11)

project(http-server VERSION 1.0 LANGUAGES C)
# 设置默认的安装目录
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}" CACHE PATH "Default install prefix" FORCE)
endif ()
# 将 ${CMAKE_SOURCE_DIR}/../lib 目录添加为子目录，
# 并在构建时使用 ${CMAKE_SOURCE_DIR}/../lib/build 作为输出目录
add_subdirectory(${CMAKE_SOURCE_DIR}/../lib ${CMAKE_SOURCE_DIR}/../lib/build)

include_directories(${CMAKE_SOURCE_DIR}/../include)
#link_directories(${CMAKE_SOURCE_DIR}/../lib/build)

add_executable(http-server main.c)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    # Windows下的定义
    add_definitions(-DWINDOWS_DEFINITION-src)
    # ${CMAKE_SOURCE_DIR}/../lib/build
    install(FILES ${CMAKE_SOURCE_DIR}/../lib/build/libmylib.dll DESTINATION ${CMAKE_SOURCE_DIR}/../build/lib)
    # 使用target_link_libraries命令将库mylib与http-server库进行链接。
    # target_link_libraries(http-server PRIVATE ${CMAKE_SOURCE_DIR}/../lib/build/libmylib.dll)
    #    target_link_libraries(http-server PRIVATE ${CMAKE_SOURCE_DIR}/../build/lib/libmylib.dll)

    # target_link_libraries(http-server  ${CMAKE_SOURCE_DIR}/../lib/build/libmylib.dll)
    target_link_libraries(http-server  ${CMAKE_SOURCE_DIR}/../lib/build/libmylib.dll)
    # target_link_libraries(http-server PRIVATE ../lib/libmylib.dll)# D:\APP\Clion\install\CLion 2023.1.4\bin\mingw\bin/ld.exe: cannot find -l..lib/libmylib.dll
    #                                                                collect2.exe: error: ld returned 1 exit status
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    # Linux下的定义
    add_definitions(-DLINUX_DEFINITION-src)
    target_link_libraries(http-server PRIVATE ${CMAKE_SOURCE_DIR}/../build/lib/libmylib.so)
    install(FILES ${CMAKE_SOURCE_DIR}/../lib/build/libmylib.so DESTINATION ${CMAKE_SOURCE_DIR}/../build/lib)
endif ()



include_directories(${CMAKE_SOURCE_DIR}/../lib/build)

target_include_directories(http-server PUBLIC ${CMAKE_SOURCE_DIR}/../lib)


#if (WIN32)
#set(WINDOWS_EXPORT_ALL_SYMBOLS ON)
#endif ()


install(TARGETS http-server DESTINATION ${CMAKE_SOURCE_DIR}/../build/bin)
install(FILES ${CMAKE_SOURCE_DIR}/../lib/build/config.h DESTINATION ${CMAKE_SOURCE_DIR}/../include)

message(src: PROJECT_SOURCE_DIR---->: ${PROJECT_SOURCE_DIR})
message(src：PROJECT_BINARY_DIR:----> ${PROJECT_BINARY_DIR})
message(src: CMAKE_INSTALL_PREFIX---->: ${CMAKE_INSTALL_PREFIX})
message(src：CMAKE_SOURCE_DIR:----> ${CMAKE_SOURCE_DIR})
message(src：CMAKE_BINARY_DIR:----> ${CMAKE_BINARY_DIR})
message(src：CMAKE_CURRENT_SOURCE_DIR:----> ${CMAKE_CURRENT_SOURCE_DIR})
message(src：CMAKE_CURRENT_BINARY_DIR:----> ${CMAKE_CURRENT_BINARY_DIR})
