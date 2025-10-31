%{
#include<stdio.h>
int yyerror(const char* s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left UMINUS

%%

S : E {
    printf("result is %d",$$);
    return 0;
};

E : E '+' E {$$=$1+$3;}
  | E '-' E {$$=$1-$3;}
  | E '*' E {$$=$1*$3;}
  | E '/' E {
    if($3==0){
        yyerror("divison by zero");
    }
    $$=$1/$3;
  }
  | E '%' E {$$=$1%$3;}
  | '-' E %prec UMINUS {$$=-$2;}
  | '(' E ')' {$$=$2;}
  | NUMBER {$$=$1;}
;

%%

int main(){
    printf("expression? ");
    yyparse();
}

int yyerror(const char* s){
    printf("%s",s);
}

int yywrap(){
return 0;
}
