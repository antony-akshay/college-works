%{
#include<stdio.h>
int line_no = 1;
extern FILE* yyout;
%}

line .*\n 

%%

{line} {
    printf("%10d %s",line_no,yytext);
    fprintf(yyout,"%10d %s",line_no,yytext);
    line_no++;
}

%%

int main(){
    yyin=fopen("input.text","r");
    yyout = fopen("output.text","w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}

int yywrap(){
    return 1;
}