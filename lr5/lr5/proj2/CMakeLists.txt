cmake_minimum_required(VERSION 3.12)
project(proj2-sockets C)
add_executable(server server.c net_utils.c)
add_executable(client client.c net_utils.c)
# Можно вынести общие флаги в переменные, например, для всех:
set_target_properties(server client PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED YES)
# Включаем текущий каталог для поиска net_utils.h
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})