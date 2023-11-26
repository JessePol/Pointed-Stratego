#include <stdio.h>
#include <stdlib.h>

int** createBoard(int rows, int columns) {
    // Allocate an array of pointers
    int **board = malloc(rows * sizeof(int*));
    if (board == NULL) {
        return NULL;
    }

    // Allocate each row
    for (int i = 0; i < rows; i++) {
        board[i] = malloc(columns * sizeof(int));
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

void freeBoard(int **board, int rows) {
    if (board != NULL) {
        // Free each row
        for (int i = 0; i < rows; i++) {
            free(board[i]);
        }
        // Free the array of pointers
        free(board);
    }
}

int main() {
    bool isPlayerOnesTurn = true;

    int rows = 5;
    int columns = 5;

    int **board = createBoard(rows, columns);

    int value = board[1][1];

    printf("Test value: %d", value);

    freeBoard(board, rows);
    return 0;
}
