cmake_minimum_required(VERSION 3.4.1)
add_library(unaligned-test
            SHARED
            src/main/cpp/unaligned_test.cpp )

target_link_libraries(unaligned-test)