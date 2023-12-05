//
// Created by jesse on 26-11-23.
//

#include "piece.h"

typedef struct {
    int rows;
    int columns;
    Piece*** gameBoard;
} Board;


Piece*** createBoard(int rows, int columns);
void freeBoard(Piece ***board, int rows, int columns);
void printBoard(Piece ***board, int rows, int columns);
Piece*** initializeBoard(int rows, int columns);

#ifndef POINTEDSTRATEGO_BOARD_H
#define POINTEDSTRATEGO_BOARD_H

#endif //POINTEDSTRATEGO_BOARD_H
