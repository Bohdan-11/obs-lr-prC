cmake_minimum_required(VERSION 3.10)
project(proj4-linear-algebra C)
add_executable(linmath main.c linalg.c)
# линковка с math
target_link_libraries(linmath PRIVATE m)