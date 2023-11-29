#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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



bool turn(Pieces*** board, bool isPlayerOne){
    int xCoordinate;
    int yCoordinate;

    printf("Enter the X coordinate: ");
    scanf("%d", &xCoordinate);

    printf("Enter the Y coordinate: ");
    scanf("%d", &yCoordinate);

    Pieces* selected_piece = board[xCoordinate][yCoordinate];

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

    direction = toupper(direction); // Convert to uppercase for consistency

    switch (direction) {
        case 'R':
            printf("You entered Right.\n");
            break;
        case 'L':
            printf("You entered Left.\n");
            break;
        case 'U':
            printf("You entered Up.\n");
            break;
        case 'D':
            printf("You entered Down.\n");
            break;
        default:
            printf("Invalid direction entered.\n");
    }

    return true;
}

int main() {

    int rows = 5;
    int columns = 5;

    Pieces ***board = initializeBoard(rows, columns);

    printBoard(board, rows, columns);

    turn(board, true);

    freeBoard(board, rows, columns);
    return 0;
}
