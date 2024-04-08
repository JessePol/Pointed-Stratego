#include <stdio.h>
#include "src/board.h"

bool turn(Piece*** board, bool isPlayerOne){
    Move* newMove = createNewMove();

    Piece* selectedPiece = selectPiece(board, newMove, isPlayerOne);

    if(selectedPiece == NULL) {
        return false;
    }

    Move* pieceMove = askDirectionMove(newMove);

    Piece* possiblePiece = board[pieceMove->yCoordinate][pieceMove->xCoordinate];

    if (possiblePiece !=NULL){
        if(selectedPiece->strength>possiblePiece->strength){
            freePiece(possiblePiece);
            printf("Your piece won from the enemy piece.\n");
            board[newMove->yCoordinate][newMove->xCoordinate] = NULL;
            board[pieceMove->yCoordinate][pieceMove->xCoordinate] = selectedPiece;
        }
        if(selectedPiece->strength<possiblePiece->strength){
            freePiece(selectedPiece);
            printf("Your piece lost against the enemy piece.\n");
            board[newMove->yCoordinate][newMove->xCoordinate] = NULL;
        }
        if(selectedPiece->strength==possiblePiece->strength){
            freePiece(selectedPiece);
            freePiece(possiblePiece);
            printf("Your piece was even with the enemy piece.\n");
            board[newMove->yCoordinate][newMove->xCoordinate] = NULL;
            board[pieceMove->yCoordinate][pieceMove->xCoordinate] = NULL;

        }
    }
    else{
        board[pieceMove->yCoordinate][pieceMove->xCoordinate] = selectedPiece;
        board[newMove->yCoordinate][newMove->xCoordinate] = NULL;
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
