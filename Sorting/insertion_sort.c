#include<stdio.h>
int main(){
    int arr[5] = {4,3,7,5,2};

    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }

    for(int i=1; i<5; i++){
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else{
                break;
            }
        }
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
}