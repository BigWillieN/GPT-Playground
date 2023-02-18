// Define a struct to represent a graph
struct graph_t {
    vertex_t *vertices; // array of vertices
    int num_vertices; // number of vertices in the graph
};

// Define a struct to represent an edge in the graph
struct edge_t {
    int weight; // weight of the edge
    int destination; // index of the destination vertex in the array of vertices
};

// Define a struct to represent a vertex in the graph
struct vertex_t {
    int id; // unique identifier for the vertex
    int num_edges; // number of edges connected to the vertex
    int color; // color of the vertex for graph traversal algorithms
    int distance; // distance of the vertex from a source vertex for graph traversal algorithms
    int scc; // strongly connected component ID for Tarjan's algorithm
    int discovery_time; // discovery time for DFS traversal
    int finish_time; // finish time for DFS traversal
    int predecessor; // index of the predecessor vertex in the array of vertices
    edge_t *edges; // array of edges connected to the vertex
};

// Define a struct to store an edge in the minimum spanning tree
typedef struct {
    int source; // index of the source vertex in the array of vertices
    int destination; // index of the destination vertex in the array of vertices
    int weight; // weight of the edge
} mst_edge_t;

int kruskal_mst(graph_t *graph) {
    int i, j, k, weight, num_edges, num_vertices;
    mst_edge_t *edges;

    // Count the total number of edges in the graph
    for (num_edges = i = 0; i < graph->num_vertices; i++) {
        num_edges += graph->vertices[i].num_edges;
    }
    num_edges /= 2; // Divide by 2 since each edge is counted twice

    // Allocate memory to store the edges
    edges = (mst_edge_t *)calloc(num_edges, sizeof(mst_edge_t));
    num_edges = 0;

    // Add all edges to the list of edges, sorted by weight
    for (i = 0; i < graph->num_vertices; i++) {
        for (j = 0; j < graph->vertices[i].num_edges; j++) {
            if (i < graph->vertices[i].edges[j].destination) {
                k = num_edges - 1;
                while (k >= 0 && edges[k].weight < graph->vertices[i].edges[j].weight) {
                    edges[k + 1] = edges[k];
                    k--;
                }
                edges[k + 1].source = i;
                edges[k + 1].destination = graph->vertices[i].edges[j].destination;
                edges[k + 1].weight = graph->vertices[i].edges[j].weight;
                num_edges++;
            }
        }
    }

    // Initialize each vertex to be its own predecessor
    for (i = 0; i < graph->num_vertices; i++) {
        graph->vertices[i].predecessor = i;
    }

    weight = num_vertices = 0;
    // Add edges to the minimum spanning tree until all vertices are connected
    for (k = 0; k < num_edges && num_vertices < graph->num_vertices - 1; k++) {
        i = find(graph, edges[k].source);
        j = find(graph, edges[k].destination);
        union_vertices(graph, edges, i, j, k, &weight, &num_vertices);
    }

    // Free memory used for edges
    free(edges);
    return weight;
}
static int union_find_find (graph_t *g, int k) {
    int i = k;
    while (i != g->g[i].pred) {
        i = g->g[i].pred;
    }
    return i;
}

static void union_find_union (graph_t *g, link *edges,int i, int j, int k, int *weight, int *ne) {
    if (i != j) {
        fprintf (stdout, "Edge %d-%d (w=%d)\n",
        edges[k].src, edges[k].dst, edges[k].weight);
        g->g[j].pred = i;
        *weight += edges[k].weight;
        *ne = *ne + 1;
    }
    return;
}