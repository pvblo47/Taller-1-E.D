cmake_minimum_required(VERSION 3.29)
project(Taller_E_Datos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller_E_Datos main.cpp
        Node.cpp
        Node.h
        LinkedList.cpp
        LinkedList.h
        Estructura.cpp
        Estructura.h
        Dificultad.cpp
        Dificultad.h
        Solicitudes.cpp
        Solicitudes.h)
