cmake_minimum_required(VERSION 3.12)
project(proj1-files-and-structs C) # имя проекта и язык
set(SRC_LIST main.c data.c) # список исходников
add_executable(proj1 ${SRC_LIST}) # создаём исполняемый файл из исходников
target_include_directories(proj1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# ^ включаем текущий каталог в пути для заголовочных файлов (чтобы data.h находился)
target_link_libraries(proj1 PUBLIC m)
# ^ линковка с математической библиотекой libm (аналог -lm)
