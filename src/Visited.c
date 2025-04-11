#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "../include/Visited.h"
#include "../include/Node.h"

NodeVector* initVisited() {
    NodeVector* visited = malloc(sizeof(NodeVector));
    int initialCapacity = 16;
    visited->size = 0;
    visited->content = malloc(sizeof(Node*) * initialCapacity);
    if(!visited->content) {
        perror("Memory allocation failed for visited->content.\n");
        exit(1);
    }
    visited->capacity = initialCapacity;

    return visited;
}

void addToVisited(Node* node, NodeVector* visited) {
    if(visited->size == visited->capacity) {
        visited->capacity *= 2;
        visited->content = realloc(visited->content, sizeof(Node*) * visited->capacity);
        if(!visited->content) {
            perror("Memory reallocation failed for visited->content.\n");
            exit(1);
        }
    }

    visited->content[visited->size] = node;
    visited->size++;
}

bool findInVisited(uint64_t hash, NodeVector* visited) {
    for(int i=0; i< visited->size; i++) {
        if(visited->content[i]->hash == hash) { return true; }
    }
    return false;
}

void freeVisited(NodeVector* visited) {
    for(int i=0; i<visited->size; i++) {
        free(visited->content[i]);
    }
    free(visited->content);
    free(visited);
}