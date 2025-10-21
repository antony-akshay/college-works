%{
#include<stdio.h>
int l=0,c=0,v=0,w=0;
%}

%%

[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
[^\t\n] {w++;}
[\n] {w++;l++; printf("c:%d\n",c); printf("v:%d\n",v); printf("w:%d\n",w); printf("l:%d\n",l); return 0;}

%%

int yywrap(){
    return (1);
}

int main(){
    printf("enter the text:");
    yylex();
    return 0;
}

