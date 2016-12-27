%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <string>
    #include <iostream>
    #include <vector>
    
    int yylex(void);
    extern int lineno;
    void yyerror(char *);
    using namespace std;
    
    struct varParListEntry
    {
        string type;
        string eleType;
        string name;
        int scope=0;
        vector<int> dimList;
        int offset;
    };
    
    //struct change karne par lex me bhi karna hai
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
        
    } tempValues;
    //initial stack pointer
    int currentScope, loadAddr, targetCount=0, spInitial = 2147479548, currentOffset, mainOffset;
    FILE *fp;
    //print symbol table
    FILE *fp2;
    
    struct globalTableEntry
    {
        string name;
        string type;
        string eleType;
        int scope=0;
        vector <struct varParListEntry> parList;
        vector <struct varParListEntry> varList;
        vector <int> dimList;
        int alreadyDefined;
        int offset;
    } *activeFuncPtr, *callFuncPtr;
    
   
    vector<globalTableEntry> symTab;
    //traverse in varList then parList then globalTableEntry
    void findEntry(struct allAttributes *, int *, struct varParListEntry *);
    
    
    void insertSymTab(struct allAttributes *);
    
    
    void compatibleArithOp(struct allAttributes *, struct allAttributes *, int *);
    
    void patch(vector <string> &, string);

    bool coercible(string, string);

    //insert func in symbol table
    void insertFunc(struct allAttributes *);
    
    //search function
    struct globalTableEntry *searchFunc(struct allAttributes *, int *);

%}

%start S1


%union 
{
    struct allAttributes *node1;

};

%token < node1> NUM
%token < node1> CHARACTER
%token < node1> ID


%token NEGATION
%token PLUS
%token MINUS
%token TIMES
%token DIV

%token LTE
%token GTE
%token LT
%token GT 
%token EQU

%token ASSIGN
%token SEMI
%token COMMA
%token COLON
%token LP  
%token RP


%token IF   
%token THEN
%token ELSE
%token WHILE
%token DO
%token BEGIN1
%token END

%token INT
%token BOOL
%token CHAR
%token VOID

%token TRUE
%token FALSE


%token CIN
%token COUT
%token LL
%token GG

%token CSB 
%token OSB
%token RETURN


%type <node1> DIMLIST func_decl func_decl1 func_defn S1 S stmt_list var_decl opt_else else_stmt opt_stmt_list func_stmt rt
%type < node1> id_array id_list expr expr1 datatype expr2 expr3 rel add_sub mul_div operator term opt_arg_list arg_list arg func_call opt_expr_list expr_list stmt


%%



S1 : S {    
            
            for(int i=0; i<$1->code.size(); i++)
                fprintf(fp,  "%s\n", $1->code[i].c_str() );
            printf("S! : S\n");}
    ;



S : 

      func_defn  S    {
                        $$ =new struct allAttributes;
                        $$->code = $1->code; 
                        $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end() ); 
                        printf("S : func_defn S\n");
                        }
    |  func_decl1    S       { $$ =new struct allAttributes; $$->code = $2->code; printf("S : func_decl1 S\n"); }
    |  stmt    S         {  
                            $$ =new struct allAttributes;
                            $$->code.insert($$->code.end(), $1->code.begin(), $1->code.end() );
                            $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end() ); 
                            
                            printf("S : stmt S\n"); 
                               
    }
    | /* epsilon */       { $$=new struct allAttributes; printf("S : epsilon\n"); }
    ;



func_decl1 : 

                func_decl semi      {
                                        cout << "in func_decl1";
                                        int found;
                                        struct globalTableEntry *rec1;
                                        rec1 = searchFunc($1, &found);
                                        
                                        if(found)
                                        {
                                            yyerror("function already declared or defined");
                                        }
                                        else
                                        {
                                            $1->alreadyDefined=0;
                                            insertFunc($1);
                                        }
                                        printf("func_decl1 : func_decl semi\n");
                                    }
                ;


func_decl :

            datatype ID LP opt_arg_list rp          {  
                                                        $$ = new struct allAttributes;
                                                        $$->type="function";
                                                        $$->eleType = $1->eleType;      //return type of function
                                                        $$->name = $2->name;
                                                        //listOfVar contains eleType of the variable
                                                        $$->parList = $4->parList;
                                                    
                                                        
                                                        printf("func_decl : func_type ID LP opt_arg_list rp\n"); 
                                                    }
            
            | VOID ID LP opt_arg_list rp            { 
                                                        $$ = new struct allAttributes;
                                                        $$->type="function";
                                                        $$->eleType = "void";
                                                        $$->name = $2->name;
                                                        $$->parList = $4->parList;
                                                        
                                                        printf("func_decl : VOID ID LP opt_arg_list rp\n"); }
            ;

            

opt_arg_list :

                arg_list        { 
                                    $$ = new struct allAttributes;
                                    $$->parList = $1->parList;
                                    
                                    printf("opt_arg_list : arg_list\n"); 
                                }
                | /*        */  {   $$= new struct allAttributes;    printf("opt_arg_list : epsilon\n"); }
                ;

                

arg_list :

            arg COMMA arg_list  {   
                                    $$ = new struct allAttributes; 
                                    $$->parList = $3->parList;
                                    struct varParListEntry temp; 
                                    temp.name = $1->name;
                                    temp.eleType=$1->eleType;
                                    temp.type = "simple";
                                    temp.scope = 1;
                                    $$->parList.push_back(temp);   
                                    printf("arg_list : arg COMMA arg_list\n"); 
                
                                }
            | arg               {  
                                    $$ = new struct allAttributes; 
                                    struct varParListEntry temp; 
                                    temp.name = $1->name; 
                                    temp.eleType=$1->eleType;
                                    temp.scope =1; 
                                    temp.type = "simple";
                                    $$->parList.push_back(temp);  
                                    printf("arg_list : arg\n");
                
                                }
            ;

            

arg :               

    datatype ID                 {    $$ = new struct allAttributes; 
                                     $$->type = "simple";
                                     $$->scope = 1;
                                     $$->eleType=$1->eleType;
                                     $$->name = $2->name;
                                     printf("arg : datatype ID\n");
                                }
    ;



func_defn :

            func_decl BEGIN1 
            {
                int found;   
                struct globalTableEntry *rec;
                
                rec = searchFunc($1,&found);
                
                
                if(found && rec->alreadyDefined!=1)
                {
                    if($1->parList.size() == rec->parList.size())
                    {
                        int i; 
                        for(i=0;i<$1->parList.size();i++)
                        {
                            if($1->parList[i].eleType != rec->parList[i].eleType)
                            {
                                yyerror("argument type mismatch");
                                rec->eleType = "error";
                                activeFuncPtr = rec;
                                break;
                            }
                        }
                        if(i == $1->parList.size())
                        {
                            activeFuncPtr= rec;
                            
                            rec->alreadyDefined=1;
                            currentScope=2;
                            for(int i=0;i<$1->parList.size();i++)
                            {
                                //we need to check that the param is not already declared
                                int k;
                                for(k=0; k<i; k++)
                                {
                                    if(rec->parList[k].name==$1->parList[i].name)
                                    {
                                        activeFuncPtr = rec;
                                        activeFuncPtr->eleType = "error";
                                        yyerror("parameters already declared");
                                        break;
                                    }
                                }
                                if(k!=i)
                                    break;
                                rec->parList[i].name = $1->parList[i].name;
                            
                            }
                            if(activeFuncPtr->eleType!="error")
                            {
                                for(int i=0; i<activeFuncPtr->parList.size(); i++)
                                {
                                    activeFuncPtr->parList[i].offset = (-1)*(activeFuncPtr->parList.size()-i)*4;
                                }
                            }
                        }
                        
                    }
                    else
                    {
                        activeFuncPtr = rec;
                        activeFuncPtr->eleType = "error";
                        yyerror("number of arguments mismatch");
                    }
                }
                else if( rec==NULL )
                {
                    $1->alreadyDefined = 1;
                    
                    insertFunc($1);
                    activeFuncPtr = &symTab.back();
                    for(int i=0; i<activeFuncPtr->parList.size(); i++)
                    {
                        activeFuncPtr->parList[i].offset = (-1)*(activeFuncPtr->parList.size()-i)*4;
                    }
                    currentScope =2;
                }
                else
                {
                    activeFuncPtr = rec;
                    activeFuncPtr->eleType = "error";
                    yyerror("function already defined");
                }
                mainOffset = currentOffset;
                currentOffset = 4;
            } 
            func_stmt end   {   
                                if(activeFuncPtr->eleType!="error")
                                {
                                    // main ka offset back up and restyore 
                                    
                                    
                                    
                                    
                                    $$= new struct allAttributes;
                                    $$->code.push_back("j "+activeFuncPtr->name + "_end");
                                    $$->code.push_back(activeFuncPtr->name+":");
                                    
                                    
                                    $$->code.push_back("move $fp $sp");
                                    $$->code.push_back("sw $ra 0($sp)");
                                    $$->code.push_back("addi $sp, $sp -4");
                                    
                                    
                                    
                                    
                                    $$->code.insert($$->code.end(), $4->code.begin(), $4->code.end());
                                    
                                    $$->code.push_back(activeFuncPtr->name+"_return:");                     // label to return in between
                                    $$->code.push_back("addi $sp, $fp, -4");
                                    
                                    $$->code.push_back("lw $ra 4($sp)");
                                    int z= 4*(activeFuncPtr->parList.size()) +8;
                                    $$->code.push_back("addi $sp $sp "+to_string(z));
                                    $$->code.push_back("lw $fp 0($sp)");
                                    $$->code.push_back("jr $ra");
                                    
                                    
                                                                                                            // retiurn value wiil be in accumilator
                                    $$->code.push_back(activeFuncPtr->name+"_end:");
                                    
                                    currentScope = 0;
                                    currentOffset = mainOffset;
                                    
                                    
                                    activeFuncPtr->varList.clear();
                                    activeFuncPtr =NULL;
                                }
                                else
                                {
                                    activeFuncPtr->varList.clear();
                                    activeFuncPtr =NULL;
                                    currentScope = 0;
                                    yyerror("errortype function");
                                }
                                printf("func_defn : func_decl BEGIN1 func_stmt end\n");
                            }
            ;

            

func_stmt :
            
            stmt func_stmt                      {   $$= new struct allAttributes;  $$->code = $1->code; $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());  printf("func_stmt : stmt func_stmt\n");    }
            | RETURN rt semi                    {   $$= new struct allAttributes;  $$->code = $2->code; $$->code.push_back("j "+activeFuncPtr->name+"_return"); printf("func_stmt : RETURN rt semi\n"); }
            | /*    */                          {   $$= new struct allAttributes;   printf("func_stmt : epsilon\n");  }
            ;

            

rt :

     expr                                       {  $$= new struct allAttributes;  $$->code = $1->code;   printf("rt : expr\n");   }
    |   /*      */                              {   $$= new struct allAttributes;   printf("rt : epsilon\n");   }
    ;





/* change semi not required */
//copy byte at source RAM location to low-order byte of destination register,
//and sign-e.g.tend to higher-order byte
stmt_list :                         

            stmt stmt_list          {  $$ = new struct allAttributes;
                                        $$->code.insert($$->code.end(),$1->code.begin(), $1->code.end() );
                                        $$->code.insert($$->code.end(),$2->code.begin(), $2->code.end() );
                                        printf("stmt_list : stmt stmt_list\n"); }
            | stmt                  {  
                                        $$ = new struct allAttributes;
                                        $$->code.insert($$->code.end(), $1->code.begin(), $1->code.end() );
                                        printf("stmt_list : stmt\n"); }
            ;





stmt :  
        id_array colon ASSIGN expr semi     {
                                                //cout<<"\n\nid scope"<<$1->scope<<endl;
                                                $$ = new struct allAttributes;
                                                struct varParListEntry *rec = new struct varParListEntry;
                                                int success;
                                                //cout << $1->name << " " << $4->name;
                                                findEntry($1, &success, rec);
                                                //cout<<"\n\nfind id scope"<<rec->scope<<endl;
                                                
                                                if(!success)
                                                {
                                                    yyerror("lhs not declared before use");
                                                }
                                                else
                                                {
                                                    if( $1->type == "array" && $1->eleType != "error" && $4->eleType !="error" )
                                                    {
                                                        //cout<<"type: array ";
                                                        if( (rec->dimList).size() == $1->dimList.size() )
                                                        {
                                                            int i;
                                                            //cout << " dim match dimlist size " <<rec.dimList.size();
                                                            for( i=0; i< rec->dimList.size(); i++)
                                                            {
                                                                //cout<<i<<"th dimension "<<rec.dimList[i]<<" "<<$1->dimList[i]<<"  ";
                                                                if( rec->dimList[i] <= $1->dimList[i] )
                                                                {
                                                                    yyerror("array out of bound");
                                                                    $$->eleType = string("error");
                                                                    
                                                                    $1->eleType = string("error");
                                                                    
                                                                    break;
                                                                }
                                                            }
                                                            if( i == rec->dimList.size() )
                                                            {
                                                                if(coercible(rec->eleType, $4->eleType))
                                                                {
                                                                    if($1->eleType == "bool")
                                                                    {
                                                                        if($4->val > 0)
                                                                            $1->val = 1;
                                                                        else
                                                                            $1->val = 0;
                                                                    }    
                                                                    else
                                                                        $1->val = $4->val;
                                                                    
                                                                    /*  code gen for array    */
                                                                    int dim = 0;
                                                                    int lastDim=1;
                                                                    for(int i=$1->dimList.size()-1; i>=0; i-- )
                                                                    {
                                                                        dim += ($1->dimList[i])*lastDim;
                                                                        lastDim *= rec->dimList[i];
                                                                    }
                                                                    $$->code.insert( $$->code.end(), $4->code.begin(), $4->code.end() );
                                                                    if(activeFuncPtr==NULL)
                                                                    {
                                                                        $$->code.push_back("move $t0, $fp");
                                                                        $$->code.push_back("addi $t0, $t0, " + to_string(-1*( rec->offset+dim*4) ));
                                                                        $$->code.push_back("sw $a0, ($t0)");
                                                                        
                                                                    }
                                                                    else
                                                                    {
                                                                        $$->code.push_back("move $t0, $fp");
                                                                        $$->code.push_back("addi $t0, $t0, " + to_string(-1*(rec->offset+dim*4)) );
                                                                        $$->code.push_back("sw $a0, ($t0)");
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    yyerror("Incompatible assignment");
                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                            yyerror("Dimensions of array mismatch");
                                                        }
                                                    }
                                                    else if($1->type == "simple" && $1->eleType != "error" && $4->eleType !="error")
                                                    {
                                                        //cout << "rec " << $1->eleType << " " << $4->eleType;
                                                        if( coercible(rec->eleType, $4->eleType) )
                                                        {
                                                            if($1->eleType == "bool")
                                                            {
                                                                if($4->val > 0)
                                                                    $1->val = 1;
                                                                else
                                                                    $1->val = 0;
                                                            }    
                                                            else
                                                                $1->val = $4->val;
                                                            /* code gen */
                                                            
                                                            $$->code.insert( $$->code.end(), $4->code.begin(), $4->code.end() );
                                                            if(activeFuncPtr == NULL)
                                                            {
                                                                $$->code.push_back("move $t0, $fp");
                                                                //$$->code.push_back("li $t0, "+to_string(spInitial) );
                                                                $$->code.push_back("addi $t0, $t0, "+ to_string((-1*rec->offset) ) );
                                                                $$->code.push_back("sw $a0, ($t0)");
                                                            }
                                                            else
                                                            {
                                                                if(rec->scope==0)
                                                                {
                                                                    $$->code.push_back("li $t0, "+to_string(spInitial) );
                                                                }
                                                                else
                                                                {
                                                                    $$->code.push_back("move $t0, $fp");
                                                                }
                                                                
                                                                $$->code.push_back("addi $t0, $t0, "+ to_string(-1*rec->offset) );
                                                                $$->code.push_back("sw $a0, ($t0)");
                                                            }
                                                                
                                                                
                                                            //cout<<"value of  "<<$1->name<<" : "<<$1->val;
                                                        }
                                                        else
                                                            yyerror("Incompatible assignment");
                                                    }
                                                }
                                                
                                                
                                                printf("stmt : id_array COLON ASSIGN expr semi\n"); 
                                            }
        |   IF expr then stmt opt_else      {   
                                                $$ = new struct allAttributes;
                                                $$->code = $2->code;
                                                $$->code.push_back("li $t0, 0");
                                                $$->code.push_back("beq $a0, $t0, target" + to_string(targetCount) );
                                                
                                                
                                                
                                                $$->code.insert($$->code.end(), $4->code.begin(), $4->code.end());
                                                
                                                $$->code.push_back("b target" + to_string(targetCount+1));

                                                $$->code.push_back("target" +to_string(targetCount)+":" );
                                                
                                                $$->code.insert($$->code.end(), $5->code.begin(), $5->code.end());
                                                
                                                $$->code.push_back("target" + to_string(targetCount+1) + ":" );
                                                
                                                targetCount+=2;
                                                printf("stmt : IF expr then stmt opt_else\n"); 
                                            }
        |   WHILE expr do stmt              {
                                                $$ = new struct allAttributes;
                                                
                                                $$->code.push_back("target" + to_string(targetCount) + ":");
                                                
                                                
                                                $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                                $$->code.push_back("li $t0 , 0");
                                                $$->code.push_back("beq $t0, $a0, target" + to_string(targetCount+1) );
                                                
                                                
                                                $$->code.insert($$->code.end(), $4->code.begin(), $4->code.end());
                                                $$->code.push_back("b target" + to_string(targetCount) );
                                                $$->code.push_back("target" + to_string(targetCount+1) + ":");
                                                targetCount+=2;
                                                printf("stmt : WHILE expr do stmt\n"); 
            
                                            }
        |   BEGIN1 { currentScope++; } opt_stmt_list end    { currentScope--;    $$ = new struct allAttributes; $$->code = $3->code;  printf("stmt : BEGIN1  opt_stmt_list end\n"); }
        |   var_decl semi                   {  $$=new struct allAttributes; $$->code =$1->code; printf("stmt : var_decl semi\n"); }
        |   func_call semi                  {  
                                                $$ = new struct allAttributes;
                                                 $$ = $1;
                                                 printf("stmt : func_call semi\n");
                                            }
        |   io semi                         {  printf("stmt : io semi\n"); }
        
         ;

        

then  : THEN            {   printf("then : THEN\n"); }
    | error              {  yyerror("then missing ");  }
    ;






opt_else : 

            else_stmt                       { $$ = new struct allAttributes; $$->code =$1->code; printf("opt_else : else_stmt\n"); }
            |   /* Just comment Epsilon production */ {  $$ = new struct allAttributes; printf("opt_else : epsilon\n"); }
            ;

            

else_stmt :

            ELSE stmt              {   $$ = new struct allAttributes;   $$->code = $2->code;    printf("else_stmt : ELSE stmt\n"); }
            ;





expr : 
        expr1 rel           {  
                                int success;
                                if($2->type == "epsilon")
                                {
                                    $$ = new struct allAttributes;
                                    $$->type = $1->type;
                                    $$->eleType = $1->eleType;
                                    $$->val = $1->val;
                                    $$->code = $1->code;
                                }
                                else
                                {
                                    compatibleArithOp($1, $2, &success);
                                    $$ = new struct allAttributes;
                                    if(success)
                                    {
                                        
                                        $$->eleType=string("bool");
                                        if($2->type=="<=")
                                        {
                                            $$->val = ($1->val <= $2->val);
                                            $$->code = $1->code;
                                            $$->code.push_back("sw $a0, ($sp)");
                                            $$->code.push_back("addi $sp, $sp, -4");
                                            
                                            $$->code.insert( $$->code.end(), $2->code.begin(), $2->code.end() );
                                            $$->code.push_back("lw $t0, 4($sp)");
                                            $$->code.push_back("addi $sp, $sp, 4");
                                            $$->code.push_back("ble $t0, $a0, target" + to_string(targetCount));    // $t0 <= $a0
                                            $$->code.push_back("li $a0, 0");
                                            $$->code.push_back("b target" + to_string(targetCount+1));
                                            $$->code.push_back("target" + to_string(targetCount) + ":" );
                                            $$->code.push_back("li $a0, 1");
                                            $$->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                            //$$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if($2->type==">=")
                                        {    
                                            
                                            $$->val = ($1->val >= $2->val);
                                            $$->code = $1->code;
                                            $$->code.push_back("sw $a0, ($sp)");
                                            $$->code.push_back("addi $sp, $sp, -4");
                                            
                                            $$->code.insert( $$->code.end(), $2->code.begin(), $2->code.end() );
                                            $$->code.push_back("lw $t0, 4($sp)");
                                            $$->code.push_back("addi $sp, $sp, 4");
                                            $$->code.push_back("bge $t0, $a0, target" + to_string(targetCount));    // $t0 >= $a0
                                            $$->code.push_back("li $a0, 0");
                                            $$->code.push_back("b target" + to_string(targetCount+1));
                                            $$->code.push_back("target" + to_string(targetCount) + ":" );
                                            $$->code.push_back("li $a0, 1");
                                            $$->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                            //$$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if($2->type=="==")
                                        {
                                            $$->val = ($1->val == $2->val);
                                            $$->code = $1->code;
                                            $$->code.push_back("sw $a0, ($sp)");
                                            $$->code.push_back("addi $sp, $sp, -4");
                                            
                                            $$->code.insert( $$->code.end(), $2->code.begin(), $2->code.end() );
                                            $$->code.push_back("lw $t0, 4($sp)");
                                            $$->code.push_back("addi $sp, $sp, 4");
                                            $$->code.push_back("beq $t0, $a0, target" + to_string(targetCount));    // $t0 <= $a0
                                            $$->code.push_back("li $a0, 0");
                                            $$->code.push_back("b target" + to_string(targetCount+1));
                                            $$->code.push_back("target" + to_string(targetCount) + ":" );
                                            $$->code.push_back("li $a0, 1");
                                            $$->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                            //$$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if($2->type=="<")
                                        {
                                            $$->val = ($1->val < $2->val);
                                            $$->code = $1->code;
                                            $$->code.push_back("sw $a0, ($sp)");
                                            $$->code.push_back("addi $sp, $sp, -4");
                                            
                                            $$->code.insert( $$->code.end(), $2->code.begin(), $2->code.end() );
                                            $$->code.push_back("lw $t0, 4($sp)");
                                            $$->code.push_back("addi $sp, $sp, 4");
                                            $$->code.push_back("blt $t0, $a0, target" + to_string(targetCount));    // $t0 <= $a0
                                            $$->code.push_back("li $a0, 0");
                                            $$->code.push_back("b target" + to_string(targetCount+1));
                                            $$->code.push_back("target" + to_string(targetCount) + ":" );
                                            $$->code.push_back("li $a0, 1");
                                            $$->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                           // $$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if($2->type==">")
                                        {
                                            $$->val = ($1->val > $2->val);
                                            $$->code = $1->code;
                                            $$->code.push_back("sw $a0, ($sp)");
                                            $$->code.push_back("addi $sp, $sp, -4");
                                            
                                            $$->code.insert( $$->code.end(), $2->code.begin(), $2->code.end() );
                                            $$->code.push_back("lw $t0, 4($sp)");
                                            $$->code.push_back("addi $sp, $sp, 4");
                                            $$->code.push_back("bgt $t0, $a0, target" + to_string(targetCount));    // $t0 <= $a0
                                            $$->code.push_back("li $a0, 0");
                                            $$->code.push_back("b target" + to_string(targetCount+1));
                                            $$->code.push_back("target" + to_string(targetCount) + ":" );
                                            $$->code.push_back("li $a0, 1");
                                            $$->code.push_back("target"+to_string(targetCount+1) + ":" );        
                                            
                                            targetCount+=2;
                                            //$$->code.push_back("addi $sp, $sp, 4");
                                        }
                                    }
                                    else
                                    {
                                        $$->eleType = string("error");
                                        yyerror("incompatible operands");
                                    }
                                }
        
                                printf("expr : expr1 rel\n"); }
        | LP expr rp        {
                                $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                printf("expr : LP expr rp\n"); 
            
                            }
        ;

        

rel :

        operator expr       { 
                                $$ = new struct allAttributes;
                                $$->eleType = $2->eleType;
                                $$->type = $1->type;              // operator itself; "<="
                                $$->code = $2->code;
                                printf("rel : operator expr\n"); 
            
                            }
        | /*    */          {
                                $$ = new struct allAttributes;
                                $$->type = string("epsilon");
                                printf("rel : epsilon\n"); 
                    
                            }
        ;



operator :

            LTE             { $$ = new struct allAttributes; $$->type = string("<="); printf("operator : LTE\n"); }
            |   GTE         { $$ = new struct allAttributes; $$->type = string(">="); printf("operator : GTE\n"); }
            |   EQU         { $$ = new struct allAttributes; $$->type = string("=="); printf("operator : EQU\n"); }
            |   GT          { $$ = new struct allAttributes; $$->type = string(">"); printf("operator : GT\n"); }
            |   LT          { $$ = new struct allAttributes; $$->type = string("<"); printf("operator : LT\n"); }
            ;



expr1 :

        expr2 add_sub       {  
        
                                int success;
                                if($2->type=="epsilon")
                                {
                                    $$ = new struct allAttributes;
                                    $$->type = $1->type;
                                    $$->eleType = $1->eleType;
                                    $$->val = $1->val;
                                    $$->code = $1->code;
                                }
                                else
                                {
                                    compatibleArithOp($1, $2, &success);
                                    $$ = new struct allAttributes;
                                    if(success)
                                    {
                                        $$->eleType=string("int");
                                        if($2->type=="+")
                                        {
                                            $$->val = ($1->val + $2->val);
                                            $$->code = $1->code;
                                            $$->code.push_back("sw $a0, ($sp)");
                                            $$->code.push_back("addi $sp, $sp, -4");
                                            
                                            $$->code.insert( $$->code.end(), $2->code.begin(), $2->code.end() );
                                            $$->code.push_back("lw $t0, 4($sp)");
                                            $$->code.push_back("add $a0, $a0, $t0");
                                            $$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if($2->type=="-")
                                        {
                                            $$->val = ($1->val - $2->val);
                                            $$->code = $1->code;
                                            $$->code.push_back("sw $a0, ($sp)");
                                            $$->code.push_back("addi $sp, $sp, -4");
                                            
                                            $$->code.insert( $$->code.end(), $2->code.begin(), $2->code.end() );
                                            $$->code.push_back("lw $t0, 4($sp)");
                                            $$->code.push_back("sub $a0,$a0, $t0");
                                            $$->code.push_back("addi $sp, $sp, 4");
                                        }    
                                    }
                                    else
                                    {
                                        $$->eleType = string("error");
                                        yyerror("incompatible operands");
                                    }
                                }
                                
                                printf("expr1 : expr2 add_sub\n"); 
            
            
                            }
        ;



add_sub : 

        PLUS expr           {
                                $$ = new struct allAttributes;
                                $$->type = string("+");
                                $$->val = $2->val;
                                $$->eleType = $2->eleType;
                                if($2->eleType != "error")
                                    $$->code =$2->code;
                                printf("add_sub : PLUS expr\n"); 
                    
                            }
        | MINUS expr        {
                                $$ = new struct allAttributes;
                                $$->type = string("-");
                                $$->val = $2->val;
                                $$->eleType = $2->eleType;
                                if($2->eleType != "error")
                                    $$->code =$2->code;
                                printf("add_sub : MINUS expr\n"); 
                    
                            }
        | /*    */          { 
                                $$ = new struct allAttributes;
                                $$->type = string("epsilon");
                                printf("add_sub : epsilon\n"); 
                            }
        ;



expr2 : 

        expr3 mul_div       {
                                int success;
                                if($2->type == "epsilon")
                                {
                                    $$ = new struct allAttributes;
                                    $$->type = $1->type;
                                    $$->eleType = $1->eleType;
                                    $$->val = $1->val;
                                    $$->code = $1->code;
                                }
                                else
                                {
                                    compatibleArithOp($1, $2, &success);
                                    $$ = new struct allAttributes;
                                    if(success)
                                    {
                                        
                                        $$->eleType=string("int");
                                        if($2->type=="*")
                                        {
                                            $$->val = ($1->val * $2->val);
                                            $$->code = $1->code;
                                            $$->code.push_back("sw $a0, ($sp)");
                                            $$->code.push_back("addi $sp, $sp, -4");
                                            
                                            $$->code.insert( $$->code.end(), $2->code.begin(), $2->code.end() );
                                            $$->code.push_back("lw $t0, 4($sp)");
                                            $$->code.push_back("mult $a0, $t0");
                                            $$->code.push_back("mflo $a0");
                                            $$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if($2->type=="/")
                                        {
                                            $$->val = ($1->val / $2->val);
                                             $$->code = $1->code;
                                            $$->code.push_back("sw $a0, ($sp)");
                                            $$->code.push_back("addi $sp, $sp, -4");
                                            
                                            $$->code.insert( $$->code.end(), $2->code.begin(), $2->code.end() );
                                            $$->code.push_back("lw $t0, 4($sp)");
                                            $$->code.push_back("div $a0, $t0");
                                            $$->code.push_back("mflo $a0");
                                            $$->code.push_back("addi $sp, $sp, 4");
                                        }
                                        else if($2->type=="epsilon")
                                        {
                                            $$->val = $1->val;
                                            $$->code = $1->code;
                                        }    
                                        
                                    }
                                    else
                                    {
                                        $$->eleType = string("error");
                                        yyerror("incompatible operands");
                                    }
                                }
                                printf("expr2 : expr3 mul_div\n");
                            }
        ;

        

mul_div :   

        TIMES expr          { 
                                $$ = new struct allAttributes;
                                $$->type = string("*");
                                $$->val = $2->val;
                                $$->eleType = $2->eleType;
                                if($2->eleType != "error")
                                    $$->code =$2->code;
                                printf("mul_div : TIMES expr\n");
                            }
        | DIV expr          {
                                $$ = new struct allAttributes;
                                $$->type = string("/");
                                $$->val = $2->val;
                                $$->eleType = $2->eleType;
                                if($2->eleType != "error")
                                    $$->code =$2->code;
                                printf("mul_div : DIV expr\n"); 
                        
                            }
        | /*    */          {
                                $$ = new struct allAttributes;
                                $$->type = string("epsilon");
                                printf("mul_div : epsilon\n");
                            }
        ;



expr3 : 

        NEGATION expr       {   
                                $$ = new struct allAttributes;
                                $$->eleType = string("bool");
                                $$->val = !($2->val);
                                if(coercible("bool", $2->type))
                                {
                                    $$->eleType ="bool";
                                    
                                    $$->code.push_back("li $t0, "+ to_string($2->val) ) ;
                                    $$->code.push_back("li $t1, 0");
                                    $$->code.push_back("beq $t0, $t1, target"+to_string(targetCount) );
                                    $$->code.push_back("li $a0, 0");
                                    $$->code.push_back("b target"+to_string(targetCount+1));
                                    $$->code.push_back("target" +to_string(targetCount) +":");
                                    $$->code.push_back("li $a0, 1");
                                    $$->code.push_back("target"+to_string(targetCount+1)+":" );
                                    targetCount+=2;
                                }
                                else
                                {
                                    $$->eleType = "error";
                                    yyerror("negation not coercible ");
                                }
                                printf("expr3 : NEGATION expr\n"); 
                
                            }
        |   term            {
                                $$ = new struct allAttributes;
                                if($1->eleType !="error")
                                {
                                    $$->type = $1->type;
                                    $$->eleType = $1->eleType;
                                    $$->val = $1->val;
                                    $$->name = $1->name;
                                    for(int i=0;i<$1->code.size();i++)
                                        $$->code.push_back($1->code[i]); 
                                }
                                else
                                    $$->eleType ="error";
                                    
                                printf("expr3 : term\n");
                            }
        ;

term :

        id_array            {
                                //cout<<"term -> id_array ";
                                int found;
                                struct varParListEntry rec;     // it can be global entry also but we dont need func table entry fields
                                $$ = new struct allAttributes;
                                
                                findEntry($1, &found, &rec);
                                
                                if( found )
                                {
                                    //cout << "entry found "
                                    $1->eleType = rec.eleType;
                                    if( $1->type == "array" )
                                    {
                                        //cout<<"type: array ";
                                        if( (rec.dimList).size() == $1->dimList.size() )
                                        {
                                            int i;
                                            //cout << " dim match dimlist size " <<rec.dimList.size();
                                            for( i=0; i< rec.dimList.size(); i++)
                                            {
                                                //cout<<i<<"th dimension "<<rec.dimList[i]<<" "<<$1->dimList[i]<<"  ";
                                                if( rec.dimList[i] <= $1->dimList[i] )
                                                {
                                                    yyerror("array out of bound");
                                                    $$->eleType = string("error");
                                                    break;
                                                }
                                            }
                                            if( i == rec.dimList.size() )
                                            {
                                                /*  code gen for array    */
                                                int dim = 0;
                                                int lastDim=1;
                                                for(int i=$1->dimList.size()-1; i>=0; i-- )
                                                {
                                                    dim += ($1->dimList[i])*lastDim;
                                                    lastDim *= rec.dimList[i];
                                                }   
                                                if(activeFuncPtr == NULL)
                                                {
                                                    $$->code.push_back("move $t0, $fp");
                                                    //$$->code.push_back("li $t0, "+to_string(spInitial) );
                                                    $$->code.push_back("addi $t0, $t0, "+to_string(  -1*(rec.offset+dim*4) ) );
                                                    $$->code.push_back("lw $a0, ($t0)");
                                                    
                                                }
                                                else{
                                                    if(rec.scope==0)
                                                    {
                                                        $$->code.push_back("li $t0, "+to_string(spInitial) );
                                                    }
                                                    else
                                                    {
                                                        $$->code.push_back("move $t0, $fp");
                                                    }
                                                    $$->code.push_back("addi $t0, $t0, "+to_string( -1*(rec.offset+dim*4) ) );
                                                    $$->code.push_back("lw $a0, ($t0)");
                                                }
                                                
                                                $$->eleType = $1->eleType;
                                                $$->val = $1->val;
                                            }
                                        }
                                        else
                                        {
                                            yyerror("array out of bound");
                                            $$->eleType = string("error");
                                            //break;
                                        }
                                    }
                                    else
                                    {
                                        $$->eleType = $1->eleType;
                                        $$->val = $1->val;
                                        
                                        if(activeFuncPtr == NULL)
                                        {
                                            $$->code.push_back("move $t0, $fp");
                                            //$$->code.push_back("li $t0, "+to_string(spInitial) );
                                            $$->code.push_back("addi $t0, $t0, "+to_string( -1*(rec.offset) ) );
                                            $$->code.push_back("lw $a0, ($t0)");
                                        }
                                        else{
                                            if(rec.scope==0)
                                            {
                                                $$->code.push_back("li $t0, "+to_string(spInitial) );
                                            }
                                            else
                                            {
                                                $$->code.push_back("move $t0, $fp");
                                            }
                                            $$->code.push_back("addi $t0, $t0, "+to_string( -1*rec.offset) );
                                            $$->code.push_back("lw $a0, ($t0)");
                                        }
                                    }
                                }
                                else
                                {
                                    $$->eleType = string("error");
                                    yyerror( (char *)("variabe not declared " + $1->name).c_str() );
                                }
                                printf("term : id_array\n");
                            }
        |   NUM             { 
                                $$ = new struct allAttributes;
                                $$->val=$1->val; 
                                $$->eleType = "int";
                                /*  code gen  */
                                $$->code.push_back("li $a0, " + to_string($1->val) );
                                
                                printf("term : NUM\n"); 
                
                            }
        |   TRUE            {
                                $$ = new struct allAttributes;
                                $$->val=1; 
                                $$->eleType = "bool";
                                /*  code gen  */
                                $$->code.push_back("li $a0, 1");
                            }
        |   FALSE           {
                                $$ = new struct allAttributes;
                                $$->val=0; 
                                $$->eleType = "bool";
                                /*  code gen  */
                                $$->code.push_back("li $a0, 0" );
                            }
        |   func_call       {  
                                
                                $$ = new struct allAttributes;
                                $$ = $1;
                                
                                printf("term : func_call\n");   
                                
                            }
        |   CHARACTER       {  
                                $$ = new struct allAttributes;
                                $$->val=$1->val; 
                                $$->eleType = "char";
                                printf("term : CHARACTER\n"); 
                                /*  code gen  */
                                $$->code.push_back("li $a0, " + to_string(0) );
                                string s;
                                s.push_back((char)$1->val);
                                $$->code.push_back("li $a0, \'" + s +"\'" );
                            }
        ;

        

opt_stmt_list : stmt_list           {   $$ = new struct allAttributes;  $$->code = $1->code;     printf("opt_stmt_list : stmt_list\n"); }
                | /* epsilon */     {  $$ = new struct allAttributes;   printf("opt_stmt_list : epsilon\n"); }
                ;



var_decl : 
            datatype id_list        {
                                        $$= new struct allAttributes;
                                        $$->code = $2->code;
                                        
                                        patch($2->listOfVar, $1->eleType); 
                                        $2->eleType="int"; 
                                        printf("var_decl : datatype id_list\n"); 
                                    }
            ;


id_list : 
            id_array    {
                            //cout<<"id_list ->>id_array";
                            //$$ = new struct allAttributes; 
                            int found; 
                            struct varParListEntry rec;
                            
                            findEntry($1, &found, &rec);
                            
                            if( found && ( (rec.scope == currentScope) || ( rec.type=="function" &&  rec.scope == 1 && currentScope == 2) ) )
                            {
                                
                                string tempError = string("variable already declared ") + $1->name; 
                                yyerror ( (char *)(tempError.c_str()) );
                            }
                            else
                            {
                                //cout << "found val " << found;
                                //cout<<"entry scope "<<$1->scope<<endl;
                                if(activeFuncPtr == NULL)
                                {
                                    $1->offset = currentOffset;
                                    if($1->type=="simple")
                                    {
                                        currentOffset+=4;
                                        $1->code.push_back("addi $sp,$sp,-4");
                                    }
                                    else if($1->type=="array")
                                    {
                                        int temp=1;
                                        for(int i=0;i<$1->dimList.size();i++)
                                        {
                                            temp*=$1->dimList[i];
                                            
                                        }
                                        temp*=4;
                                        currentOffset += temp;
                                        $1->code.push_back("addi $sp, $sp, "+ to_string(-1*currentOffset) );
                                    }
                                }
                                else
                                {
                                    $1->offset = currentOffset;
                                    if($1->type=="simple")
                                    {
                                        currentOffset+=4;
                                        $1->code.push_back("addi $sp,$sp,-4");
                                    }
                                    else if($1->type=="array")
                                    {
                                        int temp=1;
                                        for(int i=0;i<$1->dimList.size();i++)
                                        {
                                            temp*=$1->dimList[i];
                                            
                                        }
                                        temp*=4;
                                        currentOffset += temp;
                                        $1->code.push_back("addi $sp, $sp, "+ to_string(-1*currentOffset) );
                                    }
                                }
                                
                                insertSymTab($1);
                            }
                        }
                        
            COMMA       
            id_list        { 
                                $$ = new struct allAttributes; 
                                
                                $$->code.insert($$->code.end(), $1->code.begin(), $1->code.end());
                                $$->code.insert($$->code.end(), $4->code.begin(), $4->code.end());
                                
                                $4->listOfVar.push_back($1->name);
                                $$->listOfVar =$4->listOfVar;   
                                printf("id_list : id_array COMMA id_list \n");
                            }
            | id_array  {
                            
                            int found; 
                            //cout<<"Id_list called\n";
                            $$ = new struct allAttributes;
                            $$->listOfVar.push_back($1->name);  //in patch list
                            
                            struct varParListEntry rec;
                            findEntry($1, &found, &rec);
                            if( found && ( (rec.scope == currentScope) || (rec.scope == 1 && currentScope == 2) ) )
                            {
                                
                                string tempError = string("variable already declared ") + $1->name; 
                                yyerror ( (char *)(tempError.c_str()) );
                            }
                            else
                            {
                                if(activeFuncPtr == NULL)
                                {
                                    $1->offset = currentOffset;
                                    if($1->type=="simple")
                                    {
                                        currentOffset+=4;
                                        $$->code.push_back("addi $sp,$sp,-4");
                                    }
                                    else if($1->type=="array")
                                    {
                                        int temp=1;
                                        for(int i=0;i<$1->dimList.size();i++)
                                        {
                                            temp*=$1->dimList[i];
                                            
                                        }
                                        temp*=4;
                                        currentOffset += temp;
                                        $$->code.push_back("addi $sp, $sp, "+ to_string(-1*currentOffset) );
                                    }
                                }
                                else
                                {
                                    $1->offset = currentOffset;
                                    if($1->type=="simple")
                                    {
                                        currentOffset+=4;
                                        $$->code.push_back("addi $sp,$sp,-4");
                                    }
                                    else if($1->type=="array")
                                    {
                                        int temp=1;
                                        for(int i=0;i<$1->dimList.size();i++)
                                        {
                                            temp*=$1->dimList[i];
                                        }
                                        temp*=4;
                                        currentOffset += temp;
                                        $$->code.push_back("addi $sp, $sp, "+ to_string(-1*currentOffset) );
                                    }
                                }
                                insertSymTab($1);
                            }
                             printf("id_list : id_array\n"); 
                        }  
            ;
            

id_array : 

            ID      {
                       //cout<<"ID called\n";
                       //cout << "ID name " << $1->name;
                        $$ = new struct allAttributes;
                        //cout<<"after new\n";
                        $1->type = string("simple");
                        $1->scope = currentScope;
                        //$1->eleType = tempValues.eleType;
                        $$->name = $1->name;
                        $$->type = string("simple");
                        $$->scope = currentScope;
                        //$$->eleType = tempValues.eleType;
                        int success;
                        struct varParListEntry temp;
                        findEntry($1, &success, &temp);
                        $1->eleType = temp.eleType;
                        printf("id_array : ID\n");  
                    }                
            
            
            | ID    {
                       
                        $1->type = string("array");
                        $1->scope = currentScope;
                        //$1->eleType = tempValues.eleType;
                        
                    }
            OSB DIMLIST CSB     {
                                    $1->dimList = $4->dimList;
                                    $$ = new struct allAttributes;
                                    $$->dimList = $4->dimList; 
                                    $$->name = $1->name;
                                    $$->type = string("array");
                                    $$->scope = currentScope;
                                    
                                    //$$->eleType = tempValues.eleType; 
                                    printf("id_array : ID OSB DIMLIST CSB\n"); 
                
                                }
            ;

    

DIMLIST : 

            expr                        { $$ = new struct allAttributes; 
                                            /*$$->code = $1->code;
                                            
                                            $$->code.push_back("li $t0, 4");
                                            $$->code.push_back("mult $t0 $a0");
                                            $$->code.push_back("mflo $a0");
                                            */
                                            
                                            
                                            
                                            
            
                                            $$->dimList.push_back($1->val);  printf("DIMLIST : expr\n"); }
            | expr COMMA DIMLIST        { 
            
                                            $$ = new struct allAttributes; 
                                            
                                            /*$$->code = $1->code;
                                            
                                            $$->code.push_back("li $t0, 4");
                                            $$->code.push_back("mult $t0 $a0");
                                            $$->code.push_back("mflo $a0");
                                            */
                                            
                                            $3->dimList.push_back($1->val); 
                                            $$->dimList = $3->dimList;  printf("DIMLIST : expr COMMA DIMLIST\n"); }
            ;

    

datatype : 

            INT                     { $$ = new struct allAttributes; $$->eleType = string("int"); printf("datatype : INT\n"); }
            | BOOL                  { $$ = new struct allAttributes; $$->eleType = string("bool"); printf("datatype : BOOL\n"); }
            | CHAR                  { $$ = new struct allAttributes; $$->eleType = string("char"); printf("datatype : CHAR\n"); }
            ;



func_call :

            ID LP opt_expr_list rp  {  
                                        int success;
                                        $$ = new allAttributes;
                                        struct globalTableEntry *rec;
                                        rec = searchFunc($1, &success);
                                        if(success && rec->alreadyDefined==1)       // alreadyDefined =1 means it was defination .
                                        {
                                            if($3->parList.size() == rec->parList.size())
                                            {
                                                int i;
                                                for(i=0;i<$3->parList.size();i++)
                                                {
                                                    if( !coercible($3->parList[i].eleType, rec->parList[i].eleType) )
                                                    {
                                                        yyerror("arguments type mismatch");
                                                        $$->eleType = "error";
                                                        break;
                                                    }
                                                }
                                                if(i==$3->parList.size())
                                                {
                                                    $$->eleType = rec->eleType;     // return type
                                                    /*  code gen  */
                                                    $$->code.push_back("sw $fp 0($sp)");
                                                    $$->code.push_back("addi $sp $sp -4");
                                                    
                                                    
                                                   
                                                   $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                    $$->code.push_back("jal "+$1->name);
                                                    
                                                }
                                            }
                                            else{
                                                    yyerror("number of arguments mismatch");
                                                    $$->eleType = "error";
                                            }
                                        }
                                        else{
                                                yyerror("function not defined");
                                                $$->eleType = "error";
                                        }
                                        printf("func_call : ID LP opt_expr_list rp\n"); 
                                
                                    }
            ;

            

opt_expr_list : expr_list           {  
                                        $$ = new struct allAttributes;
                                        $$->parList = $1->parList;
                                        $$->code = $1->code;
                                        printf("opt_expr_list : expr_list\n"); 
        
                                    }
                | /*    epsilon */  {
                                        $$ = new struct allAttributes;
                                        printf("opt_expr_list : epsilon\n"); 
                        
                                    }
                ;

                

expr_list : expr COMMA expr_list    {  
                                        $$ = new struct allAttributes;
                                        $$->parList = $3->parList;
                                        struct varParListEntry temp;
                                        temp.eleType = $1->eleType;
                                        $$->parList.push_back(temp);
                                        /*  code gen  */
                                        $$->code = $3->code;
                                        $$->code.insert($$->code.end(), $1->code.begin(), $1->code.end());
                                        
                                        $$->code.push_back("sw $a0 0($sp)");
                                        $$->code.push_back("addi $sp $sp -4");
                                        printf("expr_list : expr COMMA expr_list\n"); }
            | expr                  {  
                                        $$ = new struct allAttributes;
                                        struct varParListEntry temp;
                                        temp.eleType = $1->eleType;
                                        $$->parList.push_back(temp);
                                        $$->code =$1->code;
                                        $$->code.push_back("sw $a0 0($sp)");
                                        $$->code.push_back("addi $sp $sp -4");
                                        printf("expr_list : expr\n"); }
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

void yyerror(char *s) 
{
    fprintf(stderr, "ERROR: %s at line no. %d\n", s, lineno );
}

struct globalTableEntry *searchFunc(struct allAttributes *entryOld, int *success)
{
    struct allAttributes entry = *entryOld;
    struct globalTableEntry *foundEntry = NULL; //initialize
    
    *success=0;
    for(int i=0; i<symTab.size(); i++)
    {
        if(symTab[i].type=="function")
        {
            if(symTab[i].name==entry.name)
            {
                *success=1;
                
                foundEntry=&symTab[i];
                return foundEntry;
            }
        }
    }
    return foundEntry;
}


// args -> entry to search, success, entry if found
void findEntry(struct allAttributes *entryOld, int *success, struct varParListEntry *foundEntryFinal)
{
    struct allAttributes entry = *entryOld;
    struct varParListEntry *foundEntry = NULL; // initialize
    *success=0;
    //cout << "find entry " << entry.name << "scope: "<<entry.scope <<endl;
    if(activeFuncPtr != NULL)
    {
        //traverse in varList
        for(int i=0; i<activeFuncPtr->varList.size(); i++)
        {
            if( activeFuncPtr->varList[i].name == entry.name && entry.scope >= activeFuncPtr->varList[i].scope )
            {
                if(foundEntry != NULL && foundEntry->scope < activeFuncPtr->varList[i].scope )
                {
                    foundEntry = &activeFuncPtr->varList[i]; 
                }
                else
                    foundEntry = &activeFuncPtr->varList[i]; 
            }
        }
        if(foundEntry!=NULL)
        {
            *success =1;
            *foundEntryFinal = *foundEntry;
            //cout<<"entry found in varlist "<<endl;
            return;
        }
        //traverse in parList
        for(int i=0; i<activeFuncPtr->parList.size(); i++)
        {
            if(activeFuncPtr->parList[i].name==entry.name)
            {
                *success=1;
                foundEntry = &activeFuncPtr->parList[i];
                *foundEntryFinal = *foundEntry;
                //cout << "entry found in paramList\n";
                return;
            }
        }
        
    }
    // search global variable
    //cout << "now search in global table\n";
    for(int i=0; i<symTab.size(); i++)
    {
        if(symTab[i].type != "function")
        {
            //cout << "entry is not func\n";
            if(symTab[i].name == entry.name && symTab[i].scope <= entry.scope )
            {
                if(foundEntry == NULL || (symTab[i].scope  > foundEntry->scope)  )
                {
                    //cout << "names match\n";
                    *success=1;
                    foundEntryFinal->name=symTab[i].name;
                    foundEntryFinal->type=symTab[i].type;
                    foundEntryFinal->eleType=symTab[i].eleType;
                    foundEntryFinal->scope=symTab[i].scope;
                    foundEntryFinal->dimList=symTab[i].dimList;
                    foundEntryFinal->offset = symTab[i].offset;
                    //cout<<"entry found in global"<<endl;
                }
                
            }
        }
    }
    return;
    //cout<<"entry not found"<<endl;
    
}

void compatibleArithOp(struct allAttributes *entry1Old, struct allAttributes *entry2Old, int *success)
{
    *success = 0;
    if(entry1Old->eleType == "error" || entry2Old->eleType == "error")
        return;
    if(entry1Old->eleType == "bool" && entry2Old->eleType == "char")
        return;
    if(entry1Old->eleType == "char" && entry2Old->eleType == "bool")
        return;
    *success=1; 
    return;
}

// to insert par and val
void insertSymTab(struct allAttributes *entryOld)
{
    struct allAttributes entry = *entryOld;
    //cout<<"inserting entry "<< entry.name<<" in symbol table"<<endl;
    
    if(activeFuncPtr == NULL) // insert global var
    {
        struct globalTableEntry newEntry;
        newEntry.name= entry.name;
        newEntry.type = entry.type;
        newEntry.eleType = entry.eleType;
        newEntry.scope = entry.scope;
        newEntry.dimList = entry.dimList;
        newEntry.offset = entry.offset;
        symTab.push_back(newEntry);
        
        //cout<<"entry inserted "<<endl;
        return;
    }   
    struct varParListEntry newEntry;
    
    newEntry.name = entry.name;
    newEntry.type = entry.type;
    newEntry.eleType = entry.eleType;
    newEntry.scope = entry.scope;
    newEntry.dimList = entry.dimList;
    newEntry.offset = entry.offset;
    
    if(entry.scope == 1)
        activeFuncPtr->parList.push_back(newEntry);
    else
        activeFuncPtr->varList.push_back(newEntry);
    //cout<<"entry inserted "<<endl;
}


void patch(vector <string> &entry, string eleType)
{
    if(activeFuncPtr==NULL)
    {
        //check in globalTableEntry
        
        for(int i=0; i<symTab.size();i++)
        {
            for(int j=0;j<entry.size();j++)
            {
                if(symTab[i].name == entry[j])
                {
                    symTab[i].eleType = eleType;
                    break;
                }
            }
        }
    }
    else
    {
        //check in varList of func
        for(int i=0; i<activeFuncPtr->varList.size(); i++)
        {
            for(int j=0; j<entry.size(); j++)
            {
                if(entry[j]==activeFuncPtr->varList[i].name)
                {
                    activeFuncPtr->varList[i].eleType=eleType;
                    break;
                }
            }
        }
        
    }
}

//takes arg as two datatypes and checks if one can be assigned to other
bool coercible(string s1, string s2)
{
    if(s1 == "error" || s2 == "error")
        return 0;
    if((s1 == "bool" && s2 == "char") || (s1 == "char" && s2 == "bool"))
        return 0;
    return 1;
}

//insert funcEntry in the global table
void insertFunc(struct allAttributes *funcEntry1)
{
    struct allAttributes funcEntry =*funcEntry1;
    
    struct globalTableEntry finalFuncEntry;
    
    finalFuncEntry.name = funcEntry.name;
    finalFuncEntry.type = funcEntry.type;
    finalFuncEntry.eleType = funcEntry.eleType;
    finalFuncEntry.scope = 1;
    finalFuncEntry.alreadyDefined = funcEntry.alreadyDefined;
    
    finalFuncEntry.parList = funcEntry.parList;
    symTab.push_back(finalFuncEntry);
}

int main(void) {

    activeFuncPtr = NULL;
    currentOffset=0;
    callFuncPtr = NULL;
    currentScope = 0;
    //tempValues.eleType = "int";
    fp = fopen("codegen.txt", "w+");
    
    fp2 = fopen("symbolTable.txt", "w+");
    fprintf(fp, "main:\n");
    fprintf(fp, "li $sp, 2147479548\n");
    fprintf(fp, "move $fp, $sp\n");
    yyparse();
    fprintf(fp, "li $v0, 10\nsyscall\n");
    
    
    
    /*
    
     struct globalTableEntry
    {
        string name;
        string type;
        string eleType;
        int scope=0;
        vector <struct varParListEntry> parList;
        vector <struct varParListEntry> varList;
        vector <int> dimList;
        int alreadyDefined;
        int offset;
    
    
    */
    
    
    for(int i=0; i<symTab.size(); i++)
    {
        fprintf(fp2, "Entry %d: ", i);
        fprintf(fp2, "   %s %s %s %d", symTab[i].name.c_str(), symTab[i].type.c_str(), symTab[i].eleType.c_str(), symTab[i].scope);
        if(symTab[i].parList.size()==0)
        {
            fprintf(fp2, " NULL ");
        }
        else
        {
            fprintf(fp2, "The parameters are:\n");
            for(int j=0; j<symTab[i].parList.size(); j++)
            {
                fprintf(fp2, "      %s ", symTab[i].parList[j].name.c_str());
            }
        }
        if(symTab[i].varList.size()==0)
        {
            fprintf(fp2, " NULL ");
        }
        else
        {
            fprintf(fp2, "The variables are:\n");
            for(int j=0; j<symTab[i].varList.size(); j++)
            {
                fprintf(fp2, "      %s ", symTab[i].varList[j].name.c_str());
            }
        }
        if(symTab[i].dimList.size()==0)
        {
            fprintf(fp2, " NULL ");
        }
        else
        {
            fprintf(fp2, "The dimensions are:\n");
            for(int j=0; j<symTab[i].dimList.size(); j++)
            {
                fprintf(fp2, "      %d ", symTab[i].dimList[j]);
            }
        }
        fprintf(fp2, "\n");
    }
    
    
    fclose(fp2);
    fclose(fp);
    return 0;
    
    
    
}
