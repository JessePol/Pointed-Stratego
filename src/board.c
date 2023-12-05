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
            // Free previously allocated rows in case of failure
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
        // Free
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                free(board[i][j]);
            }
        }
        // Free each row
        for (int i = 0; i < rows; i++) {
            free(board[i]);
        }
        // Free the array of pointers
        free(board);
    }
}

void printBoard(Piece ***board, int rows, int columns) {
    // Printing column headers (1, 2, 3, ...)
    printf("   ");
    for (int col = 0; col < columns; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        // Printing row headers (A, B, C, ...)
        printf("%2d ", i);

        for (int j = 0; j < columns; j++) {
            if (board[i][j] != NULL) {
                // Print the strength of the piece
                printf("%2d ", board[i][j]->strength);
            } else {
                // Print 'X' if the cell is empty
                printf(" X ");
            }
        }
        printf("\n");
    }
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