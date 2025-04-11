#ifndef VISITED_H
#define VISITED_H
#include<stdbool.h>
#include<stdint.h>
#include "../include/Node.h"

NodeVector* initVisited();
void addToVisited(Node* node, NodeVector* visited);
bool findInVisited(uint64_t hash, NodeVector* visited);
void freeVisited(NodeVector* visited);

#endif