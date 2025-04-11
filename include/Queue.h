#ifndef BINHEAP_H
#define BINHEAP_H
#include<stdbool.h>
#include<stdint.h>
#include "Node.h"
//QUEUE IS A BINARY HEAP STORED IN A VECTOR

NodeVector* initQueue();
void addToQueue(Node* node, NodeVector* queue);
Node* extractMin(NodeVector* queue);
Node* findInQueue(uint64_t hash, NodeVector* queue);
bool isEmpty(NodeVector* queue);
void freeQueue(NodeVector* queue);
void printQ(NodeVector* queue);

#endif