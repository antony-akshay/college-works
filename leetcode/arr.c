#include<stdio.h>

 int main(){
    int i,j,c=0;
    int arr[] = {7};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("size:%d\n",size);

    for(i=0;i<size;i++){
        j=i+1;
        while(i<size){
            if(arr[i] == arr[j]){
                j++;
            }else{
                arr[i+1] = arr[j];
                c++;
                i=j;
            }
        }
    }

    printf("count:%d",c);
 }