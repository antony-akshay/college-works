#include<string.h>
#include<stdio.h>

int strStr(char* haystack, char* needle) {
    char* result = strstr(haystack,needle);
    // printf("%d",result);
    printf("%d",result-haystack);
    if(result != NULL){
        return result-haystack;
    }
    return -1;
}

int main(){
    strStr("hi there this is me","there");
}
