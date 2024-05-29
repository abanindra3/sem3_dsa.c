#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define vv 5

int minkey(int key[],bool mst[]){
    int min=INT_MAX, mini;

    for(int v=0;v<vv;v++){
        if(mst[v]==false && key[v]<min){
            mini=v;
            min=key[v];
        }
    }
    return mini;
}
void print(int parent[],int graph[vv][vv]){
    printf("EDGE \t WEIGHT\n");
    for(int i=1;i<vv;i++){
        printf("%d-%d \t %d \n",parent[i],i,graph[i][parent[i]]);

    }
}
void prims(int graph[vv][vv]){
    int parent[vv];  // Array to store constructed MST
    int key[vv];     // Key values used to pick minimum weight edge in cut
    bool mstSet[vv]; // To represent set of vertices not yet included in MST
    
    for (int i = 0; i < vv; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0]=0;// Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1;  // First node is always root of MST

    for(int count=0;count<vv-1;count++){
        int u=minkey(key,mstSet);
        mstSet[u]=true;
    
        for (int v = 0; v < vv; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    print(parent, graph);
}

int main() {
    int graph[vv][vv] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    prims(graph);
    
    return 0;
}
