%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int yylex();
int yyerror(const char*);

int main_count = 0; // סופר את מספר הופעות main
int has_return = 0;
int last_param_number = 0;
typedef struct node
{
    char *token;
    struct node *left;
    struct node *right;
    } node;
node *mknode(char *token, node *left, node *right);
void printtree(node *tree, int tabs);
%}
%union {
    int intVal;
    float realVal;
    char charVal;
    char* stringVal;
    void* node;
}
%token <intVal> AND OR NOT BOOL TRUE FALSE
%token <stringVal> DEF MAIN IF ELSE ELIF WHILE FOR DO VAR BEGIN_TOKEN CALL END RETURN RETURNS NULL_T
%token <stringVal> REAL STRING TYPE CHAR INT
%token <intVal> INT_LITERAL REAL_LITERAL CHAR_LITERAL
%token <stringVal> INT_PTR CHAR_PTR REAL_PTR ID STRING_LITERAL
%token <intVal> EQ NEQ GE LE GT LT

%token SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
%left '+' '-'
%left '*' '/' '%'
%type <node> code functions function
%type <node> body body_main statements statement
%type <node> expression condition comparison_operator
%type <node> variables var_statements variable
%type <node> string_ids string_id ids id type bool_type
%type <node> parameters parameter
%type <node> return_statement
%type <node> declaration_statement assignment_statement call_statement params
%type <node> if_statement while_statement do_statement for_statement for_header update_expression block_statement


%start code

%%

code
    : functions
        {
            if (main_count == 0) {
                yyerror("Error: missing 'main' function.");
                YYABORT;
            }
            printf("Parsing completed. Found 1 main function.\n");

        }
    ;

functions
    : function              { $$ = mknode("function", $1, NULL); }
    | function functions    {$$ = mknode("code", $2, $1);}
    ;

function
    : DEF MAIN LPAREN RPAREN body_main
        {
            main_count++;
            if (main_count > 1) {
                yyerror("Error: multiple 'main' functions.");
                YYABORT;
            }
            printf("Main function parsed.\n");
             $$ = mknode("main", $5, NULL);
        }
    | DEF ID LPAREN parameters RPAREN RETURNS type variables body
        {
            if (!has_return) {
                yyerror("Error: non-main function must contain at least one return.");
                YYABORT;
            }
            has_return = 0;   // reset has_return for the next function
            $$ = mknode("function",
                mknode("header",
                    mknode("type",
                        mknode($2, NULL, NULL),
                        mknode("return type", $7, NULL)
                        ),
                     $4),
                mknode("",
                    mknode("variables", $8, NULL),
                    $9
                    )
                );
        }
    ;

variables
    : VAR var_statements        { $$ = $2; }
    | /* empty */               { $$ = NULL; }
    ;

var_statements
    : variable SEMICOLON var_statements { $$ = mknode("var statements", $1, $3); }
    | variable SEMICOLON    { $$ = mknode("var statements", $1, NULL); }
    ;

variable
    : TYPE type ':' ids                 { $$ = mknode("variables", $2, $4); }
    | TYPE STRING ':' string_ids        { $$ = mknode("string variables", mknode("string", NULL, NULL), $4); }
    ;

string_ids
    : string_id ',' string_ids          { $$ = mknode("string variable", $1, $3); }
    | string_id                         { $$ = mknode("string variable", $1, NULL); }
    ;

string_id
    : ID LBRACKET INT_LITERAL RBRACKET ':' STRING_LITERAL
            { char buf[50]; // assuming INT_LITERAL is not too long
              sprintf(buf, "%d", $3);
              $$ = mknode($1, mknode(strdup(buf), NULL, NULL), mknode($6, NULL, NULL)); }
    | ID LBRACKET INT_LITERAL RBRACKET
            { char buf[50];
              sprintf(buf, "%d", $3);
              $$ = mknode($1, mknode(strdup(buf), NULL, NULL), NULL); }
    ;


ids
    : id ',' ids                        { $$ = mknode("ids", $1, $3); }
    | id                                { $$ = mknode("ids", $1, NULL); }
    ;

id
    : ID ':' expression                 { $$ = mknode($1, $3, NULL); }
    | ID                                { $$ = mknode($1, NULL, NULL); }
    ;

body
    : BEGIN_TOKEN statements  return_statement END  { $$ = mknode("body", $2, $3); }
    ;
body_main
    : BEGIN_TOKEN statements END                    { $$ = $1; }
    ;

statements
    : statement  statements             { $$ = mknode("", $1, $2); }
    | /* empty */                       { $$ = mknode("", NULL, NULL); }
    ;

parameters
    : parameter COMMA parameters        { $$ = mknode("parameters", $1, $3); }
    | parameter                         { $$ = mknode("parameters", $1, NULL); }
    ;

parameter
    : ID type ':' ID
        {
            if (strncmp($1, "par", 3) != 0 ) {
                YYABORT;
            }

            int current_num = atoi(&$1[3]);
            if (current_num <= last_param_number) {
                yyerror("Parameter numbers must be in strictly increasing order.");
                YYABORT;
            }

            last_param_number = current_num;
            $$ = mknode("parameter", mknode($1, $2, NULL), mknode($4, NULL, NULL));
        }
    ;

statement
    : declaration_statement                 { $$ = $1; }
    | assignment_statement                  { $$ = $1; }
    | if_statement                          { $$ = $1; }
    | while_statement                       { $$ = $1; }
    | for_statement                         { $$ = $1; }
    | do_statement                          { $$ = $1; }
    | ID '=' call_statement                 { $$ = $1; }
    | call_statement                        { $$ = $1; }
    | block_statement                       { $$ = $1; }
    ;


block_statement
    : BEGIN_TOKEN statements END            { $$ = mknode("block", $2, NULL); }
    ;

call_statement
    : ID LPAREN params RPAREN SEMICOLON     { $$ = mknode("call statement", mknode($1, NULL, NULL), $3); }
    ;

params
    : ID COMMA params                       { $$ = NULL; }
    | ID                                    { $$ = NULL; }
    | call_statement COMMA params           { $$ = NULL; }
    | call_statement                        { $$ = NULL; }
    |                                       { $$ = NULL; }
    ;

declaration_statement
    : TYPE type ':' ID SEMICOLON
        { $$ = mknode("declaration statement", mknode($2, NULL, NULL), mknode($4, NULL, NULL)); }
    | TYPE type ':' ID '=' expression SEMICOLON
        { $$ = mknode("declaration statement", mknode($2, NULL, NULL), mknode($4, $6, NULL)); }
    ;

type
    : BOOL                                  { $$ = mknode("bool", NULL, NULL); }
    | CHAR                                  { $$ = mknode("char", NULL, NULL); }
    | INT                                   { $$ = mknode("int", NULL, NULL); }
    | REAL                                  { $$ = mknode("real", NULL, NULL); }
    | INT_PTR                               { $$ = mknode("int_ptr", NULL, NULL); }
    | CHAR_PTR                              { $$ = mknode("char_ptr", NULL, NULL); }
    | REAL_PTR                              { $$ = mknode("real_ptr", NULL, NULL); }
    ;

bool_type
    : FALSE                                 { $$ = mknode("false", NULL, NULL); }
    | TRUE                                  { $$ = mknode("true", NULL, NULL); }
    ;

assignment_statement
    : ID '=' expression SEMICOLON                                       { $$ = mknode("assignment statement", mknode($1, NULL, NULL), $3); }
    | ID LBRACKET expression RBRACKET '=' CHAR_LITERAL SEMICOLON        { $$ = NULL; }
    | '*' ID '=' expression SEMICOLON                                   { $$ = NULL; }
    | ID '=' '&' ID                                                     { $$ = NULL; }
    ;

if_statement
    : IF LPAREN condition RPAREN BEGIN_TOKEN statements END
        { $$ = mknode("if statement", $3, $6); }
    | IF LPAREN condition RPAREN BEGIN_TOKEN statements END ELSE BEGIN_TOKEN statements END
        { $$ = NULL; }
    ;

while_statement
    : WHILE condition ':' variables BEGIN_TOKEN statements END
        { $$ = NULL; }

do_statement
    : DO ':' variables BEGIN_TOKEN statements END WHILE ':' condition SEMICOLON
        { $$ = mknode("do statement", mknode("while info", $3, $9), $5); }
    ;

for_statement
    : FOR for_header ':' statement                                  { $$ = mknode("for statement", $2, $4); }
    | FOR for_header ':' variables BEGIN_TOKEN statements END       { $$ = mknode("for statement", $2, $6); }
    ;

for_header
    : LPAREN ID '=' expression SEMICOLON condition SEMICOLON update_expression RPAREN
        { $$ = mknode("for header", mknode("init", mknode($2,NULL,NULL), $4), mknode("", $6, $8)); }
    ;

update_expression
    : ID '=' expression                         { $$ = mknode("update expression", mknode($1, NULL, NULL), $3); }
    ;
expression
    : expression '+' expression                 { $$ = NULL; }
    | expression '-' expression                 { $$ = NULL; }
    | expression '*' expression                 { $$ = NULL; }
    | expression '/' expression                 { $$ = NULL; }
    | expression '%' expression                 { $$ = NULL; }
    | INT_LITERAL                               { $$ = NULL; }
    | REAL_LITERAL                              { $$ = NULL; }
    | CHAR_LITERAL                              { $$ = NULL; }
    | STRING_LITERAL                            { $$ = NULL; }
    | ID                                        { $$ = NULL; }
    | '|' ID '|'                                { $$ = NULL; }
    ;

condition
    : expression comparison_operator expression         { $$ = NULL; }
    | NOT expression                                    { $$ = NULL; }
    | NOT bool_type                                     { $$ = NULL; }
    ;

comparison_operator
    : EQ                                        {}
    | NEQ                                       {}
    | GT                                        {}
    | GE                                        {}
    | LT                                        {}
    | LE                                        {}
    ;

return_statement
    : RETURN expression SEMICOLON
        {
            has_return = 1;
            $$ = NULL;
        }
    | RETURNS SEMICOLON
        {
            has_return = 1;
            $$ = NULL;
        }
    ;

%%

#include "lex.yy.c"

int main() {

    return yyparse();
}
void printtree(node *tree, int tabs)
{
    for (int i = 0; i < tabs; i++) {
        if (i == tabs - 1)
            printf("| ");
        else
            printf("|  ");
    }
    printf("%s\n", tree->token);

    if (tree->left)
        printtree(tree->left, tabs + 1);
    if (tree->right)
        printtree(tree->right, tabs + 1);
}


int yyerror(const char* s) {
    printf("Error: %s\n", s);
    return 1;
}

node *mknode(char *token,node *left,node *right)
{
    node *newnode = (node*)malloc(sizeof(node));
    char *newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr,token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return newnode;
}
