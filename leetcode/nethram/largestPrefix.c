#include<stdio.h>

int main(){
    char *arr[] = {"flower","flows","flown"};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(1){
        char a = arr[0][i];
        for(int j=1;j<size;j++){
            if(a!=arr[j][i]){
                goto END;
            }
        }
        i++;
    }

END:
    for(int k=0;k<i;k++){
        printf("%c ",arr[0][k]);
    }
}
