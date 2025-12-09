#include<stdio.h>
void selectionSort(int arr[]){
    for(int i=0;i<=6-2;i++){
        int mini = i;
        for(int j=i;j<=6-1;j++){
            if(arr[j] < arr[mini]) mini =j;   
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
void bubbleSort(int arr[]){
    for(int i=6-1;i>=0;i--){
        int didSwap = 0;
        for(int j=0;j<=i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if(didSwap==0) break;
    }
}
void insertionSort(int arr[]){
    for(int i=0;i<=6-1;i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
void display(int arr[]){
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[6] = {13,46,24,52,20,9};
    insertionSort(arr);
    display(arr);
}