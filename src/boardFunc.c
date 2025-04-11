#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

#include "boardFunc.h"

uint64_t calculate_hash(int n, int* board) {
    uint64_t hash = 0;
    uint64_t base = n * n;
    for (int i = 0; i < n * n; i++) {
        hash = hash * base + board[i];  
    }
    return hash;
}    

int move(int n, int dir) {
    switch(dir) {
        case 0:
            return -1;
        case 1:
            return 1;
        case 2:
            return -n;
        case 3:
            return n;
        default:
            return 0;
    }
}

bool try_move(int n, int empty_space, int dir) {
    switch(dir) {
        case 0: //left
            if(empty_space % n == 0) { return false; }
            break;
        case 1: //right
            if(empty_space % n == n-1) { return false; }
            break;
        case 2: //up
            if(empty_space / n == 0) { return false; }
            break;
        case 3: //down
            if(empty_space / n == n-1) { return false; }
            break;
    }
    return true;
}

bool solution(int n, int* board) {
    for(int i=0; i<n*n-1; i++) {
        if(board[i] != i+1) { return false; }
    }
    return true;
}

bool solvable(int n, int* board) {
    int inversions = 0;
    for(int i=0; i<n*n-2; i++) {
        for(int j=i; j<n*n-1; j++) {
            if(board[i] > board[j]) { inversions++; }
        }
    }
    if(inversions % 2 == 0) { return true; }
    return false;
}

int* get_random_board(int n) {
    return 0;
}