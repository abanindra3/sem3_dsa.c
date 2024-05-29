#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct graph{
    int vertices;
    struct node** adjl;
};
struct node* createn(int data){
    struct node* new =(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    return new;
}
struct graph* create(int vertices){
    struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
    graph->adjl=(struct node**)malloc(vertices * sizeof(struct node*));
    
    graph->vertices=vertices;
    for(int i=0;i<vertices;i++){
        graph->adjl[i]=NULL;
    }
    return graph;
}

struct graph* add(struct graph* graph,int src,int dest){
    struct node* news=createn(dest);
    news->next=graph->adjl[src];
    graph->adjl[src]=news;

    struct node* newd=createn(src);
    newd->next=graph->adjl[dest];
    graph->adjl[dest]=newd;

    return graph;
}
void dfsu(struct graph* graph,int vertex,bool visited[]){
    visited[vertex]=true;
    printf("%d",vertex);
     
    struct node*temp=graph->adjl[vertex];
    while(temp!=NULL){
        int adj=temp->data;
        if(!visited[adj]){
            dfsu(graph,adj,visited);
        }
        temp=temp->next;
    }
}
bool dfs(struct graph* graph,int start){
    bool* visited=(bool*)malloc(graph->vertices * sizeof(bool));
    for(int i=0;i<graph->vertices;i++){
        visited[i]=false;
    }
    dfsu(graph,start,visited);
    free(visited);
}

int main() {
    // Create a graph with 5 vertices
    struct graph* graph = create(5);

    // Add edges
    add(graph, 0, 1);
    add(graph, 0, 2);
    add(graph, 1, 3);
    add(graph, 2, 4);

    //  DFS traversal starting from vertex 0
    printf("DFS Traversal: ");
    dfs(graph, 0);
    printf("\n");

    //free(visited);
    free(graph);
    
    return 0;
}