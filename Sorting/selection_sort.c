#include<stdio.h>
int main(){
    int arr[5] = {4,3,7,5,2};

    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }

    for(int i=0; i<4; i++){
        int index = i;
        for(int j=i+1; j<5; j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
}