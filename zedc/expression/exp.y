%{
#include<stdio.h>
int yyerror(const char *s);
%}

%token NUMBER ID
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%left UMINUS

%%

S : E {
    printf("valid");
    return 0;
};

E : E '+' E
  | E '-' E
  | E '/' E
  | E '*' E
  | E '%' E
  | '-' E %prec UMINUS
  | '(' E ')'
  | NUMBER
  | ID
;
%%

int main(){
    printf("enter the expression");
    yyparse();
    return 0;
}

int yyerror(const char *s){
    printf("not valid expression");
}

int yywrap(){
    return 0;
}
