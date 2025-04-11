#ifndef NODE_H
#define NODE_H

#include<stdint.h>
typedef struct Node {
    uint64_t hash;
    int* board;
    int empty_space;
    int cost;
    int heuristic;
    struct Node* pred;
} Node;

typedef struct NodeVector {
    int size;
    int capacity;
    Node** content;
} NodeVector;

int score(Node* node);
Node* initNode(uint64_t hash, int* board, int empty_space, int cost, int heuristic, Node* pred);

#endif
