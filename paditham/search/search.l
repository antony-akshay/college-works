%{
#include<stdio.h>
#include<string.h>
char word[30];
%}

%%

[a-zA-Z0-9]+ {
    if(strcmp(yytext,word)==0){
        printf("found");
    }else{
        printf("not found");
    }
}

%%

int main(){
    printf("enter the word to search:");
    scanf("%s",word);
    yyin = fopen("input.text","r");
    yylex();
    fclose(yyin);
}

int yywrap(){
    return 1;
}