#include<stdio.h>
#include<stdlib.h>

#include "../include/Node.h"

int score(Node* node) {
    return node->cost + node->heuristic;
}

Node* initNode(uint64_t hash, int* board, int empty_space, int cost, int heuristic, Node* pred) {
    Node* newNode = malloc(sizeof(Node));
    if(!newNode) {
        perror("Memory allocation failed for new node.\n");
        exit(1);
    }
    newNode->hash = hash;
    newNode->board = board;
    newNode->empty_space = empty_space;
    newNode->cost = cost;
    newNode->heuristic = heuristic;
    newNode->pred = pred;

    return newNode;
}