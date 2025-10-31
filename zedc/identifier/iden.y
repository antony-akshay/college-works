%{
#include<stdio.h>
int yyerror(const char *s);
%}

%token ID

%%

S : ID {
    printf("valid identifier");
    return 0;
}

%%

int main(){
    printf("expression:");
    yyparse();
}

int yyerror(const char *s){
    printf("invalid identifier");
    return 0;
}

int yywrap(){
    return 0;
}
