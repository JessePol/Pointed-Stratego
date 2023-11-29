//
// Created by jesse on 26-11-23.
//

typedef struct {
    int strength;
    bool isPlayerOne;
} Pieces;

typedef struct {
    int rows;
    int columns;
    Pieces*** gameBoard;
} Board;


Pieces*** createBoard(int rows, int columns);
void freeBoard(Pieces ***board, int rows, int columns);
void printBoard(Pieces ***board, int rows, int columns);

#ifndef POINTEDSTRATEGO_BOARD_H
#define POINTEDSTRATEGO_BOARD_H

#endif //POINTEDSTRATEGO_BOARD_H
