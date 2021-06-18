cmake_minimum_required(VERSION 3.10.2)

project("fbjni_demo")

find_library(log-lib log)
find_package(fbjni REQUIRED CONFIG)

add_library(fbjni_demo SHARED
        OnLoad.cpp
        DemoClassCppSide.cpp)

target_link_libraries(fbjni_demo
        ${log-lib}
        fbjni::fbjni)