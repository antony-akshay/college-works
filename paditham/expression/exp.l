%{
#include "y.tab.h"
%}

%option noyywrap

%%

[0-9]+          { return NUMBER; }       // numbers
[a-zA-Z]+       { return ID; }           // variable names
[ \t]+          ;                        // skip spaces
\n              return 0;                // end of input
.               { return yytext[0]; }    // operators or parentheses
%%
