%{
#include<stdio.h>
%}

%%

aeiou {
    printf("AEIOU");
}

%%

int main(){
    yyin = fopen("input.text","r");
    yylex();
    fclose(yyin);
}

int yywrap(){
    return 1;
}