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