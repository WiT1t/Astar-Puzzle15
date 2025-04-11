#include<stdio.h>
#include<stdlib.h>
#include "../include/heur.h"

//How many tiles are not in position.
int heur1(int n, int* board) {
    int sum=0;
    for(int i=0; i<n*n; i++) {
        if(board[i] == 0) { continue; }
        if(board[i] != i + 1) { sum++; }
    }
    return sum;
}

//sum of Manhattan distances form every tile to its position
int heur2(int n, int* board) {
    int sum=0;
    int x, y, rightX, rightY;
    for(int i=0; i<n*n; i++) {
        if(board[i] == 0) { continue;}
        x = i % n;
        y = i / n;
        rightX = (board[i]-1)% n ;
        rightY = (board[i]-1) / n;
        sum += abs(x - rightX) + abs(y - rightY);
    }
    return sum;
}

int heuristicFun(int i, int n, int* board) {
    switch(i) {
        case 0:
            return heur1(n, board);
        case 1: 
            return heur2(n, board);
        default:
            return 0;
    }
}