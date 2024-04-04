//
// Created by jesse on 5-12-23.
//
#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include <ctype.h>

Move* createMove(int yCoordinate, int xCoordinate){
    Move *newMove = (Move *)malloc(sizeof(Move));
    newMove->yCoordinate = yCoordinate;
    newMove->xCoordinate = xCoordinate;

    return newMove;
}

Move* createNewMove(){
    int xCoordinate;
    int yCoordinate;

    printf("Select the piece you want to move.\n");

    printf("Enter the X coordinate: ");
    scanf("%d", &xCoordinate);

    printf("Enter the Y coordinate: ");
    scanf("%d", &yCoordinate);

    Move* newMove = createMove(yCoordinate, xCoordinate);

    return newMove;
}

Move* askDirectionMove(Move* move){
    char direction;

    Move* pieceMove = createMove(move->yCoordinate, move->xCoordinate);

    printf("Enter a direction the first letter of (Right/Left/Up/Down): ");
    scanf(" %c", &direction);

    direction = toupper(direction);

    switch (direction) {
        case 'R':
            pieceMove->xCoordinate += 1;
            break;
        case 'L':
            pieceMove->xCoordinate -= 1;
            break;
        case 'U':
            pieceMove->yCoordinate -= 1;
            break;
        case 'D':
            pieceMove->yCoordinate += 1;
            break;
        default:
            printf("Invalid direction entered.\n");
    }

    return pieceMove;
}
