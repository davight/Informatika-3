add_library(df STATIC)

target_include_directories(df PUBLIC ..)

target_compile_options(df PRIVATE-Wall-Wextra-Wpedantic)
target_compile_options(df PUBLIC-std=c++20)
