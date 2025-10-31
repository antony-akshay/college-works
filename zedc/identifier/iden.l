%{
#include "y.tab.h"
%}

%%

[a-zA-Z]*[a-zA-Z_][a-zA-z0-9_]+ {return ID;}
[ \t\n]* ;
. {return yytext[0];}

%%
