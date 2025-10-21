%{
#include<stdio.h>
#include<stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%token NUMBER

%left '+' '-';
%left '*' '/' '%';
%left '(' ')';

%%

S : E {
    printf("Result is %d\n",$1);
    return 0;
};

E : E '+' E {$$ = $1 + $3;}
  | E '-' E {$$ = $1 - $3;}
  | E '*' E {$$ = $1 * $3;}
  | E '%' E {$$ = $1 % $3;}
  | E '/' E {
    if($3 == 0){
        yyerror("division by zero");
        exit(1);
    }
    $$ = $1 / $3;
  }
  | '(' E ')' {$$ = $2;}
  | NUMBER {$$ = $1;};
%%

int main(){
    printf("enter the arithmetic expression:");
    yyparse();
    if(flag == 0){
        printf("entered invalid");
        return 0;
    }
}

void yyerror(const char *s) {
    printf("\nEntered arithmetic expression is Invalid: %s\n\n", s);
    flag = 1;
}