#ifndef UTILS_H
#define UTILS_H
#include "../include/Node.h"

void printBoard(int n, int* board);
bool promptForSolution();
int promptForBoardSize();
int promptForHeuristic();
int* promptForBoard(int n);
void printSolution(int n, Node* finalNode);

#endif