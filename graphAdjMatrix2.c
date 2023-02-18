#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct mygraph graph;
graph *createGraph(int numnodes);
void destroyGraph(graph *g);
void printGraph(graph *g);
bool addEdges(graph *g, unsigned int fromNode, unsigned int toNode);
bool hasEdges(graph *g, unsigned int fromNode, unsigned int toNode);

struct mygraph{
    int numnodes;
    bool **edges;

};

graph *createGraph(int numnodes){
    graph *g = malloc(sizeof(*g));
    if (g == NULL){
        return NULL;
    }
    g->numnodes = numnodes;
    //allocate our matrix
    g->edges = calloc(sizeof(bool*), g->numnodes);
    if (g->edges == NULL){
        free(g);
        return NULL;
    }
    for (i=0; i<g->numnodes; i++){
        g->edges[i] = calloc(sizeof(bool), g->numnodes);
        if (g->edges[i] == NULL){
            destroyGraph(g);
            return NULL;
        }
    }
    return g;
}

void destroyGraph(graph *g){
    if (g->edges == NULL){
        free(g);
        return;
    }
    for (int i = 0; i < g->numnodes; i++){
        if (g->edges[i] != NULL){
            free(g->edges[i]);     
        }       
    }
    free (g->edges);
    free(g);
}

void printGraph(graph *g){
    printf ("digraph {\n");
    for(int from = 0; from < g->numnodes; from++){
        for(int to = 0; to < g->numnodes; to++){
            if (g->edges[from][to] == true){
                printf("%d -> %d;\n", from, to);
            }
        }
    }
    printf("}\n");
    
}
bool addEdges(graph *g, unsigned int fromNode, unsigned int toNode){
    if (hasEdges(g, fromNode, toNode)){
        return false;
    }
    g->edges[fromNode][toNode] = true;
    return true;
}
bool hasEdges(graph *g, unsigned int fromNode, unsigned int toNode){
    return g->edges[fromNode][toNode]
}
