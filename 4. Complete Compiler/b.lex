%{
    #include <stdlib.h>
    #include<string.h>
    #include<string>
    #include<vector>
    #include<iostream>
    using namespace std;
    void yyerror(char *);
    int lineno=1;
    struct varParListEntry
    {
        string type;
        string eleType;
        string name;
        int scope=0;
        vector<int> dimList;
        int offset;
    };
    struct allAttributes
   {
        string name;
        string type;            //simple or array or func
        string eleType;         //int or bool or char or void
        int val;
        int scope;
        vector <int> dimList;       //for DIMLIST
        vector <string> listOfVar;          //for id_list
        vector< struct varParListEntry> parList;
        int alreadyDefined;
        int offset;
        vector< string> code;
        
    };
    
    #include "y.tab.h"
%}

alpha		[a-zA-Z]
ID       [a-zA-Z_][a-zA-Z0-9]*
DIGIT    [0-9]
NUM     [0-9]+
type    "int"|"char"|"bool"
character "'"."'"

%%
 
"!"    { return NEGATION; }
"+"        { return PLUS; }
"-"   { return MINUS; }
"*"    { return TIMES; }
"/"  { return DIV; }
"<="    { return LTE; }
">="   { return GTE; }
"<"     { return LT; }
">"     { return GT; }
"=="   { return EQU; }
 
"="     { return ASSIGN; }
 
";"     { return SEMI; }
":"    { return COLON; }
","      { return COMMA; }
"("       { return LP; }
")"      { return RP; }
 
{DIGIT}+ { yylval.node1 = new struct allAttributes; yylval.node1->val = stoi( string(yytext) );  return NUM; } 
 
"if"        { return IF; }
"then"      { return THEN; }
"else"      { return ELSE; }
"while"    { return WHILE; }
"do"     { return DO; }
"{"   { return BEGIN1; }
"}"    { return END; }
 
"int"   { return INT; }
"char"  { return CHAR; }
"bool"  { return BOOL; }
"void"  { return VOID; }
 
"true"  { return TRUE; }
"false" { return FALSE; }
 
{character} { yylval.node1 = new struct allAttributes; int val = yytext[1]; yylval.node1->val = val; return CHARACTER; }   
 
"["     { return OSB; }   
"]"     { return CSB; }
 
"return" { return RETURN;}
 
"cin"   { return CIN; }
"cout"  { return COUT; }
 {ID}    {  yylval.node1 = new struct allAttributes;  yylval.node1->name = string(yytext); return ID; }
"<<"    { return LL; }
">>"    { return GG; }
[ \t] ;
"\n"    lineno++;
.   { printf("ERROR TOKEN %s",yytext); yyerror("invalid character"); }
%%
 
int yywrap(void)
{
    return 1;
}
