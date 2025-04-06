%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"  /* Contains token definitions from your yacc file */
extern int yylineno; /* Keeps track of line numbers */
%}

/* Definitions section (optional) can go here */

/* For example, you might define regular expressions for common patterns */

/*------------------------------------------------------------------------------
Rules Section: Define your tokens and patterns
------------------------------------------------------------------------------*/
%%
/* Keywords */
"def"           { return DEF; }
"if"            { return IF; }
"else"          { return ELSE; }
"elif"          { return ELIF; }
"while"         { return WHILE; }
"for"           { return FOR; }
"do"            { return DO; }
"var"           { return VAR; }
"begin"         { return BEGIN; }
"end"           { return END; }
"return"        { return RETURN; }
"null"          { return NULL_T; }
"and"           { return AND; }
"or"            { return OR; }
"not"           { return NOT; }
"bool"          { return BOOL; }
"char"          { return CHAR; }
"int"           { return INT; }
"real"          { return REAL; }
"string"        { return STRING; }

/* Pointer types: These can be recognized directly if written as e.g., "int*" */
"int*"          { return INT_PTR; }
"char*"         { return CHAR_PTR; }
"real*"         { return REAL_PTR; }

/* Literals */
/* Hexadecimal integer literal (starts with 0x or 0X) */
0[xX][0-9a-fA-F]+ {
    yylval.intVal = (int) strtol(yytext, NULL, 16);
    return INT_LITERAL;
}

/* Decimal integer literal */
[0-9]+ {
    yylval.intVal = atoi(yytext);
    return INT_LITERAL;
}

/* Real literal: handles decimals and scientific notation */
([-+]?([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)([eE][-+]?[0-9]+)?) {
    yylval.realVal = atof(yytext);
    return REAL_LITERAL;
}

/* Character literal: a single character enclosed in single quotes */
\'([^\'\n])\' {
    yylval.charVal = yytext[1];
    return CHAR_LITERAL;
}

/* String literal: characters inside double quotes (no embedded double quotes allowed) */
\"([^\"\n])*\" {
    yylval.stringVal = strdup(yytext);
    return STRING_LITERAL;
}

/* Identifier: starts with a letter and can include letters, digits, and underscores */
[a-zA-Z][a-zA-Z0-9_]* {
    yylval.stringVal = strdup(yytext);
    return IDENTIFIER;
}

/* Operators */
/* Multi-character operators first to ensure the longest match */
"=="            { return EQ; }
"!="            { return NEQ; }
">="            { return GE; }
"<="            { return LE; }

/* Single-character operators */
">"             { return GT; }
"<"             { return LT; }
"="             { return '='; }    /* Alternatively, use a defined token like ASSIGN */
"\+"            { return '+'; }
"-"             { return '-'; }
"\*"            { return '*'; }
"/"             { return '/'; }
"&"             { return '&'; }

/* Punctuation and delimiters */
";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

/* Special symbol for string length (vertical bar) */
"|"             { return '|'; }

/* Comments: block comments start with "#->" and end with "<-#" */
"#->"([^<]|"<"[^-])*"<-#"    { /* Ignore the comment text */ }

/* Whitespace: Skip spaces, tabs, and carriage returns */
[ \t\r]+       { /* do nothing, skip whitespace */ }

/* Newline: Update line counter */
\n             { yylineno++; }

/* Any other character: Could be an error or simply return the character */
.              {
    printf("Unrecognized character: %s at line %d\n", yytext, yylineno);
    return yytext[0];
}

%%

/*------------------------------------------------------------------------------
User Code Section: Additional C code and functions
------------------------------------------------------------------------------*/
int yywrap(void) {
    return 1;
}
