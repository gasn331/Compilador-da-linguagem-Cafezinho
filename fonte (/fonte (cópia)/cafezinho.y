%{
	#include <stdio.h>
        #include <string.h>
        typedef struct node{ //definicao de um no da arvore de sintaxe abstrata
                struct node *left;
                struct node *right;
                char *token;
        }node;
        node *mknode(node *left, node *right, char *token);
        void printtree(node *tree); 
        #define YYSTYPE struct node *
	yydebug=1;
%}
%start programa

%token PROGRAMA DECLARACAO_INT DECLARACAO_CAR 
%token RETORNE LEIA ESCREVA NOVALINHA
%token SE ENTAO SENAO ENQUANTO EXECUTE
%token MAIS MENOS VEZES DIV RESTO OUEXPR EEXPR ANULEXPR DBIGUAL DIFF
%token MAIORQ MENORQ MAIORIGQ MENORIGQ INTERROG DOISPONT
%token EPAREN DPAREN DBRACK EBRACK EBRACE DBRACE SEMI VIRGULA ATRIB
%token ID INTCONST CARCONST STRING

%%
programa : DeclFuncVar DeclProg   {printf("programa\n"); $$ = mknode($1, $2, "programa"); printtree($1); printf("\n");}
         ;

DeclFuncVar : Tipo ID DeclVar SEMI DeclFuncVar {printf("DeclFuncVar\n");$$ = mknode(mknode(NULL,$2,"Tipo"), mknode($4, NULL,"DeclFuncVar"), "DeclVar");}
            | Tipo ID EBRACK INTCONST DBRACK DeclVar SEMI DeclFuncVar   {printf("DeclFuncVar2\n");$$ = mknode(mknode($1,mknode($3,$5,"INTCONST"),"ID"),mknode($7,NULL,"DeclFuncVar"), "DeclVar");}
            | Tipo ID DeclFunc DeclFuncVar      {printf("DeclFuncVar3\n");$$ = mknode(mknode(NULL,$2,"Tipo"), $4, "DeclFunc");}
            | /* empty */
            ;

DeclProg : 
	PROGRAMA Bloco  {printf("DeclProg\n");$$ = mknode($1,NULL,"Bloco");}          
         ;

DeclVar : VIRGULA ID DeclVar    {printf("DeclVar\n");$$ = mknode($1, $3, "ID");}
        | VIRGULA ID EBRACK INTCONST DBRACK DeclVar {printf("DeclVar2\n");$$ = mknode($1,mknode(mknode($3,$5,"INTCONST"),NULL,"DeclVar"),"ID");}
        | /* empty */
        ;

DeclFunc : EPAREN ListaParametros DPAREN Bloco {printf("DeclFunc\n");$$ = mknode($1,mknode(NULL,$4,"DPAREN"),"ListaParametros");}
         ;

ListaParametros : /* empty */
                | ListaParametrosCont {printf("ListaParametros\n");$$ = $1;}
                ;

ListaParametrosCont : Tipo ID   {printf("ListaParametrosCont\n");$$ = mknode(NULL,$2,"Tipo");}
                    | Tipo ID EBRACK DBRACK {printf("ListaParametrosCont\n");$$ = mknode(NULL,mknode($2,$4,"EBRACK"),"Tipo");}
                    | Tipo ID VIRGULA ListaParametrosCont {printf("ListaParametrosCont\n");$$ = mknode(mknode(NULL,$2,"Tipo"),$4,"VIRGULA");}
                    | Tipo ID EBRACK DBRACK VIRGULA ListaParametrosCont {printf("ListaParametrosCont\n");$$ = mknode(mknode(NULL,mknode($2,$4,"EBRACK"),$1),$6,"VIRGULA");}
                    ;

Bloco : EBRACE ListaDeclVar ListaComando DBRACE {printf("Bloco1\n"); $$ = mknode(mknode($1,NULL,"ListaDeclVar"),$4,"ListaComando");}
      | EBRACE ListaDeclVar DBRACE {printf("Bloco2\n");$$ = mknode($1,$3,"ListaDeclVar");}
      ;

ListaDeclVar : /* empty */ {printf("ListaDeclVar0\n");}
             | Tipo ID DeclVar SEMI ListaDeclVar {printf("ListaDeclVar1\n");$$ = mknode(mknode(NULL,$2,"Tipo"),mknode($4,NULL,"ListaDeclVar"),"DeclVar");}
             | Tipo ID EBRACK INTCONST DBRACK DeclVar SEMI ListaDeclVar {printf("ListaDeclVar2\n");$$ = mknode(mknode($1,mknode($3,$5,"INTCONST"),"ID"),mknode($7,NULL,"ListaDeclVar"),"DeclVar");}
             ;

Tipo : DECLARACAO_INT   {printf("TIPO\n");$$ = mknode(NULL,NULL,"DECLARACAO_INT");}
     | DECLARACAO_CAR   {printf("TIPO\n");$$ = mknode(NULL,NULL,"DECLARACAO_CAR");}
     ;

ListaComando : Comando  {printf("LISTA COMANDO1\n");$$ = $1;}
             | Comando ListaComando {printf("LISTA COMANDO2\n");$$ = mknode(NULL,$2,"Comando");}
             ;

Comando : 
	SEMI    {printf("Comando1\n");$$ = mknode(NULL, NULL, "SEMI");}
        | Expr SEMI     {printf("Comando2\n");$$ = mknode($1, NULL, "SEMI");}
        | RETORNE Expr SEMI     {printf("Comando3\n");$$ = mknode($1, $3, "Expr");}
        | LEIA LValueExpr SEMI  {printf("Comando4\n");$$ = mknode($1, $3, "LValueExpr");}
        | ESCREVA Expr SEMI     {printf("Comando5\n");$$ = mknode($1, $3, "Expr");}
        | ESCREVA STRING SEMI   {printf("Comando6\n");$$ = mknode($1, $3, "STRING");}
        | NOVALINHA SEMI        {printf("Comando7\n");$$ = mknode(NULL, $2, "NOVALINHA");}
        | SE EPAREN Expr DPAREN ENTAO Comando {printf("Comando8\n");$$ = mknode(mknode($1,NULL,"EPAREN"),mknode($4,$6,"ENTAO"),"Expr");}
        | SE EPAREN Expr DPAREN ENTAO Comando SENAO Comando {printf("Comando9\n");$$ = mknode(mknode($1,NULL,"EPAREN"),mknode($4,mknode($6,$8,"SENAO"),"ENTAO"),"Expr");}
        | ENQUANTO EPAREN Expr DPAREN EXECUTE Comando {printf("Comando10\n");$$ = mknode(mknode($1,NULL,"EPAREN"),mknode($4,$6,"EXECUTE"),"Expr");}
        | Bloco         {printf("Comando11\n");$$ = $1;}
        ;

Expr : AssignExpr       {$$ = $1;}
     ;

AssignExpr : CondExpr {$$ = $1;}
           | LValueExpr ATRIB AssignExpr {$$ = mknode($1,$3,"ATRIB");}
           ;

CondExpr : OrExpr {$$ = $1;}
         | OrExpr INTERROG Expr DOISPONT CondExpr {$$ = mknode(mknode($1,NULL,"INTERROG"),mknode($4,NULL,"CondExpr"),"Expr");}
         ;

OrExpr : OrExpr OUEXPR AndExpr  {printf("OR\n");$$ = mknode($1,$3,"OUEXPR");}
       | AndExpr        {$$ = $1;}
       ;

AndExpr : AndExpr EEXPR EqExpr          {printf("AND\n");$$ = mknode($1,$3,"EEXPR");}
        | EqExpr        {$$ = $1;}
        ;

EqExpr : EqExpr DBIGUAL DesigExpr       {printf("EQ\n");$$ = mknode($1,$3,"DBIGUAL");}
       | EqExpr DIFF DesigExpr          {printf("EQ\n");$$ = mknode($1,$3,"DIFF");}
       | DesigExpr      {$$ = $1;}
       ;

DesigExpr : DesigExpr MENORQ AddExpr    {printf("DES\n");$$ = mknode($1,$3,"MENORQ");}
          | DesigExpr MAIORQ AddExpr    {printf("DES\n");$$ = mknode($1,$3,"MAIORQ");}  
          | DesigExpr MENORIGQ AddExpr  {printf("DES\n");$$ = mknode($1,$3,"MENORIGQ");}
          | DesigExpr MAIORIGQ AddExpr  {printf("DES\n");$$ = mknode($1,$3,"MAIORIGQ");}
          | AddExpr     {$$ = $1;}
          ;

AddExpr : AddExpr MAIS MulExpr  {printf("ADD\n");$$ = mknode($1,$3,"MAIS");}
        | AddExpr MENOS MulExpr {printf("ADD\n");$$ = mknode($1,$3,"MENOS");}
        | MulExpr       {$$ = $1;}
        ;

MulExpr : MulExpr VEZES UnExpr  {printf("MUL\n");$$ = mknode($1,$3,"VEZES");}
        | MulExpr DIV UnExpr    {printf("MUL\n");$$ = mknode($1,$3,"DIV");}
        | MulExpr RESTO UnExpr  {printf("MUL\n");$$ = mknode($1,$3,"RESTO");}
        | UnExpr        {$$ = $1;}
        ;       

UnExpr : MENOS PrimExpr {$$ = mknode(NULL,$2,"MENOS");}
       | ANULEXPR PrimExpr      {$$ = mknode(NULL,$2,"ANULEXPR");}      
       | PrimExpr       {$$ = $1;}
       ;

LValueExpr : ID EBRACK Expr DBRACK      {$$ = mknode(mknode($1,NULL,"EBRACK"),$4,"Expr");}
           | ID {$$ = mknode(NULL,NULL,"ID");}
           ;

PrimExpr : ID EPAREN ListExpr DPAREN    {$$ = mknode(mknode($1,NULL,"EPAREN"),$4,"ListExpr");}
         | ID EPAREN DPAREN     {$$ = mknode($1,$3,"EPAREN");}
         | ID EBRACK Expr DBRACK        {$$ = mknode(mknode($1,NULL,"EBRACK"),$4,"Expr");}
         | ID           {$$ = mknode(NULL,NULL,"ID");}
         | CARCONST     {$$ = mknode(NULL,NULL,"CARCONST");}
         | INTCONST     {$$ = mknode(NULL,NULL,"INTCONST");}
         | EPAREN Expr DPAREN   {$$ = mknode($1,$3,"Expr");}
         ;

ListExpr : AssignExpr   {$$ = $1;}
         | ListExpr VIRGULA AssignExpr {$$ = mknode($1, $3, "VIRGULA");}
         ;
%%

yywrap(){
	return 1;
}

main(){
	yyparse();
        
}

node *mknode(node *left, node *right, char *token){
        /*printf("PRINTING TOKEN %s\n", token);
        if(left == NULL) printf("leftNNULL\n");
        if(right == NULL) printf("RightNULL\n");*/
        if(token == NULL) return NULL;
        node *newnode = (node *)malloc(sizeof(node));
        newnode->token = (char *)malloc(sizeof(strlen(token)+1));
        newnode->left = left;
        newnode->right = right;
        strcpy(newnode->token,token);
        //printf("TOK: %s  LFT: %s RGH: %s\n", newnode->token, newnode->left->token, newnode->right->token);
        return newnode;
}
void printtree(node *tree) {
        if(tree == NULL) return;
        if(tree->left) printtree(tree->left);
        printf("%s ", tree->token);
        if(tree->right) printtree(tree->right);
 }