%{
#include<stdio.h>
#include<string.h>
extern FILE *ptr;
char word[50];
int count=0;
%}

%%

[#a-zA-Z]+ {
    if(strcmp(yytext,word) == 0){
        count++;
    }
}

.|\n ;

%%

int main(){
    yyin = fopen("input.text","r");
    if(yyin == 0){
        printf("error opening file\n");
        return 1;
    }

    printf("enter the word to search:");
    scanf("%s",word);
    yylex();
    printf("count:%d\n",count);
    fclose(yyin);
}

int yywrap(){
    return 1;
}