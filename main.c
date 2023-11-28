#include <stdio.h>
#include <stdlib.h>

#include "src/board.h"


Pieces* createPiece(bool isPlayerOne, int strength){
    Pieces *newPiece = (Pieces *)malloc(sizeof(Pieces));
    newPiece->isPlayerOne = isPlayerOne;
    newPiece->strength = strength;

    return newPiece;
}

Pieces*** initializeBoard(int rows, int columns){
    Pieces ***board = createBoard(rows, columns);
    Pieces* newPiece = createPiece(true, 10);
    board[1][1] = newPiece;


    return board;
}


int main() {
    bool isPlayerOnesTurn = true;

    int rows = 5;
    int columns = 5;

    Pieces ***board = initializeBoard(rows, columns);

    printBoard(board, rows, columns);

    freeBoard(board, rows, columns);
    return 0;
}
