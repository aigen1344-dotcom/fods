#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int par(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {

        while (i <= high && arr[i] <= pivot)
            i++;

        while (j >= low && arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void qs(int arr[],int low,int high){
    if (low >= high)      // FIXED
        return;

    int p = par(arr, low, high);
    qs(arr, low, p - 1);
    qs(arr, p + 1, high);
}

int main(){
    int arr[100], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qs(arr, 0, n - 1);

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
