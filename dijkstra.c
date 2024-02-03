// #include<stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// #define v 5
// #include <stdbool.h>
//#define vv 6


//find min distance first
// set all distances= INFINITE and sptSet[] = false///dist from source=0;;;
//selects the vertex with the minimum tentative distance, marks it as processed 
//(sptSet[u] = true),
// and updates the distances of its neighboring vertices if a shorter path is found.

// int mindist(bool spt[],int dist[]){
//     int min=INT_MAX,min_index;
//     for(int v=0;v<vv;v++){
//         if(!spt[v]&& dist[v]<=min){
//             min=dist[v];
//             min_index=v;
//         }
//     }
//     return min_index;
// }
// void print(int dist[]){
//     printf("vertex \t\t    distance");
//     for(int i=0;i<vv;i++){
//         printf("%d \t%d\n", i, dist[i]);
//     }
// }
// void dijkstra(int graph[vv][vv],int src){
//     bool spt[vv];
//     int dist[vv];
//     for(int i=0;i<vv;i++){
//         spt[i]=false;
//         dist[i]=INT_MAX;
//     }
//     dist[src]=0;

//     for(int i=0;i<vv-1;i++){
//         int u=mindist(spt,dist);
//         spt[u]=true;

//         for(int v=0;v<vv;v++){
//             if(!spt[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) //not included & is connection & not infinity and not 
//             dist[v] = dist[u] + graph[u][v];                                                    // dist overflow/
//         }

//     }
//     print(dist);
// }


// int main(){
//     int graph[vv][vv]={{0, 2, 0, 1, 0, 0},
//                        {2, 0, 4, 3, 0, 0},
//                        {0, 4, 0, 0, 2, 0},
//                        {1, 3, 0, 0, 0, 5},
//                        {0, 0, 2, 0, 0, 6},
//                        {0, 0, 0, 5, 6, 0}};
//     dijkstra(graph,0);
//     return 0;
// }
#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
#define v 9
#include <stdbool.h>
#include <limits.h>
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
