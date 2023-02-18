#include <utility.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_LINE 100
enum {WHITE, GREY, BLACK};
typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;
struct graph_s { //structure of graph, nv is number of vertices, *g points to array of vertices
    vertex_t *g;
    int nv;
};
struct vertex_s { //structure of our vertex inside the graph
    int id;
    int color;
    int dist;
    int disc_time;
    int endp_time;
    int pred;
    int scc;
    int *rowAdj;
};
graph_t *graph_load (char *filename) { //loads graph from file
    graph_t *g;
    char line[MAX_LINE];
    int i, j, weight, dir;
    FILE *fp;
    g = (graph_t *) util_calloc (1, sizeof(graph_t)); //allocate memory for graph
    fp = util_fopen (filename, "r");
    fgets (line, MAX_LINE, fp); //the first line of the file is read into the line array using fgets.
    if (sscanf(line, "%d%d", &g->nv, &dir) != 2){ //The first line of the file is parsed using sscanf to read two integers into g->nv and dir. 
        sscanf(line, "%d", &g->nv);               //If sscanf does not return 2, only one integer is read into g->nv, and dir is set to 1.
        dir = 1;
    }
    g->g = (vertex_t *) 
    util_calloc (g->nv, sizeof(vertex_t)); //Memory is allocated for an array of vertex_t structures of size g->nv, and the resulting pointer is stored in g->g.
    for (i=0; i<g->nv; i++) {   //A loop is used to initialize the vertex_t structures in the g->g array. The id field is set to the loop index i
        g->g[i].id = i;  
        g->g[i].color = WHITE;
        g->g[i].dist = INT_MAX;
        g->g[i].pred = g[i].scc = -1;
        g->g[i].disc_time = g[i].endp_time = -1;
        g->g[i].rowAdj = (int *)util_calloc(g->nv, sizeof(int));}
        while (fgets(line, MAX_LINE, fp) != NULL) {
            if (sscanf(line, "%d%d%d", &i, &j, &weight) != 3){
                sscanf(line, "%d%d", &i, &j);
                weight = 1;
            }
            g->g[i].rowAdj[j] = weight;
            if (dir == 0) g->g[j].rowAdj[i] = weight;
        }
        fclose(fp);
        return g;
}

void graph_attribute_init (graph_t *g){
    int i;
    for (i=0; i<g->nv; i++) {
        g->g[i].color = WHITE;
        g->g[i].dist = INT_MAX;
        g->g[i].disc_time = -1;
        g->g[i].endp_time = -1;
        g->g[i].pred = -1;
        g->g[i].scc = -1;
    }
return;
}
int graph_find (graph_t *g, int id){ //returns position (i) of vertex with given id
    int i;
    for (i=0; i<g->nv; i++) {
        if (g->g[i].id == id) {
            return i;
        }
    }
return -1;
}
void graph_dispose (graph_t *g) { //free memory for graph
    int i;
    for (i=0; i<g->nv; i++) {
        free(g[i].rowAdj);
    }
    free(g->g);
    free(g);
    return;
}