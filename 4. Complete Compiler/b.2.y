

%%



S1 : S  {printf("S1 : S\n"); }
    ;



S : 

      func_defn  S    {  printf("S : func_defn S\n");  }
    |  func_decl1    S       {  printf("S : func_decl1 S\n"); }
    |  stmt    S         {  printf("S : stmt S\n"); }
    | /* epsilon */       {  printf("S : epsilon\n"); }
    ;



func_decl1 : 

                func_decl semi      {   printf("func_decl1 : func_decl semi\n");  }
                ;



func_decl :

            datatype ID LP opt_arg_list rp         {  printf("func_decl : func_type ID LP opt_arg_list rp\n"); }
            | VOID ID LP opt_arg_list rp            {   printf("func_decl : VOID ID LP opt_arg_list rp\n"); }
            ;

            

opt_arg_list :

                arg_list        {  printf("opt_arg_list : arg_list\n"); }
                | /*        */  {  printf("opt_arg_list : epsilon\n"); }
                ;

                

arg_list :

            arg COMMA arg_list  {  printf("arg_list : arg COMMA arg_list\n"); }
            | arg               {  printf("arg_list : arg\n"); }
            ;

            

arg :               

    datatype id_array                 {  printf("arg : datatype id_array\n"); }
    ;



func_defn :

            func_decl BEGIN1 func_stmt end      {   printf("func_defn : func_decl BEGIN1 func_stmt end\n");    }
            ;

            

func_stmt :

            stmt func_stmt                      {   printf("func_stmt : stmt func_stmt\n");    }
            | RETURN rt semi                    {   printf("func_stmt : RETURN rt semi\n"); }
            | /*    */                          {   printf("func_stmt : epsilon\n");  }
            ;

            

rt :

     expr                                       {   printf("rt : expr\n");   }
    |   /*      */                              {   printf("rt : epsilon\n");   }
    ;





/* change semi not required */

stmt_list :                         

            stmt stmt_list          {  printf("stmt_list : stmt stmt_list\n"); }
            | stmt                  {  printf("stmt_list : stmt\n"); }
            ;





stmt :  

        id_array colon ASSIGN expr semi     {  printf("stmt : id_array COLON ASSIGN expr semi\n"); }
        |   IF expr then stmt opt_else      {  printf("stmt : IF expr then stmt opt_else\n"); }
        |   WHILE expr do stmt              {  printf("stmt : WHILE expr do stmt\n"); }
        |   BEGIN1  opt_stmt_list end       {  printf("stmt : BEGIN1  opt_stmt_list end\n"); }
        |   var_decl semi                   {  printf("stmt : var_decl semi\n"); }
        |   func_call semi                  {  printf("stmt : func_call semi\n"); }
        |   io semi                         {  printf("stmt : io semi\n"); }
        ;

        

then  : THEN            {   printf("then : THEN\n"); }
    | error              {  yyerror("then missing ");  }
    ;





opt_else : 

            else_stmt                       {  printf("opt_else : else_stmt\n"); }
            |   /* Just comment Epsilon production */ { printf("opt_else : epsilon\n"); }
            ;

            

else_stmt :

            ELSE stmt_list              {  printf("else_stmt : ELSE stmt_list\n"); }
            ;





expr : 

        expr1 rel           {  printf("expr : expr1 rel\n"); }
        | LP expr rp        {  printf("expr : LP expr rp\n"); }
        ;

        

rel :

        operator expr       {  printf("rel : operator expr\n"); }
        | /*    */          {  printf("rel : epsilon\n"); }
        ;



operator :

            LTE             {  printf("operator : LTE\n"); }
            |   GTE         {  printf("operator : GTE\n"); }
            |   EQU         {  printf("operator : EQU\n"); }
            |   GT          {  printf("operator : GT\n"); }
            |   LT          {  printf("operator : LT\n"); }
            ;



expr1 :

        expr2 add_sub       {  printf("expr1 : expr2 add_sub\n"); }
        ;



add_sub : 

        PLUS expr           {  printf("add_sub : PLUS expr\n"); }
        | MINUS expr        {  printf("add_sub : MINUS expr\n"); }
        | /*    */          {  printf("add_sub : epsilon\n");  }
        ;



expr2 : 

        expr3 mul_div       {  printf("expr2 : expr3 mul_div\n"); }
        ;

        

mul_div :   

        TIMES expr          {  printf("mul_div : TIMES expr\n"); }
        | DIV expr          {  printf("mul_div : DIV expr\n"); }
        | /*    */          {  printf("mul_div : epsilon\n"); }
        ;



expr3 : 

        NEGATION expr       {  printf("expr3 : NEGATION expr\n"); }
        |   term            {  printf("expr3 : term\n"); }
        ;

term :

        id_array            {  printf("term : id_array\n"); }
        |   NUM             {  printf("term : NUM\n"); }
        |   func_call       {   printf("term : func_call\n");   }
        |   CHARACTER       {   printf("term : CHARACTER\n"); }
        ;

        

opt_stmt_list : stmt_list           {  printf("opt_stmt_list : stmt_list\n"); }
                | /* epsilon */     {  printf("opt_stmt_list : epsilon\n"); }
                ;



var_decl : 

            datatype id_list        {  printf("var_decl : datatype id_list\n"); }
            ;



id_list : 

            id_array COMMA id_list        {  printf("id_list : id_array COMMA id_list \n"); }
            | id_array                    {  printf("id_list : id_array\n"); }
            ;

            



id_array : 

            ID                              {  printf("id_array : ID\n"); }
            | ID OSB DIMLIST CSB            {   printf("id_array : ID OSB DIMLIST CSB\n"); }
            ;

    

DIMLIST : 

            expr                             {   printf("DIMLIST : expr\n"); }
            | expr COMMA DIMLIST             {   printf("DIMLIST : expr COMMA DIMLIST\n"); }
            ;

    

datatype : 

            INT                     {  printf("datatype : INT\n"); }
            | BOOL                  {  printf("datatype : BOOL\n"); }
            | CHAR                  {  printf("datatype : CHAR\n"); }
            ;



func_call :

            ID LP opt_expr_list rp  {  printf("func_call : ID LP opt_expr_list rp\n"); }
            ;

            

opt_expr_list : expr_list           {  printf("opt_expr_list : expr_list\n"); }
                | /*    epsilon */  {  printf("opt_expr_list : epsilon\n"); }
                ;

                

expr_list : expr COMMA expr_list    {  printf("expr_list : expr COMMA expr_list\n"); }
            | expr                  {  printf("expr_list : expr\n"); }
            ;   



io : CIN gg ID                      {  printf("io : CIN gg ID\n"); }
    

    | COUT ll expr                  {   printf("io : COUT ll expr\n"); }
    ;



gg  : GG            {   printf("gg : GG\n"); }
    | error              {  yyerror("stream direction missing ");  }
    ;

    



ll  : LL            {   printf("ll : LL\n"); }
    | error              {  yyerror("stream direction missing ");  }
    ;



rp  : RP            {   printf("rp : RP\n"); }
    | error              {  yyerror("right parenthesis missing ");  }
    ;





colon :

        COLON           {  printf("colon : COLON\n");  }
        | error      {  yyerror("colon missing ");  }
        ;

semi :

        SEMI            {  printf("semi : SEMI\n");  }
        | error      {  yyerror("semicolon missing ");  }
        ;

end :

        END             {  printf("end : END\n");  }
        |   error       {  yyerror("end missing ");  }
        ;

        

do :

        DO             {  printf("do : DO\n");  }
        |   error       {  yyerror("do missing ");  }
        ;

   

        

/*

program:

        program expr '\n'         { printf("%d\n", $2); }

        | 

        ;



expr:

        INTEGER                   { $$ = $1; }

        | expr '+' expr           { $$ = $1 + $3; }

        | expr '-' expr           { $$ = $1 - $3; }

        ;

*/



%%
