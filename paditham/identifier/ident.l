digit [0-9]
letter [a-zA-Z_]

%{
#include<stdio.h>
int count = 0;
extern FILE *ptr;
%}

%%
{digit}({digit}|{letter})* {}
{letter}({letter}|{digit})* {
    count++;
    printf("%s\n",yytext);
}

.|\n ;

%%

int main(){
    yyin = fopen("input.text","r");
    yylex();
    printf("no of identifier:%d",count);
    fclose(yyin);
}

int yywrap(){
    return 1;
}