#include<stdio.h>

int main(){
    int a[] = {1,1,2,3,4,4};
    int size = sizeof(a)/sizeof(a[0]);

    int j=0;
    for(int i=0;i<size;i++){
        if(a[i]!=a[j]){
            a[++j] = a[i];
        }
    }
    printf("count:%d\n",j+1);
    for(int i=0;i<size;i++){
     printf("%d ",a[i]);
    }
}
