#ifndef BOARDFUNC_H
#define BOARDFUNC_H
#include<stdint.h>
#include<stdbool.h>

uint64_t calculate_hash(int n, int* board);
int move(int n, int dir);
bool try_move(int n, int empty_space, int dir);
bool solution(int n, int* board);
bool solvable(int n, int* board);
int* get_random_board(int n);

#endif