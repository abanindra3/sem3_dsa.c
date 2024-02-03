#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define v 6
struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct QueueNode* createNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {

        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1);
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;

    queue->front = temp->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

struct node {
    int data;
    struct node* next;
};

struct grap {
    int vertices;
    struct node** adjl;
};

struct node* createn(int data) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

struct grap* create(int vertices){
        struct grap* graph=(struct grap*)malloc(sizeof(struct grap));
        graph->adjl = (struct node**)malloc(vertices * sizeof(struct node*));
        graph->vertices=vertices;
        for(int i=0;i<vertices;i++){
            graph->adjl[i]=NULL;
        }
        return graph;
}
struct grap* add(struct grap* graph,int src,int dest){
    struct node* news=createn(dest);
    news->next=graph->adjl[src];
    graph->adjl[src]=news;

    struct node* neww =createn(src);
    neww->next=graph->adjl[dest];
    graph->adjl[dest]=neww;

    return graph;
}

    
void dfsu(struct grap* graph,int vertex,bool visited[] ){         //helper function for dfs function.

    visited[vertex]=true;
    printf("%d",vertex);

    struct node* temp=graph->adjl[vertex];
    while(temp!=NULL){
        int adj=temp->data;
        if(!visited[adj]){
            dfsu(graph,adj,visited);
        }
        temp=temp->next;
    }
    
}
bool dfs(struct grap* graph,int start){       
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for(int i=0;i<graph->vertices;i++){
        visited[i]=false;
    }
    dfsu(graph,start,visited);
    free(visited);
}

bool bfs(struct grap* graph, int start){
    struct Queue* queue = initializeQueue();
    bool* visited=(bool*)malloc(graph->vertices * sizeof(bool));
    for(int i=0;i<graph->vertices;i++){
        visited[i]=false;
    }
    visited[start]=true;
    enqueue(queue,start);

    while(!isEmpty(queue)){
        int w=dequeue(queue);
        printf("%d",w);
    struct node*temp=graph->adjl[w];
    while(temp!=NULL){
        int adj=temp->data;
        if(!visited[adj]){
            enqueue(queue,adj);
            visited[adj]=true;
        }
        temp=temp->next;
        }
    }
}

int main() {
    // Create a graph with 5 vertices
    struct grap* graph = create(5);

    // Add edges
    add(graph, 0, 1);
    add(graph, 0, 2);
    add(graph, 1, 3);
    add(graph, 2, 4);

    //  DFS traversal starting from vertex 0
    printf("DFS Traversal: ");
    dfs(graph, 0);
    printf("\n");

    // Reset visited array for BFS traversal
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    //  BFS traversal starting from vertex 0
    printf("BFS Traversal: ");
    bfs(graph, 0);
    printf("\n");

    // Free allocated memory
    free(visited);
    free(graph);
    
    return 0;
}
