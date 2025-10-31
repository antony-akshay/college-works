%{
#include<stdio.h>
#include<string.h>
extern FILE *yyin;

char* keywords[] = {
    "int","char","return","for","if","else","while","void"
};

int is_keyword(char* word){
    for(int i=0;i<sizeof(keywords)/sizeof(keywords[0]);i++){
        if(strcmp(keywords[i],word)==0){
            return 1;
        }
    }
    return 0;
}

%}

%%

[ \t\n]* ;
"//".*   ;
"/*"([^*]|\*+[^*/])*\*+"/" ;
^#[^\n]* {printf("preprocessor directive:%s\n",yytext);}
"%"|"/"|"*"|"-"|"+" {printf("operator:%s\n",yytext);}
";"|","|"("|")"|"{"|"}" {printf("separator:%s\n",yytext);}
"=="|"<="|">="|"<"|">"|"=" {printf("operator:%s\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {
    if(is_keyword(yytext)){
        printf("keyword:%s\n",yytext);
    }else{
        printf("identifier:%s\n",yytext);
    }
}
[0-9]+(\.[0-9]+)? {printf("operator:%s\n",yytext);}
. ;

%%

int main(){
 yyin=fopen("test.c","r");
 yylex();
 fclose(yyin);
}

int yywrap(){
    return 1;
}
