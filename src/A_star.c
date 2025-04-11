#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdint.h>
#include<string.h>
#include "../include/Node.h"
#include "../include/Queue.h"
#include "../include/Visited.h"
#include "../include/Utils.h"
#include "../include/heur.h"
#include "../include/boardFunc.h"
#include "../include/A_star.h"

void genNeighbours(int n, Node* currNode, NodeVector* queue, NodeVector* visited, int heur) {
    for(int i=0; i<4; i++) {
        if(try_move(n, currNode->empty_space, i)) {
            int* newBoard = malloc(n*n*sizeof(int));
            if (!newBoard) {
                perror("Memory allocation failed for newBoard.");
                exit(1);
            }
            memcpy(newBoard, currNode->board, n*n*sizeof(int));

            int new_empty_space = currNode->empty_space + move(n, i);
            newBoard[currNode->empty_space] = newBoard[new_empty_space];
            newBoard[new_empty_space] = 0;

            uint64_t hash = calculate_hash(n, newBoard);

            if(findInVisited(hash, visited)) {
                free(newBoard);
                continue;
            }

            Node* newNode;
            newNode = findInQueue(hash, queue);
            if(newNode != NULL) {
                if (newNode->cost > currNode->cost + 1) {
                    newNode->cost = currNode->cost + 1;
                    newNode->pred = currNode;
                }
                free(newBoard);
                continue;
            }

            int heuristic = heuristicFun(heur, n, newBoard);
            newNode = initNode(hash, newBoard, new_empty_space, currNode->cost + 1, heuristic, currNode);

            
            addToQueue(newNode, queue);
        }
    }
}

void solve(int n, int* starting_board, int heur, bool printSol) {
    uint64_t hash = calculate_hash(n, starting_board);
    Node* currNode = initNode(hash, starting_board, n*n - 1, 0, 0, NULL);

    NodeVector* visited = initVisited();
    NodeVector* queue = initQueue();
    addToVisited(currNode, visited);

    while(!solution(n, currNode->board)) {
        genNeighbours(n, currNode, queue, visited, heur);
        currNode = extractMin(queue);
        currNode->heuristic = 0;
        addToVisited(currNode, visited);
    }

    if(printSol) {
        printSolution(n, currNode);
    }
    printf("Solution achieved in %d steps. Visited states: %d\n", currNode->cost, visited->size);

    freeVisited(visited);
    freeQueue(queue);
}