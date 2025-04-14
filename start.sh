lex lex.l
bison -d -v parser.y
cc -o compiler parser.tab.c -ll -ly
./compiler < test.txt



# printtree($1,0);