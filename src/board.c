//
// Created by jesse on 26-11-23.
//

#include "board.h"
#include <stdlib.h>

Pieces*** createBoard(int rows, int columns) {
    Pieces ***board = (Pieces***)malloc(rows * sizeof(Pieces***));

    if (board == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        board[i] = (Pieces**)malloc(columns * sizeof(Pieces*));

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

void freeBoard(Pieces ***board, int rows, int columns) {
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