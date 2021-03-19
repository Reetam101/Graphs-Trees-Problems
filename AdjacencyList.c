#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  int weight;
  struct node* next;
};
struct node* createNode(int, int);

struct Graph {
  int numV;
  struct node** adjLists;
};

// Create a node
struct node* createNode(int v, int w) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->weight = w;
  newNode->next = NULL;
  return newNode;
}

// create graph
struct Graph* createGraph(int n) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numV = n;
  graph->adjLists = malloc(n * sizeof(struct node*));

  int i;
  for(i = 0; i < n; i++) {
    graph->adjLists[i] = NULL;
  }
  return graph;
}

void addEdge(struct Graph* graph, int a, int b, int w) {
  struct node* newNode = createNode(b, w);
  newNode->next = graph->adjLists[a];
  graph->adjLists[a] = newNode;

  newNode = createNode(a, w);
  newNode->next = graph->adjLists[b];
  graph->adjLists[b] = newNode;

}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numV; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d (%d) -> ", temp->vertex, temp->weight);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  struct Graph* graph = createGraph(N);
  for(int i = 0; i < M; i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);

    addEdge(graph, a, b, w);
  }
  printGraph(graph);
  return 0;
}
 