#include<stdio.h>
#include<string.h>

int main(){
    char a[] = " hi there this is here";
    char b[] = "there";

    if(strstr(a,b)){
        printf("%d",strstr(a,b)-a);
    }else{
        printf("not found");
    }
}
