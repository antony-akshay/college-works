#include <stdio.h>
#include <sys/param.h>
#include <string.h>

void main() {
    char a[] = "1111";
    char b[] = "1111";
    int i = strlen(a)-1;
    int j = strlen(b)-1;
    char result[(strlen(a) > strlen(b) ? strlen(a) : strlen(b)) + 2];
    int carry = 0,k=0;
    int digit,sum = 0;
    while(i>=0 || j>=0 ||carry > 0){
        sum = carry;
        if(i>=0) sum+= a[i] - '0';
        if(j>=0) sum+= b[j] - '0';

        digit = sum % 2 ;
        carry = sum / 2;

        result[k++] = digit + '0';
        i--;j--;
    }
    result[k] = '\0';

    for (int x = 0; x < k/2; x++) {
            char temp = result[x];
            result[x] = result[k-1-x];
            result[k-1-x] = temp;
    }

    printf("%s\n", result);

    return ;
}
