//
// Created by jesse on 26-11-23.
//

#include "board.h"
#include <stdlib.h>
#include <stdio.h>

Piece*** createBoard(int rows, int columns) {
    Piece ***board = (Piece***)malloc(rows * sizeof(Piece***));

    if (board == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        board[i] = (Piece**)malloc(columns * sizeof(Piece*));

        if (board[i] == NULL) {

            for (int j = 0; j < i; j++) {
                free(board[j]);
            }
            free(board);
            return NULL;
        }
    }

    return board;
}

void freeBoard(Piece ***board, int rows, int columns) {
    if (board != NULL) {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                free(board[i][j]);
            }
        }

        for (int i = 0; i < rows; i++) {
            free(board[i]);
        }

        free(board);
    }
}

void printBoard(Piece ***board, int rows, int columns) {
    printf("   ");
    for (int col = 0; col < columns; col++) {
        printf("%2d ", col);
    }
    printf(" X\n");

    for (int i = 0; i < rows; i++) {
        printf("%2d ", i);

        for (int j = 0; j < columns; j++) {
            if (board[i][j] != NULL) {
                if(board[i][j]->isPlayerOne) {
                    printf("%2d ", board[i][j]->strength);
                }
                else {
                    printf(" ? ");
                }
            } else {
                printf(" # ");
            }
        }
        printf("\n");
    }
    printf(" Y\n");
}

Piece*** initializeBoard(int rows, int columns){
    Piece ***board = createBoard(rows, columns);
    Piece* newPiece = createPiece(true, 6);
    board[3][2] = newPiece;

    Piece* enemyStrongerPiece = createPiece(false, 5);
    board[1][1] = enemyStrongerPiece;

    Piece* enemySamePiece = createPiece(false, 6);
    board[1][2] = enemySamePiece;

    Piece* enemyWeakerPiece = createPiece(false, 7);
    board[1][3] = enemyWeakerPiece;

    return board;
}