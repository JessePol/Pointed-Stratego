//
// Created by jesse on 5-12-23.
//
typedef struct {
    int strength;
    bool isPlayerOne;
} Piece;

Piece* createPiece(bool isPlayerOne, int strength);
void freePiece(Piece *piece);

#ifndef POINTEDSTRATEGO_PIECE_H
#define POINTEDSTRATEGO_PIECE_H

#endif //POINTEDSTRATEGO_PIECE_H
