// Online C compiler to run C program online
#include <stdio.h>
#include <limits.h>

#define inf INT_MAX
#define max 10
int n;
int memo[max][1<<max];
int path[max][1<<max];
int dist[max][max];

void initialise(){
    for(int i=0;i<max;i++){
        for(int j=0;j<(1<<max);j++){
            path[i][j]=-1;
            memo[i][j]=-1;
        }
    }
}
int tsp(int pos,int mask){
    
    if(mask==(1<<n)-1){
        return dist[pos][0];
    }
    if(memo[pos][mask]!=-1){
        return memo[pos][mask];
    }
    int ans=inf;
    for(int city=0;city<n;city++){
        if((mask & (1<<city))==0){
            int neww=dist[pos][city] + tsp(city, mask | (1<<city));
            if(ans>neww){
                ans=neww;
                path[pos][mask] = city;
            }
        }
    }
    return memo[pos][mask]=ans;
}
void printPath(int start) {
    int mask = 1;
    int pos = start;
    
    printf("Path: %d", pos);
    while (mask != (1 << n) - 1) {
        pos = path[pos][mask];
        mask |= (1 << pos);
        printf(" -> %d", pos);
    }
    printf(" -> %d\n", start); // Return to the starting point
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    
    initialise();
    
    int start = 0;
    int minDist = tsp(start, 1);
    
    printf("The minimum distance is: %d\n", minDist);
    printPath(start);
    
    return 0;
}