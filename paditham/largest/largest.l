%{
#include<stdio.h>
#include<string.h>
extern FILE *ptr;
char word[50];
int n=0;
%}

%%

[a-zA-Z0-9]+ {
    if(strlen(yytext) > n){
        strcpy(word,yytext);
        n = strlen(yytext);
    }
}

%%

int yywrap(){
    return 1;
}

int main(){
    yyin = fopen("input.text","r");
    if(!yyin){
        printf("error opening file\n");
        return 1;
    }

    yylex();

    printf("the largest word is %s of size %d",word,n);

    fclose(yyin);
}