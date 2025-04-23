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
void printtree(node *tree,int depth);
void print_ast_graphical(node* tree, const char* prefix, int is_left);
int is_number(const char* str);
void print_tree(node *n);
%}
%error-verbose

%union {
    int intVal;
    float realVal;
    char charVal;
    char* stringVal;
    node* node;
}
%token <intVal> AND OR NOT BOOL TRUE FALSE
%token <stringVal> DEF MAIN IF ELSE ELIF WHILE FOR DO VAR BEGIN_TOKEN CALL END RETURN RETURNS NULL_T
%token <stringVal> REAL STRING TYPE CHAR INT
%token <intVal> INT_LITERAL
%token <realVal> REAL_LITERAL
%token <stringVal> INT_PTR CHAR_PTR REAL_PTR ID STRING_LITERAL CHAR_LITERAL
%token <intVal> EQ NEQ GE LE GT LT

%token SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE COLON
%right NOT
%right '&'
%left OR
%left AND
%nonassoc EQ NEQ GE LE GT LT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE




%left '+' '-'
%left '*' '/' '%'

%type <node> code functions function
%type <node> body body_main statements statement
%type <node> expression condition boolean_expression
%type <node> variables var_statements variable
%type <node> string_ids string_id ids id
%type <node> parameters parameter
%type <node> return_statement bool_type
%type <node> declaration_statement assignment_statement call_statement params elif_statements
%type <node> if_statement while_statement do_statement for_statement for_header update_expression block_statement
%type <stringVal> type comparison_operator





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
    : DEF MAIN LPAREN RPAREN COLON variables body_main
        {
            main_count++;
            if (main_count > 1) {
                yyerror("Error: multiple 'main' functions.");
                YYABORT;
            }

            // Create the "Main Function" node
            $$ = mknode("Main Function",
                        mknode("main", NULL, NULL),
                        $7);

            // Add the variables to the binary tree (AST)
            if ($6) { // Check if there are variables
                // Loop through the list of variables and add them to the AST
                $$ = mknode("Main Function with Variables", $$, $6);
            }
        }

    | DEF ID LPAREN reset_param_counter parameters RPAREN COLON RETURNS type variables body
        {
            if (!has_return) {
                yyerror("Error: non-main function must contain at least one return.");
                YYABORT;
            }
            has_return = 0;

            node *params_node =$5;
            node *type_node = mknode("ReturnType", mknode($9, NULL, NULL), params_node);

            node *func_body;

            if ($10) {
                node *vars_node = mknode("Variables", $10, $11);
                func_body = mknode("FunctionBody", type_node, vars_node);
            } else {
                func_body = mknode("FunctionBody", type_node, $11);
            }

            $$ = mknode("Function", mknode($2, NULL, NULL), func_body);
        }




    | DEF ID LPAREN reset_param_counter parameters RPAREN COLON variables body_main
            {
                $$ = mknode("Function",
                            mknode($2, NULL, NULL),
                            mknode("BodyMain",
                                mknode("Variables", $8, NULL),
                                $9
                            ));
                //$$ = $1;
            }
        ;



reset_param_counter
    : /* empty */ { last_param_number = 0;}
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
    : TYPE type COLON ids
        { $$ = mknode("VarDecl", mknode($2,NULL,NULL), $4); }
    | TYPE STRING COLON string_ids
        { $$ = mknode("VarDecl", mknode("Type",mknode("string",NULL,NULL),NULL), $4); }
    | TYPE type '*' COLON ids
        { $$ = mknode("VarDecl", mknode("PointerType", mknode($2,NULL,NULL), NULL), $5); }
    ;

string_ids
    : string_id ',' string_ids
        { $$ = mknode("StringList", $1, $3); }
    | string_id
        { $$ = mknode("StringList", $1, NULL); }
    ;


string_id
    : ID LBRACKET INT_LITERAL RBRACKET COLON STRING_LITERAL
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
    : ID COLON expression
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
            $$ = mknode("function", $1, $2);
            last_param_number = 0;
        }
    ;

parameters
    : parameter SEMICOLON parameters
        {
            $$ = mknode("parameters", $1, $3);
        }
    | parameter
        {
            $$ = mknode("parameter", $1, NULL);
        }
    | /* empty */
        {
            $$ = NULL;
        }
    ;

parameter
    : ID type COLON ID
        {
            if (strncmp($1, "par", 3) != 0 ) {
                YYABORT;
            }
            int current_num = atoi(&$1[3]);
            if (current_num != last_param_number+1) {
                printf("Error: Parameter numbers must be in strictly increasing order.");
                YYABORT;
            }

            last_param_number = current_num;
            $$ = mknode("parameter", mknode("param name", mknode($1,NULL,NULL), NULL), mknode("param type", mknode($2,NULL,NULL), NULL));
        }
    ;

statement
    : block_statement                           { $$ = $1; }
    | declaration_statement                     { $$ = $1; }
    | assignment_statement                      { $$ = $1; }
    | if_statement                              { $$ = $1; }
    | while_statement                           { $$ = $1; }
    | for_statement                             { $$ = $1; }
    | do_statement                              { $$ = $1; }
    | ID '=' CALL call_statement                { $$ = mknode("function assign", mknode($1, NULL, NULL), $4); }
    | call_statement                            { $$ = $1; }
    ;

block_statement
    :  variables BEGIN_TOKEN statements END            { $$ = mknode("block", $1, $3); }
    ;


call_statement
    : ID LPAREN params RPAREN SEMICOLON     { $$ = mknode("call statement", mknode($1, NULL, NULL), $3); }
    ;

params
    : expression COMMA params      { $$ = mknode("params", $1, $3); }
    | expression                   { $$ = mknode("params", $1, NULL); }
    |                              { $$ = mknode("params", NULL, NULL); }
    ;


declaration_statement
    : TYPE type COLON ID SEMICOLON
        { $$ = mknode("declaration stat", mknode($2, NULL, NULL), mknode($4, NULL, NULL)); }
    | TYPE type COLON ID '=' expression SEMICOLON
        { $$ = mknode("declaration stat", mknode($2, NULL, NULL), mknode($4, $6, NULL)); }
    ;

type
    : BOOL                                  { $$ = "bool"; }
    | TRUE                                  { $$ = "TRUE"; }
    | FALSE                                 { $$ = "FALSE"; }
    | CHAR                                  { $$ = "char"; }
    | INT                                   { $$ = "int"; }
    | REAL                                  { $$ = "real"; }
    | INT_PTR                               { $$ = "int_ptr"; }
    | CHAR_PTR                              { $$ = "char_ptr"; }
    | REAL_PTR                              { $$ = "real_ptr"; }
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
    : IF condition COLON statement elif_statements ELSE statement
        {
            // if(condition) statement elif* else statement
            node *ifBranch = mknode("IfStmt", $2, $4);
            node *elifList = $5;
            node *elseBranch = mknode("ElseBranch", $7, NULL);
            node *branches = mknode("Branches", ifBranch, mknode("ElifList", elifList, elseBranch));
            $$ = mknode("IfElseStmt", NULL, branches);
        }
    | IF condition COLON statement elif_statements
        {
            // if(condition) statement elif*
            node *ifBranch = mknode("IfStmt", $2, $4);
            node *branches = mknode("Branches", ifBranch, $5);
            $$ = mknode("IfStmt", NULL, branches);
        }
    | IF condition COLON statement %%prec LOWER_THAN_ELSE
        {
            // if(condition) statement
            node *ifBranch = mknode("IfStmt", $2, $4);
            node *branches = mknode("Branches", ifBranch, NULL);
            $$ = mknode("IfStmt", NULL, branches);
        }
    ;

elif_statements
    : ELIF condition COLON statement elif_statements
        {
            // elif(condition) statement ... (with more elifs after)
            node *this_elif = mknode("ElifStmt", $2, $4);
            this_elif->right = $5;  // Chain the elifs
            $$ = this_elif;
        }
    | ELIF condition COLON statement
        {
            // Final elif(condition) statement
            $$ = mknode("ElifStmt", $2, $4);
        }
    ;



while_statement
    : WHILE condition COLON variables BEGIN_TOKEN statements END
        { $$ = mknode("WhileStmt", $2, $6); }
    ;

do_statement
    : DO COLON variables BEGIN_TOKEN statements END WHILE COLON condition SEMICOLON
        { $$ = mknode("DoStmt", $5, $9); }
    ;

for_statement
    : FOR for_header COLON statement
        { $$ = mknode("ForStmt", $2, $4); }
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
    | REAL_LITERAL {
        char real_str[40];
        sprintf(real_str, "%f", $1);
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
    | '-' expression {
        if ($2 && is_number($2->token)) {
            char *negated = malloc(strlen($2->token) + 2);
            sprintf(negated, "-%s", $2->token);
            $$ = mknode(negated, NULL, NULL);
        } else {
            $$ = mknode("neg", $2, NULL);
        }
    }
    | '&' expression {
        if ($2 && strcmp($2->token, "ref") == 0) {
            yyerror("Error: cannot take address of an address (e.g., &(&x))");
            $$ = NULL;
        } else {
            $$ = mknode("ref", $2, NULL);
        }
    }

    | ID LPAREN params RPAREN               { $$ = mknode("call_expr", mknode($1, NULL, NULL), $3); }
    | ID LBRACKET expression RBRACKET       { $$ = mknode("pointer_expr", mknode($1, NULL, NULL), $3); }
    | '*' LPAREN expression RPAREN          { $$ = $3; }
    | '|' expression '|'                    { $$ = $2; }
    ;



address_expression
    : '&' ID  { $$ = mknode("ref", mknode($2, NULL, NULL), NULL); }
    ;



condition
    : expression comparison_operator expression
        { $$ = mknode($2, $1, $3); }
    | NOT condition
        { $$ = mknode("Not", $2, NULL); }
    | boolean_expression
        { $$ = $1; }
    | bool_type
        { $$ = $1; }
    ;


boolean_expression
    : expression AND expression         { $$ = mknode("And", $1, $3); }
    | expression OR expression          { $$ = mknode("Or", $1, $3); }
    ;


bool_type
    : FALSE                     { $$ = mknode("false", NULL, NULL); }
    | TRUE                      { $$ = mknode("true", NULL, NULL); }
    | LPAREN FALSE RPAREN       { $$ = mknode("false", NULL,NULL); }
    | LPAREN TRUE RPAREN       { $$ = mknode("true", NULL,NULL); }
    ;

comparison_operator
    : EQ  { $$ = "=="; }
    | NEQ { $$ = "!="; }
    | GT  { $$ =  ">"; }
    | GE  { $$ = ">="; }
    | LT  { $$ = "<"; }
    | LE  { $$ = "<="; }
    ;


return_statement
    : RETURN expression SEMICOLON
        { has_return = 1; $$ = mknode("Return", $2, NULL); }
    | RETURN condition SEMICOLON
        {
            last_param_number = 0;
            has_return = 1; $$ = mknode("Return", $2, NULL); }
    ;


%%

#include "lex.yy.c"

int main() {

    return yyparse();
}
void print_tree(node *n) {
    if (!n) {
        printf("NONE");
        return;
    }

    printf("(");
    printf("%s", n->token);

    if (n->left || n->right) {
        printf(" ");
        if (n->left) {
            print_tree(n->left);
        } else {
            printf("NONE");
        }

        if (n->right) {
            printf(" ");
            print_tree(n->right);
        }
    }

    printf(")");
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
void printtree(node *tree, int depth)
{
    if (!tree) return;

    // הדפסת הזחה לפי עומק
    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }

    // הדפסת הטוקן של הצומת
    printf("%s\n", tree->token);

    // קריאה רקורסיבית לילדים
    if (tree->left)
        printtree(tree->left, depth + 1);
    if (tree->right)
        printtree(tree->right, depth);
}





int yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
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

int is_number(const char* str) {
    if (!str) return 0;
    return isdigit(str[0]) || str[0] == '.' || str[0] == '-';
}

