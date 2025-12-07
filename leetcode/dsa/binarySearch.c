#include<stdio.h>

int fun(int a[20],int start,int end,int val){
    // printf("start : %d end : %d",start,end);

    if(start > end){
        return start + (end - start) / 2;
    }
    int mid = start + (end - start) / 2;
    // printf(" mid : %d\n",mid);
    // printf("s_val : %d e?  : %d\n",a[start],a[end]);
    int midval = a[mid];

    if(a[mid] == val){
        return mid;
    }else if(val<a[mid]){
        return fun(a,start,mid-1,val);
    }else if(val>a[mid]){
        return fun(a,mid+1,end,val);
    }
    return mid;
}

void main(){
    int a[] = {1,3,5,6};
    int val = 5;
    int size = sizeof(a)/sizeof(a[0]);
    int data = fun(a,0,size-1,val);

    if(data == -1){
        printf("not found\n");
    }else{
        printf("%d can be inserted at %d\n",val,data);
    }
}
