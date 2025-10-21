%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
int yywrap();
%}

%token ZERO ONE

%%
N : L { 
        printf("The decimal value is = %d\n", $1);
        return 0;
    }
  ;

L : L B { $$ = $1 * 2 + $2; }
  | B   { $$ = $1; }
  ;

B : ZERO { $$ = 0; }
  | ONE  { $$ = 1; }
  ;
%%

int main() {
    printf("Enter a binary number: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("\nInvalid binary number!\n");
}
