cmake_minimum_required(VERSION 3.14)
project(ProjetoED C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(geometros GEO)
aux_source_directory(arvores ARV)
add_executable(ProjetoED main.c ${GEO} ${ARV})
target_link_libraries(ProjetoED m)