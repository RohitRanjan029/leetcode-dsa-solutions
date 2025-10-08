#include<stdio.h>
#include<time.h>
void countingSort(int arr[],int n, int exp){
    int output[n];
    int count[10] = {0};

    for(int i=0; i<n; i++){
        count[(arr[i]/exp)%10]++;
    }
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Step 4: Copy sorted elements back to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void radixsort(int arr[], int n){
    int max = getMax(arr,n);

    for(int exp=1; max/exp>0; exp*=10){
        countingSort(arr,n,exp);
    }
}
int main(){
    int arr[] = {170,45,75,90,802,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    double time_taken;
    clock_t start = clock();
    radixsort(arr,n);
    clock_t end = clock();

    time_taken = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("\n\nTime taken: %.2f ms\n", time_taken);

    return 0;
}