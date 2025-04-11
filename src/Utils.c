#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "../include/Utils.h"
#include "../include/Node.h"
#include "../include/boardFunc.h"

void printBoard(int n, int* board) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if(board[i*n + j] == 0){
                printf(" # ");
            } else {
                printf("%02d ", board[i*n + j]);
            }
        }
        printf("\n");
    }
}

bool promptForSolution() {
    printf("Do you want the program to print the solution (steps) after it is done? \n");
    printf("Type 1 (yes) or  0 (no)\n");
    int ans;
    scanf("%d", &ans);
    if(ans == 1) {
        return true;
    }
    else if(ans == 0) {
        return false;
    }
    else {
        printf("Defaulting to 'no'. \n");
        return false;
    }
}

int promptForBoardSize() {
    int n;
    printf("What size of board do you want to solve? Type n for nxn board. \n");
    scanf("%d", &n);
    if(n<=0 || n>=5) {
        printf("Cannot generate a board of this size.");
        exit(1);
    }
    return n;
}

int promptForHeuristic() {
    int heur;
    printf("What type of heuristic do you want to use? Type 0 for number of mismatched tiles or 1 for Manhattan distance.\n");
    scanf("%d", &heur);

    return heur;
}

int* promptForBoard(int n) {
    printf("Do you want a random board? Type 1 (yes) or 0 (no).\n");
    int ans;
    scanf("%d", &ans);
    if(ans == 1) {
        return get_random_board(n);
    } 
    else if(ans == 0) {
        int* board = malloc(n*n*sizeof(int));
        if(!board) {
            perror("Memory allocation failed for board.\n");
            exit(1);
        }
        printf("Please input a permutation of (1,...,%d). [Number by number] \n", n*n-1);
        for(int i=0; i<n*n-1; i++) {
                int nmb;
                scanf("%d", &nmb);
                board[i] = nmb;
        }
        board[n*n-1] = 0;
        return board;
    }
    else {
        printf("Defaulting to yes.\n");
        return get_random_board(n);
    }
}

//we assume the solution can be achieved in less than 1000 steps
void printSolution(int n, Node* finalNode) {
    Node* currNode = finalNode;

    Node* arr[1000];
    int idx = 0;
    while(currNode != NULL) {
        arr[idx++] = currNode;
        currNode = currNode->pred;
    }
    for(int i=idx-1; i>=0; i--) {
        printf("\n\n");
        printBoard(n, arr[i]->board);
    }
}