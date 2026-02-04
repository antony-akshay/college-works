#include <stdio.h>
#include <stdlib.h>

int main(){
    int* result;
    int arr[] = {9,9,9,9,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int j = size - 1;
    int carry=1;
    while(carry == 1 && j>= 0){
        arr[j]+=1;
        if(arr[j] == 10){
            arr[j]=0;
            carry=1;
            j--;
            continue;
        }
        carry=0;
    }
    if(carry == 1){
        result = malloc((size+1)* sizeof(int));
        result[0]=carry;
        for(j=0;j<size;j++){
            result[j+1]=arr[j];
        }
        for(j=0;j<size+1;j++){
            printf("%d",result[j]);
        }
        printf("\n");
    }else{
        for(j=0;j<size;j++){
            printf("%d",arr[j]);
        }
        printf("\n");
    }
}

//leetcode
// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* plusOne(int* digits, int digitsSize, int* returnSize) {
//     int carry=1,j=digitsSize-1;
//     while(carry ==1 && j>= 0){
//         digits[j]+=1;
//         if(digits[j] == 10){
//             carry = 1;
//             digits[j]=0;
//             j--;
//             continue;
//         }
//         carry=0;
//     }
//     int* result;
//     if(carry==1){
//         *returnSize = digitsSize+1;
//         result = malloc((*returnSize)* sizeof(int));
//         result[0]=1;
//         for(j=0;j<digitsSize;j++){
//             result[j+1]=digits[j];
//         }
//     }else{
//         *returnSize = digitsSize;
//         result = malloc((*returnSize)*sizeof(int));
//         for(j=0;j<digitsSize;j++){
//             result[j]=digits[j];
//         }
//     }
//     return result;
// }
