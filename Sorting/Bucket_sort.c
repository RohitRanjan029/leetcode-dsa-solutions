#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000
#define BUCKETS 10
int partition(float arr[],int start, int end){
    int pos = start;

    for(int i=start; i<=end; i++){
        if(arr[end]>=arr[i]){
            float temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
            pos++;
        }
    }
    return pos-1;
}
void quickSort(float arr[],int start, int end){
    if(start >= end){
        return;
    }
    int pivort = partition(arr,start,end);
    quickSort(arr,start,pivort-1);
    quickSort(arr,pivort+1,end);
}
void bucketSort(float arr[], int n){
    float bucket[BUCKETS][MAX];
    int count[BUCKETS] = {0};

    for(int i=0; i<n; i++){
        int index = (int)(arr[i] * BUCKETS);
        if(index>=BUCKETS){
            index = BUCKETS-1;
        }
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    for(int i=0; i<BUCKETS; i++){
        if(count[i]>1){
            quickSort(bucket[i],0,count[i]-1);
        }
    }
    int k = 0;
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k] = bucket[i][j];
            k++;
        }
    }

    
}
int main(){
    float arr[MAX];
    int n;
    double time_taken;

    printf("ENter number of element : ");
    scanf("%d", &n);

    srand(time(0));

    for(int i=0; i<n; i++){
        arr[i] = (float)rand()/RAND_MAX;
    }

    printf("\nArray before sorting:\n");
    for(int i=0; i<n; i++){
        printf("%.3f ", arr[i]);
    }
    clock_t start = clock();
    bucketSort(arr,n);
    clock_t end = clock();

    time_taken = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\n\nArray after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }

    printf("\n\nTime taken: %.2f ms\n", time_taken);

    return 0;

}