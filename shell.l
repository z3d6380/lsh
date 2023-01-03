/*
 * File: shell.l
 * Author: Luis Moraguez
 * Date: 2022-12-05
 * Version: 0.1.0
 * Description: Simple lexical analyzer for lsh
 */

%{
#include <string.h>
#include "y.tab.h"
}%

%%
\n      {
    return NEWLINE;
        }

[ \t]   {
    /* Discard spaces and tabs */
        }

">"     {
    return GREAT;
        }

"<"     {
    return LESS;
        }

">>"    {
    return GREATGREAT;
        }

">&"    {
    return GREATAMPERSAND;
        }

">>&"   {
    return GREATGREATAMPERSAND;
}

"|"     {
    return PIPE;
        }

"&"     {
    return AMPERSAND;
        }

[^ \t\n][^ \t\n]*   {
    /*Assume that file names only have alpha chars*/
    yylval.string_val = strdup(yytext);
    return WORD;
        }

        {
            /*Invalid characters in input*/
            return NOTOKEN;
        }
%%