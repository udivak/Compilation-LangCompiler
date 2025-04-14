%%
\n             { yylineno++; }
[ \t\r]+       { /* Skip whitespace */ }

"def"           { return DEF; }
"if"            { return IF; }
"else"          { return ELSE; }
"elif"          { return ELIF; }
"while"         { return WHILE; }
"for"           { return FOR; }
"do"            { return DO; }
"var"           { return VAR; }
"begin"         { return BEGIN_TOKEN; }
"call"          { return CALL; }
"end"           { return END; }
"return"        { return RETURN; }
"returns"       { return RETURNS; }
"null"          { return NULL_T; }
"and"           { return AND; }
"or"            { return OR; }
"not"           { return NOT; }
"bool"          { return BOOL; }
"TRUE"          { return TRUE; }
"FALSE"         { return FALSE; }
"char"          { return CHAR; }
"int"           { return INT; }
"string"        { return STRING; }
"real"          { return REAL; }
"main"          { return MAIN; }
"type"          { return TYPE; }
"int\\*"        { return INT_PTR; }
"char\\*"       { return CHAR_PTR; }
"real\\*"       { return REAL_PTR; }

"=="            { return EQ; }
"!="            { return NEQ; }
">="            { return GE; }
"<="            { return LE; }

">"             { return GT; }
"<"             { return LT; }
"="             { return '='; }
"\\+"           { return '+'; }
"-"             { return '-'; }
"\\*"           { return '*'; }
"/"             { return '/'; }
"&"             { return '&'; }

";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
":"             { return ':'; }
"\\|"           { return '|'; }

0[xX][0-9a-fA-F]+ {
    yylval.intVal = (int) strtol(yytext, NULL, 16);
    return INT_LITERAL;
}
[0-9]+ {
    yylval.intVal = atoi(yytext);
    return INT_LITERAL;
}

[0-9]+(\\.[0-9]+)?([eE][-+]?[0-9]+)? {
    yylval.realVal = atof(yytext);
    return REAL_LITERAL;
}

'[^'\\n]' {
    yylval.charVal = yytext[1];
    return CHAR_LITERAL;
}

\"[^\"]*\" {
    yylval.stringVal = strdup(yytext);
    if (strlen(yylval.stringVal) == 1) {
        return CHAR_LITERAL;
    }
    return STRING_LITERAL;
}

[a-zA-Z][a-zA-Z0-9_]* {
    yylval.stringVal = strdup(yytext);
    return ID;
}

"#->"[^<]*"<-#" {
    /* Ignore comments */
}


.              {
    return yytext[0];
}
%%