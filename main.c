#include <stdio.h>
#include "src/board.h"

int main() {
    bool isPlayerOnesTurn = true;

    int rows = 5;
    int columns = 5;

    Pieces ***board = createBoard(rows, columns);

    Pieces *value_pointer = board[1][1];

    freeBoard(board, rows, columns);
    return 0;
}
