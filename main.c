#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "./include/A_star.h"
#include "./include/Utils.h"
#include "./include/boardFunc.h"

int main() {
    int n = promptForBoardSize();
    int* board = promptForBoard(n);
    int heur = promptForHeuristic();
    bool printSol = promptForSolution();

    if(!solvable(n, board)) {
        printf("This board is not solvable.\n");
        return 0;
    }
    
    solve(n, board, heur, printSol);
    return 0;
}