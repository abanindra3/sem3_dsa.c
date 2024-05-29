// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #define vv 5


// void print(int col[]){
//     printf("SOLUTION--");
//     for(int i=0;i<vv;i++){
//         printf("%d",col[i]);
//     }
//     printf("\n");
// }
// bool issafe(int v,int graph[v][v],int color[],int c){
//     for(int i=0;i<vv;i++)
//         if(graph[v][i] && c==color[i])
//             return false;
//     return true;
// }
// int colutil(int v,int graph[v][v],int color[],int m){
//     if(v==vv){                  //all vertices assigned.
//         return true;       
//     }
//     for(int c=1;c<=m;c++){
//         if (issafe(v,graph,color,c)){
//             color[v]=c;

//         if(colutil(v+1,graph,color,m))              //color the next vertex.
//             return true;
//         color[v]=0;            // If no valid color found, it resets the color for vertex v and backtracks.
      
//         }
//     }
//     return false;
// }
// bool graphcol(int graph[vv][vv],int m){
//     int color[vv];
//     for(int i=0;i<vv;i++){
//         color[i]=0;
//     }
//      if (colutil(0,graph,color,m) == false) {
//         printf("Solution does not exist");
//         return false;
//     }

//     print(color);
//     return true;
// }
// int main() {
//     int graph[vv][vv] = {{0, 1, 1, 1},
//                        {1, 0, 1, 0},
//                        {1, 1, 0, 1},
//                        {1, 0, 1, 0}};

//     int chromaticNumber = 3; // Number of colors
//     graphcol(graph, chromaticNumber);
//     while (!graphcol(graph, chromaticNumber)) {
//         chromaticNumber++;
//     }

//     printf("The Chromatic Number is %d\n", chromaticNumber);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define vv 4

void print(int color[]) {
    printf("SOLUTION: ");
    for (int i = 0; i < vv; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

bool issafe(int v, int graph[vv][vv], int color[], int c) {
    for (int i = 0; i < vv; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool colutil(int graph[vv][vv], int m, int color[], int v) {
    if (v == vv) { // All vertices are assigned a color
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (issafe(v, graph, color, c)) {
            color[v] = c;

            if (colutil(graph, m, color, v + 1)) // Recur to assign colors to rest of the vertices
                return true;

            color[v] = 0; // If no valid color found, reset the color (backtrack)
        }
    }
    return false;
}

bool graphcol(int graph[vv][vv], int m) {
    int color[vv] = {0}; // Initialize all color values as 0 (no color)

    if (!colutil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    print(color);
    return true;
}

int main() {
    int graph[vv][vv] = {{0, 1, 1, 1},
                         {1, 0, 1, 0},
                         {1, 1, 0, 1},
                         {1, 0, 1, 0}};

    int chromaticNumber = 3; // Initial number of colors

    while (!graphcol(graph, chromaticNumber)) {
        chromaticNumber++;
    }

    printf("The Chromatic Number is %d\n", chromaticNumber);
    return 0;
}
