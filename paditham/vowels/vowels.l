%{
#include<stdio.h>
extern FILE *ptr;
int count=0;
int consonant = 0;
%}

%%

[aeiouAEIOU] {
    count++;
}
[a-zA-Z] {
    consonant++;
}
[^a-zA-Z] {
    
}

%%

int main(){
    yyin = fopen("input.text","r");
    yylex();
    fclose(yyin);
    printf("\ncount: %d\n",count);
    printf("\nconsonant: %d\n",consonant);
}

int yywrap(){
    return 1;
}
