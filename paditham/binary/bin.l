%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"   /* generated from bindec.y */
extern int yylval;
%}

%option noyywrap

%%
0       { yylval = 0; return ZERO; }
1       { yylval = 1; return ONE; }
[ \t]   ;              /* ignore spaces */
\n      { return 0; }  /* end input on newline */
.       { return yytext[0]; }
%%
