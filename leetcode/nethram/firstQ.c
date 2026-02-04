#include<stdio.h>

int main(){
    int arr[]= {12,13,80,85,23,90,87,104};
    int res[5];
    int size = sizeof(arr)/sizeof(arr[0]);
    int j=0;
    int k=0;
    for(int i=0;i<size;i++){
        if(arr[i] > 80){
            while(arr[i++]>80){
                j++;
            }
           res[k++] = j;
           i=j;
           j=0;
        }
    }

    for(int i=0;i<6;i++){
        printf("%d ",res[i]);
    }
}
