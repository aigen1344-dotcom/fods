#include<stdio.h>
int findMN(int arr[],int size){
    int temp[size + 1];
    for(int i = 0;i<=size;i++){
        temp[i] = 0;
    }
    for(int i=0;i<size;i++){
        if(arr[i] > 0 && arr[i] <= size){
            temp[arr[i]] = 1;
        }
    }
    for(int i = 1;i<=size;i++){
        if(temp[i] == 0) return i;
    }
    return size+1;
}
int main(){
    int arr[] = {1,2,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Smallest missing num is %d ",findMN(arr,size));
    return 0;
}