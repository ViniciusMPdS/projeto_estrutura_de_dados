cmake_minimum_required(VERSION 3.30)
project(projeto_final C)

set(CMAKE_C_STANDARD 11)

add_executable(projeto_final main.c
        ListaDinamica.c
        ListaDinamica.h
        ListaDuplamenteLigada.c
        ListaDuplamenteLigada.h
        ArvoreBinaria.c
        ArvoreBinaria.h
)
