#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "../include/Queue.h"
#include "../include/Node.h"
//QUEUE IS A BINARY HEAP STORED IN A VECTOR

NodeVector* initQueue() {
    NodeVector* queue = malloc(sizeof(NodeVector));
    int initialCapacity = 16;
    queue->content = malloc(sizeof(Node*) * initialCapacity);
    if(!queue->content) {
        perror("Memory allocation failed for visited->content.\n");
        exit(1);
    }
    queue->size = 0;
    queue->capacity = initialCapacity;

    return queue;
}

void addToQueue(Node* node, NodeVector* queue) {
    int newScore = score(node);
    if(queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->content = realloc(queue->content, queue->capacity * sizeof(Node*));
        if(!queue->content) {
            perror("Memory reallocation failed for queue->content.\n");
            exit(1);
        }
    }

    queue->content[queue->size] = node;
    queue->size++;

    int currPos = queue->size-1;
    if(currPos == 0) { return; }
    while(score(queue->content[(currPos - 1) / 2]) > newScore) {
        queue->content[currPos] = queue->content[(currPos - 1) / 2];
        queue->content[(currPos - 1) / 2] = node;
        currPos = (currPos - 1) / 2;
        if(currPos == 0) { return; }
    }
}

Node* extractMin(NodeVector* queue) {
    if(isEmpty(queue)) { return NULL; }
    Node* min = queue->content[0];
    queue->content[0] = queue->content[queue->size -1];
    queue->size--;

    int currPos = 0;
    while(1) {
        int left = currPos * 2 + 1;
        int right = currPos * 2 + 2;
        int smallest = currPos;
        if(queue->size <= left && queue->size <= right) { break; }
        if(queue->size > right) {
            if(score(queue->content[right]) < score(queue->content[smallest])) {
                smallest = right;
            }
        }
        if(score(queue->content[left]) < score(queue->content[smallest])) {
            smallest = left;
        }
        if(smallest == currPos) { break; }

        Node* tmp = queue->content[smallest];
        queue->content[smallest] = queue->content[currPos];
        queue->content[currPos] = tmp;
        currPos = smallest;
    }

    return min;
}

//TODO: think about improving this function.
Node* findInQueue(uint64_t hash, NodeVector* queue) {
    for(int i=0; i<queue->size; i++) {
        if(queue->content[i]->hash == hash) { return queue->content[i]; }
    }
    return NULL;
}

bool isEmpty(NodeVector* queue) {
    return !queue->size;
}

void freeQueue(NodeVector* queue) {
    for(int i=0; i < queue->size; i++) {
        free(queue->content[i]);
    }

    free(queue->content);
    free(queue);
}



void printQ(NodeVector* que) {
    printf("[");
    for(int i=0; i<que->size-1; i++) {
        printf("%llu, ", que->content[i]->hash);
    }
    printf("%llu]\n", que->content[que->size-1]->hash);
}