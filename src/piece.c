//
// Created by jesse on 5-12-23.
//
#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

Piece* createPiece(bool isPlayerOne, int strength){
    Piece *newPiece = (Piece *)malloc(sizeof(Piece));
    newPiece->isPlayerOne = isPlayerOne;
    newPiece->strength = strength;

    return newPiece;
}

void freePiece(Piece *piece){
    if (piece != NULL) {
        free(piece);
    }
}

Piece* selectPiece(Piece*** board, Move* move, bool isPlayerOne){

    Piece* selectedPiece = board[move->yCoordinate][move->xCoordinate];

    if (selectedPiece == NULL){
        printf("You selected an empty field.\n");
        return NULL;
    }

    if (selectedPiece->isPlayerOne != isPlayerOne){
        printf("You selected an enemy piece.\n");
        return NULL;
    }

    return selectedPiece;
}