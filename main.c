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

    Piece* selectedPiece = board[originalMove.xCoordinate][originalMove.yCoordinate];

    if (selectedPiece == NULL){
        printf("You selected an empty field.");
        return false;
    }

    if (selectedPiece->isPlayerOne != isPlayerOne){
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

    Piece* possiblePiece = board[newMove.xCoordinate][newMove.yCoordinate];

    if (possiblePiece !=NULL){
        if(selectedPiece->strength>possiblePiece->strength){
            freePiece(possiblePiece);
            printf("Your piece won from the enemy piece.\n");
            board[originalMove.xCoordinate][originalMove.yCoordinate] = NULL;
            board[newMove.xCoordinate][newMove.yCoordinate] = selectedPiece;
        }
        if(selectedPiece->strength<possiblePiece->strength){
            freePiece(selectedPiece);
            printf("Your piece lost against the enemy piece.\n");
            board[originalMove.xCoordinate][originalMove.yCoordinate] = NULL;
        }
        if(selectedPiece->strength==possiblePiece->strength){
            freePiece(selectedPiece);
            freePiece(possiblePiece);
            printf("Your piece was even with the enemy piece.\n");
            board[originalMove.xCoordinate][originalMove.yCoordinate] = NULL;
            board[newMove.xCoordinate][newMove.yCoordinate] = NULL;

        }
    }
    else{
        board[newMove.xCoordinate][newMove.yCoordinate] = selectedPiece;
        board[originalMove.xCoordinate][originalMove.yCoordinate] = NULL;
    }

    return true;
}

int main() {

    int rows = 5;
    int columns = 5;
    bool continueGame = true;

    Piece ***board = initializeBoard(rows, columns);

    printBoard(board, rows, columns);

    while(continueGame){
        turn(board, true);
        printBoard(board, rows, columns);
    }

    freeBoard(board, rows, columns);
    return 0;
}
