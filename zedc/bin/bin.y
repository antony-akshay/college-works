%{
#include<stdio.h>
int yyerror(const char* s);
%}

%token ZERO ONE

%%

N : L {
    printf("result is %d",$$);
    return 0;
};

L : L B {$$=$1*2+$2;}
  | B {$$=$1;}
;

B : ZERO {$$=0;}
  | ONE {$$=1;}
;

%%

int main(){
    printf("binary? ");
    yyparse();
}

int yyerror(const char* s){
    printf("error");
}

int yywrap(){
return 0;
}
