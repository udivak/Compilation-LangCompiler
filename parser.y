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
void print_ast_graphical(node* tree, const char* prefix, int is_left);
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
%token <intVal> INT_LITERAL REAL_LITERAL
%token <stringVal> INT_PTR CHAR_PTR REAL_PTR ID STRING_LITERAL CHAR_LITERAL
%token <intVal> EQ NEQ GE LE GT LT

%token SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
%right NOT
%right '&'
%left OR
%left AND
%nonassoc EQ NEQ GE LE GT LT
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
            print_ast_graphical($1, "", 1);
            $$ = $1;
        }
    ;

functions
    : function
        { $$ = mknode("Functions", $1, NULL); }
    | function functions
        { $$ = mknode("Functions", $1, $2); }
    ;

function
    : DEF MAIN LPAREN RPAREN body_main
        {
            main_count++;
            if (main_count > 1) { yyerror("Error: multiple 'main' functions."); YYABORT; }
            $$ = mknode("Main Function",
                        mknode("main", NULL, NULL),
                        $5);
        }
    | DEF ID LPAREN parameters RPAREN RETURNS type variables body
        {
            if (!has_return) { yyerror("Error: non-main function must contain at least one return."); YYABORT; }
            has_return = 0;
            $$ = mknode("Function",
                        mknode($2, NULL, NULL),
                        mknode("FunctionBody",
                            mknode("Parameters", $4, NULL),
                            mknode("Body", mknode("Variables", $7, NULL), $8)
                        ));
        }
    | DEF ID LPAREN parameters RPAREN variables body_main
            {
                $$ = mknode("Function",
                            mknode($2, NULL, NULL),
                            mknode("BodyMain",
                                mknode("Variables", $6, NULL),
                                $7
                            ));
                $$ = $1;
            }
        ;


variables
    : VAR var_statements { $$ = $2; }
    | /* empty */        { $$ = NULL; }
    ;

var_statements
    : variable SEMICOLON var_statements
        { $$ = mknode("VarDecls", $1, $3); }
    | variable SEMICOLON
        { $$ = mknode("VarDecls", $1, NULL); }
    ;


variable
    : TYPE type ':' ids
        { $$ = mknode("VarDecl", $2, $4); }
    | TYPE STRING ':' string_ids
        { $$ = mknode("VarDecl", mknode("Type",mknode("string",NULL,NULL),NULL), $4); }
    | TYPE type '*' ':' ids
        { $$ = mknode("VarDecl", mknode("PointerType", $2, NULL), $5); }
    ;

string_ids
    : string_id ',' string_ids
        { $$ = mknode("StringList", $1, $3); }
    | string_id
        { $$ = mknode("StringList", $1, NULL); }
    ;


string_id
    : ID LBRACKET INT_LITERAL RBRACKET ':' STRING_LITERAL
        {
            node *name = mknode($1, NULL, NULL);
            char size_str[20];
            sprintf(size_str, "%d", $3);

            node *size = mknode("Size", mknode(size_str, NULL, NULL), NULL);
            node *val  = mknode("Value", mknode($6, NULL, NULL), NULL);
            $$ = mknode("String", name, mknode("Detail", size, val));
        }
    | ID LBRACKET INT_LITERAL RBRACKET
        {
            node *name = mknode($1, NULL, NULL);
            char size_str[20];
            sprintf(size_str, "%d", $3);
            node *size = mknode("Size", mknode(size_str, NULL, NULL), NULL);
            $$ = mknode("String", name, size);
        }
    ;


ids
    : id COMMA ids   { $$ = mknode("IdList", $1, $3); }
    | id             { $$ = mknode("IdList", $1, NULL); }
    ;


id
    : ID ':' expression
        { $$ = mknode($1, $3, NULL); }
    | ID
        { $$ = mknode($1, NULL, NULL); }
    ;

body
    : BEGIN_TOKEN statements return_statement END
        { $$ = mknode("Body", $2, $3); }
    ;


body_main
    : BEGIN_TOKEN statements END
        { $$ = mknode("BodyMain", $2, NULL); }
    ;

statements
    : statement statements
        {
            $$ = mknode("statements", $1, $2);
        }
    | /* empty */
        {
            $$ = NULL;
        }
    | function statements
        {
            $$ = mknode("statements", $1, $2);
        }
    ;

parameters
    : parameter COMMA parameters
        {
            $$ = mknode("parameters", $1, $3);
        }
    | parameter
        {
            $$ = mknode("parameters", $1, NULL);
        }
    | /* empty */
        {
            $$ = NULL;
        }
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
            $$ = mknode("parameter", mknode("param name", mknode($1,NULL,NULL), NULL), mknode("param type", mknode($2,NULL,NULL), NULL));
        }
    ;

statement
    : declaration_statement                 { $$ = $1; }
    | assignment_statement                  { $$ = $1; }
    | if_statement                          { $$ = $1; }
    | while_statement                       { $$ = $1; }
    | for_statement                         { $$ = $1; }
    | do_statement                          { $$ = $1; }
    | ID '=' CALL call_statement            { $$ = mknode("function assign", mknode($1, NULL, NULL), $4); }
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
    : ID COMMA params                       { $$ = mknode("params", mknode($1, NULL, NULL), $3); }
    | ID                                    { $$ = mknode("params", mknode($1, NULL, NULL), NULL); }
    | call_statement COMMA params           { $$ = mknode("params", $1, $3); }
    | call_statement                        { $$ = mknode("params", $1, NULL); }
    |                                       { $$ = mknode("params", NULL, NULL); }
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

assignment_statement
    : ID '=' expression SEMICOLON
        { $$ = mknode("Assign", mknode($1, NULL, NULL), $3); }
    | ID LBRACKET expression RBRACKET '=' CHAR_LITERAL SEMICOLON
        { $$ = mknode("ArrayAssign", mknode($1, $3, NULL), mknode($6, NULL, NULL)); }
    | '*' ID '=' expression SEMICOLON
        { $$ = mknode("PointerAssign", mknode($2, NULL, NULL), $4); }
    | ID '=' '&' ID SEMICOLON
        { $$ = mknode("RefAssign", mknode($1, NULL, NULL), mknode($4, NULL, NULL)); }
    | ID '=' NULL_T SEMICOLON
        { $$ = mknode("NullAssign", mknode($1, NULL, NULL), mknode("null", NULL, NULL)); }
    | ID LBRACKET expression RBRACKET '=' INT_LITERAL SEMICOLON
        {
            char int_str[20];  // Buffer for the integer to string conversion
            sprintf(int_str, "%d", $6);  // Convert integer to string
            $$ = mknode("ArrayAssign", mknode($1, $3, NULL), mknode(int_str, NULL, NULL));
        }
    ;


if_statement
    : IF LPAREN condition RPAREN BEGIN_TOKEN statements END
        { $$ = mknode("IfStmt", $3, $6); }
    | IF LPAREN condition RPAREN BEGIN_TOKEN statements END ELSE BEGIN_TOKEN statements END
        { $$ = mknode("IfElseStmt", $3, mknode("Branches", $6, $10)); }
    ;

while_statement
    : WHILE condition ':' variables BEGIN_TOKEN statements END
        { $$ = mknode("WhileStmt", $2, $6); }
    ;

do_statement
    : DO ':' variables BEGIN_TOKEN statements END WHILE ':' condition SEMICOLON
        { $$ = mknode("DoStmt", $5, $9); }
    ;

for_statement
    : FOR for_header ':' statement
        { $$ = mknode("ForStmt", $2, $4); }
    | FOR for_header ':' variables BEGIN_TOKEN statements END
        { $$ = mknode("ForStmt", $2, $6); }
    ;

for_header
    : LPAREN ID '=' expression SEMICOLON condition SEMICOLON update_expression RPAREN
        { $$ = mknode("ForHeader", mknode("Init", mknode($2, NULL, NULL), $4), mknode("Loop", $6, $8)); }
    ;

update_expression
    : ID '=' expression
        { $$ = mknode("Update", mknode($1, NULL, NULL), $3); }
    ;

expression
    : INT_LITERAL                           {
        char int_str[20];  // Buffer for the integer to string conversion
        sprintf(int_str, "%d", $1);  // Convert integer to string
        $$ = mknode(int_str, NULL, NULL);
    }
    | REAL_LITERAL                          {
        char real_str[40];  // Buffer for the float to string conversion
        sprintf(real_str, "%d", $1);  // Convert float to string
        $$ = mknode(real_str, NULL, NULL);
    }
    | CHAR_LITERAL                          {
        char char_str[2];  // Buffer for the char to string conversion
        sprintf(char_str, "%s", $1);  // Convert char to string
        $$ = mknode(char_str, NULL, NULL);
    }
    | STRING_LITERAL                        {
        $$ = mknode($1, NULL, NULL);  // STRING_LITERAL is already a string, so no conversion needed
    }
    | ID                                    {
        $$ = mknode($1, NULL, NULL);
    }
    | expression '+' expression             { $$ = mknode("+", $1, $3); }
    | expression '-' expression             { $$ = mknode("-", $1, $3); }
    | expression '*' expression             { $$ = mknode("*", $1, $3); }
    | expression '/' expression             { $$ = mknode("/", $1, $3); }
    | expression '%' expression             { $$ = mknode("%", $1, $3); }
    | '-' expression                        { $$ = mknode("neg", $2, NULL); }
    | '&' expression                        { $$ = mknode("ref", $2, NULL); }
    | ID LPAREN params RPAREN               { $$ = mknode("call_expr", mknode($1, NULL, NULL), $3); }
    ;



condition
    : expression comparison_operator expression
        { $$ = mknode($2, $1, $3); }
    | NOT condition
        { $$ = mknode("Not", $2, NULL); }
    | expression OR expression
        { $$ = mknode("Or", $1, $3); }
    | expression AND expression
        { $$ = mknode("And", $1, $3); }
    | LPAREN condition RPAREN
        { $$ = $2; }
    | bool_type
        { $$ = $1; }
    ;



bool_type
    : FALSE { $$ = mknode("false", NULL, NULL); }
    | TRUE  { $$ = mknode("true", NULL, NULL); }
    ;

comparison_operator
    : EQ  { $$ = mknode("==", NULL, NULL); }
    | NEQ { $$ = mknode("!=", NULL, NULL); }
    | GT  { $$ = mknode(">", NULL, NULL); }
    | GE  { $$ = mknode(">=", NULL, NULL); }
    | LT  { $$ = mknode("<", NULL, NULL); }
    | LE  { $$ = mknode("<=", NULL, NULL); }
    ;


return_statement
    : RETURN expression SEMICOLON
        { has_return = 1; $$ = mknode("Return", $2, NULL); }
    | RETURNS condition SEMICOLON
        { has_return = 1; $$ = mknode("Return", $2, NULL); }
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
void print_ast_graphical(node* tree, const char* prefix, int is_left) {
    if (!tree) return;

    // הדפסת הטוקן עם הסימנים הגרפיים
    printf("%s", prefix);
    printf(is_left ? "├── " : "└── ");
    printf("%s\n", tree->token);

    // בניית prefix חדש לילדים
    char new_prefix[1024];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");

    if (tree->left && tree->right) {
        print_ast_graphical(tree->left, new_prefix, 1);   // שמאל
        print_ast_graphical(tree->right, new_prefix, 0);  // ימין
    } else if (tree->left) {
        print_ast_graphical(tree->left, new_prefix, 0);
    } else if (tree->right) {
        print_ast_graphical(tree->right, new_prefix, 0);
    }
}



int yyerror(const char* s) {
    printf("Error: %s\n", s);
    printf("Line %d: %s\n", yylineno, yytext);
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
