//
// Created by jesse on 5-12-23.
//

typedef struct {
    int xCoordinate;
    int yCoordinate;
} Move;

Move* createMove(int xCoordinate, int yCoordinate);
Move* createNewMove();
Move* askDirectionMove(Move* move);

#ifndef POINTEDSTRATEGO_MOVE_H
#define POINTEDSTRATEGO_MOVE_H

#endif //POINTEDSTRATEGO_MOVE_H