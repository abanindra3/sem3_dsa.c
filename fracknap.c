#include <stdio.h>
#include <stdlib.h>

struct item{
    int value;
    int wt;
};

int compare(const void *a,const void *b){
    double r1=(double)((struct item*)a)->value/((struct item*)a)->wt;
    double r2=(double)((struct item*)b)->value/((struct item*)b)->wt;
    return r2-r1;
}
double fracknap(struct item *arr,int n,int w){
    // Sort items by value-to-weight ratio in descending order
    qsort(arr, n, sizeof(struct item), compare);

    int currwt=0;
    double remwt=0.0;
    
    for(int i=0;i<n;i++){
        if(currwt+arr[i].wt<=w){
            currwt+=arr[i].wt;
            remwt+=arr[i].value;
        }else{
            int rem=w-currwt;
            remwt+=arr[i].value * (double)(rem)/arr[i].wt;
            break;
        }
    }
    return remwt;
}
int main(){
    int n,w;
    printf("ENTER NO OF ITEM IN KNAPSACK");
    scanf("%d",&n);
    struct item* arr=(struct item*)malloc(n * sizeof(struct item));

for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].wt);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &w);
    double maxValue = fracknap(arr,n,w);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);
    free(arr);
    return 0;
}