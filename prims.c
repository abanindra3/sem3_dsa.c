// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define v 5
#define max INT_MAX
struct node{
    int data;
    struct node* next;
    int wt;
};
struct graph{
    int vertices;
    struct node** adjl;
};
struct node*createn(int data,int wtt){
    struct node* neew=(struct node*)malloc(sizeof(struct node));
    neew->data=data;
    neew->wt=wtt;
    return neew;
}
struct graph* create(int vertices){
    struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
    graph->adjl=(struct node**)malloc(sizeof(struct node*) *vertices);
    graph->vertices=vertices;
    for(int i=0;i<vertices;i++){
        graph->adjl[i]=NULL;
    }
    return graph;
}
struct graph* add(struct graph* graph,int src,int dest,int wt){
    struct node* news=createn(dest,wt);
    news->next=graph->adjl[src];
    graph->adjl[src]=news;
    struct node* newd=createn(src,wt);
    newd->next=graph->adjl[dest];
    graph->adjl[dest]=newd;
    return graph;
}
int mink(int dist[],bool mst[]){
    int mini,min=max;
    for(int i=0;i<v;i++){
        if(mst[i]==false && min>dist[i]){
            mini=i;
            min=dist[i];
        }
    }
    return mini;
}
void print(int parent[], struct graph* graph) {
    printf("EDGE \t WEIGHT\n");
    for (int i = 1; i < v; i++) {
        int wt = -1;
        struct node* temp = graph->adjl[i];
        while (temp && temp->data != parent[i])
            temp = temp->next;
        if (temp)
            wt = temp->wt;
        printf("%d-%d \t %d \n", parent[i], i, wt);
    }
}

void prims(struct graph*graph){
    int dist[v];
    int parent[v];
    bool mst[v];
    for(int i=0;i<v;i++){
        mst[i]=false;
        dist[i]=max;
    }
    parent[0]=-1;
    dist[0]=0;
    for(int count=0;count<v-1;count++){
        int u=mink(dist,mst);
        mst[u]=true;
        
        struct node* temp = graph->adjl[u];
        while (temp != NULL) {
            int w = temp->data;
            int wt = temp->wt;
            if (!mst[w] && wt < dist[w]) {
                parent[w] = u;
                dist[w] = wt;
            }
            temp = temp->next;
        }
    }
    print(parent, graph);
}
int main() {
    printf("vertices=");
    int vv;
    scanf("%d", &vv);
    struct graph* graph = create(vv);
    
    // Taking input for edges
    int edges;
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest, wt;
        printf("Enter source, destination, and weight for edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &wt);
        graph = add(graph, src, dest, wt);
    }
    prims(graph);
    return 0;
}