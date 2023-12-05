cmake_minimum_required(VERSION 3.26)
project(PointedStratego C)

set(CMAKE_C_STANDARD 23)

add_executable(PointedStratego main.c
        src/board.c
        src/board.h
        src/piece.h
        src/piece.c
        src/move.c
        src/move.h
)
