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
%token DEF IF ELSE ELIF WHILE FOR DO VAR BEGIN END RETURN NULL_T
%token AND OR NOT
%token BOOL CHAR INT REAL STRING
%token INT_LITERAL REAL_LITERAL CHAR_LITERAL STRING_LITERAL IDENTIFIER
%token INT_PTR CHAR_PTR REAL_PTR
%token EQ NEQ GE LE GT LT
%token SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE

/* If your language has a RETURNS keyword, declare it here */
%token RETURNS

/* Precedence declarations for arithmetic operators (if needed) */
%left '+' '-'
%left '*' '/'

%%

/* The start symbol of the grammar */
program:
    functions
    {
      /* Print the AST after successful parsing */
      print_ast($1, 0);
    }
    ;

/* A program is a list of functions */
functions:
      functions function
      {
         /* Combine the previous functions with a new one under a CODE node */
         $$ = create_ast_node("CODE", 2, $1, $2);
      }
    | function
      { $$ = create_ast_node("CODE", 1, $1); }
    ;

/* Function definition. Adjust the structure as needed for your language. */
function:
    DEF IDENTIFIER LPAREN parameters RPAREN ret_spec block
    {
      /* Create a FUNC node with children: function name, parameters, return spec, and function body */
      $$ = create_ast_node("FUNC", 4, create_ast_leaf($2), $4, $6, $7);
    }
    ;

/* Parameters: either a non-empty list or empty (indicating no parameters) */
parameters:
    parameter_list
    |
      { $$ = create_ast_leaf("PARS NONE"); }
    ;

/* Parameter list: one or more parameters separated by semicolons */
parameter_list:
      parameter_list SEMICOLON parameter
      {
         $$ = create_ast_node("PARAMS", 2, $1, $3);
      }
    | parameter
      { $$ = create_ast_node("PARAMS", 1, $1); }
    ;

/* A parameter: typically starts with a parameter indicator (e.g., par1), followed by a type and an identifier.
   Here we assume the parameter indicator is parsed as an IDENTIFIER.
   The colon separates the type from the variable name.
*/
parameter:
    IDENTIFIER type_spec ':' IDENTIFIER
    {
       /* Create a PARAM node with the parameter indicator, type, and variable name */
       $$ = create_ast_node("PARAM", 3, create_ast_leaf($1), $2, create_ast_leaf($4));
    }
    ;

/* Type specification: maps keywords to type nodes */
type_spec:
    BOOL    { $$ = create_ast_leaf("BOOL"); }
    | CHAR  { $$ = create_ast_leaf("CHAR"); }
    | INT   { $$ = create_ast_leaf("INT"); }
    | REAL  { $$ = create_ast_leaf("REAL"); }
    | STRING { $$ = create_ast_leaf("STRING"); }
    | INT_PTR   { $$ = create_ast_leaf("INT*"); }
    | CHAR_PTR  { $$ = create_ast_leaf("CHAR*"); }
    | REAL_PTR  { $$ = create_ast_leaf("REAL*"); }
    ;

/* Return specification: functions may declare a return type.
   Procedures (functions with no return value) have no return spec.
*/
ret_spec:
    /* For functions with a return type, expect a colon, the RETURNS keyword, and a type */
    ':' RETURNS type_spec
    { $$ = create_ast_node("RET", 1, $3); }
    | /* If nothing is specified, assume no return value */
      { $$ = create_ast_leaf("RET NONE"); }
    ;

/* Function body: a block that starts with BEGIN and ends with END.
   It may include declarations (like variables) and statements.
*/
block:
    BEGIN declarations statements END
    {
       $$ = create_ast_node("BODY", 2, $2, $3);
    }
    ;

/* Declarations: For simplicity, we assume an empty declarations section.
   You can expand this rule to include variable declarations.
*/
declarations:
    /* No declarations */
      { $$ = create_ast_leaf("DECLS NONE"); }
    ;

/* Statements: a list of one or more statements */
statements:
    statements statement
    {
      $$ = create_ast_node("STMT_LIST", 2, $1, $2);
    }
    | statement
    {
      $$ = create_ast_node("STMT_LIST", 1, $1);
    }
    ;

/* A statement can be an assignment, an if-statement, or a return statement.
   You can expand this as needed.
*/
statement:
    assignment SEMICOLON
    { $$ = $1; }
    | if_statement
    { $$ = $1; }
    | RETURN expression SEMICOLON
    { $$ = create_ast_node("RET", 1, $2); }
    ;

/* Assignment statement: identifier = expression */
assignment:
    IDENTIFIER '=' expression
    { $$ = create_ast_node("ASSIGN", 2, create_ast_leaf($1), $3); }
    ;

/* If statement with optional else part */
if_statement:
    IF expression ':' block else_part
    { $$ = create_ast_node("IF-ELSE", 3, $2, $4, $5); }
    ;

/* Else part is optional */
else_part:
    ELSE ':' block
    { $$ = $3; }
    | /* No else clause */
      { $$ = create_ast_leaf("NO_ELSE"); }
    ;

/* Expression rules. These are simplified; you should expand them to cover the full language.
   The following handles basic arithmetic expressions.
*/
expression:
    expression '+' expression
    { $$ = create_ast_node("ADD", 2, $1, $3); }
    | expression '-' expression
    { $$ = create_ast_node("SUB", 2, $1, $3); }
    | expression '*' expression
    { $$ = create_ast_node("MUL", 2, $1, $3); }
    | expression '/' expression
    { $$ = create_ast_node("DIV", 2, $1, $3); }
    | '(' expression ')'
    { $$ = $2; }
    | INT_LITERAL
    { $$ = create_ast_leaf("INT_LITERAL"); }
    | REAL_LITERAL
    { $$ = create_ast_leaf("REAL_LITERAL"); }
    | IDENTIFIER
    { $$ = create_ast_leaf("IDENTIFIER"); }
    ;

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
