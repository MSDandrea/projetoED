cmake_minimum_required(VERSION 3.14)
project(ProjetoED C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(geometros GEO)
add_executable(ProjetoED main.c ${GEO} geometros/retangulo.c geometros/retangulo.h)
target_link_libraries(ProjetoED m)