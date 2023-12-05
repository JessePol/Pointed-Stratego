#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "src/board.h"
#include "src/move.h"

bool turn(Piece*** board, bool isPlayerOne){
    int xCoordinate;
    int yCoordinate;

    printf("Enter the X coordinate: ");
    scanf("%d", &xCoordinate);

    printf("Enter the Y coordinate: ");
    scanf("%d", &yCoordinate);

    Move originalMove;
    originalMove.xCoordinate = xCoordinate;
    originalMove.yCoordinate = yCoordinate;

    Piece* selected_piece = board[originalMove.xCoordinate][originalMove.yCoordinate];

    if (selected_piece == NULL){
        printf("You selected an empty field.");
        return false;
    }

    if (selected_piece->isPlayerOne != isPlayerOne){
        printf("You selected an enemy piece.");
        return false;
    }

    char direction;

    printf("Enter a direction the first letter of (Right/Left/Up/Down): ");
    scanf(" %c", &direction);

    direction = toupper(direction);

    switch (direction) {
        case 'R':
            xCoordinate += 1;
            break;
        case 'L':
            xCoordinate -= 1;
            break;
        case 'U':
            yCoordinate += 1;
            break;
        case 'D':
            yCoordinate -= 1;
            break;
        default:
            printf("Invalid direction entered.\n");
    }

    Move newMove;
    newMove.xCoordinate = xCoordinate;
    newMove.yCoordinate = yCoordinate;

    board[newMove.xCoordinate][newMove.yCoordinate] = selected_piece;
    board[originalMove.xCoordinate][originalMove.yCoordinate] = NULL;

    return true;
}

int main() {

    int rows = 5;
    int columns = 5;

    Piece ***board = initializeBoard(rows, columns);

    printBoard(board, rows, columns);

    turn(board, true);
    printBoard(board, rows, columns);

    freeBoard(board, rows, columns);
    return 0;
}
