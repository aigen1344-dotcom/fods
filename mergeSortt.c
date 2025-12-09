#include<stdio.h>
int comparisions = 0;
void merge(int arr[],int low, int mid, int high){
    int i = low ,j = mid+1, k=0;
    int temp[15];
    while(i<=mid && j<= high){
        comparisions++;
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else temp[k++] = arr[j++];
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=high){
        temp[k++] = arr[j++];
    }
    for(int i=low,k=0;i<=high;i++,k++){
        arr[i] = temp[k];
    }
}
void merge_sort(int arr[], int low,int high){
    if(low >= high) return;
    int mid = (low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int arr[100], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, 0, n - 1);

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Total comparisons: %d\n", comparisions);

}