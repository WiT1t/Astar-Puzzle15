#ifndef A_STAR_H
#define A_STAR_H

#include "Node.h"

void solve(int n, int* starting_board, int heur, bool printSol);
void getNeighbours(int n, Node* currNode, int visited, int que, int heur);

#endif