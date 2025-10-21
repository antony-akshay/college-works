%{
#include <stdio.h>
#include <stdlib.h>
int flag = 0;  // flag = 1 means invalid
%}

%token NUMBER ID

%left '+' '-'
%left '*' '/'
%left '(' ')'
%left UMINUS

%%

S : E
    {
        printf("\nEntered arithmetic expression is valid ✅\n");
        return 0;
    }
  ;

E : E '+' E
  | E '-' E
  | E '*' E
  | E '/' E
  | '(' E ')'
  | '-' E %prec UMINUS
  | NUMBER
  | ID
  ;

%%

int main() {
    printf("Enter an expression:\n");
    yyparse();
    if(flag == 0)
        printf("Parsing complete.\n");
    return 0;
}

void yyerror(const char *s) {
    printf("\nEntered arithmetic expression is invalid ❌\n");
    flag = 1;
}
