%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"   /* This header should define your AST node structures and functions, like create_ast_node and print_ast */
extern int yylineno;   /* Provided by lex to track line numbers */
int yylex(void);
void yyerror(const char *s);
%}

/* Define the types of semantic values */
%union {
    int intVal;
    double realVal;
    char charVal;
    char *stringVal;
    struct ASTNode *node;
}

/* Token declarations (should match those from your .l file) */
%token DEF MAIN IF ELSE ELIF WHILE FOR DO VAR BEGIN CALL END RETURN RETURNS NULL_T
%token AND OR NOT
%token BOOL CHAR INT REAL STRING TYPE
%token INT_LITERAL REAL_LITERAL CHAR_LITERAL STRING_LITERAL ID
%token INT_PTR CHAR_PTR REAL_PTR
%token EQ NEQ GE LE GT LT
%token PAR

%token SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE

/* If your language has a RETURNS keyword, declare it here */
%token RETURNS

/* Precedence declarations for arithmetic operators (if needed) */
%left '+' '-'
%left '*' '/'

%%
/* Grammar rules go here */
code : functions main_function functions
main_function : DEF '_' MAIN '_' LPAREN RPAREN ':' vairables BEGIN body END
functions : function functions
	| function
	| procedures
	| epsilon
function : header variables BEGIN body return_statement END
variables : VAR var_statements
	| epsilon
var_statements : variable SEMICOLON var_statements
	| variable SEMICOLON
variable : TYPE type ':' ids
	| TYPE STRING ':' string_ids
string_ids: string_id ',' string_ids
	| string_id
string_id: ID LBRACKET INT_LITERAL RBRACKET ':' STRING_LITERAL
	| ID LBRACKET INT_LITERAL RBRACKET
ids : id ',' ids
	| id
id : ID ':' value
	| ID
value : INT_LITERAL
	| REAL_LITERAL
	| CHAR_LITERAL
	| ID
	| ID LPAREN arguments RPAREN
	| expression
arguments: ID arguments
	| epsilon
header : DEF ID LPAREN parameters RPAREN ':' RETURNS_V type
procedures : procedure procedures
	| procedure
procedure : DEF ID LPAREN parameters RPAREN ':' body
pareameters : parameter parameters
	| epsilon
parameter : PAR type ':' ID
body : statements body
	| functions body
	| epsilon
statements : statement SEMICOLON statements
	| statement SEMICOLON
statement : if_statement
	| if_else_statement
	| while_statement
	| do_while_statement
	| for_statement
	| var_statement
	| call_statement
	| return_statement
	| declare_statement
while_statement : WHILE LPAREN condition RPAREN body
RETURNS_V : RETURNS
	| epsilon
type : BOOL
	| CHAR
	| INT
	| REAL
	| INT_PTR
	| CHAR_PTR
	| REAL_PTR
return_statement : RETURN expression SEMICOLON
epsilon :
%%

/* The main function simply invokes the parser */
int main(void) {
    yyparse();
    return 0;
}

/* Error handling function: prints an error message with the line number */
void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}
