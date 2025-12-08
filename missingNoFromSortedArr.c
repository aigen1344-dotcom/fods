#include<stdio.h>
int findMissingNum(int arr[],int size){
    int expected = 1;
    for(int i=0;i<size;i++){
        if(arr[i] < expected) continue;
        else if(arr[i] == expected) expected++;
        else break;
    }
    return expected;
}
int main(){
    int arr[] = {1,2,3,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Smallest missing num is %d ",findMissingNum(arr,size));
    return 0;
}