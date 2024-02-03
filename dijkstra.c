#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define v 9
int mind(bool sps[],int dist[]){   
    int mini = -1;         // Initialize mini to an invalid index
    int min = INT_MAX;

    for(int i=0;i<v;i++){
        if(!sps[i] && dist[i]<min){
            mini=i;
            min=dist[i];
        }
    }
    return mini;
}
void print(int dist[]){
    printf("VERTEX \t\tDISTANCE \n");
    for(int i=0;i<v;i++){
        printf("%d \t\t %d \n",i,dist[i]);
    }
}
void dijktras(int graph[v][v],int src){
    bool sps[v];
    int dist[v];
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
        sps[i]=false;
    }

    dist[src]=0;
    for(int i=0;i<v-1;i++){
        int u=mind(sps,dist);
        sps[u]=true;

        for(int j=0;j<v;j++){
             if(!sps[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) //not included & is connection & not infinity and not 
                    dist[j] = dist[u] + graph[u][j];                                                    // dist overflow/

            
        }
    }
    print(dist);
}


int main(){
    int graphh[v][v]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int src=0;
    dijktras(graphh,src);

    return 0;

}
