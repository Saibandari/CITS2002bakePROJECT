# cmake_minimum_required(VERSION <specify CMake version here>)
project(bake C)

set(CMAKE_C_STANDARD 99)

add_executable(bake main.c open_bakefile.c comment_check.c read_file_into_buf.c find_replace_text.c variable_definition.c bake.h readcontinuationlines.c trimline.c nextline.c)