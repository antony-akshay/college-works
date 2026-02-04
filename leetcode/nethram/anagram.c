#include <inttypes.h>
#include<stdio.h>
#include<string.h>

int main(){
    char a[] = "pen";
    char b[] = "enp";
    int flag=1;

    int l = strlen(a);
    int m = strlen(b);

    for(int i=0;i<l;i++){
        for(int j=0;j<l-1-i;j++){
            if(a[j]>a[j+1]){
                char t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    for(int i=0;i<l;i++){
        for(int j=0;j<l-1-i;j++){
            if(b[j]>b[j+1]){
                char t = b[j];
                b[j] = b[j+1];
                b[j+1] = t;
            }
        }
    }

    for(int i=0;i<(strlen(a) > strlen(b) ? strlen(a):strlen(b));i++){
        if(a[i] != b[i]){
            flag=0;
        }
    }

    if(flag){
        printf("anagram");
    }else{
        printf("not anagram");
    }
}
