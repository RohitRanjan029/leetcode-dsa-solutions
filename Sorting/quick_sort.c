#include<stdio.h>
int partition(int arr[],int start, int end){
    int pos = start;
    for(int i=start; i<=end; i++){
        if(arr[end]>=arr[i]){
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
            pos++;
        }
    }
    return pos-1;
}
void quicksort(int arr[],int start, int end){
    if(start>=end){
        return;
    }
    int pivort = partition(arr,start,end);
    quicksort(arr,start,pivort-1);
    quicksort(arr,pivort+1,end);
}
int main(){
    int arr[10] = {10,3,4,1,5,6,3,2,11,9};
    quicksort(arr,0,9);
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
}